--USE Parcial2

--SELECT * FROM Competidores
--SELECT * FROM Capturas
--SELECT * FROM Especies
--SELECT * FROM Torneos

--4 Hacer un procedimiento almacenado que a partir de un IDTorneo indique los datos
--del ganador del mismo. El ganador es aquel pescador que haya capturado la mayor
--cantidad (en peso) de peces. Indicar Nombre, Apellido, Kilos acumulados y Categor�a
--del pescador: ('El viejo Santiago' mayor a 65 a�os, 'Ilia Krusch' entre 23 y 65 a�os,
--'Manol�n' entre 16 y 22 a�os).
--NOTA: El primer puesto puede ser un empate entre varios competidores, en ese caso
--mostrar la informaci�n de todos los ganadores.

CREATE PROCEDURE PR_PUNTOS(
		@IDTORNEO BIGINT
	)
	AS
	BEGIN
		DECLARE @PUNTOS BIGINT
		
		SELECT @PUNTOS = (
		SELECT SUM(CAP.Peso) FROM Torneos AS TOR
		INNER JOIN Capturas AS CAP ON CAP.IDTorneo = TOR.ID
		INNER JOIN Competidores AS COM ON COM.ID = CAP.IDCompetidor
		)
	END