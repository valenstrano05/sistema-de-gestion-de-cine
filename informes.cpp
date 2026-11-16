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
    ArchivoDetalleEntradas archD;
    ArchivoCompras archC;
    ArchivoFunciones archF;
    ArchivoPeliculas archP;
    ArchivoSalas archS;
    ArchivoFormato archFor;
    ArchivoDescuento archDesc;
    vector<Pelicula> pelicula;
    vector<int> vCant;
    vector<float> vPrecios;
    int cantTotal = 0;
    float precioTotal = 0.0;

    int ventas = archD.contarRegistros();
    if (ventas <= 0)
    {
        cout << "No se registraron ventas." << endl;
        system("pause");
        return;
    }

    int cantP = archP.contarRegistros();
    for (int i = 0; i < cantP; i++)
    {
        Pelicula p = archP.leerRegistro(i);
        pelicula.push_back(p);
        vCant.push_back(0);
        vPrecios.push_back(0.0);
    }

    int anio;
    cout << "INGRESE ANIO A ANALIZAR (0 PARA ANIO ACTUAL): ";
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
        if (posCompra == -1) continue;
        Compra compra = archC.leerRegistro(posCompra);
        if (compra.getEstado() == false || compra.getFecha().getAnio() != anio) continue;
        int idFuncion = entrada.getIdFuncion();
        int posFuncion = archF.buscarRegistro(idFuncion);
        if (posFuncion == -1) continue;
        Funcion funcion = archF.leerRegistro(posFuncion);
        int idPelicula = funcion.getIdPelicula();
        int posPelicula = archP.buscarPorID(idPelicula);
        if (posPelicula == -1) continue;
        int idSala = funcion.getIdSala();
        int posSala = archS.buscarRegistro(idSala);
        if (posSala == -1) continue;
        Sala sala = archS.leerRegistro(posSala);
        int idFormato = sala.getFormatoProyeccion();
        int posFormato = archFor.buscarPorID(idFormato);
        if (posFormato == -1) continue;
        Formato formato = archFor.leerRegistro(posFormato);
        float precioInicial = formato.getPrecio();
        float precioFinal = precioInicial;

        int idDesc = entrada.getIdDescuento();
        if (idDesc != 0)
        {
            int posDesc = archDesc.buscarPorID(idDesc);
            if (posDesc != -1)
            {
                Descuento descuento = archDesc.leer(posDesc);
                float porcDesc = descuento.getPorcentaje();
                precioFinal = precioInicial * (1.0 - (porcDesc / 100.0));
            }
        }
        vCant[posPelicula]++;
        vPrecios[posPelicula] += precioFinal;
        cantTotal++;
        precioTotal += precioFinal;
    }
    if (cantTotal == 0)
    {
        cout << "No hay entradas vendidas en el anio " << anio << "." << endl;
        system("pause");
        return;
    }
    vector<int> orden(cantP);
    for (int i = 0; i < cantP; i++)
    {
        orden[i] = i;
    }
    for (int i = 0; i < cantP - 1; i++)
    {
        for (int j = 0; j < cantP - 1 - i; j++)
        {
            if (vPrecios[orden[j]] < vPrecios[orden[j + 1]])
            {
                int aux = orden[j];
                orden[j] = orden[j + 1];
                orden[j + 1] = aux;
            }
        }
    }
    system("cls");
    cout << "======================================================================================================================" << endl;
    cout << endl;
    cout << "                               RECAUDACION POR PELICULA DURANTE EL ANIO " << anio << endl;
    cout << endl;
    cout << "======================================================================================================================" << endl;
    cout << left
         << setw(48) << "PELICULA" << " | "
         << setw(18) << "GENERO" << " | "
         << setw(19) << "ENTRADAS VENDIDAS" << " | "
         << setw(17) << "TOTAL RECAUDADO" << endl;

    cout << "======================================================================================================================" << endl;

    for (int k = 0; k < cantP; k++)
    {
        int i = orden[k];
        cout << left
             << setw(48) << pelicula[i].getTitulo() << " | "
             << setw(18) << pelicula[i].getGenero() << " | "
             << setw(19) << vCant[i] << " | $"
             << setw(15) << (long long)vPrecios[i] << endl;
    }
    cout << "======================================================================================================================" << endl;
    cout << left
         << setw(48) << "TOTAL"
         << setw(21) << "" << " | "
         << setw(19) << cantTotal << " | $"
         << setw(15) << (long long)precioTotal << endl;

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
         << " | " << setw(10) << "FECHA"
         << " | " << setw(5)  << "HORA"
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
         << " | " << right << setw(18) << "ENTRADAS VENDIDAS"
         << " | " << right << setw(22) << "PORCENTAJE DEL TOTAL" << endl;

    cout << "==========================================================================" << endl;

    for (size_t i = 0; i < entradasXformato.size(); i++)
    {
        float porcentaje = ((float)entradasXformato[i] / totalEntradas) * 100;
        cout << left  << setw(25) << vecFormato[i].getNombre()
             << " | " << right << setw(18) << entradasXformato[i]
             << " | " << right << setw(21) << porcentaje << " %" << endl;
    }

    cout << "==========================================================================" << endl;

    cout << left  << setw(25) << "TOTAL"
         << " | " << right << setw(18) << totalEntradas
         << " | " << right << setw(21) << "100.00 %" << endl;

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
    ArchivoFunciones archFunc;
    ArchivoSalas archSalas;
    ArchivoFormato archForm;

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
    cout << endl;
    cout << "        IMPACTO DE PROMOCIONES Y DESCUENTOS - ANIO " << anioFiltro << endl;
    cout << endl;
    cout << "=====================================================================" << endl;
    cout << "PROMOCION                         | OPERACIONES  | TOTAL DESCONTADO" << endl;
    cout << "=====================================================================" << endl;

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
            cout << "| " << vecOperaciones[i] << "            | $" << (long long)vecTotalDescontado[i] << endl;
        }
    }

    cout << "=====================================================================" << endl;
    cout << "TOTAL                             | " << totalOperacionesConDesc << "          | $" << (long long)totalDescontadoGlobal << endl;
    cout << "=====================================================================" << endl;
    cout << "VALOR BRUTO (SIN DESCUENTOS): $" << (long long)valorBrutoTotal << endl;
    cout << "TOTAL DESCONTADO:             $" << (long long)totalDescontadoGlobal << endl;
    cout << "MONTO NETO ABONADO:           $" << (long long)montoNetoAbonado << endl;
    cout << "=====================================================================" << endl;

    system("pause");
}

