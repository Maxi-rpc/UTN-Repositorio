--1 Por cada cliente listar razón social, cuit y nombre del tipo de cliente.
SELECT C.RazonSocial, C.CUIT, TP.Nombre AS TipoCliente 
FROM Clientes AS C JOIN TiposCliente AS TP ON C.IDTipo = TP.ID


--2 Por cada cliente listar razón social, cuit y nombre de la ciudad y nombre del país. Sólo de aquellos clientes que posean ciudad y país.
SELECT C.RazonSocial, C.CUIT, Ciud.Nombre AS Ciudad, Pai.Nombre AS Pais 
FROM Clientes AS C 
JOIN Ciudades AS Ciud ON C.IDCiudad = Ciud.ID
JOIN Paises AS Pai ON Ciud.IDPais = Pai.ID

--3 Por cada cliente listar razón social, cuit y nombre de la ciudad y nombre del país. Listar también los datos de aquellos clientes que no tengan ciudad relacionada.
SELECT C.RazonSocial, C.CUIT, Ciud.Nombre AS Ciudad, Pai.Nombre AS Pais 
FROM Clientes AS C 
LEFT JOIN Ciudades AS Ciud ON C.IDCiudad = Ciud.ID
LEFT JOIN Paises AS Pai ON Ciud.IDPais = Pai.ID

--4 Por cada cliente listar razón social, cuit y nombre de la ciudad y nombre del país. Listar también los datos de aquellas ciudades y países que no tengan clientes relacionados.
SELECT CL.RazonSocial, CL.CUIT, Ciud.Nombre AS Ciudad, Pai.Nombre AS Pais 
FROM Clientes AS CL 
RIGHT JOIN Ciudades AS Ciud ON CL.IDCiudad = Ciud.ID
RIGHT JOIN Paises AS Pai ON Ciud.IDPais = Pai.ID

--5 Listar los nombres de las ciudades que no tengan clientes asociados. Listar también el nombre del país al que pertenece la ciudad.
SELECT C.Nombre AS CIUDAD, P.Nombre AS PAIS
FROM Clientes AS CL
RIGHT JOIN Ciudades AS C ON C.ID = CL.IDCiudad
RIGHT JOIN Paises AS P ON P.ID = C.IDPais
WHERE CL.ID IS NULL

--6 Listar para cada proyecto el nombre del proyecto, el costo, la razón social del cliente, el nombre del tipo de cliente y el nombre de la ciudad (si la tiene registrada) de aquellos clientes cuyo tipo de cliente sea 'Extranjero' o 'Unicornio'.
SELECT PR.Nombre AS Proyecto, PR.CostoEstimado, CL.RazonSocial, C.Nombre AS Ciudad
FROM Proyectos AS PR
INNER JOIN Clientes AS CL ON CL.ID = PR.IDCliente
INNER JOIN Ciudades AS C ON C.ID = CL.IDCiudad
INNER JOIN TiposCliente AS T ON T.ID = CL.IDTipo
WHERE T.Nombre = 'Unicornio' OR T.Nombre = 'Extranjero'

--7 Listar los nombre de los proyectos de aquellos clientes que sean de los países 'Argentina' o 'Italia'.
SELECT PR.Nombre 
FROM Proyectos AS PR
INNER JOIN Clientes AS CL ON CL.ID = PR.IDCliente
INNER JOIN Ciudades AS C ON C.ID = CL.IDCiudad
INNER JOIN Paises AS P ON P.ID = C.IDPais
WHERE P.Nombre = 'Argentina' OR P.Nombre = 'Italia'

--8 Listar para cada módulo el nombre del módulo, el costo estimado del módulo, el nombre del proyecto, la descripción del proyecto y el costo estimado del proyecto de todos aquellos proyectos que hayan finalizado.
SELECT MO.Nombre, MO.CostoEstimado, PR.Nombre, PR.Descripcion, PR.CostoEstimado
FROM Modulos AS MO
INNER JOIN Proyectos AS PR ON PR.ID = MO.IDProyecto
WHERE PR.FechaFin IS NOT NULL

--9 Listar los nombres de los módulos y el nombre del proyecto de aquellos módulos cuyo tiempo estimado de realización sea de más de 100 horas.
SELECT MO.Nombre, PR.Nombre
FROM Modulos AS MO
INNER JOIN Proyectos AS PR ON PR.ID = MO.IDProyecto
WHERE MO.TiempoEstimado > 100

--10 Listar nombres de módulos, nombre del proyecto, descripción y tiempo estimado de aquellos módulos cuya fecha estimada de fin sea mayor a la fecha real de fin y el costo estimado del proyecto sea mayor a cien mil.
SELECT MO.Nombre, PR.Nombre, MO.Descripcion, MO.TiempoEstimado
FROM Modulos AS MO
INNER JOIN Proyectos AS PR ON PR.ID = MO.IDProyecto
WHERE MO.FechaEstimadaFin > MO.FechaFin AND MO.CostoEstimado > 1000

--11 Listar nombre de proyectos, sin repetir, que registren módulos que hayan finalizado antes que el tiempo estimado.
SELECT DISTINCT PR.Nombre AS Nombre
FROM Proyectos AS PR
INNER JOIN Modulos AS MO ON MO.IDProyecto = PR.ID
WHERE MO.FechaFin < MO.FechaEstimadaFin

--12 Listar nombre de ciudades, sin repetir, que no registren clientes pero sí colaboradores.

