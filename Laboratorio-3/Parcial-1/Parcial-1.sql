-- 1 Listado con Apellido y nombres de los técnicos que hayan prestado servicios a más de veinte clientes distintos
SELECT TE.Apellido, TE.Nombre
FROM Tecnicos AS TE
WHERE (
SELECT COUNT(DISTINCT S.IDCliente)
FROM Servicios AS S
INNER JOIN Tecnicos AS T ON T.ID = S.IDTecnico
WHERE T.ID = TE.ID
) > 20


--2 Listado con ID, Apellido y nombres de los clientes que no hayan solicitado servicios de tipo "Reparacion de lavarropas" en el año 2020.
SELECT C.ID, C.Apellido, C.Nombre
FROM Clientes AS C
INNER JOIN Servicios AS S ON S.IDCliente = C.ID
INNER JOIN TiposServicio AS TS ON TS.ID = S.IDTipo
WHERE TS.Descripcion NOT LIKE 'Reparacion de lavarropas' AND YEAR(S.Fecha) = '2020'

--3 Listado con Apellido y nombres de los clientes, cantidad de servicios solicitados con garantía y cantidad de servicios solicitados sin garantía.SELECT C.Apellido, C.Nombre, (
SELECT COUNT(S.ID)
FROM Clientes AS CL
INNER JOIN Servicios AS S ON S.IDCliente = CL.ID
WHERE S.DiasGarantia > 0 AND CL.ID = C.ID
) AS ConGarantia, (
SELECT COUNT(S.ID)
FROM Clientes AS CL
INNER JOIN Servicios AS S ON S.IDCliente = CL.ID
WHERE S.DiasGarantia = 0 AND CL.ID = C.ID
) AS SinGarantia
FROM Clientes AS C

--4 Apellido y nombres de los técnicos que recaudaron más en servicios abonados en tarjeta que servicios abonados con efectivo. Pero que hayan recaudado con efectivo
--más de la mitad de su recaudación con tarjeta.SELECT TECNICO.Apellido, TECNICO.Nombre
FROM (
	SELECT TEC.Apellido, TEC.Nombre, (
	SELECT SUM(S.Importe)
	FROM Tecnicos AS T
	INNER JOIN Servicios AS S ON S.IDTecnico = T.ID
	WHERE S.FormaPago = 'T' AND T.ID = TEC.ID
	) AS Tarjeta, (
	SELECT SUM(S.Importe)
	FROM Tecnicos AS T
	INNER JOIN Servicios AS S ON S.IDTecnico = T.ID
	WHERE S.FormaPago = 'E' AND T.ID = TEC.ID
	) AS Efectivo
FROM Tecnicos AS TEC ) TECNICO
WHERE Tarjeta > Efectivo AND Efectivo > Tarjeta/2

--5 Agregar las tablas y/o restricciones que considere necesario para permitir a los
--técnicos registrar todos los insumos que le fueron necesarios para realizar un
--servicio. Por cada insumo necesario se registrará una descripción, un costo y un
--origen del insumo (I - Importado o N - Nacional)
CREATE TABLE Insumos(
	ID int Primary Key Identity (1,1),
	IDServicio int NOT NULL foreign Key Reference Servicios(ID)
	Descripcion varchar(50) NOT NULL,
	Costo money NOT NULL check(Costo >= 0),
	Orgien char NOT NULL check(Origen = 'I' or Origen = 'N') 
)


USE parcial1

SELECT * FROM Clientes
SELECT * FROM Tecnicos
SELECT * FROM Servicios
SELECT * FROM TiposServicio