void informeTicketsSuperanPromedio()
{
    system("cls");
    ArchivoCompras archComp;
    ArchivoDetalleEntradas archDet;
    ArchivoFunciones archFunc;
    ArchivoSalas archSalas;
    ArchivoFormato archForm;
    ArchivoDescuento archDesc;

    int cantC = archComp.contarRegistros();
    int cantD = archDet.contarRegistros();

    if (cantC <= 0 || cantD <= 0)
    {
        cout << "No hay compras registradas para generar el informe." << endl;
        system("pause");
        return;
    }

    float sumaTotal = 0;
    int contadorActivas = 0;

    for (int i = 0; i < cantC; i++)
    {
        Compra comp = archComp.leerRegistro(i);
        if (comp.getEstado())
        {
            float precioFinal = 0;
            for (int j = 0; j < cantD; j++)
            {
                DetalleEntrada det = archDet.leerRegistro(j);
                if (det.getIdCompra() == comp.getIdCompra())
                {
                    int posFunc = archFunc.buscarRegistro(det.getIdFuncion());
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
                                int idDesc = det.getIdDescuento();
                                if (idDesc > 0)
                                {
                                    int posD = archDesc.buscarPorID(idDesc);
                                    if (posD != -1)
                                    {
                                        Descuento desc = archDesc.leer(posD);
                                        float montoDesc = precioBase * (desc.getPorcentaje() / 100.0);
                                        precioFinal = precioBase - montoDesc;
                                    }
                                    else
                                    {
                                        precioFinal = precioBase;
                                    }
                                }
                                else
                                {
                                    precioFinal = precioBase;
                                }
                            }
                        }
                    }
                }
            }
            sumaTotal += precioFinal;
            contadorActivas++;
        }
    }

    if (contadorActivas == 0)
    {
        cout << "No hay compras activas en el sistema." << endl;
        system("pause");
        return;
    }

    float gastoPromedio = sumaTotal / contadorActivas;

    system("cls");
    cout << "==========================================================================" << endl;
    cout << endl;
    cout << "                    TICKETS QUE SUPERAN EL GASTO PROMEDIO                 " << endl;
    cout << endl;
    cout << "==========================================================================" << endl;
    cout << "GASTO PROMEDIO GENERAL: $" << (long long)gastoPromedio << endl;
    cout << "==========================================================================" << endl;
    cout << left
         << setw(12) << "ID COMPRA" << " | "
         << setw(10) << "ID SOCIO" << " | "
         << setw(12) << "FECHA" << " | "
         << setw(7)  << "HORA" << " | "
         << setw(13) << "MONTO PAGADO" << endl;
    cout << "==========================================================================" << endl;

    bool haySuperiores = false;

    for (int i = 0; i < cantC; i++)
    {
        Compra c = archComp.leerRegistro(i);
        if (c.getEstado())
        {
            float precioFinal = 0;
            for (int j = 0; j < cantD; j++)
            {
                DetalleEntrada d = archDet.leerRegistro(j);
                if (d.getIdCompra() == c.getIdCompra())
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
                                int idDesc = d.getIdDescuento();
                                if (idDesc > 0)
                                {
                                    int posD = archDesc.buscarPorID(idDesc);
                                    if (posD != -1)
                                    {
                                        Descuento desc = archDesc.leer(posD);
                                        float montoDesc = precioBase * (desc.getPorcentaje() / 100.0);
                                        precioFinal = precioBase - montoDesc;
                                    }
                                    else
                                    {
                                        precioFinal = precioBase;
                                    }
                                }
                                else
                                {
                                    precioFinal = precioBase;
                                }
                            }
                        }
                    }
                }
            }

            if (precioFinal > gastoPromedio)
            {
                haySuperiores = true;
                cout << left
                     << setw(12) << c.getIdCompra() << " | "
                     << setw(10) << c.getIdSocio() << " | ";
                c.getFecha().Mostrar();
                cout << " | ";
                c.getHorario().Mostrar();
                cout << " | $" << setw(10) << (long long)precioFinal << endl;
                cout << "==========================================================================" << endl;
            }
        }
    }

    if (haySuperiores == false)
    {
        cout << "No hay tickets que superen el gasto promedio." << endl;
        cout << "==========================================================================" << endl;
    }

    system("pause");
}
