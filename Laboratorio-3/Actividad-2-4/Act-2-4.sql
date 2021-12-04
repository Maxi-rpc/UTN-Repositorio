--1 Listar los nombres de proyecto y costo estimado de aquellos proyectos cuyo costo estimado sea mayor al promedio de costos.
SELECT P.Nombre, P.CostoEstimado
FROM Proyectos AS P
WHERE P.CostoEstimado > (
SELECT AVG(CostoEstimado)
FROM Proyectos
) 

--2 Listar razón social, cuit y contacto (email, celular o teléfono) de aquellos clientes que no tengan proyectos que comiencen en el año 2020
SELECT C.RazonSocial, C.CUIT, COALESCE(C.Email, C.Celular, C.Telefono) AS Contacto
FROM Clientes AS C
WHERE C.ID NOT IN (
SELECT P.IDCliente
FROM Proyectos AS P
WHERE YEAR(P.FechaInicio) = '2020'
)

--3 Listado de países que no tengan clientes relacionados
SELECT P.Nombre
FROM Paises AS P
WHERE P.ID NOT IN (
SELECT DISTINCT P.ID
FROM Paises AS P
INNER JOIN Ciudades AS C ON C.IDPais = P.ID
INNER JOIN Clientes AS CL ON CL.IDCiudad = C.ID
)

--4 Listado de proyectos que no tengan tareas registradas. 
SELECT P.ID
FROM Proyectos AS P
WHERE P.ID NOT IN (
	SELECT DISTINCT P.ID
	FROM Proyectos AS P
	INNER JOIN Modulos AS MO ON MO.IDProyecto = P.ID
	INNER JOIN Tareas AS TA ON TA.IDModulo = MO.ID
)

--5 Listado de tipos de tareas que no registren tareas pendientes.
SELECT T.ID, T.Nombre
FROM TiposTarea AS T
WHERE T.ID NOT IN (
	SELECT DISTINCT T.ID
	FROM TiposTarea AS T
	INNER JOIN Tareas AS TA ON TA.IDTipo = T.ID
	WHERE TA.FechaInicio IS NULL
)

--6 Listado con ID, nombre y costo estimado de proyectos cuyo costo estimado sea menor 
--al costo estimado de cualquier proyecto de clientes nacionales (clientes que sean de Argentina o no tengan asociado un país)
SELECT P.ID, P.Nombre, P.CostoEstimado
FROM Proyectos P
WHERE P.CostoEstimado < (
	SELECT  DISTINCT MIN(PR.CostoEstimado)
	FROM Proyectos PR
	INNER JOIN Clientes CL ON CL.ID = PR.IDCliente
	INNER JOIN Ciudades CI ON CI.ID = CL.IDCiudad
	INNER JOIN Paises PA ON PA.ID = CI.IDPais
	WHERE PA.Nombre LIKE 'Argentina' OR CL.IDCiudad IS NULL
)

--7 Listado de apellido y nombres de colaboradores que hayan demorado más 
--en una tarea que el colaborador de la ciudad de 'Buenos Aires' que más haya demorado.
SELECT C.Apellido, C.Nombre
FROM Colaboradores C
INNER JOIN Colaboraciones CO ON CO.IDColaborador = C.ID
WHERE CO.Tiempo > (
	SELECT MAX(COL.Tiempo)
	FROM Colaboraciones COL
	INNER JOIN Colaboradores CO ON CO.ID = COL.IDColaborador
	INNER JOIN Ciudades CIU ON CIU.ID = CO.IDCiudad
	WHERE CIU.Nombre LIKE 'Buenos Aires'
)

--8 Listado de clientes indicando razón social, nombre del país (si tiene) y 
--cantidad de proyectos comenzados y cantidad de proyectos por comenzar.
SELECT C.RazonSocial, ISNULL((SELECT P.Nombre
	FROM Paises P
	LEFT JOIN Ciudades CIU ON CIU.IDPais = P.ID
	LEFT JOIN Clientes CL ON CL.IDCiudad = CIU.ID
	WHERE CL.ID = C.ID
),'NO REGISTRA PAIS') PAIS,(SELECT DISTINCT COUNT(PR.ID)
	FROM Proyectos PR
	LEFT JOIN Clientes CLI ON CLI.ID = PR.IDCliente
	WHERE PR.FechaInicio > GETDATE() AND CLI.ID = C.ID
) CANTCOMEN, (SELECT DISTINCT COUNT(PRO.ID)
	FROM Proyectos PRO
	LEFT JOIN Clientes CLIE ON CLIE.ID = PRO.IDCliente
	WHERE PRO.FechaInicio <= GETDATE() AND CLIE.ID = C.ID
) CANTPORCOMEN
FROM Clientes C

