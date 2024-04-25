#pragma once

#ifndef TALLER1_ZAPATO_H
#define TALLER1_ZAPATO_H
#include <string>

class Zapato
{
private:
    std::string modelo;
    int talla;
    int precio;
    int cantidadPares;
    std::string color;
    std::string genero;
    bool cordones;

public:

    /**
     * Constructor del zapato
     * @param modelo Modelo del zapato
     * @param talla Talla del zapato
     * @param precio Precio del zapato
     * @param cantidadPares Cantidad de pares vendidos que registra ese zapato
     * @param color El color del zapato
     * @param genero Genero para el que es el zapato
     * @param cordones Si el zapato presenta o no cordones
     */
    Zapato(const std::string& modelo, int talla, int precio, int cantidadPares, const std::string& color,
        const std::string& genero, bool cordones);

    /**
     * Get's & set'S
     */
    const std::string& getModelo() const;

    void setModelo(const std::string& modelo);

    int getTalla() const;

    void setTalla(int talla);

    int getPrecio() const;

    void setPrecio(int precio);

    int getCantidadPares() const;

    void setCantidadPares(int cantidadPares);

    const std::string& getColor() const;

    void setColor(const std::string& color);

    const std::string& getGenero() const;

    void setGenero(const std::string& genero);

    bool isCordones() const;

    void setCordones(bool cordones);


};

#endif //TALLER1_ZAPATO_H

