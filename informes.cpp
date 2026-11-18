#include <iostream>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include "informes.h"
#include "funciones.h"
#include "clsArchivoDescuento.h"
#include "clsArchivoPeliculas.h"
#include "clsArchivoButacas.h"
#include "clsArchivoSalas.h"
#include "clsArchivoSocios.h"
#include "clsArchivoFunciones.h"
#include "clsArchivoFormato.h"
#include "clsArchivoCompras.h"
#include "clsArchivoDetalleEntradas.h"
#include <vector>
using namespace std;


void informeRankingRecaudacionPeliculas()
{
    system("cls");

    ArchivoPeliculas archP;
    int cantP = archP.contarRegistros();
    if (cantP <= 0){
        cout <<"No hay peliculas registradas." <<endl;
        system("pause");
        return;
    }

    ArchivoDetalleEntradas archD;
    int ventas = archD.contarRegistros();
    if (ventas <= 0){
        cout <<"No se registraron ventas. " <<endl;
        system("pause");
        return;
    }

    ArchivoCompras archC;
    ArchivoFunciones archF;
    vector<double> vRecaudacion(cantP, 0.0);
    vector<int> vCant(cantP, 0);
    int cantTotal = 0;
    double recaudacionTotal = 0.0;

    int anio;
    cout <<"Ingrese el anio a analizar (0 para el actual): ";
    cin>>anio;
    if (anio == 0){
        time_t t = time(nullptr);
        anio = localtime(&t)->tm_year + 1900;
    }

    for (int i=0; i<ventas; i++){
        DetalleEntrada entradas = archD.leerRegistro(i);

        int idCompra = entradas.getIdCompra();
        int posCompra = archC.buscarRegistro(idCompra);
        if (posCompra == -1) continue;
        Compra compra = archC.leerRegistro(posCompra);
        if (!compra.getEstado() || compra.getFecha().getAnio() != anio) continue;

        int posFuncion = archF.buscarRegistro(entradas.getIdFuncion());
        if (posFuncion == -1) continue;
        Funcion funcion = archF.leerRegistro(posFuncion);
        int posPelicula = archP.buscarPorID(funcion.getIdPelicula());
        if (posPelicula == -1) continue;
        vRecaudacion[posPelicula] += entradas.getPrecioFinal();
        vCant[posPelicula] ++ ;
        recaudacionTotal += entradas.getPrecioFinal();
        cantTotal ++;
    }

    if (cantTotal <= 0){
        cout <<"\n NO SE REGISTRARON VENTAS PARA EL ANIO " <<anio <<"." <<endl <<endl;
        system("pause");
        return;
    }

    vector <int> orden(cantP);
    for (int i=0; i<cantP; i++){
        orden[i] = i;
    }
    for (int i=0; i<cantP-1; i++){
        for (int  x=0; x<cantP-1; x++)
        {
            if (vRecaudacion[orden [x]] < vRecaudacion[orden [x+1]]){
                int aux = orden[x];
                orden[x] = orden[x+1];
                orden[x+1] = aux;
            }
        }
    }
    system("cls");
    cout << "=================================================================================================================" << endl;
    cout << endl;
    cout << "                                  RECAUDACION POR PELICULA DURANTE EL ANIO " << anio << endl;
    cout << endl;
    cout << "=================================================================================================================" << endl;
    cout << left << setw(50) << "PELICULA" << " | " << setw(18) << "GENERO" << " | " << setw(17) << "ENTRADAS VENDIDAS" << " | "
         << setw(15) << "TOTAL RECAUDADO" << endl;
    cout << "================================================================================================================" << endl;

    for (int x=0; x<cantP; x++){
        int i = orden[x];

        if (vCant[i] > 0){
            Pelicula pelicula = archP.leerRegistro(i);
            cout << left << setw(50) << pelicula.getTitulo() << " | " << setw(18) << pelicula.getGenero() << " | " << setw(17) << vCant[i] << " | $"
                 << setw(13) <<(long long)vRecaudacion[i] << endl;
            cout << "----------------------------------------------------------------------------------------------------------------" <<endl;
            }
    }

    cout << left << setw(50) << "TOTAL" << setw(21) << "" << " | " << setw(17) << cantTotal << " | $" << setw(13) <<(long long)recaudacionTotal << endl;
            cout << "----------------------------------------------------------------------------------------------------------------" <<endl;

    system("pause");
}



