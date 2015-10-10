#ifndef _NODO_H_
#define _NODO_H_

#include <map>
#include <string>

class Nodo{
	std::string name;
	std::multimap<std::string, Nodo*> children;

public:
	Nodo(std::string name);
	~Nodo();
	void addChildren(std::string relacion, Nodo *hijo);
	void printNodo();
};

#endif
