
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

    //// leer excel 
    Estanteria* estante = excelEstante();

    if (estante->load(L"stock.xls"))
    {
        Sheet* sheet = estante->getSheet(0);
        if (sheet)
        {
            for (int fila = sheet->firstRow(); fila < sheet->lastRow(); ++row)
            {
                for (int columna = sheet->firstCol(); columna < sheet->lastCol(); ++columna)
                {
                    CellType tipoCelda = sheet->tipoCelda(fila, columna);
                    std::wcout << "(" << fila << ", " << columna << ") = ";
                    if (sheet->isFormula(row, col))
                    {
                        const wchar_t* s = sheet->readFormula(fila, columna);
                        std::wcout << (s ? s : L"null") << " [formula]";
                    }
                    else
                    {
                        switch (tipoCelda)
                        {
                        case CELLTYPE_EMPTY: std::wcout << "[empty]"; break;
                        case CELLTYPE_NUMBER:
                        {
                            double d = sheet->readNum(fila, columna);
                            std::wcout << d << " [number]";
                            break;
                        }
                        case CELLTYPE_STRING:
                        {
                            const wchar_t* s = sheet->readStr(fila, columna);
                            std::wcout << (s ? s : L"null") << " [string]";
                            break;
                        }
                        case CELLTYPE_BOOLEAN:
                        {
                            bool b = sheet->readBool(fila, columna);
                            std::wcout << (b ? "true" : "false") << " [boolean]";
                            break;
                        }
                        case CELLTYPE_BLANK: std::wcout << "[blank]"; break;
                        case CELLTYPE_ERROR: std::wcout << "[error]"; break;
                        }
                    }
                    std::wcout << std::endl;
                }
            }
        }
    }

    estante->release();
    return 0;
}


void Estanteria::estadisticaPorcentaje(estante* mpp) {
    nodoZapato* aux;
    int totNegro = 0;
    std::cout << "Porcentaje de zapatos escolares vendidos vs zapatillas:" << "\n";
    for (int i = 0; i < largo; i++) {
        if(nodoZapato[i])
    }
}

    //actualizar excel
bool Estanteria::actualizarExcel()
{
    Estanteria* estanteActual = ExcelActualizadoEstante(); // para el excel
    if(estante)
    {
        Sheet* sheet = estanteActual->addSheet(L"Estante Actualizado");
        if(sheet)
        {
            sheet->writeStr(2, 1, L"Hello, World !");
            sheet->writeNum(3, 1, 1000);
        }
        estanteActual->save(L"stockUpdate.xls");
        estanteActual->release();
    }
    return 0;
}
*/