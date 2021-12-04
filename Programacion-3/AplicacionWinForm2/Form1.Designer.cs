
namespace AplicacionWinForm2
{
    partial class FormRadioButtonCheckBox
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
            this.labelNombre = new System.Windows.Forms.Label();
            this.textBoxNombre = new System.Windows.Forms.TextBox();
            this.checkBoxProgramador = new System.Windows.Forms.CheckBox();
            this.groupBoxSexo = new System.Windows.Forms.GroupBox();
            this.radioButtonHombre = new System.Windows.Forms.RadioButton();
            this.radioButtonMujer = new System.Windows.Forms.RadioButton();
            this.labelSalida = new System.Windows.Forms.Label();
            this.textBoxSalida = new System.Windows.Forms.TextBox();
            this.buttonOk = new System.Windows.Forms.Button();
            this.groupBoxSexo.SuspendLayout();
            this.SuspendLayout();
            // 
            // labelNombre
            // 
            this.labelNombre.AutoSize = true;
            this.labelNombre.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelNombre.Location = new System.Drawing.Point(78, 35);
            this.labelNombre.Name = "labelNombre";
            this.labelNombre.Size = new System.Drawing.Size(65, 20);
            this.labelNombre.TabIndex = 0;
            this.labelNombre.Text = "Nombre";
            // 
            // textBoxNombre
            // 
            this.textBoxNombre.Location = new System.Drawing.Point(181, 37);
            this.textBoxNombre.Name = "textBoxNombre";
            this.textBoxNombre.Size = new System.Drawing.Size(409, 20);
            this.textBoxNombre.TabIndex = 1;
            this.textBoxNombre.Validating += new System.ComponentModel.CancelEventHandler(this.textBoxNombre_Validating);
            // 
            // checkBoxProgramador
            // 
            this.checkBoxProgramador.AutoSize = true;
            this.checkBoxProgramador.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.checkBoxProgramador.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.checkBoxProgramador.Location = new System.Drawing.Point(82, 79);
            this.checkBoxProgramador.Name = "checkBoxProgramador";
            this.checkBoxProgramador.Size = new System.Drawing.Size(120, 24);
            this.checkBoxProgramador.TabIndex = 2;
            this.checkBoxProgramador.Text = "Programador";
            this.checkBoxProgramador.UseVisualStyleBackColor = true;
            // 
            // groupBoxSexo
            // 
            this.groupBoxSexo.Controls.Add(this.radioButtonMujer);
            this.groupBoxSexo.Controls.Add(this.radioButtonHombre);
            this.groupBoxSexo.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBoxSexo.Location = new System.Drawing.Point(82, 122);
            this.groupBoxSexo.Name = "groupBoxSexo";
            this.groupBoxSexo.Size = new System.Drawing.Size(508, 100);
            this.groupBoxSexo.TabIndex = 3;
            this.groupBoxSexo.TabStop = false;
            this.groupBoxSexo.Text = "Sexo";
            // 
            // radioButtonHombre
            // 
            this.radioButtonHombre.AutoSize = true;
            this.radioButtonHombre.Location = new System.Drawing.Point(62, 43);
            this.radioButtonHombre.Name = "radioButtonHombre";
            this.radioButtonHombre.Size = new System.Drawing.Size(84, 24);
            this.radioButtonHombre.TabIndex = 0;
            this.radioButtonHombre.TabStop = true;
            this.radioButtonHombre.Text = "Hombre";
            this.radioButtonHombre.UseVisualStyleBackColor = true;
            // 
            // radioButtonMujer
            // 
            this.radioButtonMujer.AutoSize = true;
            this.radioButtonMujer.Location = new System.Drawing.Point(371, 43);
            this.radioButtonMujer.Name = "radioButtonMujer";
            this.radioButtonMujer.Size = new System.Drawing.Size(66, 24);
            this.radioButtonMujer.TabIndex = 1;
            this.radioButtonMujer.TabStop = true;
            this.radioButtonMujer.Text = "Mujer";
            this.radioButtonMujer.UseVisualStyleBackColor = true;
            // 
            // labelSalida
            // 
            this.labelSalida.AutoSize = true;
            this.labelSalida.Location = new System.Drawing.Point(79, 241);
            this.labelSalida.Name = "labelSalida";
            this.labelSalida.Size = new System.Drawing.Size(36, 13);
            this.labelSalida.TabIndex = 4;
            this.labelSalida.Text = "Salida";
            // 
            // textBoxSalida
            // 
            this.textBoxSalida.Location = new System.Drawing.Point(82, 257);
            this.textBoxSalida.Multiline = true;
            this.textBoxSalida.Name = "textBoxSalida";
            this.textBoxSalida.Size = new System.Drawing.Size(508, 151);
            this.textBoxSalida.TabIndex = 5;
            // 
            // buttonOk
            // 
            this.buttonOk.Location = new System.Drawing.Point(677, 37);
            this.buttonOk.Name = "buttonOk";
            this.buttonOk.Size = new System.Drawing.Size(75, 23);
            this.buttonOk.TabIndex = 6;
            this.buttonOk.Text = "OK";
            this.buttonOk.UseVisualStyleBackColor = true;
            this.buttonOk.Click += new System.EventHandler(this.buttonOk_Click);
            // 
            // FormRadioButtonCheckBox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonOk);
            this.Controls.Add(this.textBoxSalida);
            this.Controls.Add(this.labelSalida);
            this.Controls.Add(this.groupBoxSexo);
            this.Controls.Add(this.checkBoxProgramador);
            this.Controls.Add(this.textBoxNombre);
            this.Controls.Add(this.labelNombre);
            this.Name = "FormRadioButtonCheckBox";
            this.Text = "RadioButton y CheckBox";
            this.Load += new System.EventHandler(this.FormRadioButtonCheckBox_Load);
            this.groupBoxSexo.ResumeLayout(false);
            this.groupBoxSexo.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelNombre;
        private System.Windows.Forms.TextBox textBoxNombre;
        private System.Windows.Forms.CheckBox checkBoxProgramador;
        private System.Windows.Forms.GroupBox groupBoxSexo;
        private System.Windows.Forms.RadioButton radioButtonMujer;
        private System.Windows.Forms.RadioButton radioButtonHombre;
        private System.Windows.Forms.Label labelSalida;
        private System.Windows.Forms.TextBox textBoxSalida;
        private System.Windows.Forms.Button buttonOk;
    }
}

