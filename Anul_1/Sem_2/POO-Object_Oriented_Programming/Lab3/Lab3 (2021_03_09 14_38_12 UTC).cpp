#include <iostream>

class Vect
{
    double cx, cy, cz;  //atribute
public:
    void Initializare(double x, double y,  double z)
    {
        cx = x;
        cy = y;
        cz = z;
    }
    void Afisare()
    {
        std::cout << "(" << cx << "," << cy << "," << cz << ")" << std::endl;
    }
};

int main()
{
    Vect v;
    v.Initializare(0, 1, 2);
    v.Afisare();
}
