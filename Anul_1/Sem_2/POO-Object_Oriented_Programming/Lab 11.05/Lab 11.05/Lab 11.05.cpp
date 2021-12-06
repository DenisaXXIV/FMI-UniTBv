#include <iostream>
#include "Animal.h"
#include "Pet.h"
#include "Pisica.h"
#include "Urs.h"

void VerificareAnimal(Animal* test)
{
    dynamic_cast<Pet*>(test);
    if (test == nullptr)
    {
        std::cout << "Nu este animal.";
    }
    else
    {
        std::cout << test.Play();
    }
}

int main()
{
    Pisica P("siameza","Bella");
    Urs U;
}