--A  Cuando se registre un usuario a LaraBox y este haya sido invitado por otro usuario, 
--este último reciba una bonificación de 100 Megabytes en su espacio total de almacenamiento.
--En cualquier caso (invitado o no), la cuenta a registrar debe establecer el tamaño total
--de almacenamiento a partir del Tipo de cuenta asignado.
CREATE TRIGGER TR_A ON Usuarios
INSTEAD OF INSERT AS
BEGIN
	BEGIN TRY
		--TOMO DATOS
		DECLARE @ID BIGINT
		DECLARE @IDUREF BIGINT
		DECLARE @NOMBREU VARCHAR(50)
		DECLARE @ESPACIO BIGINT
		DECLARE @IDTIPO INT
		DECLARE @ESTADO BIT
		--SELECCION
		SELECT @ID = I.ID, @IDUREF = I.IDUsuarioReferencia, @NOMBREU = I.Nombreusuario, @IDTIPO = I.IDTipo, @ESPACIO = TC.CapacidadAlmacenamiento, @ESTADO = I.Estado 
		FROM inserted I
		INNER JOIN TiposCuenta TC ON TC.ID = I.IDTipo

		--VERIFICO SI TIENE REFERENCIA
		DECLARE @BREF BIGINT
		SELECT @BREF = U.ID FROM Usuarios U WHERE U.ID = @IDUREF
		IF(@BREF = @IDUREF)BEGIN
			SELECT @ESPACIO = @ESPACIO + 100
		END
		INSERT INTO Usuarios (NombreUsuario, IDUsuarioReferencia, Espacio, IDTipo, Estado)
		values (@NOMBREU, @IDUREF, @ESPACIO, @IDTIPO, @ESTADO)
	END TRY
	BEGIN CATCH
	END CATCH
END

DROP TRIGGER TR_A
--PRUEBA
Insert into Usuarios (NombreUsuario, IDUsuarioReferencia, Espacio, IDTipo, Estado)
values  ('TEST10', NULL, 10000, 1, 1)

--B Cuando se registre un archivo en la base de datos, 
-- primero verificar que la cuenta asociada a dicho archivo tenga espacio suficiente para alojarlo. 
--También, tener en cuenta que sólo los usuarios con cuenta Iridio podrán registrar archivos con extensión LARA y KLOSTER.
--Mostrar un mensaje aclaratorio dependiendo del error ocurrido o registrar el archivo.
CREATE TRIGGER TR_B ON Archivos
AFTER INSERT AS
BEGIN
	BEGIN TRY
		--DATOS
		DECLARE @ID BIGINT
		DECLARE @IDUSER BIGINT
		DECLARE @IDTIPO INT
		DECLARE @ARCTAM BIGINT
		SELECT @ID = I.ID, @IDUSER = I.IDUsuario, @ARCTAM = I.Tamaño, @IDTIPO = I.IDTipo FROM inserted I
		--BUSCO EXT
		DECLARE @EXT VARCHAR(10)
		SELECT @EXT = TA.Extension FROM TiposArchivo TA WHERE TA.ID = @IDTIPO
		--BUSCO ALM Y CUENTA
		DECLARE @ESPACIOACTUAL BIGINT
		DECLARE @TPCUENTA INT
		DECLARE @CUDESC VARCHAR(100)
		DECLARE @ALMMAX BIGINT
		SELECT @ESPACIOACTUAL = SUM(A.Tamaño), @TPCUENTA = TC.ID, @CUDESC = TC.Descripcion, @ALMMAX = TC.CapacidadAlmacenamiento
		FROM Archivos A
		INNER JOIN Usuarios U ON U.ID = A.IDUsuario
		INNER JOIN TiposCuenta TC ON TC.ID = U.IDTipo
		WHERE U.ID = @IDUSER
		GROUP BY U.ID, TC.Descripcion, TC.ID, U.ID, TC.CapacidadAlmacenamiento

		--VERIFICO
		DECLARE @BAR INT
		DECLARE @BES BIT
		IF(@EXT LIKE 'LARA' AND @CUDESC NOT LIKE 'Iridio') BEGIN
			DELETE Archivos WHERE ID = @ID
			SELECT @BAR = 1
			RAISERROR('ERROR TIPO DE ARCHIVO LARA NO ACEPTADO EN LA CUENTA',16,1)
		END
		IF(@EXT LIKE 'KLOSTER' AND @CUDESC NOT LIKE 'Iridio') BEGIN
			DELETE Archivos WHERE ID = @ID
			SELECT @BAR = 2
			RAISERROR('ERROR TIPO DE ARCHIVO KLOSTER NO ACEPTADO EN LA CUENTA',16,1)
		END
		IF(@ALMMAX < @ESPACIOACTUAL) BEGIN
			DELETE Archivos WHERE ID = @ID
			SELECT @BES = 1
			RAISERROR('ERROR EL PESO DEL ARCHIVO SUPERA EL LIMITE',16,1)	
		END
	END TRY
	BEGIN CATCH
		IF(@BES = 1) BEGIN
			RAISERROR('ERROR EL PESO DEL ARCHIVO SUPERA EL LIMITE',16,1)
		END
		IF(@BAR = 1) BEGIN
			RAISERROR('ERROR TIPO DE ARCHIVO LARA NO ACEPTADO EN LA CUENTA',16,1)
		END
		IF(@BAR = 2) BEGIN
			RAISERROR('ERROR TIPO DE ARCHIVO KLOSTER NO ACEPTADO EN LA CUENTA',16,1)
		END
	END CATCH
