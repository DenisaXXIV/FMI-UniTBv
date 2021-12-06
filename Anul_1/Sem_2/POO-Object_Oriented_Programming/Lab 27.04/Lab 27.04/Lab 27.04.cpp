#include <iostream>
#include <vector>
#include "Persoana.h"
#include "Student.h"
#include "Angajat.h"

int main()
{
    std::vector<Persoana*>vect;
    std::vector<Student*>vs;
    std::vector<Angajat*>va;

    vect.push_back(new Student("Pop Andrei", 20, "Info", 400));
    vect.push_back(new Angajat("Vladescu David", 25, 1700, "Adient"));
    vect.push_back(new Angajat("Arion Mara", 22, 1600, "BCR"));
    vect.push_back(new Student("Radulescu Alexia", 21, "Mate-Info", 500));

    for (Persoana* pp : vect)
    {
        pp->Afisare();
    }

    for (Persoana* pp : vect)
    {
        if (dynamic_cast<Student*> (pp))
        {
            vs.push_back(dynamic_cast<Student*> (pp));
        }
    }

    for (Persoana* pp : vect)
    {
        if (dynamic_cast<Angajat*> (pp))
        {
            va.push_back(dynamic_cast<Angajat*> (pp));
        }
    }

}