#include <iostream>

template<typename T>
class Nod 
{
public:
	T info;
	Nod<T>* next = NULL;
	Nod<T>() 
	{
		this->info = NULL;
	}
	Nod<T>(T info) 
	{
		this->info = info;
	}
};

template<typename T>
class Stiva 
{
public:
	Nod<T>* vf;
	Stiva() 
	{
		this->vf = NULL;
	}

	void PUSH(T elem)
	{
		Nod<T>* y = new Nod<T>;
		y->info = elem;
		y->next = vf;
		vf = y;
	}

	void POP()
	{
		if (vf == NULL) 
		{
			std::cout << "Stiva este vida";
			return;
		}
		Nod<T>* y = vf;
		vf = vf->next;
		delete y;
	}

	T TOP()
	{
		if (vf == NULL) 
		{
			std::cout << "Stiva este vida";
			return 0;
		}
		return vf->info;
	}

	bool EMPTY()
	{
		if (this->vf == NULL) 
		{
			return true;
		}
		return false;
	}
	
	void CLEAR()
	{
		while (this->vf != NULL)
		{
			POP();
		}
	}
};

int main()
{
	Stiva<int> st;
	int exit=0;
	while (exit >= 0)
	{
		std::cout << "Tastati 1 daca doriti sa adaugati un element in stiva." << std::endl;
		std::cout << "Tastati 2 daca doriti sa eliminati un element din stiva." << std::endl;
		std::cout << "Tastati 3 daca doriti sa vedeti ultima valoarea din stiva." << std::endl;
		std::cout << "Tastati 4 daca doriti sa verificati daca stiva este goala." << std::endl;
		std::cout << "Tastati 5 daca doriti sa stergeti stiva." << std::endl;
		std::cout << "Tastati 6 daca doriti sa inchideti meniul." << std::endl;
		std::cout << std::endl;
		std::cin >> exit;
		switch (exit)
		{
		case 1:
			std::cout << "Elementul pe care doriti sa il adaugati in stiva: ";
			int elem;
			std::cin >> elem;
			st.PUSH(elem);
			std::cout << std::endl;
			system("CLS");
			break;
		case 2:
			st.POP();
			system("CLS");
			break;
		case 3:
			std::cout << "Ultimul element din stiva este: " << st.TOP()<< std::endl;
			break;
		case 4:
			if (st.EMPTY())
			{
				std::cout << "Stiva este goala." << std::endl;
			}
			else
			{
				std::cout << "Stiva NU este goala." << std::endl;
			}
			break;
		case 5:
			st.CLEAR();
			system("CLS");
			break;
		case 6:
			exit = -1;
			break;
		}
	}
	return 0;
}