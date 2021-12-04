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
    public partial class _Default : Page
    {
        public List<Articulo> listaArticulo;
        public List<Marca> listaMarca;
        
        protected void Page_Load(object sender, EventArgs e)
        {
            
            try
            {
                ArticuloNegocio negocio = new ArticuloNegocio();
                listaArticulo = negocio.listar();
                MarcaNegocio negocioMarca = new MarcaNegocio();
                listaMarca = negocioMarca.listar();


                Session.Add("Articulos", listaArticulo);
                Session.Add("Marcas", listaMarca);

                
            }
            catch (Exception ex)
            {

                Response.Redirect("Error.aspx");
            }
            
        }
    }
}