#pragma once
#ifndef TALLER1_NODOZAPATO_H
#define TALLER1_NODOZAPATO_H
#include "Zapato.h"
#include "NodoZapato.h"

class NodoZapato
{

private:
    Zapato* Zapato;
    int x;
    int y;
    NodoZapato* nodoDeArriba;
    NodoZapato* nodoDeIzquierda;

public:

    /**
     * Constructor del nodo zapato completo
     * @param zapato Zapato al que hace referencia
     * @param x Posicion horizontal
     * @param y Posicion vertical
     * @param nodoDeArriba Referencia al nodo de arriba
     * @param nodoDeIzquierda Referencia al nodo de la izquierda
     */
    NodoZapato(class Zapato* zapato, int x, int y, NodoZapato* nodoDeArriba, NodoZapato* nodoDeIzquierda);

    /**
     * Constructor del nodo zapato solo con los parametros de zapato y sus coordenadas
     * @param zapato Zapato al que hace referencia
     * @param x Posicion horizontal
     * @param y Posicion vertical
     */
    NodoZapato(class Zapato* zapato, int x, int y);

    /**
     * Destructor del nodo zapato
     */
    virtual ~NodoZapato();

    /**
     * Get's & Set's
     */
    class Zapato* getZapato() const;

    int getX() const;

    int getY() const;

    class NodoZapato* getNodoDeArriba() const;

    class NodoZapato* getNodoDeIzquierda() const;

    void setZapato(class Zapato* zapato);

    void setX(int x);

    void setY(int y);

    void setNodoDeArriba(class NodoZapato* nodoDeArriba);

    void setNodoDeIzquierda(class NodoZapato* nodoDeIzquierda);

};

#endif //TALLER1_NODOZAPATO_H


