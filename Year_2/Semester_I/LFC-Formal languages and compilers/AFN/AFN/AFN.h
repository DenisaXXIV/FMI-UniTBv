#pragma once

#include <string>
#include <vector>
#include <map>
#include <utility>

//   A = (Q, Sigma, Delta, q0, F)

class AFN
{
public:
	AFN();
	AFN(std::vector<std::string> stari, std::string sigma,
		std::map<std::pair<std::string, char>, std::vector<std::string>> delta,
		std::string stareInit, std::vector<std::string> finale);

	void Citire();
	void Afisare();
	friend std::istream& operator>>(std::istream& d_in, AFN& a);

	//verifica daca cuvantul dat ca parametru este acceptat de catre automat si afiseaza : 
	// 
	//	~"accepta" - daca este cuvant acceptat, 
	//	~"neacceptat" - daca nu este accepta,
	//	~"blocaj" - daca automatul se blocheaza pe parcurs.
	int Accepta(std::string cuvant, int pozitia_din_cuvant, std::string stare_curenta);

	//verificari legate de corectitudinea automatului
	bool Verifica();

	std::string GetStare(int index);
	std::vector < std::string> GetStari();
	void ResetOk();

private:
	std::vector<std::string>										m_stari;		// Q
	std::string														m_sigma;		// Sigma
	std::map<std::pair<std::string, char>,std::vector<std::string>>	m_delta;		// Delta
	std::string														m_stareInit;	// q0
	std::vector<std::string>										m_finale;		// F
	int																m_ok=0;			// verificare AFN
};

