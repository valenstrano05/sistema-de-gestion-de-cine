#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void cargarCadena (const char* mensaje, char* cadena, int tam);
int pedirEntero(const char * mensaje);

void cargarPelicula();
void listarPeliculas();
void modificarPelicula();
void darBajaPelicula();
bool confirmacionSalida();

void cargarDescuento();
void listarDescuentos();
void modificarDescuento();
void darBajaDescuento();

void cargarSocio();
void listarSocios();
void modificarSocio();
void darBajaSocio();

void cargarSala();
void listarSalas();
void modificarSala();
void darBajaSala();

void cargarButaca();
void listarButacas();
void darBajaButaca();

void cargarFuncion();
void listarFunciones();
void modificarFuncion();
void darBajaFuncion();

void registrarCompra();
void listarCompras();
void consultarComprasPorSocio();
void darBajaCompra();

void informeRankingRecaudacionPeliculas();
void informeOcupacionPorFuncion();
void informeEntradasPorFormato();
void informeSociosMasFrecuentes();
void informeImpactoDescuentos();
void informeTicketsSuperanPromedio();

#endif // FUNCIONES_H_INCLUDED
