using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MiPrimerAplicacion
{
    public partial class Formulario : Form
    {
        public Formulario()
        {
            InitializeComponent();
        }

        private void Formulario_Load(object sender, EventArgs e)
        {
            MessageBox.Show("Bienvenido a C#");
        }

        private void Formulario_FormClosed(object sender, FormClosedEventArgs e)
        {
            MessageBox.Show("Chau Chau...");
        }

        private void boton1_Click(object sender, EventArgs e)
        {
            //MessageBox.Show("Se disparo el evento Click", "Atencion");
            this.BackColor = Color.Blue;
        }

        private void Formulario_Click(object sender, EventArgs e)
        {
            MouseEventArgs click = (MouseEventArgs)e;

            if (click.Button == MouseButtons.Left)
                MessageBox.Show("Presiono el boton izquierdo", "Atencion");
            else if (click.Button == MouseButtons.Right)
                MessageBox.Show("Presiono el boton derecho", "Atencion");
            else if (click.Button == MouseButtons.Middle)
                MessageBox.Show("Presiono el boton del medio", "Atencion");
        }
    }
}
