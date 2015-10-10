#include "Frame.h"
#include <iostream>

Frame::Frame(std::string name, std::map<std::string,std::string> slots){
	this->name = name;
	this->slots = slots;
}

Frame::~Frame(){
}

bool Frame::compare(std::map<std::string,std::string> slots){
	for(std::map<std::string,std::string>::iterator it = slots.begin(); it != slots.end(); it++){
		if (it->second != this->slots[it->first]){
			std::cout << "No cumple con el frame " << this->name << std::endl;
			return false;
		}
	}
	for(std::map<std::string,std::string>::iterator it2 = this->slots.begin(); it2 != this->slots.end(); it2++){
		if (it2->second != slots[it2->first]){
			std::cout << "No cumple con el frame " << this->name << std::endl;
			return false;
		}
	}
	std::cout << "Cumple con el frame " << this->name << std::endl;
	return true;
}
