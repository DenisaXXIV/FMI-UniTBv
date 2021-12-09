#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#pragma warning(disable : 4996)

//									Exercitiul 1
void Exercitiul1()
{
	std::string sirCaractere;
	char caracterCautat = 0;
	int nrAparitii = 0;

	std::cout << "Sirul de caractere: ";
	std::getline(std::cin, sirCaractere);
	std::cout << '\n';

	std::cout << "Caracterul cautat: ";
	std::cin >> caracterCautat;
	std::cout << '\n';

	for (int index = 0; index < sirCaractere.length(); index++)
	{
		if (sirCaractere[index] == caracterCautat)
		{
			nrAparitii++;
		}
	}

	std::cout << "Caracterul apare de " << nrAparitii << " ori.";

}

//									Exercitiul 2
bool  EsteNumar(std::string numar)
{
	auto const regex1 = std::regex("^([1-9][0-9]*|0)$");
	return std::regex_match(numar, regex1);
}

bool  EsteNumarIntreg(std::string numar)
{
	auto const regex1 = std::regex("^[-+][1-9][0-9]*$");
	return std::regex_match(numar, regex1);
}

bool  EsteNumarReal(std::string numar)
{
	auto const regex1 = std::regex("^[-+]?[1-9][0-9]*\\.{1}[0-9]+$");
	return std::regex_match(numar, regex1);
}

bool  EsteNumarRealExponential(std::string numar)
{
	auto const regex1 = std::regex("^[-+]?[1-9][0-9]*\\.{1}[0-9]+E{1}[+|-]{1}[0-9]+$");
	return std::regex_match(numar, regex1);
}

// OBS! : [+|-] inseamna + sau | sau -
// Corect: [-+] sau (+|-)

void Exercitiul2()
{
	std::string sirCaractere;
	int verificare = 0;	// 0 - nu e numar
						// 1 - numar natural
						// 2 - numar intreg
						// 3 - numar real
						// 4 - numar real exponential

	std::cout << "Sirul de caractere: ";
	std::getline(std::cin, sirCaractere);
	std::cout << '\n';

	if (EsteNumarRealExponential(sirCaractere))
	{
		verificare = 4;
	}
	else
	{
		if (EsteNumarReal(sirCaractere))
		{
			verificare = 3;
		}
		else
		{
			if (EsteNumarIntreg(sirCaractere))
			{
				verificare = 2;
			}
			else
			{
				if (EsteNumar(sirCaractere))
					verificare = 1;
			}
		}
	}

	switch (verificare)
	{
	case 0:
		std::cout << "NU este numar";
		break;
	case 1:
		std::cout << "Este numar natural";
		break;
	case 2:
		std::cout << "Este numar intreg";
		break;
	case 3:
		std::cout << "Este numar real";
		break;
	case 4:
		std::cout << "Este numar real exponential";
		break;
	}
}

//									Exercitiul 4
void Exercitiul4()
{
	char fraza[256];
	int nr = 1;

	std::cin.getline(fraza, 256);

	char* cuvant = strtok(fraza, " .,?!");
	while (cuvant)
	{
		std::cout << nr++ << ". " << cuvant << std::endl;

		cuvant = strtok(NULL, " .,?!");
	}
}

//									Exercitiul 5

void SortareListaCuvinte(std::vector<std::string>& listaCuvinte)
{
	for (int index1 = 0; index1 < listaCuvinte.size() - 1; index1++)
	{
		for (int index2 = index1 + 1; index2 < listaCuvinte.size(); index2++)
		{
			if (listaCuvinte[index1].compare(listaCuvinte[index2]) > 0)
			{
				listaCuvinte[index1].swap(listaCuvinte[index2]);
			}
		}
	}
}

void Exercitiul5()
{
	std::vector<std::string> listaCuvinte;
	std::string cuvantCitit;
	int nrCuvinte = NULL;

	std::cout << "Numarul de cuvinte pe care le dorim introduse:";
	std::cin >> nrCuvinte;
	std::cout << '\n';

	std::cout << "Introduceti cuvintele: ";
	std::cout << '\n';

	for (int index = 0; index < nrCuvinte; index++)
	{
		std::cin >> cuvantCitit;
		listaCuvinte.push_back(cuvantCitit);
	}

	std::cout << '\n';

	SortareListaCuvinte(listaCuvinte);

	for (int index = 0; index < nrCuvinte; index++)
	{
		std::cout << listaCuvinte[index] << '\n';
	}
}

