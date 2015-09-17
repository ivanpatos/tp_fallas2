#include "BaseConocimiento.h"

BaseConocimiento::BaseConocimiento(std::vector<Regla*> reglas, std::vector<Hecho*> conocimientoInicial){
	this->reglas = reglas;
	this->hechosConocidos = conocimientoInicial;
}

BaseConocimiento::~BaseConocimiento(){
}

bool BaseConocimiento::esConocimientoNuevo(Hecho *hecho){
	bool encontrado = false;
	for(size_t i=0; i<this->hechosConocidos.size() && !encontrado; ++i){
		if (hecho == this->hechosConocidos[i])
			encontrado = true;
	}
	return !encontrado;
}

void BaseConocimiento::BaseConocimiento::printReglas(){
	std::cout << "Reglas: ";
	for(size_t i=0; i<this->reglas.size(); ++i)
		std::cout << "|" << this->reglas[i]->getDescripcion() << "|";
	std::cout << std::endl;
}

void BaseConocimiento::printMemoria(){
	std::cout << "Memoria: ";
	for(size_t i=0; i<this->memoria.size(); ++i)
		std::cout << "|" << this->memoria[i]->getDescripcion() << "|";
	std::cout << std::endl;
}

void BaseConocimiento::printConocimiento(){
	std::cout << "Conocimiento: ";
	for(size_t i=0; i<this->hechosConocidos.size(); ++i)
		std::cout << "|" << this->hechosConocidos[i]->getDescripcion() << "|";
	std::cout << std::endl << std::endl ;
}

void BaseConocimiento::encadenamientoHaciaAdelante(){

	for(size_t i=0; i<reglas.size(); ++i){
		this->printReglas();
		this->printMemoria();
		Hecho *hecho = reglas[i]->seCumplenHechos(this->hechosConocidos);	//veo si se cumple la regla
		if (hecho != NULL){
			if (this->esConocimientoNuevo(hecho))
				hechosConocidos.push_back(hecho);							// si es conocimiento nuevo agrego nuevo hecho a conocimiento adquirido
			memoria.push_back(reglas[i]);									//guardo en memoria regla que se cumplio
			reglas.erase(reglas.begin()+i);									//saco la regla para no volverla a aplicar
			i=-1;															//vuelvo a recorrer las reglas
		}
		this->printConocimiento();
	}
	this->printReglas();
	this->printMemoria();
	this->printConocimiento();
}




bool BaseConocimiento::encadenamientoHaciaAtras(Hecho* conclusion){

	if (this->esConocimientoNuevo(conclusion)){
		for (size_t i=0; i<reglas.size(); ++i){
			Hecho *hecho1 = NULL;
			Hecho *hecho2 = NULL;
			if (reglas[i]->seCumpleConclusion(hecho1, hecho2, conclusion)){

				reglas[i]->print();

				bool hecho1Conocido = false;
				bool hecho2Conocido = false;
				if (this->esConocimientoNuevo(hecho1) && hecho1!=NULL){
					std::cout << hecho1->getDescripcion() << " no está contenido en la base de conocimiento" << std::endl;
					hecho1Conocido = this->encadenamientoHaciaAtras(hecho1);
				}
				else{
					if (hecho1!=NULL)
						std::cout << hecho1->getDescripcion() << " está contenido en la base de conocimiento" << std::endl;
					hecho1Conocido = true;
				}
				if (this->esConocimientoNuevo(hecho2) && hecho2!=NULL){
					std::cout << hecho2->getDescripcion() << " no está contenido en la base de conocimiento" << std::endl;
					hecho2Conocido = this->encadenamientoHaciaAtras(hecho2);
				}
				else{
					if (hecho2!=NULL)
						std::cout << hecho2->getDescripcion() << " está contenido en la base de conocimiento" << std::endl;
					hecho2Conocido = true;
				}
				if (hecho1Conocido && hecho2Conocido){
					std::cout << conclusion->getDescripcion() << " se agrega a la base de conocimiento" << std::endl;
					this->hechosConocidos.push_back(conclusion);
					this->printConocimiento();
					return true;
				}
			}
		}
		return false;
	}
	else
		return true;
}

