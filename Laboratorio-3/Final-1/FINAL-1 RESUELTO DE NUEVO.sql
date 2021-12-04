--1 Hacer un trigger que no permita que un camión realice un viaje de más de 500
--kilómetros si la antigüedad del mismo es mayor a 5 años. Mostrar un mensaje de
--error aclaratorio, sino insertar el registro. La antigüedad se calcula a partir del año de
--patentamiento
CREATE TRIGGER TR_VIAJES1 ON Viajes
AFTER INSERT AS
BEGIN
	BEGIN TRY
		DECLARE @IDV BIGINT
		DECLARE @IDCHOFER INT
		DECLARE @IDCAM VARCHAR(4)
		DECLARE @KM INT
		SELECT @IDV = ID, @IDCHOFER = IDChofer, @IDCAM = IDCamion, @KM = Kilometros FROM inserted

		DECLARE @ANTIG SMALLINT
		SELECT @ANTIG = (YEAR(GETDATE()) - C.AñoPatentamiento) FROM Camiones C WHERE C.ID = @IDCAM

		IF(@KM > 500 AND @ANTIG > 5) BEGIN
			RAISERROR('ERROR AL INSERTAR TIENE MAS DE 500 KM Y ANTIGUEDAD MAYOR A 5',16,1)
			DELETE FROM Viajes WHERE ID = @IDV 
		END
	END TRY
	BEGIN CATCH
			RAISERROR('ERROR AL INSERTAR TIENE MAS DE 500 KM Y ANTIGUEDAD MAYOR A 5',16,1)
	END CATCH
END
--PRUEBA
INSERT INTO Viajes (Fecha,IDChofer,IDCamion,Kilometros)
VALUES ('10/07/2021',1,3333,510)

DROP TRIGGER TR_VIAJES1

--2  Hacer un trigger que no permita que un camión ni un chofer realicen más de un viaje
--el mismo día. Mostrar un mensaje de error aclaratorio para cada situación, sino
--insertar el registro
CREATE TRIGGER TR_VIAJE2 ON Viajes
AFTER INSERT AS
BEGIN
	BEGIN TRY
		--DATOS
		DECLARE @IDV BIGINT
		DECLARE @FECHAAC DATE
		DECLARE @IDCHOFER INT
		DECLARE @IDCAM VARCHAR(4)
		SELECT @IDV = ID, @FECHAAC = Fecha, @IDCHOFER = IDChofer, @IDCAM = IDCamion FROM inserted
		--BANDERAS
		DECLARE @BCHOF BIT
		DECLARE @BCAM BIT
		--BUSCO
		DECLARE @FCAM DATE
		SELECT @FCAM = V.Fecha FROM Viajes V WHERE V.IDCamion = @IDCAM

		DECLARE @FCHOF DATE
		SELECT @FCHOF = V.Fecha FROM Viajes V WHERE V.IDChofer = @IDCHOFER
		--COMPARO
		IF(@FECHAAC = @FCAM) BEGIN
			SET @BCAM = 1
			DELETE FROM Viajes WHERE ID = @IDV
			RAISERROR('ERROR NO PUEDE REALIZAR MAS DE 1 VIAJE EL CAMION',16,1)
		END
		IF(@FECHAAC = @FCHOF) BEGIN
			SET @BCHOF = 1
			DELETE FROM Viajes WHERE ID = @IDV
			RAISERROR('ERROR NO PUEDE REALIZAR MAS DE 1 VIAJE EL CHOFER',16,1)
		END

	END TRY
	BEGIN CATCH
		IF(@BCAM = 1) BEGIN
			RAISERROR('ERROR NO PUEDE REALIZAR MAS DE 1 VIAJE EL CAMION',16,1)
		END
		IF(@BCHOF = 1) BEGIN
			RAISERROR('ERROR NO PUEDE REALIZAR MAS DE 1 VIAJE EL CHOFER',16,1)
		END
	END CATCH
END
--PRUEBA
INSERT INTO Viajes (Fecha,IDChofer,IDCamion,Kilometros)
VALUES ('04/07/2021',1,3333,510)

INSERT INTO Viajes (Fecha,IDChofer,IDCamion,Kilometros)
VALUES ('04/07/2021',4,7777,510)

DROP TRIGGER TR_VIAJE2

