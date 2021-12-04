--1 Hacer un trigger que al ingresar una colaboración obtenga el precio de la misma a partir 
--del precio hora base del tipo de tarea. Tener en cuenta que si el colaborador es externo el costo debe ser un 20% más caro.
CREATE TRIGGER EJ1 ON Colaboraciones
AFTER INSERT AS 
BEGIN
	BEGIN TRY
		DECLARE @IDTAREA INT
		DECLARE @IDECOL INT
		SELECT @IDTAREA = IDTarea, @IDECOL = IDColaborador FROM inserted

		DECLARE @PRECIO MONEY
		SELECT @PRECIO = TT.PrecioHoraBase FROM TiposTarea TT
		INNER JOIN Tareas TA ON TA.IDTipo = TT.ID
		WHERE TA.ID = @IDTAREA

		DECLARE @TIPOCOL CHAR(1)
		SELECT @TIPOCOL = COLA.Tipo FROM Colaboradores COLA
		WHERE COLA.ID = @IDECOL

		IF(@TIPOCOL LIKE 'E') BEGIN
			SELECT @PRECIO = @PRECIO * 1.2
			UPDATE Colaboraciones SET PrecioHora = @PRECIO WHERE IDColaborador = @IDECOL AND IDTarea = @IDTAREA
		END
	
	END TRY
	BEGIN CATCH
		RAISERROR('ERROR',16,1)
	END CATCH
END

--2 Hacer un trigger que no permita que un colaborador registre más de 15 tareas en un mismo mes.
--De lo contrario generar un error con un mensaje aclaratorio.
CREATE TRIGGER EJ2 ON Colaboraciones
AFTER INSERT AS
BEGIN
	BEGIN TRY 
		DECLARE @IDTAREA INT
		DECLARE @IDCOLA INT
		SELECT @IDTAREA = IDTarea, @IDCOLA = IDColaborador FROM inserted

		DECLARE @FECHATAR DATE
		SELECT @FECHATAR = TA.FechaInicio FROM Tareas TA WHERE TA.ID = @IDTAREA

		DECLARE @CANT INT
		SELECT @CANT = COUNT(COLA.IDColaborador)
		FROM Colaboraciones COLA
		INNER JOIN Tareas TA ON TA.ID = @IDTAREA
		WHERE MONTH(TA.FechaInicio) = MONTH(@FECHATAR) AND YEAR(TA.FechaInicio) = YEAR(@FECHATAR)

		IF(@CANT > 15) BEGIN
			DELETE Colaboraciones WHERE IDColaborador = @IDCOLA AND IDTarea = @IDTAREA
			RAISERROR('COLABORADOR SUPERA LAS 15 TAREAS EN EL MES',16,1)
		END
	END TRY
	BEGIN CATCH
		RAISERROR('COLABORADOR SUPERA LAS 15 TAREAS EN EL MES',16,1)
	END CATCH
END

--3 Hacer un trigger que al ingresar una tarea cuyo tipo contenga el nombre 'Programación' 
--se agreguen automáticamente dos tareas de tipo 'Testing unitario' y 'Testing de integración' 
--de 4 horas cada una. La fecha de inicio y fin de las mismas debe ser NULL. Calcular el costo estimado de la tarea.
CREATE TRIGGER EJ3 ON Tareas
AFTER INSERT AS
BEGIN
	BEGIN TRY
		DECLARE @IDTAREA INT
		DECLARE @IDMODULO INT
		DECLARE @IDTIPO INT
		SELECT @IDTAREA = ID, @IDMODULO = IDModulo, @IDTIPO = IDTipo FROM inserted

		DECLARE @TAREANOMBRE VARCHAR(50)
		SELECT @TAREANOMBRE = TT.Nombre FROM TiposTarea TT WHERE TT.ID = @IDTIPO

		IF(@TAREANOMBRE LIKE 'Programación') BEGIN
			INSERT INTO Tareas(IDModulo,IDTipo,FechaInicio,FechaFin,Estado) 
			VALUES(@IDMODULO, 10, NULL, NULL, 1)
			INSERT INTO Tareas(IDModulo,IDTipo,FechaInicio,FechaFin,Estado) 
			VALUES(@IDMODULO, 11, NULL, NULL, 1)
		END
	END TRY
	BEGIN CATCH
		RAISERROR('ERROR',16,1)
	END CATCH
END

SELECT * FROM TiposTarea WHERE Nombre LIKE '%Testing unitario%'
SELECT * FROM TiposTarea WHERE Nombre LIKE '%Testing de integración%'

