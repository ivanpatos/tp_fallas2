#include <iostream>

#include "BaseConocimiento.h"
#include "Regla.h"
#include "Hecho.h"

int main() {

	Hecho hechoP("p");
	Hecho hechoQ("q");
	Hecho hechoR("r");
	Hecho hechoS("s");
	Hecho hechoT("t");
	Hecho hechoU("u");
	Hecho hechoV("v");

	Regla regla1("R1", &hechoP, &hechoQ, &hechoS);
	Regla regla2("R2", &hechoR, NULL, &hechoT);
	Regla regla3("R3", &hechoS, &hechoT, &hechoU);
	Regla regla4("R4", &hechoS, &hechoR, &hechoV);

	std::vector<Regla*> reglas;
	reglas.push_back(&regla1);
	reglas.push_back(&regla2);
	reglas.push_back(&regla3);
	reglas.push_back(&regla4);

	std::vector<Hecho*> conocimientoInicial;
	conocimientoInicial.push_back(&hechoP);
	conocimientoInicial.push_back(&hechoQ);
	conocimientoInicial.push_back(&hechoR);

	BaseConocimiento baseConocimiento(reglas, conocimientoInicial);
	//baseConocimiento.encadenamientoHaciaAdelante();

	baseConocimiento.encadenamientoHaciaAtras(&hechoV);

	return 0;
}
