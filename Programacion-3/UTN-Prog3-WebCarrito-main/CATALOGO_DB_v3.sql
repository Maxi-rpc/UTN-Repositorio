use master
go
create database CATALOGO_DB
go
use CATALOGO_DB
go
USE [CATALOGO_DB]
GO

SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

SET ANSI_PADDING ON
GO

CREATE TABLE [dbo].[MARCAS](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Descripcion] [varchar](50) NULL,
 CONSTRAINT [PK_MARCAS] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO

SET ANSI_PADDING OFF
GO

USE [CATALOGO_DB]
GO

/****** Object:  Table [dbo].[CATEGORIAS]    Script Date: 08/09/2019 10:32:14 a.m. ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

SET ANSI_PADDING ON
GO

CREATE TABLE [dbo].[CATEGORIAS](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Descripcion] [varchar](50) NULL,
 CONSTRAINT [PK_CATEGORIAS] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO

SET ANSI_PADDING OFF
GO

USE [CATALOGO_DB]
GO

/****** Object:  Table [dbo].[ARTICULOS]    Script Date: 08/09/2019 10:32:24 a.m. ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

SET ANSI_PADDING ON
GO

CREATE TABLE [dbo].[ARTICULOS](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Codigo] [varchar](50) NULL,
	[Nombre] [varchar](50) NULL,
	[Descripcion] [varchar](150) NULL,
	[IdMarca] [int] NULL,
	[IdCategoria] [int] NULL,
	[ImagenUrl] [varchar](1000) NULL,
	[Precio] [money] NULL,
 CONSTRAINT [PK_ARTICULOS] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO

SET ANSI_PADDING OFF
GO

-- DATOS
USE CATALOGO_DB

SELECT * FROM ARTICULOS
SELECT * FROM MARCAS
SELECT * FROM CATEGORIAS

SELECT A.Id, A.Codigo, A.Nombre, A.Descripcion, M.Descripcion Marca, C.Descripcion Categoria, A.Precio
FROM ARTICULOS A
INNER JOIN MARCAS M ON M.Id = A.IdMarca
INNER JOIN CATEGORIAS C ON C.Id = A.IdCategoria


--Categorias
insert into CATEGORIAS values ('Celulares'), ('Televisores'), ('Audio'), ('Computación'), ('Video'), ('Cámaras'), ('Videojuegos')
--1 Celulares 2 Televisores 3 Audio 4 Computacion 5 Video 6 Camaras 7 Videojuegos

--1 Celulares
--Marcas
--1 Samsung 2 Xiaomi 3 Apple 4 Motorola
insert into MARCAS values ('Samsung'), ('Xiaomi'), ('Apple'), ('Motorola')
insert into ARTICULOS values 
('C01', 'Galaxy A31', 'Posee una memoria interna (ROM) de 128GB* mientras que la externa se puede expandir mediante una tarjeta micro SD hasta 512 GB.', 1, 1, 'https://images.fravega.com/s500/57c585479f31ce4538cf97e33aef3d6b.jpg', 39999),
('C02', 'Galaxy A21s', 'Pantalla HD+ de 6,5”, una cámara de 48 MP y un procesador potente, hacen del nuevo Samsung Galaxy A21s.', 1, 1, 'https://images.fravega.com/s500/219c2383888262c5d12cf594961baeec.jpg', 32999),
('C03', 'Redmi 9', 'La cámara principal del Redmi 9 es cuádruple, con un lente principal de 13 MP.', 2, 1, 'https://images.fravega.com/s500/00de28c3707152f7744ba60b04e20ddb.jpg', 48749),
('C04', 'Redmi Note 9', 'Dispositivo liberado para que elijas la compañía telefónica que prefieras. Pantalla IPS de 6.53 . Tiene 4 cámaras traseras de 48Mpx/8Mpx/2Mpx/2Mpx.', 2, 1, 'https://images.fravega.com/s500/658028feb38bf9ae6df20cd9bdd2ffc7.jpg', 45943),
('C05', 'SE 128GB', 'Tarjeta SIM Es Dual SIM: No Cantidad de ranuras para tarjeta SIM: 1 Tamaños de tarjeta SIM compatibles: Nano-SIM Con eSIM.', 3, 1, 'https://images.fravega.com/s500/fd0be5c5a39969a620ab83e807f81955.jpg', 161841),
('C06', 'SE 64GB', '1 Tamaños de tarjeta SIM compatibles: Nano-SIM Con eSIM: Sí Cantidad de eSIMs: 1 Memoria Memoria interna: 64 GB Memoria RAM: 3 GB.', 3, 1, 'https://images.fravega.com/s500/98fa6c9c873d95fb00396189792a823f.jpg', 143420),
('C07', 'E7i Power', 'Posee una memoria interna (ROM) de 32 GB, mientras que la externa se puede expandir hasta 1 TB.', 4, 1, 'https://images.fravega.com/s500/efbb3a2a38f64f141a84626f3bebacf3.jpg', 18999),
('C08', 'G9 Plus', 'Con una pantalla de 6,8”, resolución FHD+ y un sistema multi cámara, el celular Motorola G9 Plus se presenta como una de las mejores opciones.', 4, 1, 'https://images.fravega.com/s500/bff209eb4903e564b168eb17b88ca127.jpg', 40999)

--2 Televisores
--Marcas 1 Samsung 5 TCL 6 Philips 7 Admiral 8 LG 9 Sony
insert into MARCAS values ('TCL'), ('Philips'), ('Admiral'), ('LG'),('Sony')
insert into ARTICULOS values 
('T01', 'Smart TV 4K UHD 43', 'Con la tecnología Crystal UHD 4K, HDR y un diseño sofisticado y súper delgado, el Smart TV Samsung UN43TU7000 ofrece una experiencia multimedia única.', 1, 2, 'https://images.fravega.com/s500/93639c01d8e01a705eeb8946d7b3610d.jpg', 59999),
('T02', 'Smart TV 4K UHD 50', 'Con la tecnología Crystal UHD 4K, HDR y un diseño sofisticado y súper delgado, el Smart TV Samsung UN50TU7000 ofrece una experiencia multimedia única.', 1, 2, 'https://images.fravega.com/s500/c5b71e73eb05f01c66ff3ecd20e85332.jpg', 69999),
('T03', 'Smart TV 50 4K Ultra HD', 'Mediante sus entradas HDMI podés vincular reproductores de audio y video; consolas de juegos y notebooks.', 5, 2, 'https://images.fravega.com/s500/8e340f89af7d07027ac0bc08fd324ecf.jpg', 58999),
('T04', 'Smart TV 42 Full HD', 'El Smart TV TCL L42S6500 de 41,5 pulgadas cuenta con una pantalla formato widescreen (16:9) con una resolución de 1080 x 1920 píxeles.', 5, 2, 'https://images.fravega.com/s500/e56d17ca976044828eefe7eea2d11cdf.jpg', 39999),
('T05', 'Smart TV 43 Full HD', 'El Smart TV 43 pulgadas Philips 43PFD6825/77 cuenta con una pantalla de visualización LED de formato widescreen (16:9).', 6, 2, 'https://images.fravega.com/s500/7be2a70abbadd9bb02f4695c42d8949f.jpg', 39999),
('T06', 'Smart TV 32 HD', 'Mediante sus 2 puertos USB podrás reproducir música, fotos y videos almacenados en tus dispositivos externos como tablets, smartphones y pendrives.', 6, 2, 'https://images.fravega.com/s500/6a5aac96c11a06be4ebc9d74773ceb6c.jpg', 29999),
('T07', 'Smart TV 43 UHD 4K', 'Mediante sus puertos USB podrás reproducir música, fotos y videos almacenados en tus dispositivos externos como tablets, smartphones y pendrives.', 7, 2, 'https://images.fravega.com/s500/99c30a58089453d16e6dd7e9e7c961d5.jpg', 39999),
('T08', 'Smart TV 32 HD', 'Mediante su opción HDMI podés conectar reproductores de audio y video; consolas de juegos y notebooks.', 7, 2, 'https://images.fravega.com/s500/7f7a5ae64e07ddd86eb70c7a068f4bca.jpg', 27999),
('T09', 'TV LED 43 SM 4K', 'Cuenta con la plataforma webOS exclusiva de LG, la cual es muy intuitiva, de fácil navegación y acceso a tu contenido preferido.', 8, 2, 'https://images.fravega.com/s500/8a02dd6af5cb0a26c55eabcdcc639d15.jpg', 55999),
('T10', 'Smart TV 4K 50', 'Mediante sus entradas HDMI podés conectar reproductores de audio y video; consolas de juegos y notebooks.', 8, 2, 'https://images.fravega.com/s500/8a02dd6af5cb0a26c55eabcdcc639d15.jpg', 74999),
('T11', 'Smart TV 55 4K UHD', 'Se requieren suscripciones para acceder a cierto contenido. La transmisión está optimizada únicamente para servicios seleccionados.', 9, 2, 'https://images.fravega.com/s500/cd3fdb40dca9522c7df326678ad356d5.jpg', 179999),
('T12', 'Smart TV 65 4k UHD', 'Nuestro parlante X-Balanced Speaker, diseñado para complementar la calidad de sonido y el estilizado diseño del televisor con su forma única.', 9, 2, 'https://images.fravega.com/s500/c5fbb93890d74d61500edf03638218b9.jpg', 239999)

--3 Audio
--Marcas 1 Samsung - 2 Xiaomi - 3 Apple - 4 Motorola - 5 TCL - 6 Philips - 7 Admiral - 8 LG - 9 Sony - 10 JBL - 11 Winco
insert into MARCAS values ('JBL'), ('Winco')
insert into ARTICULOS values 
('A01', 'Parlante Portátil Flip 5', 'Dispone de una potencia de 20W RMS y cuenta con conexión Bluetooth 4.2. Mientras que su batería 17.28Wh permite una reproducción de hasta 12 horas.', 10, 3, 'https://images.fravega.com/s500/084bf1a98ac58e0861475fadb4a0de01.jpg', 18999),
('A02', 'Parlante Portatil Bluetooth GO 3', 'JBL Go 3 ofrece un sonido natural, con una gran claridad y precisión, que se dispersa uniformemente por toda la habitación.', 10, 3, 'https://images.fravega.com/s500/6f3354c77bd2c2374b0c1fbe4ec5ea03.jpg', 7599),
('A03', 'Parlante Bluetooth Portatil', 'Parlante inalámbrico con TWS SURROUND Con funcion TWS SURROUND que permite conectar 2 parlantes y suenan los 2 al mismo tiempo.', 11, 3, 'https://images.fravega.com/s500/4fd77f96c5f668b7feaee749080a6af9.jpg', 2299),
('A04', 'Parlante Portatil Bluetooth', 'Parlante portatil a bluetooth, USB y SD, radio FM, entrada auxiliar, entrada para microfono, conector stereo para auriculares.', 11, 3, 'https://images.fravega.com/s500/32ac1c7d49c129e3f08c4c2e6fe33380.jpg', 8299),
('A05', 'Parlante Portátil SRS-XB01', 'Parlante portátil EXTRA BASS modelo XB01 con BLUETOOTH color negro marca Sony.', 9, 3, 'https://images.fravega.com/s500/0cacd03b89eae53a334e9388d7c6e4f8.jpg', 4499),
('A06', 'Parlante Portátil SRS-XB12', 'Parlante portátil EXTRA BASS modelo XB12 con BLUETOOTH color negro marca Sony.', 9, 3, 'https://images.fravega.com/s500/191826a6e1feba8e0b0264a1e18a81b0.jpg', 5999)

--4 Computacion
--Marcas 1 Samsung - 2 Xiaomi - 3 Apple - 4 Motorola - 5 TCL - 6 Philips - 7 Admiral - 8 LG - 9 Sony - 10 JBL - 11 Winco - 12 HP - 13 Lenovo
insert into MARCAS values ('HP'), ('Lenovo')
insert into ARTICULOS values 
('CO01', 'Notebook 15,6 Core i3 4GB 256GB', 'La notebook HP 15-DA2030LA cuenta con un diseño compacto y funcional.', 12, 4, 'https://images.fravega.com/s500/5bedd39784ade57683a4d84889b99aed.jpg', 76999),
('CO02', 'Notebook HP 14 4GB 64GB Celeron', 'La notebook HP 14-AX112LA cuenta con un diseño compacto y funcional.', 12, 4, 'https://images.fravega.com/s500/975e80a0cda67ce9af23bc6208f7e391.jpg', 39999),
('CO03', 'Notebook Lenovo 15,6 AMD A6 4GB 1TB', 'La notebook S145-81N300N7 de Lenovo cuenta con un diseño funcional y atractivo.', 13, 4, 'https://images.fravega.com/s500/37dbedab77f89b6319bb9f9b9d4a681b.jpg', 56999),
('CO04', 'Notebook Lenovo 14 Ryzen 3 8GB 1TB', 'La notebook Lenovo cuenta con un diseño compacto y funcional.', 13, 4, 'https://images.fravega.com/s500/37dbedab77f89b6319bb9f9b9d4a681b.jpg', 67999),
('CO05', 'MacBook Air 13 Core i5 128GB 8GB', 'La MacBook Air MQD32LE/A de Apple cuenta con un diseño elegante y ligero. También, dispone de teclado retroiluminado.', 3, 4, 'https://images.fravega.com/s500/09ba4dd88b91d4c4759b5c2d66285158.jpg', 149999),
('CO06', 'Magic Keyboard for 12.9-inch iPad Pro', 'Magic Keyboard for 12.9-inch iPad Pro (4th generation) - Mexican Spanish', 3, 4, 'https://images.fravega.com/s500/c565d24b8c2c777a5919ef17ae70490b.jpg', 88999)

--5 Video
--Marcas 1 Samsung - 2 Xiaomi - 3 Apple - 4 Motorola - 5 TCL - 6 Philips - 7 Admiral - 8 LG - 9 Sony - 10 JBL - 11 Winco - 12 HP - 13 Lenovo - 14 Nexxt - 15 Srihome
insert into MARCAS values ('Nexxt'), ('Srihome')
insert into ARTICULOS values 
('V01', 'Cámara Inteligente Wi-Fi', 'La cámara inteligente motorizada Wi-Fi es la solución de seguridad ideal pensada para el hogar.', 14, 5, 'https://images.fravega.com/s500/1c56ec746c16811c80c0e7428f21e0d0.jpg', 3899),
('V02', 'Webcam Full Hd1080p', 'La cámara web proporciona 1080p HD para capturar imágenes nítidas y graba vídeo 1080P(1920x1080), 720P(1280x720), VGA (640x360).', 15, 5, 'https://images.fravega.com/s500/aaba769472f34c8a4dd734572135f7cf.jpg', 4399),
('V03', 'Cámara IP HD 3mp 1296p', 'APP Srihome Gama completa de alta definición de 3 MP: 2304 x 1296 píxeles y lente óptica de nuevo diseño que te ofrece una visión más clara.', 15, 5, 'https://images.fravega.com/s500/9e12eea8d5e203143ed0bf3ea80c5740.jpg', 4999),
('V04', 'Camara Ip Exterior 3MP Visión Nocturna Full Color','Cámara de vigilancia wifi con luces LED infrarrojas de alta potencia, y dos lámparas luz de cálida, te proporciona una visión nocturna a todo color.',15,5,'https://images.fravega.com/s500/640d5f9326c5d4e92223ae7cc948ba81.jpg',6999),
('V05', 'Cámara IP Domo HD 1080 Zoom 5X Audio 2 vías','5X lente óptica: 5x rango de zoom (2,8 mm-12 mm) de telefonía móvil a distancia zoom de la pantalla controlable y outcommunication.',15,5,'https://images.fravega.com/s500/59bb21a433b4ed68d6512f5c7ac8796f.png',14999),
('V06','Cámara Ip Exterior 3MP HD Wifi - Visión Nocturna','Se usa con la APP SRIHOME FHD 3MP & Visión Nocturna La Sricam IP cámara con HD 2304 x 1296P y el filtro interruptor automático IR-CUT.',15,5,'https://images.fravega.com/s500/be4881f45304924e14cf3a04ffa9e445.jpg',6999),
('V07','Cámara Ip Wifi Exterior Hd 3mp- visión Nocturna','Admite detección de movimiento, alarma de teléfono, alarma de correo electrónico.',15,5,'https://images.fravega.com/s500/6293d671c92bb15d0acdc486eeb1e63c.png',12999)
--6 CAmaras
--Marcas 1 Samsung - 2 Xiaomi - 3 Apple - 4 Motorola - 5 TCL - 6 Philips - 7 Admiral - 8 LG - 9 Sony - 10 JBL - 11 Winco - 12 HP - 13 Lenovo - 14 Nexxt - 15 Srihome
insert into ARTICULOS values 
('CA01', 'Cámara APS-C Sony a6600 con Montura', 'a6600 camara APS-C con montura tipo E de alta calidad', 9, 6, 'https://images.fravega.com/s500/6cbbd9aee4dd1e03a4ca75689b5ce90d.jpg', 149999),
('CA02', 'Camara para Vlog 4K HDR', 'A pesar de su diseño compacto, la ZV-1 está equipada con un sensor de gran tamaño CMOS Exmor RSTm de tipo 1.0.', 9, 6, 'https://images.fravega.com/s500/2c631a5ee79372743b4a0fd3c5dec63e.jpg', 86999),
('CA03', 'Cámara Digital con Montura', 'Ligera, compacta y robusta, la a6400 dispone de capacidades y funciones impresionantes.', 9, 6, 'https://images.fravega.com/s500/797a9c45231e906b7f7b9b0a360ca432.jpg', 123999),
('CA04','Lente Objetivo Sony SELP18105G E Pz 18-105MM F4','Lente de zoom estandar de 6x, Estabilizacion de imagen SteadyShot, Formato APS-C, montura E',9,6,'https://images.fravega.com/s500/f82cdd8026a955ef39f51725181fef1b.png',73999),
('CA05','Lente Teleobjetivo Sony 85MM SEL85F18 Full Frame','Montura tipo E con formato Full Frame, Teleobjetivo medio prime, Gran portabilidad para el uso diario',9,6,'https://images.fravega.com/s500/c7b252a2d7e9b5191639e542d577f85c.jpg',67999),
('CA06','Lente Objetivo Sony 55MM SEL55F18Z Zeiss F1.8 Full','Montura E, formato Full Frame, Lente prime estandar ZEISS, Apertura circular de 9 laminas',9,6,'https://images.fravega.com/s500/69688bf7ebba3aa2b91e7daf51469fad.png',111999),
('CA07','Lente Gran Angular Sony 35MM F1.8 SEL35F18F Full','Montura tipo E con formato Full Frame, Prime gran angular, Rapido, compacto y ligero',9,6,'https://images.fravega.com/s500/b62862d39ce664ae4535f871211360ac.jpg',79999)
--7 VIdeojuegos
--Marcas 1 Samsung - 2 Xiaomi - 3 Apple - 4 Motorola - 5 TCL - 6 Philips - 7 Admiral - 8 LG - 9 Sony - 10 JBL - 11 Winco - 12 HP - 13 Lenovo - 14 Nexxt - 15 Srihome - 16 Microsoft - 17 Levelup
insert into MARCAS values ('Microsoft'), ('Levelup')
insert into ARTICULOS values 
('VI01', 'Joystick Sony Dualshock 4', 'El Dualshock 4 wireless presenta mejoras en cuanto a su capacidad de respuesta y la comodidad de sus componentes.', 9, 7, 'https://images.fravega.com/s500/51fd942ef50a1109720aabbbb8a10cdd.jpg', 9999),
('VI02', 'Joystick Sony Dualshock 5', 'Con el nuevo control inalámbrico Sony DualSense para PlayStation 5 vas a poder tener una experiencia de juego más intensa e inmersiva.', 9, 7, 'https://images.fravega.com/s500/a23c2e9cbe114eca833fc5f7288457fc.jpg', 10999),
('VI03', 'Joystick Microsoft Xbox Series', 'El nuevo control para Xbox te permite conectar cualquier auricular compatible con la entrada de audio de 3.5 mm.', 16, 7, 'https://images.fravega.com/s500/5a4ba01d89206aea02e7385919f709bd.jpg', 13999),
('VI04', 'Consola Sony PS4 1TB', 'La PlayStation 4 presenta un elegante diseño y cuenta con detalles como los botones táctiles de encendido o eject que no se ven a simple vista.', 9, 7, 'https://images.fravega.com/s500/86d4d229047eec4bfb1036b67209615b.jpg', 68999),
('VI05', 'Consola Level Up Retro', 'La consola Retro Nes de 8-bits trae 500 títulos incorporados, sumado a esto incluye 2 controles.', 17, 7, 'https://images.fravega.com/s500/07822d606253bed06e0e936d63991271.jpg', 3999),
('VI06', 'Consola Portátil con 168 Juegos', 'La consola portátil Retroboy de Level Up cuenta con 168 juegos incorporados.', 17, 7, 'https://images.fravega.com/s500/cd371127591d2b99e003327019efcf6b.jpg', 3499),
('VI07', 'Juego PS4 Sony God of War', 'God of War es un videojuego de acción y aventura en tercera persona.', 9, 7, 'https://images.fravega.com/s500/b9a34a7f9db8607229fc133753df5190.jpg', 2799),
('VI08', 'Juego PS4 Konami PES 2020', 'El Pro Evolution Soccer PES 2020 cuenta con varias mejoras respecto de la edición anterior.', 9, 7, 'https://images.fravega.com/s500/ab09fdb4b7825d6bbcc1d171a073a895.jpg', 1999),
('VI09', 'Juego PS4 Ghost of Tsushima', 'Ghost of Tsushima es un juego de acción y aventuras que ocurre a finales del siglo XIII.', 9, 7, 'https://images.fravega.com/s500/8b8022066fc0dba870ef09cb20ed15b5.jpg', 5499),
('VI10', 'Juego Xbox One Microsoft Halo Wars 2', 'Juego Xbox One Microsoft Halo Wars 2, Estrategia, RTS.', 16, 7, 'https://images.fravega.com/s500/f0b1a751f810162619cf9c9d1a198eea.jpg', 5999)

