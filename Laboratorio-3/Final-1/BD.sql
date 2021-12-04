Create Database Examen
go
Use Examen
go
Create Table Camiones(
    ID varchar(4) not null primary key,
    AñoPatentamiento smallint not null,
    PesoLimite int not null check (PesoLimite > 0 ),
    AptoAlimentos bit not null
)
go
Create Table Choferes(
    ID int not null primary key identity (1, 1),
    Apellidos varchar(50) not null,
    Nombres varchar(50) not null
)
go
Create Table Viajes(
    ID bigint not null primary key identity (1, 1),
    Fecha date not null,
    IDChofer int not null foreign key references Choferes(ID),
    IDCamion varchar(4) not null foreign key references Camiones(ID),
    Kilometros int not null
)
go
Create Table Paquetes(
    ID bigint not null primary key identity (1, 1),
    IDViaje bigint not null foreign key references Viajes(ID),
    Peso int not null,
    Alimento bit not null
)
go
INSERT INTO Camiones (ID, AñoPatentamiento, PesoLimite, AptoAlimentos)
VALUES(1111, 2020,	300,	1), 
(2222	,2015,	1500,	0), 
(3333	,2010,	900,	1),
(4444	,2000,	800,	0),
(5555	,2004,	750,	0),
(6666	,2009,	100,	1),
(7777	,2021,	400,	1),
(8888	,2018,	500,	0),
(9999	,2019,	950,	0)

INSERT INTO Choferes( Apellidos,Nombres)
VALUES('Kloster', 'Daniel'),
('Lara', 'Brian'),
('Simon',	'Angel'),
('Fernandez',	'Gladys')


SET DATEFORMAT 'DMY'
INSERT INTO Viajes(Fecha,IDChofer,IDCamion,Kilometros)
VALUES('10/07/2021',1,1111,500),
('09/07/2021',2,2222,600),
('08/07/2021',3,1111,50),
('04/07/2021',4,3333,140),
('24/7/21',1,4444,150),
('10/07/2021',2,5555,900),
('09/07/2021',3,5555,400),
('08/07/2021',4,6666,300),
('04/07/2021',1,7777,600),
('24/7/21',2,8888,800),
('10/07/2021',3,7777,500),
('09/07/2021',4,7777,700),
('08/07/2021',1,3333,50),
('04/07/2021',2,5555,150),
('05/08/2021',3,6666,300)

INSERT INTO Paquetes(IDViaje,Peso,Alimento)
VALUES(1,10,1),
(1,50,1),
(1,100,1),
(1,50,1),
(2,80,1),
(2,50,1),
(2,60,1),
(2,100,1),
(3,100,1),
(3,100,0),
(3,50,0),
(4,250,0),
(4,250,0),
(4,350,1),
(5,500,0)
