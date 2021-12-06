#include <iostream>
#include <fstream>

using namespace std;

void Array_input(int& size_array, int* array)
{
	size_array = 1;
	ifstream f("cautari.txt");
	while (f >> array[size_array])
		size_array++;
	size_array--;
	f.close();
}

void Sorting_array(int size_array, int* array)
{
	for (int counter = 1; counter <= size_array - 1; counter++)
		for (int secondary_counter = counter + 1; secondary_counter <= size_array; secondary_counter++)
			if (array[counter] > array[secondary_counter])
			{
				int aux = array[counter];
				array[counter] = array[secondary_counter];
				array[secondary_counter] = aux;
			}

}

void Outputting_initial_positions(int size_array, int* array)
{
	ifstream f("cautari.txt");
	int current_element;
	for (int counter = 1; counter <= size_array; counter++)
	{
		f >> current_element;
		bool found = 0;
		for (int secondary_counter = 1; secondary_counter <= size_array && found == 0; secondary_counter++)
			if (array[secondary_counter] == current_element)
			{
				cout << secondary_counter << " ";
				found = 1;
			}
	}
}

int main()
{
	int dim, array[1000];
	Array_input(dim, array);
	Sorting_array(dim, array);
	Outputting_initial_positions(dim, array);
}