
#ifndef TALLER1_ESTANTERIA_H
#define TALLER1_ESTANTERIA_H
#include "NodoZapato.h"
#include "Zapato.h"

class Estanteria
{
private:

    int largo;
    int alto;
    NodoZapato** Modelo = new NodoZapato * [largo];
    NodoZapato** Talla = new NodoZapato * [alto];
    int modelosVendidos[1000];
    int tallasVendidas[1000];
    std::string coloresVendidos[1000];


    //INCLUIR UN METODO QUE CREE CONTADORES RESPECTO AL LARGO DE LA MATRIZ COMO TAL
public:

    explicit Estanteria();

    virtual ~Estanteria();

    int getLargo() const;

    void setLargo(int largo);

    int getAlto() const;

    void setAlto(int alto);

    NodoZapato** getModelo() const;

    void setModelo(NodoZapato** modelo);

    NodoZapato** getTalla() const;

    void setTalla(NodoZapato** talla);

    const int* getModelosVendidos() const;

    const int* getTallasVendidas() const;

    const std::string* getColoresVendidos() const;

    bool buscarModeloZapato(int modeloBuscado);

    bool buscarTallaZapato(int tallaBuscada);

    bool venderZapato(int modeloBuscado, int tallaBuscada);

    int modeloMasVendido();

    int tallaMasVendida();

    int porcentajeColorMasVendido();






};

#endif //TALLER1_ESTANTERIA_H
