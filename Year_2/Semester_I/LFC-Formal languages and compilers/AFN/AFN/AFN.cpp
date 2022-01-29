#include "AFN.h"

#include <iostream>
#include <fstream>
#include <algorithm>

AFN::AFN()
{
}

AFN::AFN(std::vector<std::string> stari, std::string sigma,
	std::map<std::pair<std::string, char>, std::vector<std::string>> delta,
	std::string stareInit, std::vector<std::string> finale) :
	m_stari(stari),
	m_sigma(sigma),
	m_delta(delta),
	m_stareInit(stareInit),
	m_finale(finale),
	m_ok('#')
{
}

void AFN::Citire()
{
}

void AFN::Afisare()
{
	int tranzitieMax = 0;

	for (auto tranzitie : m_delta)
	{
		if (tranzitieMax < tranzitie.second.size())
		{
			tranzitieMax = tranzitie.second.size();
		}
	}

	std::cout << '\n' << '\n' << '\n' << '\n';
	std::cout << "-----------------";  //deasupra cuvantului Intrare


	// deasupra literelor din sigma
	for (int index = 0; index < m_sigma.size(); index++)
	{
		if (tranzitieMax == 1)
		{
			std::cout << "--------------";
		}
		else
		{
			for (int index = 0; index < tranzitieMax; index++)
				std::cout << "------";
		}
	}

	std::cout << std::endl;

	std::cout << "	Intrare |";

	for (auto litera : m_sigma)
	{
		for (int index = 0; index < tranzitieMax / 2; index++)
			std::cout << "       ";
		if (tranzitieMax == 1)
		{
			std::cout << "      ";
		}
		std::cout << litera;
		for (int index = 0; index < tranzitieMax / 2; index++)
			std::cout << "       ";
		if (tranzitieMax == 1)
		{
			std::cout << "      ";
		}
		std::cout << "|";
	}

	std::cout << std::endl;

	std::cout << "Stare	  Delta |";
	for (auto litera : m_sigma)
	{
		for (int index = 0; index < tranzitieMax / 2; index++)
			std::cout << "       ";
		if (tranzitieMax == 1)
		{
			std::cout << "      ";
		}
		std::cout << " ";
		for (int index = 0; index < tranzitieMax / 2; index++)
			std::cout << "       ";
		if (tranzitieMax == 1)
		{
			std::cout << "      ";
		}
		std::cout << "|";
	}

	std::cout << std::endl;

	// sub Stari Delta
	std::cout << "----------------";


	// intre litere si delta
	for (int index = 0; index < m_sigma.size(); index++)
	{
		if (tranzitieMax == 1)
		{
			std::cout << "--------------";
		}
		else
		{
			for (int index = 0; index < tranzitieMax; index++)
				std::cout << "------";
		}
	}
	std::cout << "-";

	std::cout << std::endl;

	for (int indexStari = 0; indexStari < m_stari.size(); indexStari++)
	{

		if (m_stareInit == m_stari[indexStari])
		{
			std::cout << " -> ";
		}
		else
		{
			int ok = 0;

			for (int index = 0; index < m_finale.size(); index++)
			{
				if (m_stari[indexStari] == m_finale[index])
				{
					ok = 1;
				}
			}
			if (ok == 1)
			{
				std::cout << " <- ";
			}
			else std::cout << "    ";
		}

		std::cout << m_stari[indexStari] << "	        |    ";

		int  indexIntrare = 0, index = 0;
		int lipsa;

		while (indexIntrare < m_sigma.size())
		{
			int ok = 1;

			for (auto& tranzitie : m_delta)
			{
				if (tranzitie.first.first == m_stari[indexStari] &&
					tranzitie.first.second == m_sigma[indexIntrare])
				{
					ok = 0;
				}

				// afisare stari din delta

				if (ok == 0)
				{
					std::cout << "{ ";

					for (int index = 0; index < tranzitie.second.size(); index++)
					{
						std::cout << tranzitie.second.at(index);

						if (index == tranzitie.second.size() - 1)
						{
							std::cout << " }";

							lipsa = tranzitieMax - tranzitie.second.size();

							for (int indexSpatiu = 0; indexSpatiu < lipsa; indexSpatiu++)
							{
								std::cout << "    ";
							}

							ok = 1;
						}
						else
						{
							std::cout << ", ";
						}
					}

				}

			}

			// intre starile din delta

			std::cout << "   |    ";

			indexIntrare++;
		}

		std::cout << std::endl;

		// intre stari din m_stari
		std::cout << "-----------------";


		// intre vectorii din delta
		for (int index = 0; index < m_sigma.size(); index++)
		{
			if (tranzitieMax == 1)
			{
				std::cout << "--------------";
			}
			else
			{
				for (int index = 0; index < tranzitieMax; index++)
					std::cout << "------";
			}
		}

		std::cout << std::endl;

	}

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "OBS!!! { #  } , inseamna ca nu exista o tranzitie intre acea stare si acea litera.";

}

