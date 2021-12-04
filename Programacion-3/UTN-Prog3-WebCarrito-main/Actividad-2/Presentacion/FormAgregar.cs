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
    public partial class FormArticulo : Form
    {
        private Articulo nuevo = null;
        public FormArticulo()
        {
            InitializeComponent();
        }

        public FormArticulo(Articulo nuevo)
        {
            InitializeComponent();
            this.nuevo = nuevo;
            Text = "Modificar Articulo";

        }

        public FormArticulo(string detalle, Articulo nuevo)
        {
            InitializeComponent();
            this.nuevo = nuevo;
            Text = detalle;
            txtCodigo.ReadOnly = true;
            txtNombre.ReadOnly = true;
            txtDescripcion.ReadOnly = true;
            txtPrecio.ReadOnly = true;
            txtUrlImagen.ReadOnly = true;
            btnAgregarCategoria.Visible = false;
            btnAgregarMarca.Visible = false;
            btnAgregar.Visible = false;
            btnCancelar.Visible = false;
            Size = new Size(780, 400);
            cmbCategoria.Enabled = false;
            cmbMarca.Enabled = false;
        }

       private void btnAgregar_Click(object sender, EventArgs e)
        {
            
            ArticuloNegocio articuloNegrocio = new ArticuloNegocio();

            try
            {
                if(nuevo == null)
                    nuevo = new Articulo();

                nuevo.Codigo = txtCodigo.Text.Trim();
                nuevo.Nombre = txtNombre.Text.Trim();
                nuevo.Descripcion = txtDescripcion.Text;              
                nuevo.TipoMarca = (Marca)cmbMarca.SelectedItem;
                nuevo.TipoCategoria = (Categoria)cmbCategoria.SelectedItem;
                nuevo.Precio = decimal.Parse(txtPrecio.Text);
                nuevo.UrlImagen = txtUrlImagen.Text;
                
                if(nuevo.Id == 0)
                {
                    articuloNegrocio.agregar(nuevo);
                    MessageBox.Show("El artículo se agregó con éxito");
                }
                else
                {
                    articuloNegrocio.modificar(nuevo);
                    MessageBox.Show("El artículo se modificó con éxito");
                }

                Close();
            }
            catch (Exception ex)
            {

                MessageBox.Show(ex.ToString());
            }
          
        }

        private void FormAgregar_Load(object sender, EventArgs e)
        {
            CategoriaNegocio categoriaNegocio = new CategoriaNegocio();
            MarcaNegocio marcaNegocio = new MarcaNegocio();

            try
            {
                txtPrecio.Text = "0.00";
                cmbCategoria.DataSource = categoriaNegocio.listar();
                cmbMarca.DataSource = marcaNegocio.listar();

                cmbCategoria.ValueMember = "Id";
                cmbCategoria.DisplayMember = "Nombre";
                cmbMarca.ValueMember = "Id";
                cmbMarca.DisplayMember = "Nombre";

                if (nuevo != null)
                {
                    txtCodigo.Text = nuevo.Codigo;
                    txtDescripcion.Text = nuevo.Descripcion;
                    txtNombre.Text = nuevo.Nombre;
                    txtPrecio.Text = nuevo.Precio.ToString();
                    RecargarImg(nuevo.UrlImagen);
                    cmbCategoria.Text = nuevo.TipoCategoria.Nombre;
                    cmbMarca.Text = nuevo.TipoMarca.Nombre;
                    txtUrlImagen.Text = nuevo.UrlImagen;
                    cmbMarca.SelectedValue = nuevo.TipoMarca.Id;
                    cmbCategoria.SelectedValue = nuevo.TipoCategoria.Id;
                }

            }
            catch (Exception ex)
            {

                MessageBox.Show(ex.ToString());
            }
        }

        private void btnCancelar_Click(object sender, EventArgs e)
        {
            DialogResult dr = MessageBox.Show("¿Estás seguro que deseas salir? Perderás la información", "Agregar Artículo", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
            if (dr == DialogResult.Yes)
                Close();
        }

        private void txtPrecio_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((e.KeyChar < 48 || e.KeyChar > 59) && e.KeyChar != 8)
                e.Handled = true;

        }

        private void txtUrlImagen_TextChanged(object sender, EventArgs e)
        {
            try
            {
                RecargarImg(txtUrlImagen.Text);
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
                pbAgregar.Load(img);
            }
            catch (Exception)
            {

                pbAgregar.ImageLocation = "\\error.jpg";
            }
            
        }

        private void btnAgregarMarca_Click(object sender, EventArgs e)
        {
            Marca nuevo = new Marca();
            Marca_Categoria marcaCategoria = new Marca_Categoria(nuevo);
            marcaCategoria.ShowDialog();
            
            MarcaNegocio marcaNegocio = new MarcaNegocio();
            cmbMarca.DataSource = marcaNegocio.listar();
            


        }

        private void btnAgregarCategoria_Click(object sender, EventArgs e)
        {
            Categoria nuevo = new Categoria();
            Marca_Categoria marcaCategoria = new Marca_Categoria(nuevo);
            marcaCategoria.ShowDialog();
            CategoriaNegocio categoriaNegocio = new CategoriaNegocio();
            cmbCategoria.DataSource = categoriaNegocio.listar();

        }

        private void txtCodigo_Validating(object sender, CancelEventArgs e)
        {
            string texto = txtCodigo.Text.Trim();

            if (texto.Length == 0)
            {
                txtCodigo.BackColor = Color.Red;
            }
            else
            {
                txtCodigo.BackColor = System.Drawing.SystemColors.Window;
            }

            btnAgregar.Enabled = (txtCodigo.BackColor != Color.Red);
        }

        private void txtNombre_Validating(object sender, CancelEventArgs e)
        {
           string texto = txtNombre.Text.Trim();

            if (texto.Length == 0)
            {
                txtNombre.BackColor = Color.Red;
            }
            else
            {
                txtNombre.BackColor = System.Drawing.SystemColors.Window;
            }

            btnAgregar.Enabled = (txtNombre.BackColor != Color.Red);
        }


    }
}
