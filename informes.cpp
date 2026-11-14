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
//    ArchivoDetalleEntradas archD;
//    ArchivoFunciones archF;
//    int ventas = archD.contarRegistros();
//    if (ventas <= 0){
//        cout <<"No se registraron ventas." <<endl;
//        system ("pause");
//        return;
//    }
//
//    for (int i=0; i<ventas; i++){
//        Funcion funcion = archF.leerRegistro(i);
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
    cout << "\n";
    cout << "                     PORCENTAJE DE OCUPACION POR FUNCION                " << endl;
    cout << "\n";
    cout << "==============================================================================" << endl;
//    cout << "FUNCION ID | FECHA      | HORA  | PELICULA ID | SALA ID | OCUPACION" << endl;
//    cout << "---------------------------------------------------------------------" << endl;
    cout << left  << setw(12) << "FUNCION ID"
     << " | " << setw(10) << "FECHA"
     << " | " << setw(5)  << "HORA"
     << " | " << setw(13) << "PELICULA ID"
     << " | " << setw(9)  << "SALA ID"
     << " | " << "OCUPACION" << endl;
     cout << "------------------------------------------------------------------------------" <<endl;

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

//            cout << f.getIdFuncion() << "          | ";
//            f.getFecha().Mostrar();
//            cout << " | ";
//            f.getHorario().Mostrar();
//            cout << " | " << f.getIdPelicula() << "           | " << f.getIdSala() << "       | ";
//            cout << porcentajeOcupacion << "% (" << butacasVendidas << "/" << capacidadTotal << ")" << endl;
//            cout << "---------------------------------------------------------------------" << endl;
        cout << left << setw(12) << f.getIdFuncion() << " | ";

        cout << setfill('0')
             << setw(2) << f.getFecha().getDia() << "/"
             << setw(2) << f.getFecha().getMes() << "/"
             << f.getFecha().getAnio()
             << setfill(' ') << " | ";

        cout << setfill('0')
             << setw(2) << f.getHorario().getHora() << ":"
             << setw(2) << f.getHorario().getMinutos()
             << setfill(' ') << " | ";

        cout << left << setw(13) << f.getIdPelicula()
             << " | " << setw(9)  << f.getIdSala()
             << " | ";

        cout << fixed << setprecision(2) << porcentajeOcupacion << "% ("
             << butacasVendidas << "/" << capacidadTotal << ")" << endl;

        cout << "------------------------------------------------------------------------------" << endl;
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
    ArchivoDetalleEntradas archD;
    ArchivoCompras archC;
    ArchivoSalas archS;
    ArchivoFormato archF;

    int ventas = archD.contarRegistros();
    if (ventas <= 0){
        cout <<"No se registraron ventas. " <<endl;
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
    cout <<"INGRESE AL ANIO A ANALIZAR (0 PARA EL ACTUAL): "; cin>>anio;
    if (anio == 0){
        time_t t = time(nullptr);
        anio = localtime(&t)->tm_year + 1900;
    }

    for (int i=0; i<ventas; i++){
        DetalleEntrada entrada = archD.leerRegistro(i);
        int idCompra = entrada.getIdCompra();
        int posCompra = archC.buscarRegistro(idCompra);
        if (posCompra != -1){
            Compra compra = archC.leerRegistro(posCompra);
            if (compra.getEstado() && compra.getFecha().getAnio() == anio){
                int idSala = entrada.getIdSala();
                int posSala = archS.buscarRegistro(idSala);
                if (posSala != -1){
                    Sala sala = archS.leerRegistro(posSala);
                    int idFormato = sala.getFormatoProyeccion();
                    int posFormato = archF.buscarPorID(idFormato);
                    if (posFormato != -1){
                        entradasXformato[posFormato]++;
                        totalEntradas ++;
                    }
                }
            }
        }
    }

    if (totalEntradas == 0){
        cout <<"No hay ventas registradas en el anio " <<anio <<"." <<endl;
        system("pause");
        return;
    }


    system("cls");
    cout << "==========================================================================" << endl;
    cout <<"\n";
    cout <<"           ENTRADAS VENDIDAS POR FORMATO EN EL ANIO " <<anio <<":" <<endl;
    cout <<"\n";
    cout << "==========================================================================" << endl;

    cout << left  << setw(25) << "FORMATO"
         << " | " << right << setw(18) << "ENTRADAS VENDIDAS"
         << " | " << right << setw(22) << "PORCENTAJE DEL TOTAL" << endl;

    cout << "--------------------------------------------------------------------------" << endl;

    for (size_t i = 0; i < entradasXformato.size(); i++) {
        double porcentaje = (static_cast<double>(entradasXformato[i]) / totalEntradas) * 100;
        cout << left  << setw(25) << vecFormato[i].getNombre()
             << " | " << right << setw(18) << entradasXformato[i]
             << " | " << right << setw(21) << porcentaje << " %" << endl;
    }

    cout << "--------------------------------------------------------------------------" << endl;

    cout << left  << setw(25) << "TOTAL"
         << " | " << right << setw(18) << totalEntradas
         << " | " << right << setw(21) << "100.00 %" << endl;

    cout << "==========================================================================" <<endl;

    system("pause");
}



