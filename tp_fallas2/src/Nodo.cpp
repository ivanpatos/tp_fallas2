#include "Nodo.h"
#include <iostream>

Nodo::Nodo(std::string name){
	this->name = name;
}

Nodo::~Nodo(){
}

void Nodo::addChildren(std::string relacion, Nodo *hijo){
	this->children.insert(std::pair<std::string,Nodo*>(relacion, hijo));
}

void Nodo::printNodo(){
	if (!this->children.empty())
		std::cout << this->name << std::endl;
	for(std::map<std::string, Nodo*>::iterator it = this->children.begin(); it != this->children.end(); it++){
		std::cout << it->second->name << " " << it->first << " " << this->name << std::endl;
		it->second->printNodo();
	}
}
