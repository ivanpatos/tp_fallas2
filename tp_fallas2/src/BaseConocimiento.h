#ifndef _BASE_CONOCIMIENTO_H_
#define _BASE_CONOCIMIENTO_H_

#include "Regla.h"
#include <vector>
#include <iostream>


class BaseConocimiento{

private:
	std::vector<Regla*> reglas;
	std::vector<Hecho*> hechosConocidos;
	std::vector<Regla*> memoria;

	bool esConocimientoNuevo(Hecho *hecho);
	void printReglas();
	void printMemoria();
	void printConocimiento();

public:
	BaseConocimiento(std::vector<Regla*> reglas, std::vector<Hecho*> conocimientoInicial);
	~BaseConocimiento();
	void encadenamientoHaciaAdelante();
	bool encadenamientoHaciaAtras(Hecho* conclusion);

};

#endif
