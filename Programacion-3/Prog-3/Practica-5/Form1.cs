using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Practica_5
{
    public partial class DatosPersonales : Form
    {
        public DatosPersonales()
        {
            InitializeComponent();
        }

        private void textBoxEdad_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((e.KeyChar < 48 || e.KeyChar > 59) && e.KeyChar != 8)
            {
                e.Handled = true;
            }
        }

        private void buttonCancelar_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void buttonAceptar_Click(object sender, EventArgs e)
        {
            int contarError = 0;

            if(textBoxApellido.Text == "")
            {
                textBoxApellido.BackColor = Color.Red;
                contarError++;
            }

            if (textBoxNombre.Text == "")
            {
                textBoxNombre.BackColor = Color.Red;
                contarError++;
            }

            if (textBoxEdad.Text == "")
            {
                textBoxEdad.BackColor = Color.Red;
                contarError++;
            }

            if (textBoxDireccion.Text == "")
            {
                textBoxDireccion.BackColor = Color.Red;
                contarError++;
            }

            if(contarError == 0)
            {
                textBoxResultado.Text = "Apellido y Nombre: " + textBoxApellido.Text + " " + textBoxNombre.Text;
                textBoxResultado.Text += "\r\n" + "Edad: " + textBoxEdad.Text;
                textBoxResultado.Text += "\r\n" + "Dirección: " + textBoxDireccion.Text;
            } else
            {
                textBoxResultado.Text = "COMPLETAR TODOS LOS DATOS";
            }
        }
    }
}