--13 Listar el nombre del proyecto y nombre de módulos de aquellos módulos que contengan la palabra 'login' en su nombre o descripción.
SELECT PR.Nombre, MO.Nombre
FROM Proyectos AS PR
INNER JOIN Modulos AS MO ON MO.IDProyecto = PR.ID
WHERE PR.Nombre LIKE '%login%' OR PR.Descripcion LIKE '%login%'

--14 Listar el nombre del proyecto y el nombre y apellido de todos los colaboradores que hayan realizado algún tipo de tarea cuyo nombre contenga 'Programación' o 'Testing'. Ordenarlo por nombre de proyecto de manera ascendente.
SELECT PR.Nombre AS Proyecto, COL.Nombre, COL.Apellido
FROM Proyectos AS PR
INNER JOIN Modulos AS MO ON MO.IDProyecto = PR.ID
INNER JOIN Tareas AS TA ON TA.IDModulo = MO.ID
INNER JOIN TiposTarea AS TT ON TT.ID = TA.IDTipo
INNER JOIN Colaboraciones AS CO ON CO.IDTarea = TA.ID
INNER JOIN Colaboradores AS COL ON COL.ID = CO.IDColaborador
WHERE TT.Nombre LIKE '%Programación%' OR TT.Nombre LIKE '%Testing%'
ORDER BY PR.Nombre ASC

--15 Listar nombre y apellido del colaborador, nombre del módulo, nombre del tipo de tarea, precio hora de la colaboración y precio hora base de aquellos colaboradores que hayan cobrado su valor hora de colaboración más del 50% del valor hora base.
SELECT COL.Nombre, COL.Apellido, MO.Nombre AS Modulo, TT.Nombre AS Tarea, CO.PrecioHora, TT.PrecioHoraBase
FROM Colaboradores AS COL
INNER JOIN Colaboraciones AS CO ON CO.IDColaborador = COL.ID
INNER JOIN Tareas AS TA ON TA.ID = CO.IDTarea
INNER JOIN Modulos AS MO ON MO.ID = TA.IDModulo
INNER JOIN TiposTarea AS TT ON TT.ID = TA.ID
WHERE CO.PrecioHora > (1.5 * TT.PrecioHoraBase)

--16 Listar nombres y apellidos de las tres colaboraciones de colaboradores externos que más hayan demorado en realizar alguna tarea cuyo nombre de tipo de tarea contenga 'Testing'.
SELECT TOP 3 C.Nombre, C.Apellido
FROM Colaboradores AS C
INNER JOIN Colaboraciones AS COL ON COL.IDColaborador = C.ID
INNER JOIN Tareas AS T ON T.ID = COL.IDTarea
INNER JOIN TiposTarea AS TT ON TT.ID = T.IDTipo
WHERE C.Tipo ='E' AND TT.Nombre LIKE '%Testing%'
ORDER BY COL.Tiempo DESC

--17 Listar apellido, nombre y mail de los colaboradores argentinos que sean internos y cuyo mail no contenga '.com'.
SELECT C.Apellido, C.Nombre, C.EMail
FROM Colaboradores AS C
INNER JOIN Ciudades AS CI ON CI.ID = C.IDCiudad
INNER JOIN Paises AS PA ON PA.ID = CI.IDPais
WHERE C.Tipo = 'I' AND C.EMail NOT LIKE '%.COM' AND PA.Nombre LIKE 'Argentina'

--18 Listar nombre del proyecto, nombre del módulo y tipo de tarea de aquellas tareas realizadas por colaboradores externos.
SELECT PR.Nombre, MO.Nombre AS Modulo, TT.Nombre AS TipoTarea
FROM Proyectos AS PR
INNER JOIN Modulos AS MO ON MO.IDProyecto = PR.ID
INNER JOIN Tareas AS TA ON TA.IDModulo = MO.ID
INNER JOIN TiposTarea AS TT ON TT.ID = TA.IDTipo
INNER JOIN Colaboraciones AS CO ON CO.IDTarea = TA.ID
INNER JOIN Colaboradores AS COL ON COL.ID = CO.IDColaborador
WHERE COL.Tipo LIKE 'E'

--19 Listar nombre de proyectos que no hayan registrado tareas.
SELECT PR.Nombre
FROM Proyectos AS PR
INNER JOIN Modulos AS MO ON MO.IDProyecto = PR.ID
FULL JOIN Tareas AS TA ON TA.IDModulo = MO.ID
WHERE TA.IDModulo IS NULL

--20 Listar apellidos y nombres, sin repeticiones, de aquellos colaboradores que hayan trabajado en algún proyecto que aún no haya finalizado.
SELECT DISTINCT C.Apellido, C.Nombre
FROM Colaboradores AS C
INNER JOIN Colaboraciones AS CO ON CO.IDColaborador = C.ID
INNER JOIN Tareas AS T ON T.ID = CO.IDTarea
INNER JOIN Modulos AS M ON M.ID = T.IDModulo
INNER JOIN Proyectos AS P ON P.ID = M.IDProyecto
WHERE P.FechaFin IS NULL

USE BluePrint
SELECT * FROM Ciudades
SELECT * FROM Clientes
SELECT * FROM Colaboraciones
SELECT * FROM Colaboradores
SELECT * FROM Modulos
SELECT * FROM Paises
SELECT * FROM Proyectos
SELECT * FROM Tareas
SELECT * FROM TiposCliente
SELECT * FROM TiposTarea


