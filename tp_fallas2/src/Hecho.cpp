#include "Hecho.h"

Hecho::Hecho(std::string descripcion){
	this->descripcion = descripcion;
}

Hecho::~Hecho(){
}

std::string Hecho::getDescripcion(){
	return this->descripcion;
}
