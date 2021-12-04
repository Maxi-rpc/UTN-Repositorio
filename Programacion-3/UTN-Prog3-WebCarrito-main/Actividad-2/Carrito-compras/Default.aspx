<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="Carrito_compras._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <!--slide-->
    <div class="container-fluid mt-3">
        <div
            id="carouselExampleIndicators"
            class="carousel slide"
            data-ride="carousel">
            <ol class="carousel-indicators">
                <li
                    data-target="#carouselExampleIndicators"
                    data-slide-to="0"
                    class="active"></li>
                <li data-target="#carouselExampleIndicators" data-slide-to="1"></li>
                <li data-target="#carouselExampleIndicators" data-slide-to="2"></li>
            </ol>
            <div class="carousel-inner" role="listbox">
                <div class="carousel-item active">
                    <img
                        class="d-block img-fluid"
                        src="https://images.fravega.com/f300/6ff78d945bed029b454d9e180d8f2b61.png.webp"
                        alt="First slide" />
                </div>
                <div class="carousel-item">
                    <img
                        class="d-block img-fluid"
                        src="https://images.fravega.com/f300/5363d9b07012fb56b6a4f2de83753192.png.webp"
                        alt="Second slide" />
                </div>
                <div class="carousel-item">
                    <img
                        class="d-block img-fluid"
                        src="https://images.fravega.com/f300/19bcc9bde2cd898fbb7db295ccfe94d4.png.webp"
                        alt="Third slide" />
                </div>
            </div>
            <a
                class="carousel-control-prev"
                href="#carouselExampleIndicators"
                role="button"
                data-slide="prev">
                <span class="carousel-control-prev-icon" aria-hidden="true"></span>
                <span class="sr-only">Previous</span>
            </a>
            <a
                class="carousel-control-next"
                href="#carouselExampleIndicators"
                role="button"
                data-slide="next">
                <span class="carousel-control-next-icon" aria-hidden="true"></span>
                <span class="sr-only">Next</span>
            </a>
        </div>
    </div>
    <!--/slide-->
    <!--main-->
    <div class="container">
        <div class="row py-4">
            <h1 class="h1">Categorías</h1>
        </div>
        <div class="row text-center justify-content-center">
            <a href="Art.aspx?id=4&marca=0&buscar=0" class="col cat-card">
                <i class="fas fa-laptop cat-icon"></i>
                <h5>Computación</h5>
            </a>

            <a href="Art.aspx?id=1&marca=0&buscar=0" class="col cat-card">
                <i class="fas fa-mobile-alt cat-icon"></i>
                <h5>Celulares</h5>
            </a>

            <a href="Art.aspx?id=3&marca=0&buscar=0" class="col cat-card">
                <i class="fas fa-headphones cat-icon"></i>
                <h5>Audio</h5>
            </a>

            <a href="Art.aspx?id=5&marca=0&buscar=0" class="col cat-card">
                <i class="fas fa-video cat-icon"></i>
                <h5>Video</h5>
            </a>

            <a href="Art.aspx?id=6&marca=0&buscar=0" class="col cat-card">
                <i class="fas fa-camera cat-icon"></i>
                <h5>Camaras</h5>
            </a>

            <a href="Art.aspx?id=2&marca=0&buscar=0" class="col cat-card">
                <i class="fas fa-tv cat-icon"></i>
                <h5>Televisores</h5>
            </a>

            <a href="Art.aspx?id=7&marca=0&buscar=0" class="col cat-card">
                <i class="fas fa-gamepad cat-icon"></i>
                <h5>Video Juegos</h5>
            </a>

        </div>

        <div class="separador my-5"></div>
        <div class="row justify-content-around">
            <div class="col-sm-5">
                <div class="row mini-card align-items-center shadow">
                    <div class="col">
                        <img
                            src="https://images.fravega.com/s500/37dbedab77f89b6319bb9f9b9d4a681b.jpg"
                            alt=""
                            class="img-fluid" />
                    </div>
                    <div class="col">
                        <h4>12 cuotas sin interes</h4>
                        <a href="Art.aspx?id=4&marca=0&buscar=0" class="btn btn-primary">Ver más</a>
                    </div>
                </div>
            </div>
            <div class="col-sm-5">
                <div class="row mini-card align-items-center shadow">
                    <div class="col">
                        <img
                            src="https://images.fravega.com/s500/c5b71e73eb05f01c66ff3ecd20e85332.jpg"
                            alt=""
                            class="img-fluid" />
                    </div>
                    <div class="col">
                        <h4>12 cuotas sin interes</h4>
                        <a href="Art.aspx?id=2&marca=0&buscar=0" class="btn btn-primary">Ver más</a>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <!--/main-->

</asp:Content>
