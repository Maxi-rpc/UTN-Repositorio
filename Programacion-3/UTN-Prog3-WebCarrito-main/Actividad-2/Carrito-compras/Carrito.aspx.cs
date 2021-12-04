using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using Dominio;

namespace Carrito_compras
{
    public partial class Carrito : System.Web.UI.Page
    {
        public List<ItemCarrito> items;
        ItemCarrito iten;
        public decimal total;

        protected void Page_Load(object sender, EventArgs e)
        {

            try
            {
                items = (List<ItemCarrito>)Session["items"];
                if (items == null)
                    items = new List<ItemCarrito>();

                iten = new ItemCarrito();

                if (!IsPostBack)
                {
                    if (Request.QueryString["Id"] != null)
                    {
                        if (items.Find(x => x.ItemArt.Id.ToString() == Request.QueryString["Id"]) == null)
                        {
                            List<Articulo> listaActual = (List<Articulo>)Session["Articulos"];
                            iten.ItemArt = listaActual.Find(x => x.Id.ToString() == Request.QueryString["Id"]);
                            iten.Cantidad = 1;
                            iten.Subtotal = iten.Cantidad * iten.ItemArt.Precio;
                            items.Add(iten);
                        }
                        else
                        {
                            if (Request.QueryString["a"] == "r")
                            {
                                ItemCarrito elim = items.Find(x => x.ItemArt.Id.ToString() == Request.QueryString["Id"]);
                                iten.Cantidad = elim.Cantidad - 1;
                                iten.ItemArt = elim.ItemArt;
                                iten.Subtotal = iten.Cantidad * iten.ItemArt.Precio;

                                if (iten.Cantidad == 0)
                                {
                                    items.Remove(elim);
                                }
                                else
                                {
                                    items.Remove(elim);
                                    items.Add(iten);
                                }

                            }
                            else
                            {

                                ItemCarrito elim = items.Find(x => x.ItemArt.Id.ToString() == Request.QueryString["Id"]);
                                iten.Cantidad = elim.Cantidad + 1;
                                iten.ItemArt = elim.ItemArt;
                                iten.Subtotal = iten.Cantidad * iten.ItemArt.Precio;
                                items.Remove(elim);
                                items.Add(iten);
                            }
                        }

                    }

                    if (Request.QueryString["a"] == "d")
                    {
                        ItemCarrito elim = items.Find(x => x.ItemArt.Id.ToString() == Request.QueryString["Id"]);
                        items.Remove(elim);
                        Session.Add("items", items);
                    }

                    repetidor.DataSource = items;
                    repetidor.DataBind();

                }

                Session.Add("items", items);

                foreach (ItemCarrito item in items)
                {
                    total += item.Subtotal;
                }
            }
            catch (Exception ex)
            {

                Response.Redirect("Error.aspx");
            }

        }

    }
}