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
     *
     * @param zapato
     * @param x
     * @param y
     * @param nodoDeArriba
     * @param nodoDeIzquierda
     */
    NodoZapato(class Zapato* zapato, int x, int y, NodoZapato* nodoDeArriba, NodoZapato* nodoDeIzquierda);

    /**
     *
     * @param zapato
     * @param x
     * @param y
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


