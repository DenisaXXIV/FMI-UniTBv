#include <iostream>

using namespace std;

void Citire(int& k, int& lp, int& lq)
{
	cout << "k=";
	cin >> k;
	cout << "Lungimea cuvantului p = ";
	cin >> lp;
	cout << "Lungimea cuvantului q = ";
	cin >> lq;
}

void Calcul_r(int lq)
{
	cout << "r=";
	for (int index = 1; index <= lq; index++)
	{
		cout << "a_" << index;
	}
	cout << endl;
}

void Calcul_p(int lp, int lq)
{
	int cat = lp / lq, rest = lp % lq;
	cout << "p=r^" << cat;
	for (int index = 1; index <= rest; index++)
	{
		cout << "a_" << index;
	}
	cout << endl;
}

void Calcul_q(int lp, int lr)
{
	cout << "q=";
	for (int index = lp % lr + 1; index <= lr; index++)
	{
		cout << "a_" << index;
	}
	for (int index = 1; index <= lp % lr; index++)
	{
		cout << "a_" << index;
	}
}

int main()
{
	int k, lp, lq, putere_r = 1;
	Citire(k, lp, lq);
	int lr = lq;
	Calcul_r(lq);
	Calcul_p(lp, lq);
	Calcul_q(lp, lr);
}
