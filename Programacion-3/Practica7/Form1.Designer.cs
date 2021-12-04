
namespace Practica7
{
    partial class FormRichTextBox
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
            this.buttonNegrita = new System.Windows.Forms.Button();
            this.buttonSubrayado = new System.Windows.Forms.Button();
            this.buttonCursiva = new System.Windows.Forms.Button();
            this.buttonCentrado = new System.Windows.Forms.Button();
            this.labelTamanoFuente = new System.Windows.Forms.Label();
            this.textBoxTamanoFuente = new System.Windows.Forms.TextBox();
            this.richTextBox = new System.Windows.Forms.RichTextBox();
            this.buttonGuardar = new System.Windows.Forms.Button();
            this.buttonAbrir = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonNegrita
            // 
            this.buttonNegrita.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.buttonNegrita.Location = new System.Drawing.Point(101, 32);
            this.buttonNegrita.Name = "buttonNegrita";
            this.buttonNegrita.Size = new System.Drawing.Size(75, 23);
            this.buttonNegrita.TabIndex = 0;
            this.buttonNegrita.Text = "Negrita";
            this.buttonNegrita.UseVisualStyleBackColor = true;
            this.buttonNegrita.Click += new System.EventHandler(this.buttonNegrita_Click);
            // 
            // buttonSubrayado
            // 
            this.buttonSubrayado.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.buttonSubrayado.Location = new System.Drawing.Point(232, 32);
            this.buttonSubrayado.Name = "buttonSubrayado";
            this.buttonSubrayado.Size = new System.Drawing.Size(75, 23);
            this.buttonSubrayado.TabIndex = 1;
            this.buttonSubrayado.Text = "Subrayado";
            this.buttonSubrayado.UseVisualStyleBackColor = true;
            this.buttonSubrayado.Click += new System.EventHandler(this.buttonSubrayado_Click);
            // 
            // buttonCursiva
            // 
            this.buttonCursiva.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.buttonCursiva.Location = new System.Drawing.Point(361, 32);
            this.buttonCursiva.Name = "buttonCursiva";
            this.buttonCursiva.Size = new System.Drawing.Size(75, 23);
            this.buttonCursiva.TabIndex = 2;
            this.buttonCursiva.Text = "Cursiva";
            this.buttonCursiva.UseVisualStyleBackColor = true;
            this.buttonCursiva.Click += new System.EventHandler(this.buttonCursiva_Click);
            // 
            // buttonCentrado
            // 
            this.buttonCentrado.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.buttonCentrado.Location = new System.Drawing.Point(486, 32);
            this.buttonCentrado.Name = "buttonCentrado";
            this.buttonCentrado.Size = new System.Drawing.Size(75, 23);
            this.buttonCentrado.TabIndex = 3;
            this.buttonCentrado.Text = "Centrado";
            this.buttonCentrado.UseVisualStyleBackColor = true;
            this.buttonCentrado.Click += new System.EventHandler(this.buttonCentrado_Click);
            // 
            // labelTamanoFuente
            // 
            this.labelTamanoFuente.AutoSize = true;
            this.labelTamanoFuente.Location = new System.Drawing.Point(229, 78);
            this.labelTamanoFuente.Name = "labelTamanoFuente";
            this.labelTamanoFuente.Size = new System.Drawing.Size(82, 13);
            this.labelTamanoFuente.TabIndex = 4;
            this.labelTamanoFuente.Text = "Tamaño Fuente";
            // 
            // textBoxTamanoFuente
            // 
            this.textBoxTamanoFuente.Location = new System.Drawing.Point(317, 75);
            this.textBoxTamanoFuente.MaxLength = 3;
            this.textBoxTamanoFuente.Name = "textBoxTamanoFuente";
            this.textBoxTamanoFuente.Size = new System.Drawing.Size(100, 20);
            this.textBoxTamanoFuente.TabIndex = 5;
            this.textBoxTamanoFuente.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBoxTamanoFuente_KeyPress);
            this.textBoxTamanoFuente.Validated += new System.EventHandler(this.textBoxTamanoFuente_Validated);
            // 
            // richTextBox
            // 
            this.richTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.richTextBox.Location = new System.Drawing.Point(101, 109);
            this.richTextBox.Name = "richTextBox";
            this.richTextBox.Size = new System.Drawing.Size(460, 262);
            this.richTextBox.TabIndex = 6;
            this.richTextBox.Text = "";
            this.richTextBox.LinkClicked += new System.Windows.Forms.LinkClickedEventHandler(this.richTextBox_LinkClicked);
            // 
            // buttonGuardar
            // 
            this.buttonGuardar.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.buttonGuardar.Location = new System.Drawing.Point(232, 388);
            this.buttonGuardar.Name = "buttonGuardar";
            this.buttonGuardar.Size = new System.Drawing.Size(75, 23);
            this.buttonGuardar.TabIndex = 7;
            this.buttonGuardar.Text = "Guardar";
            this.buttonGuardar.UseVisualStyleBackColor = true;
            this.buttonGuardar.Click += new System.EventHandler(this.buttonGuardar_Click);
            // 
            // buttonAbrir
            // 
            this.buttonAbrir.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.buttonAbrir.Location = new System.Drawing.Point(361, 388);
            this.buttonAbrir.Name = "buttonAbrir";
            this.buttonAbrir.Size = new System.Drawing.Size(75, 23);
            this.buttonAbrir.TabIndex = 8;
            this.buttonAbrir.Text = "Abrir";
            this.buttonAbrir.UseVisualStyleBackColor = true;
            this.buttonAbrir.Click += new System.EventHandler(this.buttonAbrir_Click);
            // 
            // FormRichTextBox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonAbrir);
            this.Controls.Add(this.buttonGuardar);
            this.Controls.Add(this.richTextBox);
            this.Controls.Add(this.textBoxTamanoFuente);
            this.Controls.Add(this.labelTamanoFuente);
            this.Controls.Add(this.buttonCentrado);
            this.Controls.Add(this.buttonCursiva);
            this.Controls.Add(this.buttonSubrayado);
            this.Controls.Add(this.buttonNegrita);
            this.Name = "FormRichTextBox";
            this.Text = "RichTextBox";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonNegrita;
        private System.Windows.Forms.Button buttonSubrayado;
        private System.Windows.Forms.Button buttonCursiva;
        private System.Windows.Forms.Button buttonCentrado;
        private System.Windows.Forms.Label labelTamanoFuente;
        private System.Windows.Forms.TextBox textBoxTamanoFuente;
        private System.Windows.Forms.RichTextBox richTextBox;
        private System.Windows.Forms.Button buttonGuardar;
        private System.Windows.Forms.Button buttonAbrir;
    }
}

