#include "sistema.h"
#include "NodoZapato.h"
#include "estanteria.h"
using namespace std;

Sistema::Sistema()
{
    MenuPrincipal();
}

Sistema::~Sistema()
{
}

static bool stringToBool(string str){
    return (str == "true" || str == "1");
}


void Sistema::lecturaArchivos() {

    fstream archivoStock("stock.csv");
    printf("Cargando...\n");
    string input = "";
    
    e = new Estanteria();
    Zapato* zap;
    NodoZapato* nodo;

    while (getline(archivoStock, input)) 
    {
        int modelo = 0;
        string modeloAux = "";
        int talla = 0;
        string tallaAux = "";
        int precio = 0;
        string precioAux = "";
        int cantidadPares = 0;
        string cantParesAux = "";
        string color = "";
        string genero = "";
        bool cordones;
        string cordonesAux = "";

        stringstream ss(input);
        getline(ss, modeloAux, ',');
        getline(ss, tallaAux, ',');
        getline(ss, precioAux, ',');
        getline(ss, cantParesAux, ',');
        getline(ss, color, ',');
        getline(ss, genero, ',');
        getline(ss, cordonesAux, ',');

        modelo = stoi(modeloAux);
        talla = stoi(tallaAux);
        precio = stoi(precioAux);
        cantidadPares = stoi(cantParesAux);
        cordones = stringToBool(cordonesAux);

        zap = new Zapato(modeloAux,talla,precio,cantidadPares,color,genero,cordones);
        nodo = new NodoZapato(zap, modelo, talla);
        e->agregarAEstante(nodo);
        

    }

    fstream archivoBodega("bodega.csv");
    string inputB = "";
    NodoZapato* nodoB;
    eB = new Estanteria();
    Zapato* zapBodega;

    while (getline(archivoBodega, inputB))
    {
        int modeloB = 0;
        string modeloAuxB = "";
        int tallaB = 0;
        string tallaAuxB = "";
        int precioB = 0;
        string precioAuxB = "";
        int cantidadParesB = 0;
        string cantParesAuxB = "";
        string colorB = "";
        string generoB = "";
        bool cordonesB;
        string cordonesAuxB = "";

        stringstream ssB(inputB);
        getline(ssB, modeloAuxB, ',');
        getline(ssB, tallaAuxB, ',');
        getline(ssB, precioAuxB, ',');
        getline(ssB, cantParesAuxB, ',');
        getline(ssB, colorB, ',');
        getline(ssB, generoB, ',');
        getline(ssB, cordonesAuxB, ',');

        modeloB = stoi(modeloAuxB);
        tallaB = stoi(tallaAuxB);
        precioB = stoi(precioAuxB);
        cantidadParesB = stoi(cantParesAuxB);
        cordonesB = stringToBool(cordonesAuxB);

        zapBodega = new Zapato(modeloAuxB, tallaB, precioB, cantidadParesB, colorB, generoB, cordonesB);
        nodoB = new NodoZapato(zapBodega, modeloB, tallaB);
        eB->agregarAEstante(nodoB);
        
    }


}

//Hacer otro metodo para ordenarla mpp segun modelo y talla

    //actualizar excel
void Sistema::actualizarArchivos()
{
    
    ofstream sobreEscritura;
    sobreEscritura.open("stock_test.csv");
    sobreEscritura.close();
    int x = e->getLargo();
    NodoZapato** mpp = e->getModelo();
    e->agregarArchivo(mpp[x]);

}



void Sistema::MenuPrincipal() {

    lecturaArchivos();
    Estanteria estanteria;
    int opcionMenu = 0;
    while (opcionMenu != 5){

        cout << "Menú Principal" << endl;
        cout << "Ingrese su opción:" << endl;
        cout << "1) Vender zapato" << endl;
        cout << "2) Rellenar estante" << endl;
        cout << "3) Ver estante" << endl;
        cout << "4) Ver estadísticas" << endl;
        cout << "5) Cerrar Programa" << endl;
        cin >> opcionMenu;
        switch (opcionMenu){
            case 1:
                estanteria.venderZapato();
                break;
            case 2:
                estanteria.ModeloTallaRelleno(eB);
            case 3:
                estanteria.imprimirEstante(e);
            case 4:
                cout << "Entrando a las estadisticas" << endl;
                MenuEstadisticas();
            case 5:
                actualizarArchivos();
                cout << "Saliendo del sistema, muchas gracias." << endl;
        }
    }
}

void Sistema::MenuEstadisticas() {

    Estanteria estanteria;
    std::vector <std::string> modelos = estanteria.getModelosVendidos();
    std::vector <int> tallas = estanteria.getTallasVendidas();
    int zapatosNegros = estanteria.getCantZapatosNegrosVendidos();
    int zapatosBlancos = estanteria.getCantZapatosBlancosVendidos();
    int zapatos = estanteria.getCantZapatosVendidos();
    int ventasTotales = estanteria.getVentasTotales();
    int opcionEstadisticas = 0;
    while (opcionEstadisticas != 5){

        cout << "Menú Estadísticas" << endl;
        cout << "Ingrese su opción:" << endl;
        cout << "1) Modelo más vendido" << endl;
        cout << "2) Talla de zapatos más vendida" << endl;
        cout << "3) Porcentaje de ventas según color" << endl;
        cout << "4) Imprimir Ventas totales" << endl;
        cout << "5) Menú anterior" << endl;
        cin >> opcionEstadisticas;
        switch (opcionEstadisticas){
            case 1:
                estanteria.modeloMasVendido(modelos);
                break;
            case 2:
                estanteria.tallaMasVendida(tallas);
                break;
            case 3:
                estanteria.porcentajeColorBlancoVendido(zapatosBlancos, zapatos);
                estanteria.porcentajeColorNegroVendido(zapatosNegros, zapatos);
                break;
            case 4:
                cout << "Las ventas totales son: " << ventasTotales << endl;
                break;
            case 5:
                cout << "Saliendo al menú principal" << endl;
                return;
            default:
                cout << "Opnción invalida, volviendo al menu principal" << endl;
        }
    }


}