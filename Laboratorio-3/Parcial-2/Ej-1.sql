--USE Parcial2

--SELECT * FROM Competidores
--SELECT * FROM Capturas
--SELECT * FROM Especies
--SELECT * FROM Torneos

 --1 Hacer un trigger que al registrar una captura se verifique que la misma se haya
 --realizado durante el horario de Inicio y Fin del torneo a la que pertenece. En caso que
 --se encuentre fuera de ese rango indicarlo con un mensaje de error. De lo contrario,
 --registrar la captura.

CREATE TRIGGER TR_VERIFICAR_CAPTURAS ON Capturas
	INSTEAD OF INSERT
	AS
	BEGIN
		BEGIN TRY
				DECLARE @IDCAP BIGINT
				SELECT @IDCAP = ID FROM inserted
				DECLARE @IDTORNEO BIGINT
				SELECT @IDTORNEO = IDTorneo FROM inserted
				DECLARE @FECHAHORA DATETIME
				SELECT @FECHAHORA = FechaHora FROM inserted
				DECLARE @FECHAINI DATETIME
				SELECT @FECHAINI = Inicio FROM Torneos WHERE @IDTORNEO = ID
				DECLARE @FECHAFIN DATETIME
				SELECT @FECHAFIN = Fin FROM Torneos WHERE @IDTORNEO = ID

				IF @FECHAHORA >= @FECHAINI AND @FECHAHORA <= @FECHAFIN BEGIN
					INSERT INTO Capturas(IDCompetidor, IDTorneo, IDEspecie, FechaHora, Peso, Devuelta)
					SELECT IDCompetidor, IDTorneo, IDEspecie, FechaHora, Peso, Devuelta FROM inserted
				END
		END TRY
		BEGIN CATCH
			RAISERROR('NO SE PUEDE REGISTRAR',16,1)
		END CATCH
	END

DROP TRIGGER TR_VERIFICAR_CAPTURAS

SELECT * FROM Torneos