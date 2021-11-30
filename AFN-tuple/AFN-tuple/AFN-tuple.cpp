#include <iostream>
#include <Windows.h>
#include <fstream>

#include "AFD.h"

void Fereastra1()
{
	system("color F0");

	// <!--------------- FEREASTRA 1 (Bun venit!) --------------->
	std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
	std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
	std::cout << "                                    Buna ziua si bun venit la prezentarea Temei 3!";
	Sleep(3000); // 3 secunde

	system("cls");
}

void Fereastra2(int& comanda)
{
	system("cls");
	// <!--------------- FEREASTRA 2(Meniu principal) --------------->

	std::cout << "Vasile Denisa-Georgiana\nGrupa 10LF203\nFacultatea de Matematica si Informatica\nUniTBv";
	std::cout << '\n';

	std::cout << "                                       Tema 3: Automate Finite Deterministe";
	std::cout << '\n' << '\n' << '\n';

	std::cout << " Avand urmatorul AFD : A = (Q = {q0, q1}, Sigma = {a, b}, Delta, q0, F = {q1}), va rog alegeti ce doriti sa faceti" << '\n' << " cu acesta : ";
	std::cout << '\n' << '\n';
	std::cout << " [ 1 ] Citire AFD din fisier";
	std::cout << '\n' << '\n';
	std::cout << " [ 2 ] Introducere date pentru AFD de la tastatura";
	std::cout << '\n' << '\n';
	std::cout << " [ 3 ] Afisare AFD";
	std::cout << '\n' << '\n';
	std::cout << " [ 4 ] Verificare daca un cuvand face parte din AFD";
	std::cout << '\n' << '\n';
	std::cout << " [ 5 ] Verificare daca AFD-ul a fost construit cu succes";
	std::cout << '\n' << '\n';
	std::cout << " [ 6 ] EXIT";
	std::cout << '\n' << '\n';
	std::cout << "_______________________________________________________________________________________________________________________";
	std::cout << '\n' << '\n';

	std::cin >> comanda;

	// <!--------------- Verificare corectitudine comanda --------------->

	while (comanda < 0 || comanda >6)
	{
		std::cout << '\n' << '\n';
		system("color F4");
		std::cout << "COMANDA NERECUNOSCUTA! Apasati ENTER pentru a continua!";
		std::cin.ignore();
		std::cin.ignore();
		system("cls");

		system("color F0");
		std::cout << "Vasile Denisa-Georgiana\nGrupa 10LF203\nFacultatea de Matematica si Informatica\nUniTBv";
		std::cout << '\n';

		std::cout << "                                       Tema 3: Automate Finite Deterministe";
		std::cout << '\n' << '\n' << '\n';

		std::cout << " Avand urmatorul AFD : A = (Q = {q0, q1}, Sigma = {a, b}, Delta, q0, F = {q1}), va rog alegeti ce doriti sa faceti cu acesta:";
		std::cout << '\n' << '\n';
		std::cout << "[ 1 ] Citire AFD din fisier";
		std::cout << '\n' << '\n';
		std::cout << "[ 2 ] Introducere date pentru AFD de la tastatura";
		std::cout << '\n' << '\n';
		std::cout << "[ 3 ] Afisare AFD";
		std::cout << '\n' << '\n';
		std::cout << "[ 4 ] Verificare daca un cuvand face parte din AFD";
		std::cout << '\n' << '\n';
		std::cout << "[ 5 ] Verificare daca AFD-ul a fost construit cu succes";
		std::cout << '\n' << '\n';
		std::cout << "[ 6 ] EXIT";
		std::cout << '\n' << '\n';
		std::cout << "_______________________________________________________________________________________________________________________";
		std::cout << '\n' << '\n';

		std::cin >> comanda;

	}
}

void Fereastra2_1(int comanda, AFD& a)
{
	// <!--------------- FEREASTRA 3(Citire fisier) --------------->

	system("cls");
	system("color F2");

	std::ifstream fin("D:/Educatie/5. Facultate/Anul II/Semestrul I/LFC - Limbaje formale si compilatoare/LAB/03/AFN-tuple/AFN-tuple//AFD2.txt");

	fin >> a;

	fin.close();

	std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
	std::cout << '\n' << '\n' << '\n' << '\n';
	std::cout << "                                    ===========================================" << '\n';
	std::cout << "                                    |                                         |" << '\n';
	std::cout << "                                    |            CITIRE CU SUCCES!            |" << '\n';
	std::cout << "                                    |                                         |" << '\n';
	std::cout << "                                    ===========================================" << '\n';


	Sleep(3000); // 3 secunde

	system("cls");
}

void Fereastra2_2(int comanda, AFD& a)
{
	system("cls");

	/*a.Citire();*/

	system("cls");
	system("color F2");

	std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
	std::cout << '\n' << '\n' << '\n' << '\n';
	std::cout << "                                    ===========================================" << '\n';
	std::cout << "                                    |                                         |" << '\n';
	std::cout << "                                    |            CITIRE CU SUCCES!            |" << '\n';
	std::cout << "                                    |                                         |" << '\n';
	std::cout << "                                    ===========================================" << '\n';


	Sleep(3000); // 3 secunde

	system("cls");
	system("color F0");
}

void Fereastra2_3(int comanda, AFD a)
{
	system("cls");

	std::cout << '\n' << '\n';
	std::cout << "_______________________________________________________________________________________________________________________";
	a.Afisare();
	std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
	std::cout << "_______________________________________________________________________________________________________________________";
	std::cout << '\n' << '\n';

	std::cout << "Apasati ENTER pentru a continua!";

	std::cin.ignore();
	std::cin.ignore();

	system("cls");
}

