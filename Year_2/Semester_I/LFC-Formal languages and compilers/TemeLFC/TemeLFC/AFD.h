#pragma once

#include <string>
#include <vector>
#include <tuple>

// A = (Q = {q0, q1}, Sigma = {a, b}, Delta, q0, F = {q1})
class AFD
{
public:
	AFD();
	AFD(std::vector<std::string> stari, std::string sigma,
		std::vector<std::tuple<std::string, char, std::string>> delta,
		std::string stareInit, std::vector<std::string> finale);

	void Citire();
	void CitireFisier();
	void Afisare();
	friend std::istream& operator>>(std::istream& d_in, AFD& a);

	//verifica daca cuvantul dat ca parametru este acceptat de catre
	//automat si afiseaza : "accepta" - daca este cuvant acceptat, 
	//"neacceptat" - daca nu este accepta,
	//"blocaj" - daca automatul se blocheaza pe parcurs.
	int Accepta(std::string& cuvant);

	//verifica (daca starea initiala / starile finale se gasesc in 
	//multimea de stari, daca tanzitiile contin doar elemente ale automatului)
	bool Verifica();

private:
	void Verificare(int& ok, std::string& cuvant, std::string& stareActuala);

private:
	std::vector<std::string> m_stari;									// Q
	std::string m_sigma;												// Sigma
	std::vector<std::tuple<std::string, char, std::string>> m_delta;	// Delta
	std::string m_stareInit;											// q0
	std::vector<std::string> m_finale;									// F

};