#include <iostream>

template <typename T>
class Nod
{
private:
	T info;
	Nod<T>* next = NULL;
public:
	Nod<T>()
	{
		this->info = NULL;
	}

	Nod<T>(T info)
	{
		this->info = info;
	}

	Nod<T>* getNext()
	{
		return this->next;
	}

	T getInfo()
	{
		return this->info;
	}

	void setNext(Nod<T>* next)
	{
		this->next = next;
	}

	void setInfo(T info)
	{
		this->info = info;
	}

};

template <typename T>
class Lista
{
private:
	Nod<T>* head;
public:
	Lista()
	{
		head = NULL;
	}

	Nod<T> FIRST()
	{
		if (EMPTY())
		{
			std::cout << "Lista este vida!";
			return NULL;
		}
		return head->getInfo();
	}

	Nod<T> LAST()
	{
		if (EMPTY())
		{
			std::cout << "Lista este vida!";
			return NULL;
		}
		Nod<T>* current = head;
		while (current->getNext() != NULL)
		{
			current = current->getNext();
		}
		return current->getInfo();
	}

	int NR_ELEM()
	{

		if (EMPTY())
		{
			std::cout << "Lista este vida!";
			return NULL;
		}
		Nod<T>* current = head;
		int nrElem = 1;
		while (current->getNext() != NULL)
		{
			current = current->getNext();
			nrElem++;
		}
		return nrElem;
	}

	void PUSH_FRONT(T element)
	{
		Nod<T>* nodNou = new Nod<T>(element);
		nodNou->setNext(head);
		nodNou->setInfo(element);
		head = nodNou;
	}

	void PUSH_BACK(T element)
	{
		if (EMPTY())
		{
			std::cout << "Lista este vida!";
			return;
		}
		if (head == NULL)
		{
			head = new Nod<T>(element);
			return;
		}
		Nod<T>* current = head;
		while (current->getNext() != NULL)
		{
			current = current->getNext();
		}
		Nod<T>* nodNou = new Nod<T>(element);
		current->setNext(nodNou);
	}

	Nod<T>* SEARCH(T element)
	{
		if (EMPTY())
		{
			std::cout << "Lista este vida!";
			return NULL;
		}
		Nod<T>* nodNou = head;
		while (nodNou->getNext() != NULL && nodNou->getInfo() != element)
		{
			nodNou = nodNou->getNext();
		}
		if (nodNou->getInfo() == element) return nodNou;
		return NULL;
	}

	void ERASE(Nod<T>* nod)
	{
		if (EMPTY())
		{
			std::cout << "Lista este vida!";
			return;
		}
		if (nod == head)
		{
			head = head->getNext();
			return;
		}
		Nod<T>* nodCurrent = head;
		while (nodCurrent->getNext() != nod)
		{
			nodCurrent = nodCurrent->getNext();
		}
		nodCurrent->setNext(nod->getNext());

	}

	void ERASE(T element)
	{
		if (EMPTY())
		{
			std::cout << "Lista este vida!";
			return;
		}
		Nod<T>* nod = new Nod<T>;
		nod = SEARCH(element);
		if (nod == head)
		{
			head = head->getNext();
			return;
		}
		Nod<T>* nodCurrent = head;
		while (nodCurrent->getNext() != nod)
		{
			nodCurrent = nodCurrent->getNext();
		}
		nodCurrent->setNext(nod->getNext());
	}

	bool EMPTY()
	{
		return head == NULL ? true : false;
	}

	void CLEAR()
	{
		if (EMPTY())
		{
			std::cout << "Lista este vida!";
			return;
		}
		while (!EMPTY())
			ERASE(head);
	}

	void PRINT()
	{
		Nod<T>* aux = new Nod<T>;
		aux = head;
		while (aux != NULL) {
			std::cout << aux->getInfo() << std::endl;
			aux = aux->getNext();
		}
	}

