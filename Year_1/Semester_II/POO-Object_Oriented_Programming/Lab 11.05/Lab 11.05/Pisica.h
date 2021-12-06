#pragma once
#include <string>
#include "Animal.h"
#include "Pet.h"
#include <iostream>

class Pisica: public Animal, Pet
{
public:
	std::string Rasa;

	Pisica(std::string, std::string);
	std::string getSunetSpecific();
	virtual std::string getName()=0;
	virtual void setName(std::string)=0;
	void Play();
};

