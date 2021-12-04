using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using Dominio;
using Negocio;

namespace Carrito_compras
{
    public partial class SiteMaster : MasterPage
    {
        public List<ItemCarrito> ListaItem;
        public int cantidadCarrito;
        public List<Articulo> ArtBuscar;
        protected void Page_Load(object sender, EventArgs e)
        {
            try
            {
                ListaItem = (List<ItemCarrito>)Session["items"];
                if (ListaItem == null)
                {
                    cantidadCarrito = 0;
                }
                else
                {
                    foreach (ItemCarrito item in ListaItem)
                    {
                        cantidadCarrito += item.Cantidad;
                    }
                    
                }
                Session.Add("CantidadCarrito", cantidadCarrito);
            }
            catch (Exception ex)
            {

                Response.Redirect("Error.aspx");
            }
        }

        protected void BtnBuscar_Click(object sender, EventArgs e)
        {
            List<Articulo> Aux = (List<Articulo>)Session["Articulos"];
            ArtBuscar = new List<Articulo>();

            foreach (Articulo item in Aux)
            {
                if (System.Text.RegularExpressions.Regex.IsMatch(item.Nombre, TxtBuscar.Text, System.Text.RegularExpressions.RegexOptions.IgnoreCase))
                {
                    ArtBuscar.Add(item);
                }
                else
                {
                    if (System.Text.RegularExpressions.Regex.IsMatch(item.TipoMarca.Nombre, TxtBuscar.Text, System.Text.RegularExpressions.RegexOptions.IgnoreCase))
                    {
                        ArtBuscar.Add(item);
                    }
                }
            }

            Session.Add("Buscar", ArtBuscar);

            Response.Redirect("Art.aspx?id=0&marca=-1&buscar=1");
        }
    }
}