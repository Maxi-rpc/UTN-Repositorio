
namespace Practica_8
{
    partial class FormListBoxCheckedListBox
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.checkedListBox1 = new System.Windows.Forms.CheckedListBox();
            this.listBoxDerecha = new System.Windows.Forms.ListBox();
            this.buttonMover = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // checkedListBox1
            // 
            this.checkedListBox1.CheckOnClick = true;
            this.checkedListBox1.FormattingEnabled = true;
            this.checkedListBox1.Items.AddRange(new object[] {
            "Uno",
            "Dos",
            "Tres",
            "Cuatro",
            "Cinco",
            "Seis",
            "Siete",
            "Ocho",
            "Nueve"});
            this.checkedListBox1.Location = new System.Drawing.Point(12, 12);
            this.checkedListBox1.Name = "checkedListBox1";
            this.checkedListBox1.Size = new System.Drawing.Size(313, 349);
            this.checkedListBox1.TabIndex = 1;
            // 
            // listBoxDerecha
            // 
            this.listBoxDerecha.FormattingEnabled = true;
            this.listBoxDerecha.Location = new System.Drawing.Point(475, 12);
            this.listBoxDerecha.Name = "listBoxDerecha";
            this.listBoxDerecha.Size = new System.Drawing.Size(313, 355);
            this.listBoxDerecha.TabIndex = 2;
            // 
            // buttonMover
            // 
            this.buttonMover.Location = new System.Drawing.Point(362, 170);
            this.buttonMover.Name = "buttonMover";
            this.buttonMover.Size = new System.Drawing.Size(75, 23);
            this.buttonMover.TabIndex = 3;
            this.buttonMover.Text = "Mover";
            this.buttonMover.UseVisualStyleBackColor = true;
            this.buttonMover.Click += new System.EventHandler(this.buttonMover_Click);
            // 
            // FormListBoxCheckedListBox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonMover);
            this.Controls.Add(this.listBoxDerecha);
            this.Controls.Add(this.checkedListBox1);
            this.Name = "FormListBoxCheckedListBox";
            this.Text = "ListBox y CheckedListBox";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.CheckedListBox checkedListBox1;
        private System.Windows.Forms.ListBox listBoxDerecha;
        private System.Windows.Forms.Button buttonMover;
    }
}

