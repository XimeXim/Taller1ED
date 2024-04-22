#include "sistema.h"
#include "NodoZapato.h"
using namespace std;

Sistema::Sistema()
{
}

Sistema::~Sistema()
{
}

bool Sistema::rellenarEstante(class NodoZapato* mppBodega) {


    std::string input;
    std::cout << "Porfavor, ingrese el modelo con el que desea rellenar el estante: ";
    std::cin >> input;

    //mppBodega = lecturaBodega();

    try {
        int modeloBuscado = std::stoi(input);
        std::cout << "El modelo ingresado es: " << modeloBuscado << std::endl;
        std::cout << "Buscando modelo..." << std::endl;
        std::string inputTalla;
       /* if (buscarModeloZapato(modeloBuscado) == true) {
            std::cout << "Se encontraron zapatos de este modelo! Porfavor ingrese tallas que quiere reponer: " << std::endl;
            std::cin >> inputTalla;

            try {
                int tallaBuscada = std::stoi(input);
                std::cout << "La talla ingresada es: " << tallaBuscada << std::endl;
                std::cout << "Buscando talla..." << std::endl;

                if (buscarTallaZapato(tallaBuscada) == true) {

                }
                
            }
            catch (const std::invalid_argument& e) {
                std::cerr << "Error: El modelo que ingreso no es un válido.Porfavor ingrese un numero valido." << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cerr << "Error: El número ingresado está fuera del rango de un int." << std::endl;
            }
        }*/
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: El modelo que ingreso no es un válido.Porfavor ingrese un numero valido." << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: El número ingresado está fuera del rango de un int." << std::endl;
    }


}

bool stringToBool(string str){
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

