#include "Pet.h"

Pet::Pet(std::string NumeNou)
{
	this->Nume = "NumeNou";
}

std::string Pet::getName()
{
	return Nume;
}

void Pet::setName(std::string NumeNou)
{
	Nume = NumeNou;
}