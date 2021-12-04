using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Dominio;
using Negocio;

namespace Presentacion
{
    public partial class Presentacion : Form
    {
        private List<Articulo> listaArticulos;

        public Presentacion()
        {
            InitializeComponent();
        }

        private void btnAgregar_Click(object sender, EventArgs e)
        {
            FormArticulo formAgregar = new FormArticulo();
            formAgregar.ShowDialog();
            cargarGrilla();
        }

        private void btnDetalle_Click(object sender, EventArgs e)
        {
            try
            {
                Articulo nuevo = (Articulo)dgvArticulos.CurrentRow.DataBoundItem;
                FormArticulo detalle = new FormArticulo("Detalle de Artículo", nuevo);
                detalle.ShowDialog();
            }
            catch (Exception ex)
            {

                MessageBox.Show(ex.ToString());
            }
            
            
        }

        private void btnEliminar_Click(object sender, EventArgs e)
        {
            Articulo seleccionado = (Articulo)dgvArticulos.CurrentRow.DataBoundItem;
            ArticuloNegocio articuloNegocio = new ArticuloNegocio();

            try
            {
                if (MessageBox.Show("¿Estás seguro que querés eliminar el articulo?", "Eliminar", MessageBoxButtons.YesNo, MessageBoxIcon.Warning) == DialogResult.Yes)
                {
                    articuloNegocio.eliminar(seleccionado.Id);
                    cargarGrilla();
                }
            }
            catch (Exception ex)
            {

                MessageBox.Show(ex.ToString());
            }
            
                
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            cargarGrilla();
        }

        private void cargarGrilla()
        {
            ArticuloNegocio articuloNegocio = new ArticuloNegocio();
           
            try
            {
                listaArticulos = articuloNegocio.listar();
                dgvArticulos.DataSource = listaArticulos;

                //ocultarColumnas();

                RecargarImg(listaArticulos[0].UrlImagen);
            }
            catch (Exception ex)
            {

                MessageBox.Show(ex.ToString());
            }
        }

        private void RecargarImg(string img)
        {
            try
            {
                pbxArticulo.Load(img);
            }
            catch (Exception)
            {

                pbxArticulo.ImageLocation = "\\error.jpg";
            }
            
        }

        private void ocultarColumnas()
        {
            dgvArticulos.Columns["Id"].Visible = false;
            dgvArticulos.Columns["Descripcion"].Visible = false;
            dgvArticulos.Columns["UrlImagen"].Visible = false;
            dgvArticulos.Columns["Codigo"].Visible = false;
        }

        private void dgvArticulos_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            Articulo seleccionado = (Articulo)dgvArticulos.CurrentRow.DataBoundItem;
            RecargarImg(seleccionado.UrlImagen);
        }

        private void dgvArticulos_MouseClick(object sender, MouseEventArgs e)
        {
            Articulo seleccionado = (Articulo)dgvArticulos.CurrentRow.DataBoundItem;
            RecargarImg(seleccionado.UrlImagen);
        }

        private void txtBFiltrar_KeyUp(object sender, KeyEventArgs e)
        {
            try
            {
                buscar();
            }
            catch (Exception ex)
            {

                MessageBox.Show(ex.ToString());
            }
        }

        private void buscar()
        {
            List<Articulo> listaFiltrada;
            if(txtBFiltrar.Text != "")
            {
                listaFiltrada = listaArticulos.FindAll(Art => Art.Nombre.ToUpper().Contains(txtBFiltrar.Text.ToUpper()) || Art.TipoMarca.Nombre.ToUpper().Contains(txtBFiltrar.Text.ToUpper()) || Art.TipoCategoria.Nombre.ToUpper().Contains(txtBFiltrar.Text.ToUpper()) );
                dgvArticulos.DataSource = null;
                dgvArticulos.DataSource = listaFiltrada;
            }
            else
            {
                dgvArticulos.DataSource = null;
                dgvArticulos.DataSource = listaArticulos;
            }
            //ocultarColumnas();
        }

        private void btnModificar_Click_1(object sender, EventArgs e)
        {
            Articulo seleccionado = (Articulo)dgvArticulos.CurrentRow.DataBoundItem;
            FormArticulo modificar = new FormArticulo(seleccionado);

            try
            {
                modificar.ShowDialog();
                cargarGrilla();
            }
            catch (Exception ex)
            {

                MessageBox.Show(ex.ToString());
            }
            
        }
    }
}
