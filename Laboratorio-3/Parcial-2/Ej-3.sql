--USE Parcial2

--SELECT * FROM Competidores
--SELECT * FROM Capturas
--SELECT * FROM Especies
--SELECT * FROM Torneos

--3 Hacer un trigger que al eliminar una captura sea marcada como devuelta y que al
--eliminar una captura que ya se encuentra como devuelta se realice la baja física del
--registro.CREATE TRIGGER TR_ELIMINAR_CAPTURA ON Capturas
	INSTEAD OF DELETE
	AS
	BEGIN
		BEGIN TRY
				BEGIN TRANSACTION
					DECLARE @ID BIGINT
					SELECT @ID = ID FROM deleted
					DECLARE @DEVUELTA BIT
					SELECT @DEVUELTA = Devuelta FROM Capturas WHERE @ID = ID
					
					IF @DEVUELTA = 0 BEGIN
						UPDATE Capturas SET Devuelta = 1 WHERE @ID = ID
					END
					ELSE BEGIN
						DELETE FROM Capturas WHERE @ID = ID
					END
				COMMIT TRANSACTION
		END TRY
		BEGIN CATCH
			ROLLBACK TRANSACTION
			RAISERROR('NO PUEDE ELIMINAR',16,1)
		END CATCH
	END

--DROP TRIGGER TR_ELIMINAR_CAPTURA
