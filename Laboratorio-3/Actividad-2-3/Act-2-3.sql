--1 La cantidad de colaboradores
SELECT COUNT(*) AS CantidadColaboradores
FROM Colaboradores

--2 La cantidad de colaboradores nacidos entre 1990 y 2000.
SELECT COUNT(FechaNacimiento) AS NacidosEntre
FROM Colaboradores
WHERE FechaNacimiento BETWEEN '1990' AND '2000'

--3 El promedio de precio hora base de los tipos de tareas
SELECT AVG(PrecioHoraBase) AS Promedio
FROM TiposTarea

--4 El promedio de costo de los proyectos iniciados en el año 2019
SELECT AVG(CostoEstimado) AS Costo
FROM Proyectos
WHERE YEAR(FechaInicio) = 2019

--5 El costo más alto entre los proyectos de clientes de tipo 'Unicornio'
SELECT MAX(P.CostoEstimado) AS CostoAlto
FROM Proyectos AS P
INNER JOIN Clientes AS C ON C.ID = P.IDCliente
INNER JOIN TiposCliente AS TC ON TC.ID = C.IDTipo
WHERE TC.Nombre LIKE 'Unicornio'

--6 El costo más bajo entre los proyectos de clientes del país 'Argentina'
SELECT MIN(P.CostoEstimado) AS CostoBajo
FROM Proyectos AS P
INNER JOIN Clientes AS C ON C.ID = P.IDCliente
INNER JOIN Ciudades AS CI ON CI.ID = C.IDCiudad
INNER JOIN Paises AS PA ON PA.ID = CI.IDPais
WHERE PA.Nombre LIKE 'Argentina'

--7 La suma total de los costos estimados entre todos los proyectos
SELECT SUM(CostoEstimado) AS Suma 
FROM Proyectos

--8 Por cada ciudad, listar el nombre de la ciudad y la cantidad de clientes.
SELECT C.Nombre, COUNT(*) AS Clientes
FROM Ciudades AS C
INNER JOIN Clientes AS CL ON CL.IDCiudad = C.ID
GROUP BY C.Nombre

--9 Por cada país, listar el nombre del país y la cantidad de clientes.
SELECT P.Nombre, COUNT(*) AS Clientes
FROM Paises AS P
INNER JOIN Ciudades AS CI ON CI.IDPais = P.ID
INNER JOIN Clientes AS C ON C.IDCiudad = CI.ID
GROUP BY P.Nombre

--10 Por cada tipo de tarea, la cantidad de colaboraciones registradas. Indicar el tipo de tarea y la cantidad calculada.
SELECT TT.Nombre, COUNT(*) AS CantidadColaboraciones
FROM TiposTarea AS TT
INNER JOIN Tareas AS TA ON TA.IDTipo = TT.ID
INNER JOIN Colaboraciones AS CO ON CO.IDTarea = TA.ID
GROUP BY TT.Nombre

--11 Por cada tipo de tarea, la cantidad de colaboradores distintos que la hayan realizado. Indicar el tipo de tarea y la cantidad calculada.
SELECT TT.Nombre, COUNT(DISTINCT COL.ID) AS Colaboradores
FROM TiposTarea AS TT
INNER JOIN Tareas AS TA ON TA.IDTipo = TT.ID
INNER JOIN Colaboraciones AS CO ON CO.IDTarea = TA.ID
INNER JOIN Colaboradores AS COL ON COL.ID = CO.IDColaborador
GROUP BY TT.Nombre

--12 Por cada módulo, la cantidad total de horas trabajadas. Indicar el ID, 
--nombre del módulo y la cantidad totalizada. Mostrar los módulos sin horas registradas con 0.
SELECT M.ID, M.Nombre, ISNULL(SUM(CO.Tiempo),0) AS HORAS
FROM MODULOS AS M
LEFT JOIN Tareas AS TA ON TA.IDModulo = M.ID
LEFT JOIN Colaboraciones AS CO ON CO.IDTarea = TA.ID
GROUP BY M.ID, M.Nombre

--13 Por cada módulo y tipo de tarea, el promedio de horas trabajadas. 
--Indicar el ID y nombre del módulo, el nombre del tipo de tarea y el total calculado.
SELECT M.ID, M.Nombre, TT.Nombre, AVG(CO.Tiempo) AS TOTALCALCULADO
FROM MODULOS AS M
INNER JOIN Tareas AS TA ON TA.IDModulo = M.ID
INNER JOIN TiposTarea AS TT ON TT.ID = TA.IDTipo
INNER JOIN Colaboraciones AS CO ON CO.IDTarea = TA.ID
GROUP BY M.ID, M.Nombre, TT.Nombre

--14 Por cada módulo, indicar su ID, apellido y nombre del colaborador y 
--total que se le debe abonar en concepto de colaboraciones realizadas en dicho módulo
SELECT M.ID, COL.Apellido, COL.Nombre, SUM(CO.PrecioHora * CO.Tiempo) AS TOTAL
FROM Modulos AS M
INNER JOIN Tareas AS TA ON TA.IDModulo = M.ID
INNER JOIN Colaboraciones AS CO ON CO.IDTarea = TA.ID
INNER JOIN Colaboradores AS COL ON COL.ID = CO.IDColaborador
GROUP BY M.ID, COL.Apellido, COL.Nombre

