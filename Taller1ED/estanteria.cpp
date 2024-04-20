
#include "Estanteria.h"
//#include "libxl.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include "zapato.h"


//using namespace libxl;


Estanteria::Estanteria() {
}

Estanteria::~Estanteria() {
}

int Estanteria::getLargo() const {
    return largo;
}

void Estanteria::setLargo(int largo) {
    Estanteria::largo = largo;
}

int Estanteria::getAlto() const {
    return alto;
}

void Estanteria::setAlto(int alto) {
    Estanteria::alto = alto;
}

NodoZapato** Estanteria::getModelo() const {
    return Modelo;
}

void Estanteria::setModelo(NodoZapato** modelo) {
    Modelo = modelo;
}

NodoZapato** Estanteria::getTalla() const {
    return Talla;
}

void Estanteria::setTalla(NodoZapato** talla) {
    Talla = talla;
}

int Estanteria::getCantZapatosBlancosVendidos() const {
    return cantZapatosBlancosVendidos;
}

void Estanteria::setCantZapatosBlancosVendidos(int cantZapatosBlancosVendidos) {
    Estanteria::cantZapatosBlancosVendidos = cantZapatosBlancosVendidos;
}

int Estanteria::getCantZapatosNegrosVendidos() const {
    return cantZapatosNegrosVendidos;
}

void Estanteria::setCantZapatosNegrosVendidos(int cantZapatosNegrosVendidos) {
    Estanteria::cantZapatosNegrosVendidos = cantZapatosNegrosVendidos;
}

int Estanteria::getVentasTotales() const {
    return ventasTotales;
}

void Estanteria::setVentasTotales(int ventasTotales) {
    Estanteria::ventasTotales = ventasTotales;
}

const std::vector<std::string> &Estanteria::getModelosVendidos() const {
    return modelosVendidos;
}

void Estanteria::setModelosVendidos(const std::vector<std::string> &modelosVendidos) {
    Estanteria::modelosVendidos = modelosVendidos;
}

const std::vector<int> &Estanteria::getTallasVendidas() const {
    return tallasVendidas;
}

void Estanteria::setTallasVendidas(const std::vector<int> &tallasVendidas) {
    Estanteria::tallasVendidas = tallasVendidas;
}

const std::vector<std::string> &Estanteria::getColoresVendidos() const {
    return coloresVendidos;
}

void Estanteria::setColoresVendidos(const std::vector<std::string> &coloresVendidos) {
    Estanteria::coloresVendidos = coloresVendidos;
}

int Estanteria::getCantZapatosVendidos() const {
    return cantZapatosVendidos;
}

void Estanteria::setCantZapatosVendidos(int cantZapatosVendidos) {
    Estanteria::cantZapatosVendidos = cantZapatosVendidos;
}

bool Estanteria::buscarModeloZapato(int modeloBuscado) {
    for (int i = 0; i < alto; ++i) {
        NodoZapato* AUX = Talla[i]->getNodoDeIzquierda();
        while (AUX != Talla[i]) {
            if (AUX->getX() == modeloBuscado) {
                return true;
            }
            AUX = AUX->getNodoDeIzquierda();
        }
    }
    return false;
}

bool Estanteria::buscarTallaZapato(int tallaBuscada) {
    for (int i = 0; i < largo; ++i) {
        NodoZapato* AUX = Modelo[i]->getNodoDeArriba();
        while (AUX != Modelo[i]) {
            if (AUX->getX() == tallaBuscada) {
                return true;
            }
            AUX = AUX->getNodoDeArriba();
        }
    }
    return false;
}


