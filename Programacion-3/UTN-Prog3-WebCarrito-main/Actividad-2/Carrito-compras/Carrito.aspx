<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Carrito.aspx.cs" Inherits="Carrito_compras.Carrito" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">

    <div class="container">
        <div class="row d-flex justify-content-center">
            <h1 class="mt-5 mb-5">Mi carrito</h1>

        </div>

      <table class="table">
            <thead>
                <tr>
                    <th>Código</th>
                    <th>Nombre</th>
                    <th>Cantidad</th>
                    <th>Precio Unitario</th>
                    <th>SubTotal</th>
                    <th></th>
                </tr>
            </thead>
            <tbody>

                <asp:Repeater runat="server" ID="repetidor" >
                    <ItemTemplate>
                        <tr>
                            <th scope="row"><%#Eval("ItemArt.Codigo")%></th>
                            <td><a href="ArtDetalle.aspx?codigo=<%#Eval("ItemArt.Codigo")%>"><%#Eval("ItemArt.Nombre")%></a></td>
                            <td>
                                <%#Eval("Cantidad") %>
                                <a href="Carrito.aspx?id=<%#Eval("ItemArt.Id")%>&a=a" class="btn btn-success btn-sm">+</a>
                                <a href="Carrito.aspx?id=<%#Eval("ItemArt.Id")%>&a=r" class="btn btn-warning btn-sm">-</a>
                            </td>
                            <td>$<%#Eval("ItemArt.Precio")%></td>
                            <td>
                                $<%#Eval("Subtotal") %>
                                
                            </td>
                           <td><a href="Carrito.aspx?id=<%#Eval("ItemArt.Id")%>&a=d" class="btn btn-danger btn-sm">Eliminar</a>
                            </td>
                       </tr>
                    </ItemTemplate>
                </asp:Repeater>
                        
           </tbody>

          <tfoot>
              <th></th>
              <th></th>
              <th></th>
              <th></th>
              <th>$<%= total %></th>
              <th>Total</th>
          </tfoot>
        </table>

        

    </div>

    <div class="container d-flex justify-content-center">

        <a href="Default.aspx" class="btn btn-secondary btn-lg mb-5 mr-2">
            Seguir Comprando</a>

        <button type="button" class="btn btn-primary btn-lg mb-5 ml-2" data-toggle="modal" data-target="#exampleModal">
            Finalizar Compra</button>
    </div>


<!-- Modal -->
<div class="modal fade" id="exampleModal" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <h5 class="modal-title" id="exampleModalLabel">Web-Carrito</h5>
        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
          <span aria-hidden="true">&times;</span>
        </button>
      </div>
      <div class="modal-body">
          <p>Proyecto hecho para UTN-FRGP Programación III</p>
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-secondary" data-dismiss="modal">Cerrar</button>
        <button type="button" class="btn btn-primary" data-dismiss="modal">Ok</button>
      </div>
    </div>
  </div>
</div>

</asp:Content>