//									Exercitiul 6
void Exercitiul6()
{
	std::string cuvant;
	std::vector<char> vectorLitere;

	std::cin >> cuvant;

	for (int index = 0; index < cuvant.length(); index++)
	{
		vectorLitere.push_back(cuvant[index]);
	}

	for (int index1 = 0; index1 < vectorLitere.size(); index1++)
	{
		for (int index2 = 0; index2 < index1; index2++)
		{
			std::cout << vectorLitere[index2];
		}
		std::cout << " ";
	}
}

//									Exercitiul 7
void Exercitiul7()
{
	std::vector<std::string> v, cuvinteS1;
	std::string s1, cuvant;

	std::ifstream fin("Cuvinte7.txt");

	while (fin >> cuvant)
	{
		v.push_back(cuvant);
	}

	fin.close();

	std::cout << "Subsirul cautat: ";
	std::cin >> s1;
	std::cout << '\n';

	for (int index = 0; index < v.size(); index++)
	{
		if (v[index].find(s1) != std::string::npos)
		{
			cuvinteS1.push_back(v[index]);
		}
	}

	std::cout << "Cuvintele ce corespund sunt:\n";
	for (int index = 0; index < cuvinteS1.size(); index++)
	{
		std::cout << cuvinteS1[index] << " ";
	}
}

//									Exercitiul 8
void Exercitiul8()
{
	int ok = 0;
	while (ok == 0)
	{
		ok = 1;

		// se selecteaza random cuvantul din lista
		srand(time(0));
		int nrCuvant = rand() % 20 + 1;

		std::string cuvant, cuvantGhicit, cuvantControl;

		// citim cuvantul 
		std::ifstream fin("Cuvinte8.txt");

		for (int index = 0; index < nrCuvant; index++)
		{
			std::getline(fin, cuvant);
		}

		fin.close();

		// construim cuvantul vazut de jucator
		for (int index = 0; index < cuvant.length(); index++)
		{
			cuvantGhicit.insert(cuvantGhicit.length(), "_ ");
		}

		// construim un cuvant ce ne va ajuta sa verificam starea jocului
		for (int index = 0; index < cuvant.length(); index++)
		{
			cuvantControl.insert(cuvantControl.length(), "$");
		}

		std::cout << "Aveti cuvantul cu numarul: " << nrCuvant << '\n';

		std::string literaCitita;
		bool stareJoc = true;
		int nrGreseli = 6;

		// Jocul in sine
		while (stareJoc == true && nrGreseli != 0)
		{
			std::cout << '\n';
			std::cout << cuvantGhicit;
			std::cout << '\n';
			std::cout << '\n';

			std::cout << "Introduceti o litera: ";
			std::cin >> literaCitita;
			std::cout << '\n';

			// contorizam numarul de greseli
			if (cuvant.find(literaCitita, 0) == std::string::npos)
			{
				nrGreseli--;

				std::cout << "Mai aveti " << nrGreseli << "/6 incercari !";
			}
			else
			{
				//inlocuim toate litere ce seamana cu litera citita
				while (cuvant.find(literaCitita, 0) != std::string::npos)
				{
					size_t pozitieLiteraGasita = cuvant.find(literaCitita) * 2;

					cuvantGhicit.replace(pozitieLiteraGasita, 1, literaCitita);
					cuvant.replace(cuvant.find(literaCitita), 1, "$");
				}
			}

			// verificam daca jocul s-a finalizat
			if (cuvant.compare(cuvantControl) == 0)
			{
				stareJoc = false;
			}

		}

		// Afisajul la final de joc
		if (nrGreseli == 0)
		{
			std::cout << "Ati pierdut...";
			std::cout << '\n';
			std::cout << '\n';
		}
		else
		{
			std::cout << "FELICITARI! Ati castigat!";
			std::cout << '\n';
			std::cout << '\n';
		}

		//Se doreste o reluare de joc?
		std::cout << "Apasati ENTER ca sa reluati jocul.\n";
		char esteEnter = getchar();
		esteEnter = getchar();

		if (esteEnter == '\n')
		{
			ok = 0;
			system("CLS");
		}
	}
}

void Tema1()
{

}