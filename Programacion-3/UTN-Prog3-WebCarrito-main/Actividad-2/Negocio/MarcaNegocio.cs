using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Dominio;

namespace Negocio
{
    public class MarcaNegocio
    {
        public List<Marca> listar()
        {
            List<Marca> lista = new List<Marca>();
            AccesoDatos datos = new AccesoDatos();
            

            try
            {
                datos.setearConsulta("select id, descripcion from Marcas");
                datos.ejecutarLectura();

                while (datos.Lector.Read())
                {
                    lista.Add(new Marca((int)datos.Lector["id"], (string)datos.Lector["descripcion"]));
                }

                return lista;
            }
            catch (Exception ex)
            {
                throw ex;
            }
            finally
            {
                datos.cerrarConexion();
            }
        }
    
        public void agregarMarca(Marca nuevo)
    {
        AccesoDatos datos = new AccesoDatos();

        try
        {
            datos.setearConsulta("insert into Marcas (Descripcion) values (@Descripcion)");
            datos.setearParametro("@Descripcion", nuevo.Nombre);

            datos.ejecutarAccion();

        }
        catch (Exception ex)
        {
            throw ex;
        }
        finally
        {
            datos.cerrarConexion();
        }
    }
}
}

