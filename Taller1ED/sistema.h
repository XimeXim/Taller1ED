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

public:
	Sistema();
	void lecturaArchivos();
	bool stringToBool(string str);
	bool rellenarEstante(class NodoZapato* mppBodega);
	void actualizarArchivos();
    void MenuPrincipal();
    void MenuEstadisticas();
	~Sistema();
};