--USE Parcial2

--SELECT * FROM Competidores
--SELECT * FROM Capturas
--SELECT * FROM Especies
--SELECT * FROM Torneos

--2 Hacer un trigger que no permita que se carguen un torneo en la misma ciudad a
--menos que hayan pasado m�s de 5 a�os (desde la �ltima vez que se realiz� un
--torneo en esa ciudad). Si esto ocurre indicarlo con un mensaje de error. Caso
--contrario, registrar el torneo.CREATE TRIGGER TR_VERIFICAR_TORNEO ON Torneos
	INSTEAD OF INSERT
	AS
	BEGIN
		BEGIN TRY
			BEGIN TRANSACTION
				DECLARE @ID BIGINT
				SELECT @ID = ID FROM inserted
				DECLARE @CIUDAD VARCHAR(50)
				SELECT @CIUDAD = Ciudad FROM inserted
				DECLARE @ANIOACTUAL SMALLINT
				SELECT @ANIOACTUAL = YEAR(GETDATE()) 
				DECLARE @ANIO SMALLINT
				SELECT @ANIO = MAX(A�o) FROM Torneos WHERE @CIUDAD LIKE Ciudad 

				IF @ANIO < (@ANIOACTUAL - 5) BEGIN
					INSERT INTO Torneos(Nombre, A�o, Ciudad, Inicio, Fin, Premio, CapturasPorCompetidor)
					SELECT Nombre, A�o, Ciudad, Inicio, Fin, Premio, CapturasPorCompetidor FROM inserted
				END
			COMMIT TRANSACTION
		END TRY
		BEGIN CATCH
			ROLLBACK TRANSACTION
			RAISERROR('NO SE PUEDE REGISTRAR',16,1)
		END CATCH
	END