--9 Listado de tareas indicando nombre del módulo, nombre del tipo de tarea, 
-- cantidad de colaboradores externos que la realizaron y cantidad de colaboradores internos que la realizaron.
SELECT T.ID, MO.Nombre, TT.Nombre, 
(SELECT COUNT(*)
	FROM Colaboradores COL
	INNER JOIN Colaboraciones COLA ON COLA.IDColaborador = COL.ID
	WHERE COL.Tipo LIKE 'E' AND COLA.IDTarea = T.ID
) CANTCOLE,
(SELECT COUNT(*)
	FROM Colaboradores COLAB
	INNER JOIN Colaboraciones COLABO ON COLABO.IDColaborador = COLAB.ID
	WHERE COLAB.Tipo LIKE 'I' AND COLABO.IDTarea = T.ID
) CANTCOLI
FROM Tareas T
INNER JOIN Modulos MO ON MO.ID = T.IDModulo
INNER JOIN TiposTarea TT ON TT.ID = T.IDTipo

--10 Listado de proyectos indicando nombre del proyecto, 
-- costo estimado, cantidad de módulos cuya estimación de fin haya sido exacta, 
-- cantidad de módulos con estimación adelantada y cantidad de módulos con estimación demorada.
-- Adelantada →  estimación de fin haya sido inferior a la real.
-- Demorada   →  estimación de fin haya sido superior a la real.
SELECT P.Nombre, P.CostoEstimado, (SELECT COUNT(*)
	FROM Modulos MO
	WHERE MO.FechaEstimadaFin = MO.FechaFin AND MO.IDProyecto = P.ID
) CANTMODFEXACTA,
(SELECT COUNT(*)
	FROM Modulos MO
	WHERE MO.FechaEstimadaFin > MO.FechaFin AND MO.IDProyecto = P.ID
) CANTMODFADEL,
(SELECT COUNT(*)
	FROM Modulos MO
	WHERE MO.FechaEstimadaFin < MO.FechaFin AND MO.IDProyecto = P.ID
) CANTMODFDEM
FROM Proyectos P

--11 Listado con nombre del tipo de tarea y total abonado en concepto de honorarios 
--para colaboradores internos y total abonado en concepto de honorarios para colaboradores externos.
SELECT T.Nombre,
(SELECT SUM(COLA.PrecioHora * COLA.Tiempo)
	FROM Colaboradores COL
	INNER JOIN Colaboraciones COLA ON COLA.IDColaborador = COL.ID
	INNER JOIN Tareas TA ON TA.ID = COLA.IDTarea
	INNER JOIN TiposTarea TT ON TT.ID = TA.IDTipo
	WHERE COL.Tipo LIKE 'I' AND TT.ID = T.ID
) TOTALI,
(SELECT SUM(COLA.PrecioHora * COLA.Tiempo)
	FROM Colaboradores COL
	INNER JOIN Colaboraciones COLA ON COLA.IDColaborador = COL.ID
	INNER JOIN Tareas TA ON TA.ID = COLA.IDTarea
	INNER JOIN TiposTarea TT ON TT.ID = TA.IDTipo
	WHERE COL.Tipo LIKE 'E' AND TT.ID = T.ID
) TOTALE
FROM TiposTarea T

--12 Listado con nombre del proyecto, razón social del cliente y saldo final del proyecto. 
--El saldo final surge de la siguiente fórmula: 
--Costo estimado - Σ(HCE) - Σ(HCI) * 0.1
--Siendo HCE → Honorarios de colaboradores externos y HCI → Honorarios de colaboradores internos.
SELECT P.Nombre, CL.RazonSocial, (P.CostoEstimado - P.HCE - P.HCI *0.1) SALDO
FROM (
	SELECT PR.Nombre, PR.IDCliente, PR.CostoEstimado,
	(
		SELECT ISNULL(SUM(C.Tiempo * C.PrecioHora),0)
		FROM Colaboraciones C
		INNER JOIN Colaboradores COL ON COL.ID = C.IDColaborador
		INNER JOIN Tareas TA ON TA.ID = C.IDTarea
		INNER JOIN TiposTarea TT ON TT.ID = TA.IDTipo
		INNER JOIN Modulos MO ON MO.IDProyecto = PR.ID
		INNER JOIN Proyectos PRO ON PRO.ID = MO.IDProyecto
		WHERE COL.Tipo LIKE 'E' AND PRO.ID = PR.ID
	) HCE,
	(
		SELECT ISNULL(SUM(C.Tiempo * C.PrecioHora),0)
		FROM Colaboraciones C
		INNER JOIN Colaboradores COL ON COL.ID = C.IDColaborador
		INNER JOIN Tareas TA ON TA.ID = C.IDTarea
		INNER JOIN TiposTarea TT ON TT.ID = TA.IDTipo
		INNER JOIN Modulos MO ON MO.IDProyecto = PR.ID
		INNER JOIN Proyectos PRO ON PRO.ID = MO.IDProyecto
		WHERE COL.Tipo LIKE 'I' AND PRO.ID = PR.ID
	) HCI
	FROM Proyectos PR
) AS P
INNER JOIN Clientes CL ON CL.ID = P.IDCliente

