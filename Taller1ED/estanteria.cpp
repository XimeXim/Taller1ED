
#include "Estanteria.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include "zapato.h"

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


