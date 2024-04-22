#include "NodoZapato.h"


NodoZapato::NodoZapato(class Zapato* zapato, int x, int y, NodoZapato* nodoDeArriba, NodoZapato* nodoDeIzquierda) : Zapato(
    zapato), x(x), y(y), nodoDeArriba(nodoDeArriba), nodoDeIzquierda(nodoDeIzquierda) {}

NodoZapato::NodoZapato(class Zapato* zapato, int x, int y)
{
    NodoZapato::Zapato = zapato;
    NodoZapato::x = x;
    NodoZapato::y = y;
    NodoZapato::nodoDeArriba = nullptr;
    NodoZapato::nodoDeIzquierda = nullptr;

}


NodoZapato::~NodoZapato() {
}

Zapato* NodoZapato::getZapato() const {
    return Zapato;
}

int NodoZapato::getX() const {
    return x;
}

int NodoZapato::getY() const {
    return y;
}

NodoZapato* NodoZapato::getNodoDeArriba() const {
    return nodoDeArriba;
}

NodoZapato* NodoZapato::getNodoDeIzquierda() const {
    return nodoDeIzquierda;
}

void NodoZapato::setZapato(class Zapato *zapato) {
    Zapato = zapato;
}

void NodoZapato::setX(int x) {
    NodoZapato::x = x;
}

void NodoZapato::setY(int y) {
    NodoZapato::y = y;
}

void NodoZapato::setNodoDeArriba(NodoZapato *nodoDeArriba) {
    NodoZapato::nodoDeArriba = nodoDeArriba;
}

void NodoZapato::setNodoDeIzquierda(NodoZapato *nodoDeIzquierda) {
    NodoZapato::nodoDeIzquierda = nodoDeIzquierda;
}

