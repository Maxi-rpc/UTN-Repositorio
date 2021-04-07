
namespace MiPrimerAplicacion
{
    partial class Formulario
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.boton1 = new System.Windows.Forms.Button();
            this.labelUno = new System.Windows.Forms.Label();
            this.txtApellido = new System.Windows.Forms.TextBox();
            this.txtNuevo = new System.Windows.Forms.TextBox();
            this.labelNombre = new System.Windows.Forms.Label();
            this.labelEdad = new System.Windows.Forms.Label();
            this.textEdad = new System.Windows.Forms.TextBox();
            this.labelDireccion = new System.Windows.Forms.Label();
            this.textDireccion = new System.Windows.Forms.TextBox();
            this.labelResultado = new System.Windows.Forms.Label();
            this.textResultado = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // boton1
            // 
            this.boton1.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.boton1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.boton1.Location = new System.Drawing.Point(170, 318);
            this.boton1.Name = "boton1";
            this.boton1.Size = new System.Drawing.Size(75, 23);
            this.boton1.TabIndex = 0;
            this.boton1.Text = "boton";
            this.boton1.UseVisualStyleBackColor = false;
            this.boton1.Click += new System.EventHandler(this.boton1_Click);
            // 
            // labelUno
            // 
            this.labelUno.AutoSize = true;
            this.labelUno.Font = new System.Drawing.Font("Microsoft Tai Le", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelUno.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.labelUno.Location = new System.Drawing.Point(56, 25);
            this.labelUno.Name = "labelUno";
            this.labelUno.Size = new System.Drawing.Size(75, 21);
            this.labelUno.TabIndex = 1;
            this.labelUno.Text = "Apellido";
            this.labelUno.MouseLeave += new System.EventHandler(this.labelUno_MouseLeave);
            this.labelUno.MouseMove += new System.Windows.Forms.MouseEventHandler(this.labelUno_MouseMove);
            // 
            // txtApellido
            // 
            this.txtApellido.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtApellido.Location = new System.Drawing.Point(170, 28);
            this.txtApellido.MaxLength = 30;
            this.txtApellido.Name = "txtApellido";
            this.txtApellido.Size = new System.Drawing.Size(264, 20);
            this.txtApellido.TabIndex = 2;
            this.txtApellido.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtApellido_KeyPress);
            // 
            // txtNuevo
            // 
            this.txtNuevo.Location = new System.Drawing.Point(170, 76);
            this.txtNuevo.Name = "txtNuevo";
            this.txtNuevo.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtNuevo.Size = new System.Drawing.Size(264, 20);
            this.txtNuevo.TabIndex = 3;
            this.txtNuevo.TextChanged += new System.EventHandler(this.txtNuevo_TextChanged);
            this.txtNuevo.Leave += new System.EventHandler(this.descripcion_Leave);
            // 
            // labelNombre
            // 
            this.labelNombre.AutoSize = true;
            this.labelNombre.Font = new System.Drawing.Font("Microsoft Tai Le", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelNombre.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.labelNombre.Location = new System.Drawing.Point(56, 75);
            this.labelNombre.Name = "labelNombre";
            this.labelNombre.Size = new System.Drawing.Size(73, 21);
            this.labelNombre.TabIndex = 4;
            this.labelNombre.Text = "Nombre";
            // 
            // labelEdad
            // 
            this.labelEdad.AutoSize = true;
            this.labelEdad.Font = new System.Drawing.Font("Microsoft Tai Le", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelEdad.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.labelEdad.Location = new System.Drawing.Point(56, 120);
            this.labelEdad.Name = "labelEdad";
            this.labelEdad.Size = new System.Drawing.Size(48, 21);
            this.labelEdad.TabIndex = 5;
            this.labelEdad.Text = "Edad";
            this.labelEdad.Click += new System.EventHandler(this.label1_Click);
            // 
            // textEdad
            // 
            this.textEdad.Location = new System.Drawing.Point(170, 121);
            this.textEdad.Name = "textEdad";
            this.textEdad.Size = new System.Drawing.Size(48, 20);
            this.textEdad.TabIndex = 6;
            // 
            // labelDireccion
            // 
            this.labelDireccion.AutoSize = true;
            this.labelDireccion.Font = new System.Drawing.Font("Microsoft Tai Le", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelDireccion.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.labelDireccion.Location = new System.Drawing.Point(56, 154);
            this.labelDireccion.Name = "labelDireccion";
            this.labelDireccion.Size = new System.Drawing.Size(83, 21);
            this.labelDireccion.TabIndex = 7;
            this.labelDireccion.Text = "Direccion";
            // 
            // textDireccion
            // 
            this.textDireccion.Location = new System.Drawing.Point(170, 155);
            this.textDireccion.Name = "textDireccion";
            this.textDireccion.Size = new System.Drawing.Size(264, 20);
            this.textDireccion.TabIndex = 8;
            // 
            // labelResultado
            // 
            this.labelResultado.AutoSize = true;
            this.labelResultado.Font = new System.Drawing.Font("Microsoft Tai Le", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelResultado.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.labelResultado.Location = new System.Drawing.Point(56, 195);
            this.labelResultado.Name = "labelResultado";
            this.labelResultado.Size = new System.Drawing.Size(86, 21);
            this.labelResultado.TabIndex = 9;
            this.labelResultado.Text = "Resultado";
            // 
            // textResultado
            // 
            this.textResultado.Location = new System.Drawing.Point(60, 219);
            this.textResultado.Name = "textResultado";
            this.textResultado.Size = new System.Drawing.Size(374, 20);
            this.textResultado.TabIndex = 10;
            // 
            // Formulario
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlDark;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.textResultado);
            this.Controls.Add(this.labelResultado);
            this.Controls.Add(this.textDireccion);
            this.Controls.Add(this.labelDireccion);
            this.Controls.Add(this.textEdad);
            this.Controls.Add(this.labelEdad);
            this.Controls.Add(this.labelNombre);
            this.Controls.Add(this.txtNuevo);
            this.Controls.Add(this.txtApellido);
            this.Controls.Add(this.labelUno);
            this.Controls.Add(this.boton1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Formulario";
            this.Opacity = 0.9D;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "MiApp";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Formulario_FormClosed);
            this.Load += new System.EventHandler(this.Formulario_Load);
            this.Click += new System.EventHandler(this.Formulario_Click);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button boton1;
        private System.Windows.Forms.Label labelUno;
        private System.Windows.Forms.TextBox txtApellido;
        private System.Windows.Forms.TextBox txtNuevo;
        private System.Windows.Forms.Label labelNombre;
        private System.Windows.Forms.Label labelEdad;
        private System.Windows.Forms.TextBox textEdad;
        private System.Windows.Forms.Label labelDireccion;
        private System.Windows.Forms.TextBox textDireccion;
        private System.Windows.Forms.Label labelResultado;
        private System.Windows.Forms.TextBox textResultado;
    }
}

