#include "Zapato.h"

Zapato::Zapato(const std::string& modelo, int talla, int precio, int cantidadPares, const std::string& color,
    const std::string& genero, bool cordones) : modelo(modelo), talla(talla), precio(precio),
    cantidadPares(cantidadPares), color(color), genero(genero),
    cordones(cordones) {}

const std::string& Zapato::getModelo() const {
    return modelo;
}

void Zapato::setModelo(const std::string& modelo) {
    Zapato::modelo = modelo;
}

int Zapato::getTalla() const {
    return talla;
}

void Zapato::setTalla(int talla) {
    Zapato::talla = talla;
}

int Zapato::getPrecio() const {
    return precio;
}

void Zapato::setPrecio(int precio) {
    Zapato::precio = precio;
}

int Zapato::getCantidadPares() const {
    return cantidadPares;
}

void Zapato::setCantidadPares(int cantidadPares) {
    Zapato::cantidadPares = cantidadPares;
}

const std::string& Zapato::getColor() const {
    return color;
}

void Zapato::setColor(const std::string& color) {
    Zapato::color = color;
}

const std::string& Zapato::getGenero() const {
    return genero;
}

void Zapato::setGenero(const std::string& genero) {
    Zapato::genero = genero;
}

bool Zapato::isCordones() const {
    return cordones;
}

void Zapato::setCordones(bool cordones) {
    Zapato::cordones = cordones;
}