	void SORT()
	{
		if (EMPTY())
		{
			std::cout << "Lista este vida!";
			return;
		}
		Nod<T>* aux = new Nod<T>;
		aux = head;
		bool sortat = false;
		while (sortat == false)
		{
			sortat = true;
			while (aux->getNext() != NULL)
			{
				if (aux->getInfo() > aux->getNext()->getInfo())
				{
					sortat = false;
					swapInfo(aux, aux->getNext());
				}

				aux->setNext(aux->getNext());
			}
		}
	}
};

template <typename T>
void swapInfo(Nod<T>* nod1, Nod<T>* nod2)
{
	T tmp = nod1->getInfo();
	nod1->setInfo(nod2->getInfo());
	nod2->setInfo(tmp);
}

int main()
{
	Lista<int> Lista, L;
	int selectie = 0, cheie;
	Nod<int>* nod = new Nod<int>;

	while (selectie != -1)
	{
		std::cout << "Apasati  1 pentru a afisa pointerul primului nod." << std::endl;
		std::cout << "Apasati  2 pentru a afisa pointerul ultimului nod." << std::endl;
		std::cout << "Apasati  3 pentru a afisa numarul de elemente din lista." << std::endl;
		std::cout << "Apasati  4 pentru a adauga o cheie in capul listei." << std::endl;
		std::cout << "Apasati  5 pentru a adauga o cheie la finalul listei." << std::endl;
		std::cout << "Apasati  6 pentru a cauta o cheie in lista." << std::endl;
		std::cout << "Apasati  7 pentru a sterge un nod din lista." << std::endl;
		std::cout << "Apasati  8 pentru a sterge o cheie din lista." << std::endl;
		std::cout << "Apasati  9 pentru a verifica daca lista este vida." << std::endl;
		std::cout << "Apasati 10 pentru a goli lista." << std::endl;
		std::cout << "Apasati 11 pentru a afisa lista." << std::endl;
		std::cout << "Apasati 12 pentru a sorta crescator lista." << std::endl;
		std::cout << "Apasati 13 pentru EXIT." << std::endl;
		std::cout << std::endl;
		std::cout << "Alegerea dumneavoastra:";
		std::cin >> selectie;
		std::cout << std::endl;

		switch (selectie)
		{
		case 3:
			std::cout << "Lista are " << Lista.NR_ELEM() << " elemente." << std::endl;
		case 4:
			std::cout << "Introduceti cheia:";
			std::cin >> cheie;
			Lista.PUSH_FRONT(cheie);
			std::cout << std::endl;
			system("CLS");
			break;
		case 5:
			std::cout << "Introduceti cheia:";
			std::cin >> cheie;
			Lista.PUSH_BACK(cheie);
			std::cout << std::endl;
			system("CLS");
			break;
		case 6:
			std::cout << "Introduceti cheia cautata:";
			std::cin >> cheie;
			std::cout << std::endl;
			Lista.SEARCH(cheie) != NULL ? std::cout << Lista.SEARCH(cheie) : std::cout << "Cheia nu a fost gasita" << std::endl;
			std::cout << std::endl;
			break;
		case 8:
			std::cout << "Introduceti cheia pe care doriti sa o stergeti:";
			std::cin >> cheie;
			std::cout << std::endl;
			Lista.ERASE(cheie);
			system("CLS");
			break;
		case 9:
			Lista.EMPTY() ? std::cout << "Lista este vida" : std::cout << "Lista nu este vida";
			std::cout << std::endl;
			std::cout << std::endl;
			break;
		case 10:
			Lista.CLEAR();
			system("CLS");
			break;
		case 11:
			std::cout << "Lista:" << std::endl;
			Lista.PRINT();
			std::cout << std::endl;
			break;
		case 12:
			Lista.SORT();
			system("CLS");
			break;
		case 13:
			selectie = 16;
			system("CLS");
			break;
		}
	}
	return 0;
}
