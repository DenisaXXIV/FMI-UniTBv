#pragma once

#include <iostream>

class Matrice
{
private:
    int nrLinii, nrColoane;
    int** elem;
    int** alocare(int, int);
public:
    Matrice(int dim);
    Matrice(int nrLinii, int nrColoane);
    Matrice();
    friend std::ostream& operator <<(std::ostream& out, Matrice m);
    friend std::istream& operator >>(std::istream& in, Matrice& m);
    int getNrLinii();
    int getNrColoane();
    int getElemente(int linie, int coloana);
    int** getElemente();
    void RESIZE(int nrLinii, int nrColoane);
    Matrice operator +(Matrice s);
    Matrice operator -(Matrice d);
    Matrice operator *(Matrice p);
    friend Matrice operator *(int alfa, Matrice m);
    ~Matrice();               //Destructor
};
