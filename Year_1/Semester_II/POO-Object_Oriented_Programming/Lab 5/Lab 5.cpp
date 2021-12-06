#include <iostream>
#include "Matrice.h"

Matrice copie(Matrice B)
{
    Matrice a = B;
    return a;
}

int main()
{
    Matrice A(2);
    std::cin>> A;

    //putem face initializarea la crearea unui obiect cu atribuitele existele la alt obiect

    Matrice B(A); /// se face apelul la constructorul DE COPIERE
    std::cout << B;
    Matrice C = copie(B);
    std::cout << C;
}
