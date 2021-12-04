using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AplicacionWinForm2
{
    public partial class FormRadioButtonCheckBox : Form
    {
        public FormRadioButtonCheckBox()
        {
            InitializeComponent();
        }

        private void ValidarOK()
        {
            //Habilita el Botón, siempre y cuando txtNombre tenga datos.
            buttonOk.Enabled = (textBoxNombre.BackColor != Color.Red);
        }

        private void textBoxNombre_Validating(object sender, CancelEventArgs e)
        {
            TextBox tb = (TextBox)sender;

            if (tb.Text.Length == 0)
                tb.BackColor = Color.Red;
            else
                tb.BackColor = System.Drawing.SystemColors.Window;

            ValidarOK();
        }

        private void FormRadioButtonCheckBox_Load(object sender, EventArgs e)
        {
            //Deshabilito el boton OK.
            buttonOk.Enabled = false;
        }

        private void buttonOk_Click(object sender, EventArgs e)
        {
            //No valido datos ya que si el Botón esta Habilitado
            //es porque paso el Evento Validating del Nombre.

            String salida; //Declaro una variable para armar la salida.

            salida = "Nombre: " + textBoxNombre.Text + "\r\n";
            salida += "Ocupacion: " + (string)(checkBoxProgramador.Checked ?
                "Programador" : "No es Programador") + "\r\n";
            salida += "Sexo: " + (string)(radioButtonHombre.Checked ?
                "Hombre" : "Mujer") + "\r\n";

            //Vuelco la salida al TextBox Salida.
            textBoxSalida.Text = salida;
        }
    }
}