--13 Para cada módulo listar el nombre del proyecto, el nombre del módulo, 
--el total en tiempo que demoraron las tareas de ese módulo y qué porcentaje de tiempo 
--representaron las tareas de ese módulo en relación al tiempo total de tareas del proyecto.
SELECT PR.Nombre PROYECTO, M.Nombre MODULO,
(	SELECT ISNULL(SUM(COL.Tiempo),0)
	FROM Colaboraciones COL
	INNER JOIN Tareas TA ON TA.ID = COL.IDTarea
	INNER JOIN Modulos MO ON MO.ID = TA.IDModulo
	WHERE MO.ID = M.ID
) TOTAL_TIEMPO,
(	SELECT ISNULL(SUM(COL.Tiempo),0)
	FROM Colaboraciones COL
	INNER JOIN Tareas TA ON TA.ID = COL.IDTarea
	INNER JOIN Modulos MO ON MO.ID = TA.IDModulo
	WHERE MO.ID = M.ID 
) *  100 /
(	SELECT ISNULL(SUM(COL.Tiempo),1)
	FROM Colaboraciones COL
	INNER JOIN Tareas TA ON TA.ID = COL.IDTarea
	INNER JOIN Modulos MO ON MO.ID = TA.IDModulo
	INNER JOIN Proyectos PRO ON PR.ID = MO.IDProyecto
	WHERE PRO.ID = PR.ID
)
PORCENTAJE
FROM Modulos M
INNER JOIN Proyectos PR ON PR.ID = M.IDProyecto

--14 Por cada colaborador indicar el apellido, el nombre, 'Interno' o 'Externo' 
--según su tipo y la cantidad de tareas de tipo 'Testing' que haya realizado y 
--la cantidad de tareas de tipo 'Programación' que haya realizado.
--NOTA: Se consideran tareas de tipo 'Testing' a las tareas que contengan la palabra 'Testing' en su nombre. Ídem para Programación.
SELECT C.Apellido, C.Nombre, 
CASE 
WHEN C.Tipo LIKE 'I' THEN 'Interno'
WHEN C.Tipo LIKE 'E' THEN 'Externo'
END AS TIPO,
(	SELECT COUNT(TT.Nombre)
	FROM TiposTarea TT
	INNER JOIN Tareas TA ON TA.IDTipo = TT.ID
	INNER JOIN Colaboraciones COL ON COL.IDTarea = TA.ID
	WHERE TT.Nombre LIKE '%Testing%' AND COL.IDColaborador = C.ID
) TESTING,
(	SELECT COUNT(TT.Nombre)
	FROM TiposTarea TT
	INNER JOIN Tareas TA ON TA.IDTipo = TT.ID
	INNER JOIN Colaboraciones COL ON COL.IDTarea = TA.ID
	WHERE TT.Nombre LIKE '%Programación%' AND COL.IDColaborador = C.ID
) PROGRAMACION
FROM Colaboradores C

--15 Listado apellido y nombres de los colaboradores que no hayan realizado tareas de 'Diseño de base de datos'.
SELECT C.Apellido, C.Nombre
FROM Colaboradores C
WHERE C.ID IN (
	SELECT COL.IDColaborador
	FROM Tareas TA
	INNER JOIN TiposTarea TT ON TT.ID = TA.IDTipo
	INNER JOIN Colaboraciones COL ON COL.IDTarea = TA.ID
	WHERE TT.Nombre NOT LIKE '%Diseño de base de datos%'
)

--16 Por cada país listar el nombre, la cantidad de clientes y la cantidad de colaboradores.
SELECT P.Nombre, (
	SELECT COUNT(C.ID)
	FROM Clientes C
	INNER JOIN Ciudades CIU ON CIU.ID = C.IDCiudad
	INNER JOIN Paises PA ON PA.ID = CIU.IDPais
	WHERE PA.ID = P.ID
) CLIENTES,
(
	SELECT COUNT(C.ID)
	FROM Colaboradores C
	INNER JOIN Ciudades CIU ON CIU.ID = C.IDCiudad
	INNER JOIN Paises PA ON PA.ID = CIU.IDPais
	WHERE PA.ID = P.ID
) COLABORADORES
FROM Paises P



USE BluePrint
SELECT * FROM Ciudades
SELECT * FROM Clientes
SELECT * FROM Colaboraciones
SELECT * FROM Colaboradores
SELECT * FROM Modulos
SELECT * FROM Paises
SELECT * FROM Proyectos
SELECT * FROM Tareas
SELECT * FROM TiposTarea
SELECT * FROM TiposCliente