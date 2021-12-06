#pragma once
#include "Animal.h"
#include "AnimalCompanie.h"
#include <iostream>
#include <string>

class Caine:public Animal,public AnimalCompanie
{
public:
	Caine(int, int, std::string);

	void Play();
};

