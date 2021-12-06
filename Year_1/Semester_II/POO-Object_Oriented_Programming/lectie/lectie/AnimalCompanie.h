#pragma once
#include "Animal.h"

class AnimalCompanie:public Animal
{
protected:
	int gradIngrijire;

	AnimalCompanie(int,int,std::string);
};

