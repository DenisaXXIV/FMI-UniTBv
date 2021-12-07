// Laborator AF 3 + 4 302 + 204.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int* metoda(int* tablouInput) {

    int newTable[]{ 1,5,76,2 };
    cout << &newTable;
    //std::cout<<tablouInput[0];
    tablouInput[0] = 222;
    //std::cout << tablouInput[12];
    return newTable;
}

void metodaMatrice(int matriceInput[][3]) {
    matriceInput[0][0] = 222;
}

int main()
{
    int tablou[]{ 1,22,3,4,5,6,7,8,9,10,11,12,13,14,15 };

    int pointer[100];
    for (size_t i = 0; i < 15; i++)
    {
        pointer[i] = tablou[i];
    }

    tablou[0] = 124;
    cout << pointer[0] << " " << tablou[0];
    cout << &tablou << " " << pointer;

    cout << *(pointer + 1);

    tablou[1] = 55;

    cout << *(pointer + 1);
    std::cout << "\n";
    int* nouTablou = metoda(tablou);
    std::cout << "\n";
    std::cout << &nouTablou;
    std::cout << "\n";
    std::cout << nouTablou[0];

    int matriceNuMerge[][3]{ 1,2,3,4,5 };

    int** matrice = new int* [10];
    for (size_t i = 0; i < 10; i++)
    {
        matrice[i] = new int[12]{};
    }

    //metodaMatrice(matrice);
    metodaMatrice(matriceNuMerge);

}
