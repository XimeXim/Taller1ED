
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

void Estanteria::setModelo(nodoZapato** modelo) {
    Modelo = modelo;
}

NodoZapato** Estanteria::getTalla() const {
    return Talla;
}

void Estanteria::setTalla(NodoZapato** talla) {
    Talla = talla;
}

const int* Estanteria::getModelosVendidos() const {
    return modelosVendidos;
}

const int* Estanteria::getTallasVendidas() const {
    return tallasVendidas;
}

const std::string* Estanteria::getColoresVendidos() const {
    return coloresVendidos;
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
    if (buscarModeloZapato(modeloBuscado) && buscarTallaZapato(tallaBuscada)) {
        for (int i = 0; i < alto; ++i) {
            NodoZapato* nodoZapatoAObtener = Modelo[i]->getNodoDeIzquierda();
            while (nodoZapatoAObtener != Modelo[i]) {
                if (nodoZapatoAObtener->getX() == modeloBuscado && nodoZapatoAObtener->getY() == tallaBuscada) {
                    nodoZapatoAObtener->getZapato()->setCantidadPares(
                        nodoZapatoAObtener->getZapato()->getCantidadPares() - 1);






                    return true;
                }
            }
        }
        return false;
    }
}

int Estanteria::modeloMasVendido() {}

int Estanteria::tallaMasVendida() {}

int Estanteria::porcentajeColorMasVendido() {}

/*
void Estanteria::lecturaArchivos() {
    printf("Cargando estante...\n")
    std::ifstream archivoStock("stock.csv");

    if (!archivoStock.is_open()){
        std::cerr << "No se pudo abrir el archivo.." << std::endl;
        return;
    }

    Estanteria* mpp = new estante();

    Zapato* z;
    std::string archivoCargado;
    alto = 1000;
    while (std::getline(archivoStock, archivoCargado)){
        std::istringstream ss (archivoCargado);
        z = new zapato();

        std::string modelo;
        int talla;
        int precio;
        int cantidadPares;
        std::string color;
        std::string genero;
        bool cordones;

        std::getline(ss, modelo, ',');
        std::getline(ss, talla, ',');
        std::getline(ss, precio, ',');
        std::getline(ss, cantidadPares, ',');
        std::getline(ss, color, ',');
        std::getline(ss, genero, ',');
        std::getline(ss, cordones, ',');

    }
}

void Estanteria::estadisticaPorcentaje(estante* mpp) {
    nodoZapato* aux;
    int totNegro = 0;
    std::cout << "Porcentaje de zapatos escolares vendidos vs zapatillas:" << "\n";
    for (int i = 0; i < largo; i++) {
        if(nodoZapato[i])
    }
}*/