void informeSociosMasFrecuentes() {
}


void informeImpactoDescuentos()
{
    system("cls");
    ArchivoDescuento archDesc;
    ArchivoCompras archComp;
    ArchivoDetalleEntradas archDet;
    ArchivoFunciones archFunc;
    ArchivoSalas archSalas;
    ArchivoFormato archForm;

    int cantDesc = archDesc.cantidadRegistros();
    int cantComp = archComp.contarRegistros();
    int cantDet = archDet.contarRegistros();

    if (cantComp <= 0 || cantDet <= 0)
    {
        cout << "No hay compras registradas para generar el informe." << endl;
        system("pause");
        return;
    }

    int anioFiltro = pedirEntero("INGRESE ANIO A ANALIZAR (0 para anio actual 2026): ");
    if (anioFiltro == 0){
        time_t t = time(nullptr);
        anioFiltro = localtime(&t)->tm_year + 1900;
    }

    vector<Descuento> vecDescuentos;
    vector<int> vecOperaciones;
    vector<float> vecTotalDescontado;

    for (int i = 0; i < cantDesc; i++)
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
                int posFunc = archFunc.buscarRegistro(d.getIdFuncion());
                if (posFunc != -1)
                {
                    Funcion func = archFunc.leerRegistro(posFunc);
                    int posSala = archSalas.buscarRegistro(func.getIdSala());

                    if (posSala != -1)
                    {
                        Sala sala = archSalas.leerRegistro(posSala);
                        int posForm = archForm.buscarPorID(sala.getFormatoProyeccion());

                        if (posForm != -1)
                        {
                            Formato form = archForm.leerRegistro(posForm);
                            float precioBase = form.getPrecio();
                            valorBrutoTotal += precioBase;

                            int idDesc = d.getIdDescuento();
                            if (idDesc > 0)
                            {
                                int posD = archDesc.buscarPorID(idDesc);
                                if (posD != -1)
                                {
                                    Descuento descObj = archDesc.leer(posD);
                                    float montoDesc = precioBase * (descObj.getPorcentaje() / 100.0);

                                    totalDescontadoGlobal += montoDesc;
                                    totalOperacionesConDesc++;

                                    for (int j = 0; j < (int)vecDescuentos.size(); j++)
                                    {
                                        if (vecDescuentos[j].getIDDescuento() == idDesc)
                                        {
                                            vecOperaciones[j]++;
                                            vecTotalDescontado[j] += montoDesc;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    float montoNetoAbonado = valorBrutoTotal - totalDescontadoGlobal;

    system("cls");
    cout << "=====================================================================" << endl;
    cout <<"\n";
    cout << "        IMPACTO DE PROMOCIONES Y DESCUENTOS - ANIO " << anioFiltro << endl;
    cout <<"\n";
    cout << "=====================================================================" << endl;
    cout << "PROMOCION                          | OPERACIONES  | TOTAL DESCONTADO" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    for (int i = 0; i < (int)vecDescuentos.size(); i++)
    {
        if (vecDescuentos[i].getEstado() || vecOperaciones[i] > 0)
        {
            cout << vecDescuentos[i].getNombre();
            int largo = strlen(vecDescuentos[i].getNombre());
            for (int k = largo; k < 35; k++)
            {
                cout << " ";
            }
            cout << "| " << vecOperaciones[i] << "           | $" << (long long)vecTotalDescontado[i] << endl;
        }
    }

    cout << "---------------------------------------------------------------------" << endl;
    cout << "TOTAL                              | " << totalOperacionesConDesc << "          | $" << (long long)totalDescontadoGlobal << endl;
    cout << "=====================================================================" << endl;
    cout << "VALOR BRUTO (SIN DESCUENTOS): $" << (long long)valorBrutoTotal << endl;
    cout << "TOTAL DESCONTADO:             $" << (long long)totalDescontadoGlobal << endl;
    cout << "MONTO NETO ABONADO:           $" << (long long)montoNetoAbonado << endl;
    cout << "=====================================================================" << endl;

    system("pause");
}

void informeTicketsSuperanPromedio() {
}
