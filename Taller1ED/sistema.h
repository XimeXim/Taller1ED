#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "NodoZapato.h"
#include "Zapato.h"
#include "estanteria.h"

using namespace std;

class Sistema
{
private:
	Estanteria* e;
	Estanteria* eB;
    Estanteria estanteria;

public:
	/**
	 * Constructor del sistema
	 */
	Sistema();

    /**
     * Metodo que se encarga de la lectura de archivos
     */
    void lecturaArchivos();

	/**
	 * Metodo que cambia parámetros de string a bool
	 * @param str String que cambiará a bool
	 * @return El bool que antes era un string
	 */
	bool stringToBool(string str);

    /**
     * Metodo que actualiza el archivo
     */
    void actualizarArchivos();

    /**
     * Metodo que contiene el menú principal
     */
    void MenuPrincipal();

    /**
     * Metodo que contiene el menu de estadísticas
     */
    void MenuEstadisticas();

    /**
     * Destructor del sistema
     */
    ~Sistema();
};