#include <iostream>
using namespace std;

void Reading_Array(int array[], int number)
{
	for (int index1 = 0; index1 < number; index1++)
	{
		cin >> array[index1];
	}
}
bool Verify_Sum(int neighbor1, int number, int neighbor2)
{
	if (neighbor1 + neighbor2 == number)
		return true;
	else
		return false;
}
void Removing_an_Element_from_Array(int array[], int &number, int position)
{
	for (int index2 = position; index2 < number; index2++)
	{
		array[index2] = array[index2 + 1];
	}
	number--;
}
void Modify_Array(int array[], int number)
{
	Reading_Array(array, number);
	for (int index3 = 1; index3 < number - 1; index3++)
	{
		if (Verify_Sum(array[index3 - 1], array[index3], array[index3 + 1]) == true)
		{
			Removing_an_Element_from_Array(array, number, index3);
		}
	}
	for (int index4 = 0; index4 < number; index4++)
	{
		cout << array[index4] << " ";
	}
}
int main()
{
	int n, array[100];
	cin >> n;
	Modify_Array(array, n);
	return 0;
}


