

#include <iostream>
using namespace std;
void Citire_Vector(int numar, int vector[])
{
    for (int index = 0; index < numar; index++)
    {
        cin >> vector[index];
    }
}

void Returnare_Vector(int vector[],int index,int &n)
{
    if (n >= 100) cout << "Eroare";
    else
    {
        for (int i = n - 1; i >= index; i--)
            vector[i + 2] = vector[i];
        n = n + 2;
        vector[index] = vector[index - 1] + vector[index + 2];
        vector[index + 1] = vector[index - 1] * vector[index + 2];
        for (int i = 0; i < n; i++)
        {
            cout << vector[i] << " ";
        }
    }
}
int main()
{
    int n, vector[100], random_value;
    cin >> n >> random_value;
    Citire_Vector(n, vector);
    Returnare_Vector(vector, random_value, n);
}


