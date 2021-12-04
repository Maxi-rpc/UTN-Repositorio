package TP4;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLayeredPane;
import javax.swing.border.TitledBorder;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JComboBox;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class Ejercicio2 extends JFrame {

	private JPanel contentPane;
	private JTextField txtNota1;
	private JTextField txtNota2;
	private JTextField txtNota3;
	private JTextField txtProm;
	private JTextField txtCond;

	/**
	 * Launch the application.
	 */
	

	/**
	 * Create the frame.
	 */
	public Ejercicio2() {
		setTitle("Promedio");
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 450, 390);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLayeredPane layeredPane = new JLayeredPane();
		layeredPane.setBorder(new TitledBorder(null, "Notas del estudiante", TitledBorder.LEFT, TitledBorder.TOP, null, null));
		layeredPane.setBounds(20, 35, 259, 162);
		contentPane.add(layeredPane);
		
		JLabel lblNota = new JLabel("Nota 1:");
		lblNota.setBounds(24, 28, 46, 14);
		layeredPane.add(lblNota);
		
		txtNota1 = new JTextField();
		txtNota1.addKeyListener(new KeyAdapter() {
			
			@Override
			public void keyTyped(KeyEvent e) {
				
				if(txtNota1.getBackground() == Color.red) {
					txtNota1.setBackground(Color.white);
				}
				
				char caracter = e.getKeyChar();
                if (((caracter < '0') || (caracter > '9')) && (caracter != KeyEvent.VK_BACK_SPACE)
                        && (caracter != '.') ) {
                    e.consume();
                }
			}
		});
		txtNota1.setBounds(106, 25, 127, 20);
		layeredPane.add(txtNota1);
		txtNota1.setColumns(10);
		
		txtNota2 = new JTextField();
		txtNota2.addKeyListener(new KeyAdapter() {
			@Override
			public void keyTyped(KeyEvent e) {
				
				if(txtNota2.getBackground() == Color.red) {
					txtNota2.setBackground(Color.white);
				}
				
				char caracter = e.getKeyChar();
                if (((caracter < '0') || (caracter > '9')) && (caracter != KeyEvent.VK_BACK_SPACE)
                        && (caracter != '.') ) {
                    e.consume();
                }
			}
		});
		txtNota2.setColumns(10);
		txtNota2.setBounds(106, 53, 127, 20);
		layeredPane.add(txtNota2);
		
		JLabel lblNota_1 = new JLabel("Nota 2:");
		lblNota_1.setBounds(24, 56, 46, 14);
		layeredPane.add(lblNota_1);
		
		JLabel lblNota_2 = new JLabel("Nota 3:");
		lblNota_2.setBounds(24, 85, 46, 14);
		layeredPane.add(lblNota_2);
		
		txtNota3 = new JTextField();
		txtNota3.addKeyListener(new KeyAdapter() {
			@Override
			public void keyTyped(KeyEvent e) {
				
				if(txtNota3.getBackground() == Color.red) {
					txtNota3.setBackground(Color.white);
				}
				
				char caracter = e.getKeyChar();
                if (((caracter < '0') || (caracter > '9')) && (caracter != KeyEvent.VK_BACK_SPACE)
                        && (caracter != '.') ) {
                    e.consume();
                }
                
			}
		});
		txtNota3.setColumns(10);
		txtNota3.setBounds(106, 82, 127, 20);
		layeredPane.add(txtNota3);
		
		JLabel lblNewLabel = new JLabel("TPS");
		lblNewLabel.setBounds(24, 118, 46, 14);
		layeredPane.add(lblNewLabel);
		
		JComboBox comboBoxTps = new JComboBox();
		comboBoxTps.setModel(new DefaultComboBoxModel(new String[] {"Aprobado", "Desaprobado"}));
		comboBoxTps.setBounds(106, 113, 127, 20);
		layeredPane.add(comboBoxTps);
		
		JLayeredPane layeredPane_1 = new JLayeredPane();
		layeredPane_1.setBorder(new TitledBorder(null, "Notas del estudiante", TitledBorder.LEFT, TitledBorder.TOP, null, null));
		layeredPane_1.setBounds(20, 222, 259, 106);
		contentPane.add(layeredPane_1);
		
		JLabel lblPromedio = new JLabel("Promedio");
		lblPromedio.setBounds(10, 24, 60, 14);
		layeredPane_1.add(lblPromedio);
		
		txtProm = new JTextField();
		txtProm.setEditable(false);
		txtProm.setBounds(106, 21, 131, 20);
		layeredPane_1.add(txtProm);
		txtProm.setColumns(10);
		
		JLabel lblCondicion = new JLabel("Condicion");
		lblCondicion.setBounds(10, 67, 60, 14);
		layeredPane_1.add(lblCondicion);
		
		txtCond = new JTextField();
		txtCond.setEditable(false);
		txtCond.setColumns(10);
		txtCond.setBounds(106, 64, 131, 20);
		layeredPane_1.add(txtCond);
		
		JButton btnCal = new JButton("CALCULAR");
		btnCal.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {

				if(!validarCampos()) {
					return;
				}
				
				float nota1 = Float.parseFloat(txtNota1.getText());
				float nota2 = Float.parseFloat(txtNota2.getText());
				float nota3 = Float.parseFloat(txtNota3.getText());
				
				
				if(comboBoxTps.getSelectedIndex() == 1) {
					txtCond.setText("Libre");
				} else {
					if(nota1 < 6 || nota2 < 6 || nota3 < 6) {
						txtCond.setText("Libre");
					} else {
						if(nota1 >= 8 && nota2 >= 8 && nota3 >= 8) {
							txtCond.setText("Promocionado");
						} else {
							txtCond.setText("Regular");
						}
					}
				}
				float promedio = (nota1 + nota2 + nota3)/3;
				txtProm.setText(String.valueOf(promedio));
				
			}
		});
		btnCal.setBounds(289, 80, 111, 23);
		contentPane.add(btnCal);
		
		JButton btnNuevo = new JButton("NUEVO");
		btnNuevo.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				limpiarCampos();
			}
		});
		btnNuevo.setBounds(289, 114, 111, 23);
		contentPane.add(btnNuevo);
		
		JButton btnSalir = new JButton("SALIR");
		btnSalir.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				dispose();
			}
		});
		btnSalir.setBounds(289, 148, 111, 23);
		contentPane.add(btnSalir);
	}
	
	public void limpiarCampos() {
		txtNota1.setText("");
		txtNota2.setText("");
		txtNota3.setText("");
		txtProm.setText("");
		txtCond.setText("");
	}
	
	public boolean validarCampos() {
		
		int cont = 0;
		
		if(txtNota1.getText().trim().length() == 0) {
			cont++;
			txtNota1.setBackground(Color.red);
		}
		
		if(txtNota2.getText().trim().length() == 0) {
			cont++;
			txtNota2.setBackground(Color.red);
		}
		
		if(txtNota3.getText().trim().length() == 0) {
			cont++;
			txtNota3.setBackground(Color.red);
		}
		
		if(cont > 0) {
			return false;
		}
		
		return true;
	}
}