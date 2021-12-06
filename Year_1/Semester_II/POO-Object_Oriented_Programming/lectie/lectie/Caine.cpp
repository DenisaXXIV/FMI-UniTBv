#include "Caine.h"

void Caine :: Play()
{
	std::cout << "Aport";
}

Caine::Caine(int varsta, int gradIngrijire, std::string sunet):AnimalCompanie(gradIngrijire,varsta,sunet),Animal(varsta,sunet)
{

}