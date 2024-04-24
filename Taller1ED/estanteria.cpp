
#include "estanteria.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "NodoZapato.h"
#include "zapato.h"
using namespace std;

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
    cout << "El modelo ingresado no se encuentra" << endl;
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
    cout << "La talla ingresada no se encuentra" << endl;
    return false;
}


void Estanteria::venderZapato() {

    int modeloBuscado = 0;
    int tallaBuscada = 0;
    cout <<"Ingrese el modelo del zapato que desea:" << endl;
    cin >> modeloBuscado;
    cout <<"Ingrese la talla del zapato que desea:" << endl;
    cin >> tallaBuscada;

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
                }
            }
        }
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
    std::cout << "Los modelos mas vendidos son: " << std::endl;
    for (int i = 0; i < modelosMasRepetidos.size(); ++i) {
        std::cout << modelosMasRepetidos[i] << std::endl;
    }
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
    std::cout << "Las tallas mas vendidas son: " << std::endl;
    for (int i = 0; i < tallasMasRepetidas.size(); ++i) {
        std::cout << tallasMasRepetidas[i] << std::endl;
    }
}

int porcentajeColorBlancoVendido(int cantZapatosBlancosVendidos, int cantZapatosVendidos) {

    int parteBlanca = cantZapatosBlancosVendidos;
    int totalZapatosVendidos = cantZapatosVendidos;
    int porcentajeZapatosBlancosVendidos = (parteBlanca * 100) / cantZapatosVendidos;
    cout <<"El porcentaje de pares de zapatos blancos es: "<< porcentajeZapatosBlancosVendidos << endl;
    return 0;

}

int porcentajeColorNegroVendido(int cantZapatosNegrosVendidos, int cantZapatosVendidos) {

    int parteNegra = cantZapatosNegrosVendidos;
    int totalZapatosVendidos = cantZapatosVendidos;
    int porcentajeZapatosNegrosVendidos = (parteNegra * 100) / cantZapatosVendidos;
    cout <<"El porcentaje de pares de zapatos negros es: "<< porcentajeZapatosNegrosVendidos << endl;
    return 0;
}

void Estanteria::agregarAEstante(NodoZapato* nodo) {
    int y = nodo->getY();
    int x = nodo->getX();

    NodoZapato* aux = Talla[x];
    while (aux->getNodoDeIzquierda()->getY() > 0 && aux->getNodoDeIzquierda()->getY() > y) {
        if (aux->getNodoDeIzquierda()->getY() == y) {
            return;
        }
        aux = aux->getNodoDeIzquierda();
    }
    nodo->setNodoDeIzquierda(aux->getNodoDeIzquierda());
    aux->setNodoDeIzquierda(nodo);

    NodoZapato* AUX = Modelo[y];
    while (AUX->getNodoDeArriba()->getX() > 0 && AUX->getNodoDeArriba()->getX() > x) {
        AUX = AUX->getNodoDeArriba();
    }
    nodo->setNodoDeArriba(AUX->getNodoDeArriba());
    AUX->setNodoDeArriba(nodo);

    return;
}

void Estanteria::agregarArchivo(NodoZapato* nodo)
{

    if (nodo != NULL) {
        std::ofstream arch;
        arch.open("stock_test.csv", std::ios::app);
        
        for (int i = 0; i < largo; i++) {
            NodoZapato* aux = Modelo[i]->getNodoDeArriba();
            while (aux != Modelo[i]) {
                std::string data = nodo->getZapato()->getModelo();
                data += ",";
                data += nodo->getZapato()->getTalla();
                data += ",";
                data += std::to_string(nodo->getZapato()->getPrecio());
                data += ",";
                data += std::to_string(nodo->getZapato()->getCantidadPares());
                data += ",";
                data += nodo->getZapato()->getColor();
                data += ",";
                data += std::to_string(nodo->getZapato()->isCordones());

                arch << data << std::endl;
                agregarArchivo(nodo->getNodoDeArriba());
            }
            
        }
        
    }

}