#ifndef _REGLA_H_
#define _REGLA_H_

#include <string>
#include <vector>
#include "Hecho.h"

class Regla{

	std::string descripcion;
	Hecho *hecho1;
	Hecho *hecho2;
	Hecho *conclusion;

public:
	Regla(const std::string& descripcion, Hecho* hecho1, Hecho* hecho2, Hecho* conclusion);
	~Regla();
	std::string getDescripcion();
	void print();
	Hecho* seCumplenHechos(std::vector<Hecho*> conocimiento);
	bool seCumpleConclusion(Hecho *&hecho1, Hecho *&hecho2, Hecho* conclusion);
};

#endif