--15 Por cada proyecto indicar el nombre del proyecto y la cantidad de horas 
--registradas en concepto de colaboraciones y el total que debe abonar en concepto de colaboraciones.
SELECT P.Nombre, SUM(CO.Tiempo) AS COLTIEMPO, SUM(CO.Tiempo * CO.PrecioHora) AS TOTALABONAR
FROM Proyectos AS P
INNER JOIN Modulos AS MO ON MO.IDProyecto = P.ID
INNER JOIN Tareas AS TA ON TA.IDModulo = MO.ID
INNER JOIN Colaboraciones AS CO ON CO.IDTarea = TA.ID
GROUP BY P.Nombre

--16 Listar los nombres de los proyectos que hayan registrado menos de cinco colaboradores distintos 
--y más de 100 horas total de trabajo.
SELECT P.Nombre
FROM Proyectos AS P
INNER JOIN Modulos AS MO ON MO.IDProyecto = P.ID
INNER JOIN Tareas AS TA ON TA.IDModulo = MO.ID
INNER JOIN Colaboraciones AS CO ON CO.IDTarea = TA.ID
GROUP BY P.Nombre
HAVING COUNT(CO.IDColaborador) < 5 AND SUM(CO.Tiempo) > 100

--17 Listar los nombres de los proyectos que hayan comenzado en el año 2020 que hayan registrado más de tres módulos.
SELECT P.Nombre
FROM Proyectos AS P
INNER JOIN Modulos AS MO ON MO.IDProyecto = P.ID
WHERE YEAR(MO.FechaInicio) = '2020'
GROUP BY P.Nombre
HAVING COUNT(MO.ID) > 3

--18 Listar para cada colaborador externo, el apellido y nombres y el tiempo máximo de horas que ha trabajo en una colaboración.
SELECT C.Nombre, C.Apellido, MAX(CO.Tiempo) AS MAXIMO
FROM Colaboradores AS C
INNER JOIN Colaboraciones AS CO ON CO.IDColaborador = C.ID
WHERE C.Tipo LIKE 'E'
GROUP BY C.Nombre, C.Apellido
ORDER BY C.Nombre ASC

--19 Listar para cada colaborador interno, el apellido y nombres y el promedio percibido en concepto de colaboraciones.
SELECT C.Apellido, C.Nombre, AVG(CO.Tiempo*CO.PrecioHora) PROMEDIO
FROM Colaboradores AS C
INNER JOIN Colaboraciones AS CO ON CO.IDColaborador = C.ID
WHERE C.Tipo LIKE 'I'
GROUP BY C.Nombre, C.Apellido
ORDER BY C.Nombre ASC

--20 Listar el promedio percibido en concepto de colaboraciones para colaboradores internos 
--y el promedio percibido en concepto de colaboraciones para colaboradores externos.
SELECT C.Tipo, AVG(CO.Tiempo*CO.PrecioHora) PROMEDIO
FROM Colaboradores AS C
INNER JOIN Colaboraciones AS CO ON CO.IDColaborador = C.ID
GROUP BY C.Tipo

--21 Listar el nombre del proyecto y el total neto estimado. 
--Este último valor surge del costo estimado menos los pagos que requiera hacer en concepto de colaboraciones.
SELECT P.Nombre, SUM(P.CostoEstimado - (CO.PrecioHora * CO.Tiempo) ) AS TOTALNETO
FROM Proyectos AS P
INNER JOIN Modulos AS MO ON MO.IDProyecto = P.ID
INNER JOIN Tareas AS TA ON TA.IDModulo = MO.ID
INNER JOIN Colaboraciones AS CO ON CO.IDTarea = TA.ID
GROUP BY P.Nombre

--22 Listar la cantidad de colaboradores distintos que hayan colaborado 
--en alguna tarea que correspondan a proyectos de clientes de tipo 'Unicornio'.
SELECT COUNT(DISTINCT(C.ID)) AS CANTIDAD
FROM Colaboradores AS C
INNER JOIN Colaboraciones AS CO ON CO.IDColaborador = C.ID
INNER JOIN Tareas AS TA ON TA.ID = CO.IDTarea
INNER JOIN Modulos AS MO ON MO.ID = TA.IDModulo
INNER JOIN Proyectos AS PR ON PR.ID = MO.IDProyecto
INNER JOIN Clientes AS CL ON CL.ID = PR.IDCliente
INNER JOIN TiposCliente AS TC ON TC.ID = CL.IDTipo
WHERE TC.Nombre LIKE 'Unicornio'

--23 La cantidad de tareas realizadas por colaboradores del país 'Argentina'.
SELECT COUNT(DISTINCT(T.ID))
FROM Tareas AS T
INNER JOIN Colaboraciones AS CO ON CO.IDTarea = T.ID
INNER JOIN Colaboradores AS COL ON COL.ID = CO.IDColaborador
INNER JOIN Ciudades AS CI ON CI.ID = COL.IDCiudad
INNER JOIN Paises AS PA ON PA.ID = CI.IDPais
WHERE PA.Nombre LIKE 'Argentina'

--24 Por cada proyecto, la cantidad de módulos que se haya estimado mal la fecha de fin. 
--Es decir, que se haya finalizado antes o después que la fecha estimada. Indicar el nombre del proyecto y la cantidad calculada.
SELECT P.Nombre, COUNT(MO.ID) AS CANT
FROM Proyectos AS P
INNER JOIN Modulos AS MO ON MO.IDProyecto = P.ID
WHERE MO.FechaEstimadaFin > MO.FechaFin OR MO.FechaEstimadaFin < MO.FechaFin
GROUP BY P.Nombre

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