bool Estanteria::venderZapato(int modeloBuscado, int tallaBuscada) {

    if (buscarModeloZapato(modeloBuscado) && buscarTallaZapato(tallaBuscada)){
        for (int i = 0; i < alto; ++i) {
            NodoZapato* nodoZapatoAObtener = Modelo[i]->getNodoDeIzquierda();
            while (nodoZapatoAObtener != Modelo[i]) {
                if (nodoZapatoAObtener->getX() == modeloBuscado && nodoZapatoAObtener->getY() == tallaBuscada) {
                    nodoZapatoAObtener->getZapato()->setCantidadPares(
                            nodoZapatoAObtener->getZapato()->getCantidadPares() - 1);
                    std::string modeloZapatoVendido = nodoZapatoAObtener->getZapato()->getModelo();
                    int tallaZapatoVendida = nodoZapatoAObtener->getZapato()->getTalla();
                    std::string colorZapatoVendido = nodoZapatoAObtener->getZapato()->getColor();
                    modelosVendidos.push_back(modeloZapatoVendido);
                    tallasVendidas.push_back(tallaZapatoVendida);
                    coloresVendidos.push_back(colorZapatoVendido);
                    if (nodoZapatoAObtener->getZapato()->getColor() == "Blanco" || nodoZapatoAObtener->getZapato()->getColor() == "blanco"){
                        cantZapatosBlancosVendidos = cantZapatosBlancosVendidos + 1;
                        cantZapatosVendidos = cantZapatosVendidos + 1;
                        ventasTotales = ventasTotales + nodoZapatoAObtener->getZapato()->getPrecio();
                    }
                    if (nodoZapatoAObtener->getZapato()->getColor() == "Negro" || nodoZapatoAObtener->getZapato()->getColor() == "negro"){
                        cantZapatosNegrosVendidos = cantZapatosNegrosVendidos + 1;
                        cantZapatosVendidos = cantZapatosVendidos + 1;
                        ventasTotales = ventasTotales + nodoZapatoAObtener->getZapato()->getPrecio();
                    }
                    return true;
                }
            }
        }
        return false;
    }
}

std::vector <std::string> Estanteria::modeloMasVendido(std::vector <std::string> modelosVendidos) {
    std::unordered_map<std::string, int> frecuenciaModelo;
    std::string modeloMasVeces = modelosVendidos[0];
    int numeroVecesPresente = frecuenciaModelo[modeloMasVeces];
    for (int i = 0; i < modelosVendidos.size(); ++i) {
        frecuenciaModelo[modelosVendidos[i]]++;
    }
    std::vector <std::string> modelosMasRepetidos;
    for (int i = 0; i < modelosVendidos.size(); i++){
        if(frecuenciaModelo[modelosVendidos[i]] >= numeroVecesPresente){
            modelosMasRepetidos.push_back(modelosVendidos[i]);
            frecuenciaModelo[modelosVendidos[i]] = 0;
        }
    }
    return modelosMasRepetidos;
}

std::vector <int> Estanteria::tallaMasVendida(std::vector <int> tallasVendidas) {
    std::unordered_map<int, int> frecuenciaTalla;
    int tallaMasVeces = tallasVendidas[0];
    int numeroVecesPresente = frecuenciaTalla[tallaMasVeces];
    for (int i = 0; i < tallasVendidas.size(); ++i) {
        frecuenciaTalla[tallasVendidas[i]]++;
    }
    std::vector <int> tallasMasRepetidas;
    for (int i = 0; i < tallasVendidas.size(); i++){
        if (frecuenciaTalla[tallasVendidas[i]] >= numeroVecesPresente){
            tallasMasRepetidas.push_back(tallasVendidas[i]);
            frecuenciaTalla[tallasVendidas[i]] = 0;
        }
    }
    return tallasMasRepetidas;
}

int porcentajeColorBlancoVendido(int cantZapatosBlancosVendidos, int cantZapatosVendidos) {

    int parteBlanca = cantZapatosBlancosVendidos;
    int totalZapatosVendidos = cantZapatosVendidos;
    int porcentajeZapatosBlancosVendidos = (parteBlanca * 100) / cantZapatosVendidos;
    return porcentajeZapatosBlancosVendidos;
}

int porcentajeColorNegroVendido(int cantZapatosNegrosVendidos, int cantZapatosVendidos) {

    int parteNegra = cantZapatosNegrosVendidos;
    int totalZapatosVendidos = cantZapatosVendidos;
    int porcentajeZapatosNegrosVendidos = (parteNegra * 100) / cantZapatosVendidos;
    return porcentajeZapatosNegrosVendidos;
}

