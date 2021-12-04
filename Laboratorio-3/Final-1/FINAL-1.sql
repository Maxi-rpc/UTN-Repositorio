USE Examen

SELECT * FROM Paquetes
SELECT * FROM Viajes
SELECT * FROM Camiones
SELECT * FROM Choferes

--1 Hacer un trigger que no permita que un camión realice un viaje de más de 500
--kilómetros si la antigüedad del mismo es mayor a 5 años. Mostrar un mensaje de
--error aclaratorio, sino insertar el registro. La antigüedad se calcula a partir del año de
--patentamiento
DROP TRIGGER camion_mayor_5_años

CREATE TRIGGER camion_mayor_5_años  on Viajes
INSTEAD of INSERT AS
BEGIN
			
            DECLARE @antig int
            DECLARE @km int 
            DECLARE @idcamion varchar(4)

            --verificar la cantidad de kilometros del viaje
            SELECT @km = Kilometros,  @idcamion= IDCamion FROM inserted 

                --calcualr la fecha de antiguedad del camion
            SELECT  @antig= (YEAR(GETDATE()) - AñoPatentamiento) FROM Camiones WHERE ID= @idcamion

            IF @antig > 5  BEGIN
                IF @km > 500  BEGIN
					 
                    RAISERROR('no se puede realizar el viaje con un camion mayor a 5 años de antigüedad ', 16, 1)
                END
            END
            ELSE BEGIN 
                COMMIT TRANSACTION --si es menor se realiza el viaje
            END

END

INSERT INTO Viajes(Fecha,IDChofer,IDCamion,Kilometros)
VALUES('10/07/2021',1,1111,500)

--2  Hacer un trigger que no permita que un camión ni un chofer realicen más de un viaje
--el mismo día. Mostrar un mensaje de error aclaratorio para cada situación, sino
--insertar el registro
DROP TRIGGER camion_mas_viajes

CREATE TRIGGER camion_mas_viajes  on Viajes
INSTEAD of INSERT AS
BEGIN
            DECLARE @fecha date
			DECLARE @fechaBuscar int
			DECLARE @idcam varchar(4)
			DECLARE @idchof int
			--guardo ids
			SELECT @idcam = IDCamion FROM inserted
			SELECT @idchof = IDChofer FROM inserted

			--guardo fecha y cuento si hay mas de una fecha
			SELECT @fecha = Fecha FROM inserted
			SELECT @fechaBuscar = COUNT(Fecha) FROM Viajes WHERE IDCamion = @idcam AND IDChofer = @idchof AND Fecha = @fecha

			--consulto si hay mas de una fecha
			IF(@fechaBuscar > 0 ) BEGIN
				RAISERROR('no se puede realizar el viaje en la misma fecha', 16, 1)
                END
				ELSE BEGIN 
                COMMIT TRANSACTION --si no hay fechas en el mismo dia se realiza el viaje
            END
END
			
INSERT INTO Viajes(Fecha,IDChofer,IDCamion,Kilometros)
VALUES('10/07/2021',1,1111,500)

--3 Hacer un trigger que al ingresar un paquete no permita que el peso del mismo supere
--la capacidad máxima que puede llevar el camión en ese viaje (teniendo en cuenta
--todos los paquetes del viaje). Tampoco puede cargarse el paquete si es un alimento
--y el camión no es apto para transporte de alimentos. Mostrar un mensaje de error
--aclaratorio por cada situación, sino insertar el registro.DROP TRIGGER paquete_max

CREATE TRIGGER paquete_max  on Paquetes
INSTEAD of INSERT AS
BEGIN
            DECLARE @peso int
			DECLARE @pesoMax int
			DECLARE @idViaje bigint

			SELECT @idViaje = FROM
			SELECT @pesoMax = PesoLimite FROM Camiones WHERE 




--4 Por cada camión, listar el ID, el año de patentamiento y la cantidad de viajes que
-- hayan superado la mitad del peso límite en concepto de peso de paquetes..SELECT Cam.ID, Cam.[AñoPatentamiento], (
SELECT count(DISTINCT v.ID) FROM Viajes v 
INNER JOIN Camiones c ON c.ID=v.IDCamion
INNER JOIN Paquetes p ON p.IDViaje=v.ID
WHERE p.Peso > (c.PesoLimite/2) AND c.ID = Cam.ID
) AS cantidadViajes
FROM Camiones AS Cam