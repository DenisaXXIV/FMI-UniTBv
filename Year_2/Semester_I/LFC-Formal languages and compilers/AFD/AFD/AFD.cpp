#include "AFD.h"

#include <fstream>
#include <iostream>


AFD::AFD()
{
}

AFD::AFD(std::vector<std::string> stari, std::string sigma,
	std::vector<std::tuple<std::string, char, std::string>> delta,
	std::string stareInit, std::vector<std::string> finale) :
	m_stari(stari),
	m_sigma(sigma),
	m_delta(delta),
	m_stareInit(stareInit),
	m_finale(finale)
{
}

void AFD::Citire()
{

}

void AFD::Afisare()
{
	std::cout << '\n' << '\n' << '\n' << '\n';
	std::cout << "-----------------";

	for (int index = 0; index < m_sigma.size(); index++)
	{
		std::cout << "----------------";
	}

	std::cout << std::endl;

	std::cout << "	    Intrare |     ";

	for (auto litera : m_sigma)
	{
		std::cout << litera << "	|	";
	}

	std::cout << std::endl;

	std::cout << "Stare	      Delta | 	  ";
	for (auto litera : m_sigma)
	{
		std::cout << " 	|	 ";
	}

	std::cout << std::endl;

	std::cout << "-----------------";

	for (int index = 0; index < m_sigma.size(); index++)
	{
		std::cout << "----------------";
	}

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

		std::cout << m_stari[indexStari] << "	            |	  ";

		int  indexIntrare = 0, index = 0;

		while (indexIntrare < m_sigma.size())
		{
			for (index; index < m_delta.size(); index++)
			{
				if (std::get<0>(m_delta[index]) == m_stari[indexStari] &&
					std::get<1>(m_delta[index]) == m_sigma[indexIntrare])
				{
					break;
				}
			}

			std::cout << std::get<2>(m_delta[index]) << "	| 	";

			indexIntrare++;
		}

		std::cout << std::endl;

		std::cout << "-----------------";

		for (int index = 0; index < m_sigma.size(); index++)
		{
			std::cout << "----------------";
		}

		std::cout << std::endl;

	}


	std::cout << std::endl;
}

int AFD::Accepta(std::string& cuvant)
{
	std::string stareActuala = m_stareInit;
	int ok = 0;

	Verificare(ok, cuvant, stareActuala);

	std::cout << '\n';

	if (ok != 0)
	{
		return -1;			// NEACCEPTAT	!!
	}
	else
	{
		ok = 0;

		for (auto final : m_finale)
		{
			if (stareActuala == final)
				ok = 1;
		}

		if (ok != 1)
		{
			return 1;		// BLOCAT		!
		}
		else
		{
			return 0;	// ACCEPTAT

		}
	}
}

bool AFD::Verifica()
{
	int nrOK = 0, okFinal = 0;

	for (auto tranzitie : m_delta)
	{
		int ok = 0;

		// (1) daca starea initiala se gaseste in multimea de tranzactii
		for (auto stare : m_stari)
		{
			if (std::get<0>(tranzitie).find(stare) != std::string::npos)
			{
				ok++;
			}
		}

		// (2) daca starea finala se gaseste in multimea de tranzactii
		for (auto intrare : m_sigma)
		{
			if (std::get<1>(tranzitie) == intrare)
			{
				ok++;
			}
		}

		// (3) daca tranzactiile se gasesc in multimea de tranzactii
		for (auto stare : m_stari)
		{
			if (std::get<2>(tranzitie).find(stare) != std::string::npos)
			{
				ok++;
			}
		}

		// (4) daca avem un numar adecvat de tranzactii
		if (m_delta.size() == m_sigma.size() * m_stari.size())
		{
			ok++;
		}

		if (ok == 4)
		{
			nrOK++;
		}

		// (5) daca finalele se gasesc in multimea de tranzactii
		if (okFinal == 0)
		{
			for (auto final : m_finale)
			{
				if (std::get<2>(tranzitie).find(final) != std::string::npos)
				{
					okFinal = 1;
					break;
				}
			}
		}
	}
	if (nrOK == m_delta.size() && okFinal == 1)
	{
		return true;
	}

	return false;
}

void AFD::Verificare(int& ok, std::string& cuvant, std::string& stareActuala)
{
	char intrareCautata = cuvant[0];;

	while (ok != m_delta.size() && !cuvant.empty())
	{
		for (auto tranzitie : m_delta)
		{
			if (std::get<0>(tranzitie) == stareActuala && std::get<1>(tranzitie) == intrareCautata)
			{
				cuvant.erase(cuvant.begin());
				ok = 0;
				stareActuala = std::get<2>(tranzitie);
				Verificare(ok, cuvant, stareActuala);
			}
			else
			{
				if (!cuvant.empty())
				{
					ok++;
					cuvant.erase(cuvant.begin());
					Verificare(ok, cuvant, stareActuala);
				}
			}
		}
	}
}

std::istream& operator>>(std::istream& d_in, AFD& a)
{
	int nr;
	std::string str, str2;
	char ch;

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
	}

	d_in >> nr;
	for (int index = 0; index < nr; index++)
	{
		d_in >> str >> ch >> str2;

		a.m_delta.push_back(std::make_tuple(str, ch, str2));
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
