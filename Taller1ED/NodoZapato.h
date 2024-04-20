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
    //Constructor, destrcutor, gets y sets del nodozapato.
    //REVISAR SI ES QUE EL CONSTRUCTOR DEBE ESTAR VACIO O NO
    NodoZapato(class Zapato* zapato, int x, int y, NodoZapato* nodoDeArriba, NodoZapato* nodoDeIzquierda);

    virtual ~NodoZapato();

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