--3 Hacer un trigger que al ingresar un paquete no permita que el peso del mismo supere
--la capacidad máxima que puede llevar el camión en ese viaje (teniendo en cuenta
--todos los paquetes del viaje). Tampoco puede cargarse el paquete si es un alimento
--y el camión no es apto para transporte de alimentos. Mostrar un mensaje de error
--aclaratorio por cada situación, sino insertar el registro.
CREATE TRIGGER TR_PAQUETE ON Paquetes
AFTER INSERT AS
BEGIN
	BEGIN TRY
		--VARIABLES
		DECLARE @ID BIGINT
		DECLARE @IDVIAJE BIGINT
		DECLARE @PESO INT
		DECLARE @ALIMENTO BIT
		--ASIGNO
		SELECT @ID = ID, @IDVIAJE = IDViaje, @PESO = Peso, @ALIMENTO = Alimento FROM inserted
		--FUNCION BUSCO CAMION, APTO, Y PESO ACTUAL DE PAQ
		DECLARE @PESOLIM INT
		DECLARE @ALIMENTO_SI_NO BIT
		DECLARE @PESOACT INT
		SELECT @PESOLIM = C.PesoLimite, @ALIMENTO_SI_NO = C.AptoAlimentos, @PESOACT = SUM(PA.Peso) FROM Camiones C
		INNER JOIN Viajes V ON V.IDCamion = C.ID
		INNER JOIN Paquetes PA ON PA.IDViaje = V.ID
		WHERE @IDVIAJE = V.ID
		GROUP BY C.PesoLimite, C.AptoAlimentos
		--BANDERAS
		DECLARE @BPESO BIT
		DECLARE @BALIM BIT

		--VERIFICO PESO ACTUAL CONTRA LIMITE
		IF(@PESOACT > @PESOLIM) BEGIN
			DELETE FROM Paquetes WHERE ID = @ID
			SET @BPESO = 1
			RAISERROR('ERROR NO PUEDE INGRESAR EL PAQUETE SOBREPASO EL LIMITE DEL CAMION',16,1)
		END
		--VERIFICO SI ES ALIMENTO Y SI ACEPTA
		IF(@ALIMENTO = 1 AND @ALIMENTO_SI_NO = 0) BEGIN
			DELETE FROM Paquetes WHERE ID = @ID
			SET @BALIM = 1
			RAISERROR('ERROR NO PUEDE INGRESAR EL PAQUETE ALIMENTO PORQUE EL CAMION NO ES APTO',16,1)
		END

	END TRY
	BEGIN CATCH
		IF(@BPESO = 1) BEGIN
			RAISERROR('ERROR NO PUEDE INGRESAR EL PAQUETE SOBREPASO EL LIMITE DEL CAMION',16,1)
		END
		IF(@BALIM = 1) BEGIN
			RAISERROR('ERROR NO PUEDE INGRESAR EL PAQUETE ALIMENTO PORQUE EL CAMION NO ES APTO',16,1)
		END
	END CATCH
END

--PRUEBA
INSERT INTO Paquetes(IDViaje,Peso,Alimento)
VALUES(1,100,1)

INSERT INTO Paquetes(IDViaje,Peso,Alimento)
VALUES(2,10,1)

DROP TRIGGER TR_PAQUETE

--4 Por cada camión, listar el ID, el año de patentamiento y la cantidad de viajes que
-- hayan superado la mitad del peso límite en concepto de peso de paquetes..
SELECT C.ID, C.AñoPatentamiento,
(	SELECT ISNULL(COUNT(V.ID),0) CANT
	FROM Viajes V
	INNER JOIN Camiones CA ON CA.ID = V.IDCamion
	WHERE CA.ID = C.ID AND C.PesoLimite / 2 < 
	(	SELECT ISNULL(SUM(P.Peso),0) PESOPAQ
		FROM Paquetes P
		INNER JOIN Viajes VI ON VI.ID = P.IDViaje
		WHERE VI.IDCamion = C.ID
	)
) CANT
FROM Camiones C


SELECT ISNULL(COUNT(*),0) CANT
FROM Viajes V
INNER JOIN Camiones CA ON CA.ID = V.IDCamion
GROUP BY CA.ID

SELECT VI.ID, ISNULL(SUM(P.Peso),0)
FROM Paquetes P
INNER JOIN Viajes VI ON VI.ID = P.IDViaje
GROUP BY VI.ID


USE Examen

SELECT * FROM Paquetes
SELECT * FROM Viajes
SELECT * FROM Camiones
SELECT * FROM Choferes

SELECT V.ID VIAJE, CA.ID CAMION, CA.PesoLimite, CA.AptoAlimentos, SUM(PA.Peso) PEPAQUETE FROM Viajes V
INNER JOIN Camiones CA ON CA.ID = V.IDCamion
INNER JOIN Paquetes PA ON PA.IDViaje = V.ID
GROUP BY V.ID, CA.ID, CA.PesoLimite, CA.AptoAlimentos