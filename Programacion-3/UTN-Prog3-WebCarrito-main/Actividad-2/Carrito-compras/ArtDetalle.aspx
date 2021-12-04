<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="ArtDetalle.aspx.cs" Inherits="Carrito_compras.ArtDetalle" %>

<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">
       
        

    <%foreach (Dominio.Articulo iten in (List<Dominio.Articulo>)Session["Articulos"])
        {
            if (string.Compare(iten.Codigo, codigo) == 0)
            {
                cat = iten.TipoCategoria.Id;
    %>
    <div class="row mt-5 align-items-center">
        <div class="col-md-6">
            <div class="row justify-content-center">
                <img
                    class="img-fluid"
                    src="<%=iten.UrlImagen%>"
                    alt="" />
            </div>
        </div>
        <div class="col-md-6">
            <h1 class="pb-4"><%=iten.Nombre%></h1>
            <p class="py-3">
                <%=iten.Descripcion%>
            </p>
            <h4 class="h3">$<%=iten.Precio%></h4>
            <a href="Carrito.aspx?id=<%=iten.Id %>" class="btn btn-primary btn-lg mt-4">Agregar</a>
        </div>
    </div>
    <% }
        } %>
    <!--Otras sugerencias-->
    <div class="barra-espacio"></div>
    <div class="row py-2">
        <h2 class="h4">Productos que relacionados</h2>
    </div>
    <div class="row justify-content-center">
        <div class="card-deck text-center">
            <% int cont = 0;
                foreach (Dominio.Articulo suge in (List<Dominio.Articulo>)Session["Articulos"])
                {
                    if (suge.TipoCategoria.Id == cat && cont < 5)
                    {
                        cont++;
            %>
            <a href="ArtDetalle.aspx?codigo=<%=suge.Codigo%>" class="card shadow">
                <img
                    class="card-img-top"
                    src="<%=suge.UrlImagen%>"
                    alt="Card image cap" />
                <div class="card-body">
                    <h4 class="card-title h5"><%=suge.Nombre%></h4>
                    <p class="card-text">$<%=suge.Precio%></p>
                </div>
            </a>
            <% }
                } %>
        </div>
    </div>


</asp:Content>
