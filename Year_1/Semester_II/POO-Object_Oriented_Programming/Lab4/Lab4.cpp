#include "Tricou.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

ifstream myFile("Tricou.txt");

int main()
{
    vector<Tricou> tricouri;
    int index = 0;
    while (!myFile.eof())
    {
        Tricou t;
        myFile >> t;
        tricouri.push_back(t);
    }

    sort(tricouri.begin(), tricouri.end());
    
    for (int i = 0; i < tricouri.size(); i++)
    {
        cout << tricouri[i];
    }
}
