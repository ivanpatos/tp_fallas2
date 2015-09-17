#include "Regla.h"

#include <iostream>

Regla::Regla(const std::string& descripcion, Hecho* hecho1, Hecho* hecho2, Hecho* conclusion){
	this->descripcion = descripcion;
	this->hecho1 = hecho1;
	this->hecho2 = hecho2;
	this->conclusion = conclusion;
}

Regla::~Regla(){
}

std::string Regla::getDescripcion(){
	return this->descripcion;
}

void Regla::print(){
	if (hecho1 != NULL && hecho2 !=NULL)
		std::cout << this->descripcion << " (" << this->hecho1->getDescripcion()<< ","<< this->hecho2->getDescripcion() << ") " << "incluye a "<< this->conclusion->getDescripcion() << std::endl;
	if (hecho1 != NULL && hecho2 ==NULL)
		std::cout << this->descripcion << " (" << this->hecho1->getDescripcion()<< ") " << "incluye a "<< conclusion->getDescripcion() << std::endl;
	if (hecho1 == NULL && hecho2 !=NULL)
		std::cout << this->descripcion << " (" << this->hecho2->getDescripcion()<< ") " << "incluye a "<< conclusion->getDescripcion() << std::endl;
}

Hecho* Regla::seCumplenHechos(std::vector<Hecho*> conocimiento){

	bool cumpleHecho1 = false;
	bool cumpleHecho2 = false;

	for(size_t i=0; i<conocimiento.size() && !cumpleHecho1; ++i){
		if (conocimiento[i] == this->hecho1)
			cumpleHecho1 = true;
	}
	for(size_t j=0; j<conocimiento.size() && !cumpleHecho2; ++j){
			if (conocimiento[j] == this->hecho2)
				cumpleHecho2 = true;
	}

	if ((cumpleHecho1 && cumpleHecho2) || (cumpleHecho1 && this->hecho2 == NULL) || (this->hecho1 == NULL && cumpleHecho2))
		return this->conclusion;
	else
		return NULL;
}

bool Regla::seCumpleConclusion(Hecho *&hecho1, Hecho *&hecho2, Hecho* conclusion){

	if (this->conclusion == conclusion){
		hecho1 = this->hecho1;
		hecho2 = this->hecho2;
		return true;
	}
	return false;

}