--4 Hacer un trigger que al borrar una tarea realice una baja lógica de la misma en lugar de una baja física.
CREATE TRIGGER EJ4 ON Tareas
INSTEAD OF DELETE AS
BEGIN
	BEGIN TRY
		DECLARE @IDTAREA INT
		SELECT @IDTAREA = ID FROM deleted

		UPDATE Tareas SET Estado = 0 WHERE ID = @IDTAREA
	END TRY
	BEGIN CATCH
		RAISERROR('ERROR',16,1)
	END CATCH
END

--5 Hacer un trigger que al borrar un módulo realice una baja lógica del mismo en lugar de una baja física. 
-- Además, debe borrar todas las tareas asociadas al módulo.
CREATE TRIGGER EJ5 ON Modulos
INSTEAD OF DELETE AS
BEGIN
	BEGIN TRY
		DECLARE @IDMOD INT
		SELECT @IDMOD = ID FROM deleted

		UPDATE Modulos SET Estado = 0 WHERE ID = @IDMOD
		UPDATE Tareas SET Estado = 0 WHERE Tareas.IDModulo = @IDMOD

	END TRY
	BEGIN CATCH
		RAISERROR('ERROR',16,1)
	END CATCH
END

--6 Hacer un trigger que al borrar un proyecto realice una baja lógica del mismo en lugar de una baja física. 
--Además, debe borrar todas los módulos asociados al proyecto.
CREATE TRIGGER EJ6 ON Proyectos
INSTEAD OF DELETE AS
BEGIN
	BEGIN TRY
		DECLARE @IDPR INT
		SELECT @IDPR = ID FROM deleted

		UPDATE Proyectos SET Estado = 0 WHERE ID = @IDPR
		UPDATE Modulos SET Estado = 0 WHERE IDProyecto = @IDPR

	END TRY
	BEGIN CATCH
		RAISERROR('ERROR',16,1)
	END CATCH
END

--7 Hacer un trigger que si se agrega una tarea cuya fecha de fin es mayor a 
--la fecha estimada de fin del módulo asociado a la tarea entonces se modifique la fecha estimada de fin en el módulo.
CREATE TRIGGER EJ7 ON Tareas
AFTER INSERT AS
BEGIN
	BEGIN TRY
		DECLARE @ID INT
		DECLARE @FFIN DATE
		DECLARE @IDMOD INT
		SELECT @ID = ID, @FFIN = FechaFin, @IDMOD = IDModulo FROM inserted

		DECLARE @FFINMOD DATE
		SELECT @FFINMOD = FechaEstimadaFin FROM Modulos WHERE ID = @IDMOD

		IF(@FFIN > @FFINMOD) BEGIN
			UPDATE Modulos SET FechaEstimadaFin = @FFIN WHERE ID = @IDMOD
		END
	END TRY
	BEGIN CATCH
		RAISERROR('ERROR',16,1)
	END CATCH
END

--8 Hacer un trigger que al borrar una tarea que previamente se ha dado de baja lógica realice la baja física de la misma.
CREATE TRIGGER EJ8 ON Tareas
INSTEAD OF DELETE AS
BEGIN
	BEGIN TRY
		DECLARE @ID INT
		SELECT @ID = ID FROM deleted
		DECLARE @EACTUAL BIT
		SELECT @EACTUAL = TA.Estado FROM Tareas TA WHERE TA.ID = @ID

		IF(@EACTUAL = 1) BEGIN
			UPDATE Tareas SET Estado = 0 WHERE ID = @ID
		END
		ELSE BEGIN
			IF(@EACTUAL = 0) BEGIN
				DELETE FROM Tareas WHERE ID = @ID
			END
		END

	END TRY
	BEGIN CATCH
		RAISERROR('ERROR',16,1)
	END CATCH
END

--9 Hacer un trigger que al ingresar una colaboración no permita que el colaborador/a 
--superponga las fechas con las de otras colaboraciones que se les hayan asignado anteriormente. 
--En caso contrario, registrar la colaboración sino generar un error con un mensaje aclaratorio.
CREATE TRIGGER EJ9 ON Colaboraciones
AFTER INSERT AS
BEGIN
	BEGIN TRY
		DECLARE @IDCOL INT
		DECLARE @IDTAR INT
		SELECT @IDCOL = IDColaborador, @IDTAR = IDTarea FROM inserted

		DECLARE @FECHA DATE
		SELECT 


	END TRY
	BEGIN CATCH
		RAISERROR('ERROR NO PUEDE REGISTRAR EN LA MISMA FECHA',16,1)
	END CATCH
END

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