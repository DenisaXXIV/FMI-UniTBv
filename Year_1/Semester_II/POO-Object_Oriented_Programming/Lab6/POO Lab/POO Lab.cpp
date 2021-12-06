#include "Matrice.h"
#include <iostream>

Matrice copie(Matrice B)
{
	Matrice a = B;
	return a;
}

int main()
{
	Matrice A(2);
	std::cin >> A;
	//putem face initializarea in momentul creari obiectului cu atributele existente in alt obiect
	Matrice B(A); //A se copiaza in B bit cu bit
	std::cout << B;
	Matrice C = copie(B);
	std::cout << C;

	try
	{
		std::cout << C.getValoare(-2, 3) << std::endl;
	}
	catch (std::out_of_range& e)
	{
		std::cout << "Eroarea este" <<e.what();
	}
	catch (std::invalid_argument& e)
	{
		std::cout << "Eroare: " << e.what() << std::endl;
	}



}