package dominio;

import java.math.BigDecimal;

public class seguro {
	
	private int Id;
	private String Descripcion;
	private BigDecimal CostoContrataci�n;
	private BigDecimal CostoAsegurado;
	private tipoSeguro Tipo;
	
	public int getId() {
		return Id;
	}

	public void setId(int id) {
		Id = id;
	}

	public String getDescripcion() {
		return Descripcion;
	}

	public void setDescripcion(String descripcion) {
		Descripcion = descripcion;
	}

	public BigDecimal getCostoContrataci�n() {
		return CostoContrataci�n;
	}

	public void setCostoContrataci�n(BigDecimal costoContrataci�n) {
		CostoContrataci�n = costoContrataci�n;
	}

	public BigDecimal getCostoAsegurado() {
		return CostoAsegurado;
	}

	public void setCostoAsegurado(BigDecimal costoAsegurado) {
		CostoAsegurado = costoAsegurado;
	}

	public tipoSeguro getTipo() {
		return Tipo;
	}

	public void setTipo(tipoSeguro tipo) {
		Tipo = tipo;
	}

	public seguro() {
		// TODO Auto-generated constructor stub
		Tipo = new tipoSeguro();
	}

}
