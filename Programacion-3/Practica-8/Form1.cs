using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Practica_8
{
    public partial class FormListBoxCheckedListBox : Form
    {
        public FormListBoxCheckedListBox()
        {
            InitializeComponent();

            //Con el método Add agregamos un ultimo Ítem a la
            //Colección de Ítems. Como parámetro la cadena de caracteres.
            //checkedListBox1.Items.Add("Diez");
        }

        private void buttonMover_Click(object sender, EventArgs e)
        {
            //Pregunta si la cantidad (Count) de elementos chequeados
            //en la colección de ítems chequeados(CheckedItems) es mayor a cero.
            if (listBoxDerecha.CheckedItems.Count > 0)
            {
                //Si es mayor a cero. Limpia los Ítem en el ListBox.
                checkedListBox1.Items.Clear();

                //La sentencia foreach recorre la colección de Ítems Seleccionados
                //Y los asigna de a uno a la variable ítem del tipo String.
                foreach (string item in listBoxDerecha.CheckedItems)
                {
                    //Agrego los ítems seleccionados en la colección
                    //Al Listbox con el Método Add.
                    checkedListBox1.Items.Add(item.ToString());
                }
                //Recorro todos los Ítems del CheckedListBox.
                for (int i = 0; i < listBoxDerecha.Items.Count; i++)
                    //Con el Método SetItemChecked, establezco en falso la
                    //casilla de verificación (No esta seleccionado).
                    //Como parámetros i-El índice y el valor de estado en este caso false.
                    listBoxDerecha.SetItemChecked(i, false);
            }
        }
    }
}
