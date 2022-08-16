#include <iostream>

class Coada
{
private:
    int* val, capacitate, inceput, sfarsit;
public:
    Coada(int capacitate)
    {
        this->capacitate = capacitate;
        this->val = new int[capacitate];
        this->inceput = 0;
        this->sfarsit = 0;
    }

    void PUSH(int element)
    {
        if (capacitate > sfarsit)
        {
            val[sfarsit] = element;
            sfarsit++;
        }
        else
        {
            std::cout << "Atentie! Coada este plina.";
        }
    }

    void POP()
    {
        if (inceput <= sfarsit)
        {
            for (int index = 0; index < capacitate - 1; index++)
            {
                val[index] = val[index + 1];
            }
            sfarsit--;
        }
        else
        {
            std::cout << "Atentie! Coada este goala.";
        }
    }

    int FRONT()
    {
        return val[inceput];
    }

    int BACK()
    {
        return val[sfarsit];
    }

    bool EMPTY()
    {
        if (inceput == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void CLEAR()
    {
        while (!EMPTY())
        {
            POP();
        }

    }
};

int main()
{
    int n;
    std::cout << "Numarul de elemente din coada:";
    std::cin >> n;
    std::cout << std::endl;
    Coada a(n);
    for (int index = 0; index < n; index++)
    {
        int elem;
        std::cout << "Se citeste elementul:";
        std::cin >> elem;
        a.PUSH(elem);
    }
    for (int index = 0; index < n; index++)
    {
        std::cout << a.FRONT() << std::endl;
        a.POP();
    }
}