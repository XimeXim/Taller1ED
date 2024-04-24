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
	static bool stringToBool(string str);
	void actualizarArchivos();
    void MenuPrincipal();
    void MenuEstadisticas();
	~Sistema();
	bool rellenarEstante(Estanteria* e);
};