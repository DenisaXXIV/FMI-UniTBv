#pragma once
#include <string>

class Animal
{
protected:
	std::string specie;
	std::string SunetSpecific;

	Animal();
	virtual std::string getSunetSpecific()=0;
	virtual void setSunetSpecific(std::string) = 0;
	virtual ~Animal();
};