void informeOcupacionPorFuncion()
{
    system("cls");
    ArchivoFunciones archFunciones;
    ArchivoSalas archSalas;
    int cantFunciones = archFunciones.contarRegistros();

    if (cantFunciones <= 0)
    {
        cout << "No hay funciones registradas en el sistema." << endl;
        system("pause");
        return;
    }

    system("cls");
    cout << "==============================================================================" << endl;
    cout << endl;
    cout << "                     PORCENTAJE DE OCUPACION POR FUNCION                " << endl;
    cout << endl;
    cout << "==============================================================================" << endl;
    cout << left  << setw(12) << "FUNCION ID"
         << " | " << setw(12) << "FECHA"
         << " | " << setw(7)  << "HORA"
         << " | " << setw(13) << "PELICULA ID"
         << " | " << setw(9)  << "SALA ID"
         << " | " << "OCUPACION" << endl;
    cout << "==============================================================================" << endl;
    bool hayFuncionesActivas = false;

    for (int i = 0; i < cantFunciones; i++)
    {
        Funcion f = archFunciones.leerRegistro(i);

        if (f.getEstado() == true)
        {
            hayFuncionesActivas = true;
            int posSala = archSalas.buscarRegistro(f.getIdSala());
            int capacidadTotal = 0;

            if (posSala != -1)
            {
                Sala s = archSalas.leerRegistro(posSala);
                capacidadTotal = s.getCapacidadButacas();
            }
            int butacasVendidas = butacasOcupadas(f.getIdFuncion());

            float porcentajeOcupacion = 0;
            if (capacidadTotal > 0)
            {
                porcentajeOcupacion = ((float)butacasVendidas / capacidadTotal) * 100.0;
            }

            cout << left << setw(12) << f.getIdFuncion() << " | ";

            f.getFecha().Mostrar();
            cout << "   | "; // Espacios de relleno para alinear con setw(12) de FECHA

            f.getHorario().Mostrar();
            cout << "  | ";  // Espacios de relleno para alinear con setw(7) de HORA

            cout << left << setw(13) << f.getIdPelicula()
                 << " | " << setw(9)  << f.getIdSala()
                 << " | ";

            cout << fixed << setprecision(2) << porcentajeOcupacion << "% ("
                 << butacasVendidas << "/" << capacidadTotal << ")" << endl;

            cout << "==============================================================================" << endl;
        }
    }

    if (hayFuncionesActivas == false)
    {
        cout << "No hay funciones activas para generar el informe." << endl;
    }

    system("pause");
}



void informeEntradasPorFormato()
{
    system("cls");
    ArchivoDetalleEntradas archD;
    ArchivoCompras archC;
    ArchivoSalas archS;
    ArchivoFormato archF;

    int ventas = archD.contarRegistros();
    if (ventas <= 0)
    {
        cout << "No se registraron ventas. " << endl;
        system("pause");
        return;
    }

    int totalEntradas = 0;
    vector <int> entradasXformato;
    vector <Formato> vecFormato;
    int cantFormatos = archF.contarRegistros();
    for (int i = 0; i < cantFormatos; i++)
    {
        Formato f = archF.leerRegistro(i);
        vecFormato.push_back(f);
        entradasXformato.push_back(0);
    }

    int anio;
    cout << "INGRESE AL ANIO A ANALIZAR (0 PARA EL ACTUAL): ";
    cin >> anio;
    if (anio == 0)
    {
        time_t t = time(nullptr);
        anio = localtime(&t)->tm_year + 1900;
    }

    for (int i = 0; i < ventas; i++)
    {
        DetalleEntrada entrada = archD.leerRegistro(i);
        int idCompra = entrada.getIdCompra();
        int posCompra = archC.buscarRegistro(idCompra);
        if (posCompra != -1)
        {
            Compra compra = archC.leerRegistro(posCompra);
            if (compra.getEstado() && compra.getFecha().getAnio() == anio)
            {
                int idSala = entrada.getIdSala();
                int posSala = archS.buscarRegistro(idSala);
                if (posSala != -1)
                {
                    Sala sala = archS.leerRegistro(posSala);
                    int idFormato = sala.getFormatoProyeccion();
                    int posFormato = archF.buscarPorID(idFormato);
                    if (posFormato != -1)
                    {
                        entradasXformato[posFormato]++;
                        totalEntradas++;
                    }
                }
            }
        }
    }

    if (totalEntradas == 0)
    {
        cout << "No hay ventas registradas en el anio " << anio << "." << endl;
        system("pause");
        return;
    }

    system("cls");
    cout << "==========================================================================" << endl;
    cout << endl;
    cout << "           ENTRADAS VENDIDAS POR FORMATO EN EL ANIO " << anio << ":" << endl;
    cout << endl;
    cout << "==========================================================================" << endl;

    cout << left  << setw(25) << "FORMATO"
         << " | " << setw(18) << "ENTRADAS VENDIDAS"
         << " | " << "PORCENTAJE DEL TOTAL" << endl;

    cout << "==========================================================================" << endl;

    for (int i = 0; i < entradasXformato.size(); i++)
    {
        float porcentaje;
        if (totalEntradas > 0)
        {
            porcentaje = ((float)entradasXformato[i] * 100) / totalEntradas;
        }

    cout << left  << setw(25) << vecFormato[i].getNombre()
             << " | " << setw(18) << entradasXformato[i]
             << " | " << fixed << setprecision(2) << porcentaje << "%" << endl;
    }

    cout << "==========================================================================" << endl;

    cout << left  << setw(25) << "TOTAL"
         << " | " << setw(18) << totalEntradas
         << " | 100%" << endl;

    cout << "==========================================================================" << endl;

    system("pause");
}



