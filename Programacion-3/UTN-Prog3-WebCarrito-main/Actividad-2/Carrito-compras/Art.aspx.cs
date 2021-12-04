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
    public partial class Art : System.Web.UI.Page
    {
        public List<Articulo> listado;
        public List<Marca> lista;
        public int id;
        public int marca;
        public List<Articulo> listaCarrito;
        public int buscar;
        public List<Articulo> listaBuscar;

        protected void Page_Load(object sender, EventArgs e)
        {
            try
            {
                id = int.Parse(Request.QueryString["id"]);
                marca = int.Parse(Request.QueryString["marca"]);

                buscar = int.Parse(Request.QueryString["buscar"]);
                listaBuscar = (List<Articulo>)Session["Buscar"];

            }
            catch (Exception ex)
            {

                Response.Redirect("Error.aspx");
            }
        }

     
    }
}

