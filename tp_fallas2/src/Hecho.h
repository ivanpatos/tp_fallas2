#ifndef _HECHO_H_
#define _HECHO_H_

#include <string>

class Hecho{

	std::string descripcion;

public:
	Hecho(std::string descripcion);
	~Hecho();
	std::string getDescripcion();
};

#endif