void informeSociosMasFrecuentes()
{
    system("cls");
    ArchivoSocios archSocios;
    ArchivoCompras archCompras;

    int cantSocios = archSocios.contarRegistros();
    int cantCompras = archCompras.contarRegistros();

    if (cantSocios <= 0 || cantCompras <= 0)
    {
        cout << "No hay socios o compras para generar el ranking." << endl;
        system("pause");
        return;
    }

    vector<int> vecIdSocios;
    vector<int> vecCantidadCompras;

    for (int i = 0; i < cantSocios; i++)
    {
        Socio s = archSocios.leerRegistro(i);
        if (s.getEstado())
        {
            vecIdSocios.push_back(s.getIdSocio());
            vecCantidadCompras.push_back(0);
        }
    }

    int SociosActivos = vecIdSocios.size();
    if (SociosActivos == 0)
    {
        cout << "No hay socios activos en el sistema." << endl;
        system("pause");
        return;
    }

    for (int i = 0; i < cantCompras; i++)
    {
        Compra c = archCompras.leerRegistro(i);
        if (c.getEstado())
        {
            int idSocioCompra = c.getIdSocio();
            for (int j = 0; j < SociosActivos; j++)
            {
                if (vecIdSocios[j] == idSocioCompra)
                {
                    vecCantidadCompras[j]++;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < SociosActivos - 1; i++)
    {
        for (int j = 0; j < SociosActivos - 1 - i; j++)
        {
            if (vecCantidadCompras[j] < vecCantidadCompras[j + 1])
            {
                int auxComp = vecCantidadCompras[j];
                vecCantidadCompras[j] = vecCantidadCompras[j + 1];
                vecCantidadCompras[j + 1] = auxComp;

                int auxId = vecIdSocios[j];
                vecIdSocios[j] = vecIdSocios[j + 1];
                vecIdSocios[j + 1] = auxId;
            }
        }
    }

    system("cls");
    cout << "==========================================================================" << endl;
    cout << endl;
    cout << "                     RANKING DE SOCIOS MAS FRECUENTES                     " << endl;
    cout << endl;
    cout << "==========================================================================" << endl;
    cout << left
         << setw(8)  << "PUESTO" << " | "
         << setw(10) << "ID SOCIO" << " | "
         << setw(30) << "NOMBRE Y APELLIDO" << " | "
         << right << setw(14) << "CANTIDAD COMPRAS" << endl;

    cout << "==========================================================================" << endl;

    int puesto = 1;
    for (int i = 0; i < SociosActivos; i++)
    {
        if (vecCantidadCompras[i] > 0)
        {
            int posSoc = archSocios.buscarRegistro(vecIdSocios[i]);
            Socio s = archSocios.leerRegistro(posSoc);

            string nombreCompleto = string(s.getNombre()) + " " + s.getApellido();

            cout << left
                 << setw(8)  << puesto << " | "
                 << setw(10) << vecIdSocios[i] << " | "
                 << setw(30) << nombreCompleto << " | "
                 << vecCantidadCompras[i] << endl;

            cout << "==========================================================================" << endl;
            puesto++;
        }
    }

    if (puesto == 1)
    {
        cout << "Aun no hay compras registradas asociadas a socios activos." << endl;
    }

    cout << endl;
    system("pause");
}



void informeImpactoDescuentos()
{
    system("cls");
    ArchivoDescuento archDesc;
    ArchivoCompras archComp;
    ArchivoDetalleEntradas archDet;

    int cantD = archDesc.cantidadRegistros();
    int cantComp = archComp.contarRegistros();
    int cantDet = archDet.contarRegistros();

    if (cantComp <= 0 || cantDet <= 0)
    {
        cout << "No hay compras registradas para generar el informe." << endl;
        system("pause");
        return;
    }

    int anioFiltro;
    cout << "INGRESE ANIO A ANALIZAR (0 para anio actual 2026): ";
    cin >> anioFiltro;

    if (anioFiltro == 0)
    {
        time_t t = time(nullptr);
        anioFiltro = localtime(&t)->tm_year + 1900;
    }

    vector<Descuento> vecDescuentos;
    vector<int> vecOperaciones;
    vector<float> vecTotalDescontado;

    for (int i = 0; i < cantD; i++)
    {
        Descuento d = archDesc.leer(i);
        vecDescuentos.push_back(d);
        vecOperaciones.push_back(0);
        vecTotalDescontado.push_back(0.0);
    }

    float valorBrutoTotal = 0;
    float totalDescontadoGlobal = 0;
    int totalOperacionesConDesc = 0;

    for (int i = 0; i < cantDet; i++)
    {
        DetalleEntrada d = archDet.leerRegistro(i);
        int posComp = archComp.buscarRegistro(d.getIdCompra());
        if (posComp != -1)
        {
            Compra comp = archComp.leerRegistro(posComp);
            if (comp.getEstado() && comp.getFecha().getAnio() == anioFiltro)
            {
                int idDesc = d.getIdDescuento();
                if (idDesc == 0)continue;

                int posD = archDesc.buscarPorID(idDesc);
                Descuento descObj = archDesc.leer(posD);

                float montoDesc = d.getPrecioBase() - d.getPrecioFinal();
                valorBrutoTotal += d.getPrecioBase();

                for (size_t j = 0; j < vecDescuentos.size(); j++)
                {
                    if (vecDescuentos[j].getIDDescuento() == idDesc)
                    {
                        vecOperaciones[j]++;
                        vecTotalDescontado[j] += montoDesc;
                        break;
                    }

                }
                totalDescontadoGlobal += montoDesc;
                totalOperacionesConDesc++;
            }
        }
    }

    if (totalOperacionesConDesc <= 0){
        cout <<"\n NO SE REGISTRARON DESCUENTOS DURANTE EL ANIO " <<anioFiltro <<"." <<endl <<endl;
        system("pause");
        return;
    }

    float montoNetoAbonado = valorBrutoTotal - totalDescontadoGlobal;

    system("cls");
    cout << "==========================================================================" << endl;
    cout << endl;
    cout << "               IMPACTO DE PROMOCIONES Y DESCUENTOS - ANIO " << anioFiltro << endl;
    cout << endl;
    cout << "==========================================================================" << endl;
    cout << left << setw(35) << "PROMOCION" << " | " << setw(15) << "OPERACIONES" << " | " << "TOTAL DESCONTADO" << endl;
    cout << "==========================================================================" << endl;

    for (size_t i = 0; i < vecDescuentos.size(); i++)
    {
        if (vecOperaciones[i] > 0)
        {
            cout << left << setw(35) << vecDescuentos[i].getNombre() << " | " << setw(15) << vecOperaciones[i]
                 << " | $" << (long long)vecTotalDescontado[i] << endl;
        }
    }

    cout << "==========================================================================" << endl;
    cout << left << setw(35) << "TOTAL" << " | " << setw(15) << totalOperacionesConDesc << " | $" << (long long)totalDescontadoGlobal << endl;
    cout << "==========================================================================" << endl;
    cout << "VALOR BRUTO (SIN DESCUENTOS): $" << (long long)valorBrutoTotal << endl;
    cout << "TOTAL DESCONTADO:             $" << (long long)totalDescontadoGlobal << endl;
    cout << "MONTO NETO ABONADO:           $" << (long long)montoNetoAbonado << endl;
    cout << "==========================================================================" << endl;

    system("pause");
}




void informeTicketsSuperanPromedio()
{
    system("cls");
    ArchivoCompras archComp;
    ArchivoDetalleEntradas archDet;
    int cantC = archComp.contarRegistros();
    int cantD = archDet.contarRegistros();

    if (cantC <= 0 || cantD <= 0)
    {
        cout << "No hay compras registradas para generar el informe." << endl;
        system("pause");
        return;
    }

    vector<float> vGastos(cantC, 0.0f);
    vector<int> vCantEnt(cantC, 0);
    float totalMonto = 0.0;
    int contadorActivas = 0;

    for (int i=0; i<cantD; i++)
    {
        DetalleEntrada detalle = archDet.leerRegistro(i);
        int  posCompra = archComp.buscarRegistro(detalle.getIdCompra());
        if (posCompra == -1) continue;

        Compra compra = archComp.leerRegistro(posCompra);

        if (compra.getEstado()){
            vGastos[posCompra] += detalle.getPrecioFinal();
            vCantEnt[posCompra] ++;
        }
    }

    int ticketsValidos = 0;
    for (int i = 0; i < cantC; i++) {
        if (vGastos[i] > 0) {
            totalMonto += vGastos[i];
            ticketsValidos++;
        }
    }
    if (ticketsValidos <= 0) {
        cout << "No hay ventas registradas." << endl;
        system("pause");
        return;
    }

    float gastoPromedio = totalMonto / ticketsValidos;
    int cantTicketsMayorPromedio = 0;

    system("cls");
    cout << "==================================================================================================" << endl;
    cout <<endl;
    cout << "                               TICKETS QUE SUPERAN EL GASTO PROMEDIO                " << endl;
    cout <<endl;
    cout << "==================================================================================================" << endl;
    cout << "                                GASTO PROMEDIO GENERAL: $" <<(long long)gastoPromedio << endl;
    cout << "==================================================================================================" << endl;
    cout << left << setw(11) << "ID COMPRA" << " | "
         << setw(28) << "SOCIO" << " | "
         << setw(11) << "FECHA" << " | "
         << setw(7)  << "HORA" << " | "
         << setw(15) <<"CANT. ENTRADAS" <<"|"
         << setw(13) << "MONTO TOTAL" << endl;
    cout << "==================================================================================================" << endl;

    for (int i=0; i<cantC; i++){
        if (vGastos[i]> gastoPromedio){
            cantTicketsMayorPromedio ++ ;
            Compra compra = archComp.leerRegistro(i);
            ArchivoSocios archS;
            int posSocio = archS.buscarRegistro(compra.getIdSocio());
            Socio socio = archS.leerRegistro(posSocio);
            cout << left
                 << setw(12) << compra.getIdCompra() << "| "
                 << setw(10) << socio.getNombre()
                 << setw(10) <<socio.getApellido() << "(ID: "
                 << setw(2) << socio.getIdSocio() <<") | "
                 << setw(2)  << compra.getFecha().getDia() << "/"
                 << setw(2)  << compra.getFecha().getMes() << "/"
                 << setw(6)  << compra.getFecha().getAnio() << "| "
                 << setw(2)  << compra.getHorario().getHora() << ":"
                 << setw(5)  << compra.getHorario().getMinutos() << "| "
                 << setw(15) << vCantEnt[i] << "| $"
                 << setw(13) << vGastos[i] <<endl;
            cout << "--------------------------------------------------------------------------------------------------" <<endl;
        }
    }
    cout << "==================================================================================================" << endl;
    cout <<"\n                      CANTIDAD DE TICKETS EVALUADOS: " <<cantC <<endl;
    cout <<"                      CANTIDAD DE TICKETS QUE SUPERAN EL PROMEDIO: " <<cantTicketsMayorPromedio <<endl;
    cout << "\n==================================================================================================" << endl;
    system("pause");

}