END

DROP TRIGGER TR_B
Insert Into Archivos (IDTipo, IDUsuario, Nombre, FechaCreacion, Tamaño, Estado)
values (4, 4, 'Final TEST 2', '1/6/2020', 10, 1)

-- C Realizar un procedimiento almacenado que a partir de un IDUsuario válido en LaraBox 
--se puedan visualizar todos los archivos de dicha cuenta. Se deberá incluir en el listado: 
--Nombre de usuario, descripción del tipo de archivo, extensión del archivo, nombre del archivo, 
--fecha de creación, tamaño del archivo y porcentaje de ocupación*

--*El porcentaje de ocupación consiste en cuánto ocupa dicho archivo (porcentualmente) 
--en la cuenta del usuario. Por ejemplo, si el usuario tiene un almacenamiento total de 50 Megabytes y
--el archivo ocupa 10 Megabytes, entonces su porcentaje de ocupación es (10 MB * 100 )/50 MB → 20 %

CREATE PROCEDURE SP_C(
	@IDUSER BIGINT
)AS
BEGIN
	SELECT U.Nombreusuario, TA.Descripcion, TA.Extension, AR.Nombre, AR.FechaCreacion, AR.Tamaño, (AR.Tamaño*100) / U.Espacio PORCENTAJE
	FROM Usuarios U
	INNER JOIN Archivos AR ON AR.IDUsuario = U.ID
	INNER JOIN TiposArchivo TA ON TA.ID = AR.IDTipo
	WHERE U.ID = @IDUSER
END

EXEC SP_C 1
DROP PROCEDURE SP_C

--D Cuando se elimine un usuario, realizar la baja lógica en cascada del usuario y 
-- de todos los archivos que el usuario posea si la cuenta es de tipo Iridio, Oro o Plata. 
--En caso de ser de tipo Free o Cobre se realizará la baja física de los archivos y de la cuenta del usuario.
CREATE TRIGGER TR_D ON Usuarios
INSTEAD OF DELETE AS
BEGIN
	BEGIN TRY
		--DATOS
		DECLARE @ID BIGINT
		DECLARE @IDTIPO INT
		SELECT @ID = ID, @IDTIPO = IDTipo FROM deleted
		--BUSCO CUENTA
		DECLARE @CUENT VARCHAR(100)
		SELECT @CUENT = TC.Descripcion FROM TiposCuenta TC WHERE TC.ID = @IDTIPO
		--VERIFICO
		IF(@CUENT LIKE 'Iridio' OR @CUENT LIKE 'Oro' OR @CUENT LIKE 'Plata') BEGIN
			UPDATE Archivos SET Estado = 0 WHERE IDUsuario = @ID
		END
		ELSE BEGIN
			DELETE FROM Archivos WHERE IDUsuario IN (SELECT ID FROM deleted)
			DELETE FROM Usuarios WHERE ID = @ID
		END

	END TRY
	BEGIN CATCH
	END CATCH
END
DROP TRIGGER TR_D
DELETE Usuarios WHERE ID = 1
UPDATE Archivos SET Estado = 1


-- UTILES
USE Examen
SELECT * FROM Archivos
SELECT * FROM Usuarios
SELECT * FROM TiposCuenta
SELECT * FROM TiposArchivo

SELECT U.ID, U.IDTipo, TP.Descripcion, TP.CapacidadAlmacenamiento FROM Usuarios U
INNER JOIN TiposCuenta TP ON TP.ID = U.IDTipo

SELECT SUM(A.Tamaño), TC.Descripcion, TC.ID, U.ID, TC.CapacidadAlmacenamiento
FROM Archivos A
INNER JOIN Usuarios U ON U.ID = A.IDUsuario
INNER JOIN TiposCuenta TC ON TC.ID = U.IDTipo
WHERE U.ID = 1
GROUP BY U.ID, TC.Descripcion, TC.ID, U.ID, TC.CapacidadAlmacenamiento

SELECT U.ID, AR.ID, AR.Estado FROM TiposCuenta TC
INNER JOIN Usuarios U ON U.IDTipo = TC.ID
INNER JOIN Archivos AR ON AR.IDUsuario = U.ID
WHERE TC.Descripcion LIKE 'Iridio'

SELECT U.Nombreusuario, TA.Descripcion, TA.Extension, AR.Nombre, AR.FechaCreacion, AR.Tamaño, (AR.Tamaño*100) / (
	SELECT SUM(ARC.Tamaño)
	FROM Archivos ARC
	WHERE ARC.IDUsuario = U.ID
) PORCENTAJE
FROM Usuarios U
INNER JOIN Archivos AR ON AR.IDUsuario = U.ID
INNER JOIN TiposArchivo TA ON TA.ID = AR.IDTipo
WHERE U.ID = 1