void Fereastra2_4(int comanda, AFD a)
{
	system("cls");

	std::string cuvant;
	int aux;

	std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
	std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
	std::cout << "                                    Introduceti cuvantul dorit:" << '\n';
	std::cout << "                                       -------> ";

	std::cin >> cuvant;

	system("cls");

	std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
	std::cout << '\n' << '\n';

	aux = a.Accepta(cuvant);

	switch (aux)
	{
	case 0:
		system("color F2");
		std::cout << "                                    ===========================================" << '\n';
		std::cout << "                                    |                                         |" << '\n';
		std::cout << "                                    |             A C C E P T A T             |" << '\n';
		std::cout << "                                    |                                         |" << '\n';
		std::cout << "                                    ===========================================" << '\n';
		break;
	case -1:
		system("color F4");
		std::cout << "                                    ===========================================" << '\n';
		std::cout << "                                    |                                         |" << '\n';
		std::cout << "                                    |           N E A C C E P T A T           |" << '\n';
		std::cout << "                                    |                                         |" << '\n';
		std::cout << "                                    ===========================================" << '\n';
		break;
	case 1:
		system("color F6");
		std::cout << "                                    ===========================================" << '\n';
		std::cout << "                                    |                                         |" << '\n';
		std::cout << "                                    |               B L O C A T               |" << '\n';
		std::cout << "                                    |                                         |" << '\n';
		std::cout << "                                    ===========================================" << '\n';
		break;
	}

	Sleep(2000);
	system("color F0");

	std::cout << '\n' << '\n' << '\n' << '\n';
	std::cout << "_______________________________________________________________________________________________________________________";
	std::cout << '\n' << '\n' << '\n' << '\n';
	std::cout << " Doriti sa mai verificati un cuvant?";
	std::cout << '\n' << '\n';
	std::cout << " [ 1 ] Da, mai am un cuvant de verificat";
	std::cout << '\n' << '\n';
	std::cout << " [ 2 ] Nu, vreau inapoi la meniul principal";
	std::cout << '\n' << "   ---> ";

	int comandaCuv = 0;

	std::cin >> comandaCuv;

	while (comanda < 0 || comanda >6)
	{
		std::cout << '\n' << '\n';
		system("color F4");
		std::cout << "COMANDA NERECUNOSCUTA! Apasati ENTER pentru a continua!";
		std::cin.ignore();
		std::cin.ignore();
		system("cls");

		system("color F0");

		std::cout << '\n' << '\n' << '\n' << '\n';
		std::cout << " Doriti sa mai verificati un cuvant?";
		std::cout << '\n' << '\n';
		std::cout << " [ 1 ] Da, mai am un cuvant de verificat";
		std::cout << '\n' << '\n';
		std::cout << " [ 2 ] Nu, vreau inapoi la meniul principal";
		std::cout << '\n' << "   ---> ";
		std::cin >> comanda;

	}

	switch (comandaCuv)
	{
	case 1:
		Fereastra2_4(comanda, a);
	case 2:
		return;
	}


}

void Fereastra2_5(int comanda, AFD a)
{
	system("cls");

	if (a.Verifica() != true)
	{

		system("color F4");

		std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
		std::cout << '\n' << '\n' << '\n' << '\n';
		std::cout << "                                    ============================================" << '\n';
		std::cout << "                                    |                                          |" << '\n';
		std::cout << "                                    |              AUTOMAT GRESIT!             |" << '\n';
		std::cout << "                                    |                                          |" << '\n';
		std::cout << "                                    | Va rugam sa verificati datele introduse! |" << '\n';
		std::cout << "                                    |                                          |" << '\n';
		std::cout << "                                    ============================================" << '\n';

	}
	else
	{
		system("color F2");

		std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
		std::cout << '\n' << '\n' << '\n' << '\n';
		std::cout << "                                    =============================================" << '\n';
		std::cout << "                                    |                                           |" << '\n';
		std::cout << "                                    |             AUTOMAT CORECT! :)            |" << '\n';
		std::cout << "                                    |                                           |" << '\n';
		std::cout << "                                    =============================================" << '\n';

	}

	Sleep(3000); // 3 secunde

	system("cls");
	system("color F0");
}

void Fereastra2_6(int comanda)
{
	system("cls");
	system("color F5");

	std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
	std::cout << '\n' << '\n' << '\n' << '\n';
	std::cout << "                                    ===========================================" << '\n';
	std::cout << "                                    |                                         |" << '\n';
	std::cout << "                                    |            La revedere! (^.^)/          |" << '\n';
	std::cout << "                                    |                                         |" << '\n';
	std::cout << "                                    ===========================================" << '\n';

	Sleep(3000); // 3 secunde

	system("cls");
}

void Meniu(AFD a)
{
	Fereastra1();

	// <!--------------- FEREASTRA 2(Meniu principal) --------------->

	int comanda = NULL;

	while (comanda != 7)
	{
		system("color F0");
		Fereastra2(comanda);

		switch (comanda)
		{
		case 1:
			Fereastra2_1(comanda, a);
			break;
		case 2:
			Fereastra2_2(comanda, a);
			break;
		case 3:
			Fereastra2_3(comanda, a);
			break;
		case 4:
			Fereastra2_4(comanda, a);
			break;
		case 5:
			Fereastra2_5(comanda, a);
			break;
		case 6:
			Fereastra2_6(comanda);
			return;
		}
	}
}
int main()
{
	AFD a;
	Meniu(a);
	return 0;
}