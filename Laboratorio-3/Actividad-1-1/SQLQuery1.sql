CREATE DATABASE utn
GO

USE utn
GO

CREATE TABLE Carrera(
	ID VARCHAR(4) NOT NULL PRIMARY KEY,
	Nombre VARCHAR(100) NOT NULL,
	Fecha_creacion DATE NOT NULL CHECK(Fecha_creacion <= GETDATE()),
	Email VARCHAR(50) NOT NULL,
	Nivel VARCHAR(50) NOT NULL CHECK(Nivel='Diplomatura'OR Nivel='Pregrado'OR Nivel='Grado'OR Nivel='Posgrado')
)
GO

CREATE TABLE Materias(
	ID BIGINT NOT NULL PRIMARY KEY IDENTITY(1,1),
	ID_carrera VARCHAR(4) NOT NULL FOREIGN KEY REFERENCES Carrera(ID),
	Nombre VARCHAR(50) NOT NULL,
	Carga_horaria INT NOT NULL CHECK(Carga_horaria > 0)
)
GO

CREATE TABLE Alumnos(
	Legajo BIGINT NOT NULL PRIMARY KEY IDENTITY(1000,1),
	ID_carrera VARCHAR(4) NOT NULL FOREIGN KEY REFERENCES Carrera(ID),
	Apellidos VARCHAR(50) NOT NULL,
	Nombres VARCHAR(50) NOT NULL,
	Fecha_nacimiento DATE NOT NULL CHECK(Fecha_nacimiento <= GETDATE()),
	Email VARCHAR(50) NOT NULL UNIQUE,
	Telefono VARCHAR(20) NULL
)