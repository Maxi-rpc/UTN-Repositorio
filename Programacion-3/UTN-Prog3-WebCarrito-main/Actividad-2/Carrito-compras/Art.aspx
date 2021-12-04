<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Art.aspx.cs" Inherits="Carrito_compras.Art" %>

<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">

    <%--Mostramos las marcas y la cantidad de artículos de esta categoria para cada marca--%>

    <div class="row">
        <div class="col pad px-1">
            <h1 class="mb-4 mt-4">Marcas</h1>
            <ul>
                <% foreach (Dominio.Marca item in (List<Dominio.Marca>)Session["Marcas"])
                    {
                        int contador = 0;
                        foreach (Dominio.Articulo items in (List<Dominio.Articulo>)Session["Articulos"])
                        {
                            if (items.TipoCategoria.Id == id)
                            {
                                if (item.Id == items.TipoMarca.Id)
                                {
                                    contador++;
                                }

                            }
                            else
                            {
                                if (id == 0)
                                {
                                    if (item.Id == items.TipoMarca.Id)
                                    {
                                        contador++;
                                    }
                                }
                            }

                        } %>
                <% FiltroMarca.Text = item.Nombre + " (" + contador + ")"; %>
                <li style="margin-bottom: 5px; margin-left: -15px"><a href="Art.aspx?id=<%=id%>&marca=<%=item.Id%>&buscar=0">
                    <asp:Button ID="FiltroMarca" runat="server" BackColor="White" BorderColor="Transparent" /></a> </li>




                <% } %>
            </ul>
        </div>

        <%-- Encolumnamos los articulos de la categoria --%>

        <%     if (marca == 0)
            {          %>



        <div class="col card-columns">

            <%--Se cargan los productos sin filtro de marca--%>

            <% foreach (Dominio.Articulo iten in (List<Dominio.Articulo>)Session["Articulos"])
                {
                    if (iten.TipoCategoria.Id == id)
                    { %>
            <div class="card text-center mr-3 mt-3" style="width: 18rem;">
                <div class="card-body">
                    <img class="img-fluid" src=" <% = iten.UrlImagen %>" alt="alternate text" />
                    <h5 class="card-title"><%  = iten.Nombre  %> </h5>
                    <h6 class="card-title">$<% = iten.Precio %></h6>
                    <a href="ArtDetalle.aspx?codigo=<%=iten.Codigo%>" class="btn btn-primary align-content-center">Detalle</a>
                    <a href="Carrito.aspx?id=<%=iten.Id%>&cant=1" class="btn btn-primary align-content-center"><i class="fas fa-shopping-cart"></i></a>
                </div>
            </div>
            <% }
                } %>
        </div>



        <%}
            else
            {%>

        <div class="col card-columns">

            <%-- Encolumnamos los articulos de la categoria --%>
            <%--Se cargan los productos filtrados por marca--%>

            <% foreach (Dominio.Articulo iten in (List<Dominio.Articulo>)Session["Articulos"])
                {
                    if (iten.TipoCategoria.Id == id)
                    {
                        if (iten.TipoMarca.Id == marca)
                        {        %>

            <div class="card text-center mr-3 mt-3" style="width: 18rem;">

                <div class="card-body">
                    <img class="img-fluid" src=" <% = iten.UrlImagen %>" alt="alternate text" />
                    <h5 class="card-title"><%  = iten.Nombre  %> </h5>
                    <h6 class="card-title">$<% = iten.Precio %></h6>
                    <a href="ArtDetalle.aspx?codigo=<%=iten.Codigo%>" class="btn btn-primary align-content-center">Detalle</a>
                    <a href="Carrito.aspx?id=<%=iten.Id %>" class="btn btn-primary align-content-center"><i class="fas fa-shopping-cart"></i></a>
                </div>
            </div>
            <% }
                    }
                }
                //Se cargan los articulos buscados
                if (buscar == 1)
                {
                    foreach (Dominio.Articulo buscar in listaBuscar)
                    { %>

            <div class="card text-center mr-3 mt-3" style="width: 18rem;">

                <div class="card-body">
                    <img class="img-fluid" src=" <% = buscar.UrlImagen %>" alt="alternate text" />
                    <h5 class="card-title"><%  = buscar.Nombre  %> </h5>
                    <h6 class="card-title">$<% = buscar.Precio %></h6>
                    <a href="ArtDetalle.aspx?codigo=<%=buscar.Codigo%>" class="btn btn-primary align-content-center">Detalle</a>
                    <a href="Carrito.aspx?id=<%=buscar.Id %>" class="btn btn-primary align-content-center"><i class="fas fa-shopping-cart"></i></a>
                </div>
            </div>

            <% }
                }
            %>
        </div>
        <% }%>
    </div>

 

</asp:Content>
