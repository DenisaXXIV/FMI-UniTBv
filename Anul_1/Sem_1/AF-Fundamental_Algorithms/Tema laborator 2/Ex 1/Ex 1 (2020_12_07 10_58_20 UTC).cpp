#include <iostream>
using namespace std;


int Verify_if_the_Number_is_Prime(int number)
{
    if (number < 2 || (number % 2 == 0 && number != 2))
        return 0;
    else for (int index = 3; index * index <= number; index = index + 2)
    {
        if (number % index == 0)
            return 0;
    }
    return 1;
}
int Return_the_Biggest_Digit(int number)
{
    int maximum_digit = 0;
    while (number > 0)
    {
        if (maximum_digit < number % 10)
        {
            maximum_digit = number % 10;
        }
        number /= 10;
    }
    return maximum_digit;
}
void Array(int number, int array[])
{
    for (int index1 = 0; index1 < number; index1++)
    {
        cin >> array[index1];
    }
}
void Modify_Array(int number, int array[])
{
    int new_array[100];
    Array(number, array);
    for (int index = 0; index < number; index++)
    {
        if (index % 2 == 0)
            new_array[index] = Return_the_Biggest_Digit(array[index]);
        else
            new_array[index] = Verify_if_the_Number_is_Prime(array[index]);
    }
    for (int index2 = 0; index2 < number; index2++)
    {
        cout << new_array[index2] << " ";
    }
}
int main()
{
    int n, array[100];
    cin >> n;
    Modify_Array(n, array);
    return 0;
}
