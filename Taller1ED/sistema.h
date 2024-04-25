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
	Sistema();
	void lecturaArchivos();
	bool stringToBool(string str);
	void actualizarArchivos();
    void MenuPrincipal();
    void MenuEstadisticas();
	~Sistema();
};