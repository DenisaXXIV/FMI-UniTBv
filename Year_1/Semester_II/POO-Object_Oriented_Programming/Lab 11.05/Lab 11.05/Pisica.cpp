#include "Pisica.h"

Pisica::Pisica(std::string RasaNoua, std::string NumeNou) : Pet(NumeNou)
{
	this->Rasa = RasaNoua;
}

std::string Pisica::getSunetSpecific()
{
	return SunetSpecific;
}

std::string Pisica::getName()
{
	return Nume;
}

void Pisica::setName(std::string NumeNou)
{
	Nume = NumeNou;
}

void Pisica::Play()
{
	std::cout << "Se joaca cu soricelul de jucarie.";
}