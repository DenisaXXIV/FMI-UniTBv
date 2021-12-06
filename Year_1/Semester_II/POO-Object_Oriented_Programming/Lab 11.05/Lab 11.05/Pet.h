#pragma once
#include <string>

class Pet
{
protected:
	std::string Nume;

	Pet(std::string);
	std::string getName();
	void setName(std::string);
	virtual void Play()=0;
	virtual ~Pet();
};