// ok == 0 ACCEPTAT
// ok == 1 NEACCEPTAT
// ok == 2 BLOCAT
int AFN::Accepta(std::string cuvant, int pozitia_din_cuvant, std::string stare_curenta)
{
	//Daca am ajuns la finalul Cuvantului, inseamna ca am parcurs toate literele
	if (pozitia_din_cuvant == cuvant.size())
	{
		//Verific daca starea_curenta se afla intr-o stare finala
		for (auto final:m_finale)
			if (stare_curenta == final)
			{
				m_ok = 1; 
				return 0;
			} //Atunci Cuvantul este Acceptat
	}
	else//Daca mai avem de verificat sau am revenit la o litera anterioara
	{
		if (m_ok == 1)
		{
			return 0;
		}

		if (m_ok == 2)
		{
			return 1;
		}


		for (auto litera : cuvant)
		{
			int ok = 0;

			for (auto caracter : m_sigma)
			{
				if (litera == caracter)
				{
					ok = 1;
				}
			}

			if (ok == 0)
			{
				m_ok = 2;
				return 1;
			}
		}
		for (auto tranzitie:m_delta)
		{
			//daca sar peste if, verific daca exista vreo tranzitie care sa contina starea mea curenta
			// si litera din cuvant la care ma aflu
			if (tranzitie.first.first == stare_curenta && tranzitie.first.second == cuvant[pozitia_din_cuvant])
			{
				for (auto stare2 : tranzitie.second)
				{
					if (Accepta(cuvant, pozitia_din_cuvant + 1, stare2) == 0)
					{
						return 0;
					}
				}
			}
		}
		return 2;
	}
}

bool AFN::Verifica()
{
	int ok1 = 0, ok2 = 0;

	for (auto tranzitie : m_delta)
	{
		// (1) daca starea initiala se gaseste in multimea de tranzactii, ok = 1
		if (tranzitie.first.first == m_stareInit)
		{
			ok1=1;
		}

		// (2) daca starile finale se gasesc in multimea de tranzactii, ok = 2
		int okFinale = 0;
		for (auto finale : m_finale)
		{
			for (int index = 0; index < tranzitie.second.size() && okFinale != m_finale.size(); index++)
			{
				if (tranzitie.second.at(index) == finale)
				{
					okFinale++;
				}
			}
		}
		if (okFinale == m_finale.size())
		{
			ok2=1;
		}

	}


	if (ok1+ok2==2)
	{
		return true;
	}

	return false;
}

std::string AFN::GetStare(int index)
{
	return m_stari[index];
}

std::vector<std::string> AFN::GetStari()
{
	return m_stari;
}

void AFN::ResetOk()
{
	m_ok = 0;
}

std::istream& operator>>(std::istream& d_in, AFN& a)
{
	int nr, index2 = -1;
	std::string str, str2;
	char ch;
	std::vector<std::string> implicit = { "# " };
	std::pair<std::string, char> stareLitera;

	d_in >> nr;
	for (int index = 0; index < nr; index++)
	{
		d_in >> str;
		a.m_stari.push_back(str);
	}

	d_in >> nr;
	for (int index = 0; index < nr; index++)
	{
		d_in >> ch;
		a.m_sigma.push_back(ch);

		for (int index1 = 0; index1 < a.m_stari.size(); index1++)
		{
			stareLitera.first = a.m_stari[index1];
			stareLitera.second = ch;

			a.m_delta.insert(std::pair < std::pair<std::string, char>, std::vector<std::string>>(stareLitera, implicit));
		}
	}

	d_in >> nr;
	for (int index = 0; index < nr; index++)
	{
		d_in >> str >> ch >> str2;

		for (auto& tranzitie : a.m_delta)
		{
			if (tranzitie.first.first == str && tranzitie.first.second == ch && tranzitie.second == implicit)
			{
				tranzitie.second[0] = str2;
			}
			else
			{
				if (tranzitie.first.first == str && tranzitie.first.second == ch)
				{
					tranzitie.second.push_back(str2);
				}
			}
		}
	}

	d_in.ignore();

	getline(d_in, a.m_stareInit);

	d_in >> nr;
	for (int index = 0; index < nr; index++)
	{
		d_in >> str;
		a.m_finale.push_back(str);
	}
	return d_in;
}
