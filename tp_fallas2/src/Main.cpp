#include <iostream>
#include <map>
#include <string>

#include "BaseConocimiento.h"
#include "Regla.h"
#include "Hecho.h"
#include "Frame.h"
#include "Nodo.h"

int main() {

	/*Hecho hechoP("p");
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

	BaseConocimiento baseConocimiento(reglas, conocimientoInicial);*/
	//Ejemplo ENCADENAMIENTO HACIA ADELANTE
	//baseConocimiento.encadenamientoHaciaAdelante();
	//Ejemplo ENCADENAMIENTO HACIA ATRAS
	//baseConocimiento.encadenamientoHaciaAtras(&hechoV);


	//Ejemplo FRAME
	/*std::vector<Frame*> frames;
	std::map<std::string,std::string> slots1;
	slots1.insert(std::pair<std::string,std::string>("Slot_1","Valor_A"));
	slots1.insert(std::pair<std::string,std::string>("Slot_2","Valor_B"));
	slots1.insert(std::pair<std::string,std::string>("Slot_3","Valor_C"));
	Frame frame1("FRAME1", slots1);

	std::map<std::string,std::string> slots2;
	slots2.insert(std::pair<std::string,std::string>("Slot_1","Valor_A"));
	slots2.insert(std::pair<std::string,std::string>("Slot_2","Valor_D"));
	slots2.insert(std::pair<std::string,std::string>("Slot_3","Valor_E"));
	Frame frame2("FRAME2", slots2);

	frames.push_back(&frame1);
	frames.push_back(&frame2);

	std::map<std::string,std::string> objeto;
	objeto.insert(std::pair<std::string,std::string>("Slot_1","Valor_A"));
	objeto.insert(std::pair<std::string,std::string>("Slot_2","Valor_D"));
	objeto.insert(std::pair<std::string,std::string>("Slot_3","Valor_E"));

	bool encontrado = false;
	for(std::vector<Frame*>::iterator it = frames.begin(); it != frames.end() && !encontrado; it++){
		encontrado = (*it)->compare(objeto);
	}*/

	//Ejemplo de RED SEMANTICA
	/*Nodo *mamifero = new Nodo("mamifero");
	Nodo *perro = new Nodo("perro");
	Nodo *gato = new Nodo("gato");
	Nodo *Susi = new Nodo("Susi");
	Nodo *Belo = new Nodo("Belo");
	Nodo *Tino = new Nodo("Tino");

	mamifero->addChildren("es un", perro);
	mamifero->addChildren("es un", gato);

	gato->addChildren("es un", Susi);

	Susi->addChildren("tamaño", new Nodo("20 cm"));
	Susi->addChildren("color", new Nodo("negro"));
	Susi->addChildren("lugar", new Nodo("casa de Kurt"));

	mamifero->printNodo();*/

	return 0;
}