bool Estanteria::rellenarEstante(class NodoZapato* mppBodega) {
    
    
    std::string input;
    std::cout << "Porfavor, ingrese el modelo con el que desea rellenar el estante: ";
    std::cin >> input;

    //mppBodega = lecturaBodega();

    try {
        int modeloBuscado = std::stoi(input);
        std::cout << "El modelo ingresado es: " << modeloBuscado << std::endl;
        std::cout << "Buscando modelo..." << std::endl;
        std::string inputTalla;
        if (buscarModeloZapato(modeloBuscado) == true) {
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
        }
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: El modelo que ingreso no es un válido.Porfavor ingrese un numero valido." << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: El número ingresado está fuera del rango de un int." << std::endl;
    }

    
}


NodoZapato Estanteria::lecturaBodega() {

}
//FALTA AGREGAR A LA ESTANTERIA Y PROBAR SI REALMENTE FUNCA


/*
void Estanteria::lecturaArchivos() {
    printf("Cargando estante...\n");
        
        Book stock = xlCreateBook();
        Book bodega = xlCreateBook();
        NodoZapato* mpp = new NodoZapato();

    if (stock->load(L"stock.xlsx"))
    {
        class Sheet* hoja = stock->getSheet(0);

        if (hoja)
        {
            for (int i = 1; i < hoja->lastRow(); i++)
            {
                
                for (int j = 0; j < hoja->lastCol(); j++)
                {

                    Zapato* zap = new Zapato();

                    int modelo;
                    int talla;
                    int precio;
                    int cantidadPares;
                    std::string color;
                    std::string genero;
                    bool cordones;

                    //leer valores y asignar a atributos de zapato

                    switch (j){
                    case 0:
                        modelo = hoja->readNum(i, j);
                        zap->setModelo(modelo);
                        break;
                    case 1:
                        talla = hoja->readNum(i, j);
                        zap->setTalla(talla);
                        break;
                    case 2:
                        precio = hoja->readNum(i, j);
                        zap->setPrecio(precio);
                        break;
                    case 3:
                        cantidadPares = hoja->readNum(i, j);
                        zap->setCantidadPares(cantidadPares);
                        break;
                    case 4:
                        color = hoja->readStr(i, j);
                        zap->setColor(color);
                        break;
                    case 5:
                        genero = hoja->readStr(i, j);
                        zap->setGenero(genero);
                        break;
                    case 6:
                        cordones = hoja->readBool(i, j);
                        zap->setCordones(cordones);
                        break;
                    default:
                        break;
                    }
                    NodoZapato* zapatoInsertado;
                    zapatoInsertado->setZapato(zap);
                    
                }
                
            }
        }
        stock->release();
    }

}

//Hacer otro metodo para ordenarla mpp segun modelo y talla

    //actualizar excel
bool Estanteria::actualizarExcel(NodoZapato* mpp, int largo, int alto)
{
    Book* estanteActualizado = xlCreateXMLBook();

    if (estanteActualizado)
    {
        std::string archivoStock = "stock.xlsx";

        if (estanteActualizado->load(archivoStock))
        {
            Sheet* hoja = estanteActualizado->getSheet(0);
            if (hoja)
            {
                for (int i = 0; i < alto; i++)
                {
                    for (int j = 0; j < alto; j++)
                    {
                        switch (j)[{
                        case 0:
                            hoja->writeNum(i + 1, j, mpp[i][j]->getZapato()->getModelo());
                            break;
                        case 1:
                            hoja->writeNum(i + 1, j, mpp[i][j]->getZapato()->getTalla());
                            break;
                        case 2:
                            hoja->writeNum(i + 1, j, mpp[i][j]->getZapato()->getPrecio());
                            break;
                        case 3:
                            hoja->writeNum(i + 1, j, mpp[i][j]->getZapato()->getCantidadPares());
                            break;
                        case 4:
                            hoja->writeStr(i + 1, j, mpp[i][j]->getZapato()->getColor());
                            break;
                        case 5:
                            hoja->writeStr(i + 1, j, mpp[i][j]->getZapato()->getGenero());
                            break;
                        case 6:
                            hoja->writeBool(i + 1, j, mpp[i][j]->getZapato()->getCordones());
                            break;
                        default:
                            break;
                        }

                    }
                }
                estanteActualizado->save(archivoStock);
            }

        }
        estanteActualizado->release();
    }

    Book* bodegaActualizada = xlCreateXMLBook();
    if (bodegaActualizada) {
        std::string archivoBodega = "bodega.xlsx";
    }

}
*/
