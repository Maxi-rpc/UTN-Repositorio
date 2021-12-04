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
    public partial class Marca_Categoria : Form
    {
        public Marca_Categoria()
        {
            InitializeComponent();
        }

        public Marca_Categoria(Marca nuevo)
        {
            InitializeComponent();
            Text = "Agregar Marca";
        }

        public Marca_Categoria(Categoria nuevo)
        {
            InitializeComponent();
            Text = "Agregar Categoria";
        }

        private void btnGuardar_Click(object sender, EventArgs e)
        {
            string texto = txtNombre.Text.Trim();
            
            if (Text == "Agregar Categoria")
            {
                CategoriaNegocio categoriaNegocio = new CategoriaNegocio();
                Categoria nuevo = new Categoria(texto);
                categoriaNegocio.agregarCategoria(nuevo);
                                
            }
            else if (Text == "Agregar Marca")
            {
                MarcaNegocio marcaNegocio = new MarcaNegocio();
                Marca nuevo = new Marca(texto);
                marcaNegocio.agregarMarca(nuevo);
            }


            MessageBox.Show("Guardado con éxito");
            

            Close();
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

            btnGuardar.Enabled = (txtNombre.BackColor != Color.Red);
        }

        private void txtNombre_KeyPress(object sender, KeyPressEventArgs e)
        {
            if(txtNombre.Text.Length > 0)
            {
                txtNombre.BackColor = Color.White;
                btnGuardar.Enabled = true;
            }

        }
    }
}
