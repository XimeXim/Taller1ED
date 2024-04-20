
#include "Estanteria.h"
#include "libxl.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include "zapato.h"

using namespace libxl;


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

//FALTA AGREGAR A LA ESTANTERIA Y PROBAR SI REALMENTE FUNCA
void Estanteria::lecturaArchivos() {
    printf("Cargando estante...\n")

    //// leer excel  stock
    Book* stock = xlCreateBook();
    Book* bodega = xlCreateBook();

    if (stock->load(L"stock.xls"))
    {
        Sheet* hoja = stock->getSheet(0);

        if (hoja)
        {
            Estanteria* estante;

            for (int fila = 1; fila < hoja->lastRow(); fila++)
            {
                for (int columna = 0; columna < hoja->lastCol(); columna++)
                {
                    Zapato* zap = new Zapato();

                    std::string modelo;
                    int talla;
                    int precio;
                    int cantidadPares;
                    std::string color;
                    std::string genero;
                    bool cordones;

                    //leer valores y asignar a atributos de zapato

                    switch (columna)[{
                    case 0:
                        modelo = hoja->readStr(fila, columna);
                        break;
                    case 1:
                        talla = hoja->readNum(fila, columna);
                        break;
                    case 2:
                        precio = hoja->readNum(fila, columna);
                        break;
                    case 3:
                        cantidadPares = hoja->readNum(fila, columna);
                        break;
                    case 4:
                        color = hoja->readStr(fila, columna);
                        break;
                    case 5:
                        genero = hoja->readStr(fila, columna);
                        break;
                    case 6:
                        cordones = hoja->readBool(fila, columna);
                        break;
                    default:
                        break;
                    }

                }
            }
        }
    }
    stock->release();
    return 0;
}

    //actualizar excel
bool Estanteria::actualizarExcel()
{
    Book* estanteActualizado = xlCreateXMLBook();
    if (estanteActualizado)
    {
        Sheet* hoja = estanteActualizado->addSheet(L"Sheet1");
        if (hoja)
        {
            // adaptar a que guarde como queda
            hoja->writeStr(2, 1, L"Hello, World !");
            hoja->writeNum(3, 1, 1000);
        }
        hoja->save(L"stock.xls");
        hoja->release();
    }
    return 0;
}
*/