#ifndef _FRAME_H_
#define _FRAME_H_

#include <map>
#include <string>

class Frame{
	std::string name;
	std::map<std::string,std::string> slots;

public:
	Frame(std::string name, std::map<std::string,std::string> slots);
	~Frame();
	bool compare(std::map<std::string,std::string> slots);
};

#endif
