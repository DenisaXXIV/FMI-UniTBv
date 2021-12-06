#include "AnimalCompanie.h"

AnimalCompanie::AnimalCompanie(int gradIngrijire,int varsta,std::string sunet):Animal(varsta,sunet)
{
	this->gradIngrijire = gradIngrijire;
}