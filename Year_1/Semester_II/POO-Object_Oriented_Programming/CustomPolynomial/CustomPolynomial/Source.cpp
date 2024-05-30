#include <iostream>
#include "MenuHelper.cpp"
#include "PasswordHelper.cpp"

void printTypeMenu();

template <typename U>
void callMenu();

int main() {
    PasswordHelper::readPassword();

    int option;
    do {
        printTypeMenu();
        std::cin >> option;
        switch (option)
        {
        case TypeEnum::NATURAL_NUMBERS:
            callMenu<unsigned int>();
            break;
        case TypeEnum::INTEGER_NUMBERS:
            callMenu<int>();
            break;
        case TypeEnum::REAL_NUMBERS:
            callMenu<double>();
            break;
        default:
            std::cout << "\n\nIncorrect option !\n\n";
        }
        std::cin.get();
    } while ('a');

    return 0;
}

void printTypeMenu() {
    system("cls"); // cleaning window

    std::cout << "\n\nSelect the set that includes the coefficients you will use:";
    std::cout << "\n\n1. Natural Set ( e.g.: 1, 344, 122, 0, ...)";
    std::cout << "\n\n2. Integers Set ( e.g.: -59, 4, -2, 0, ...)";
    std::cout << "\n\n3. Real Set ( e.g.: 0.59, -24, 8, -0.37, ...)";
    std::cout << "\n\nInput your option:";
}

template <typename U>
void callMenu()
{
    MenuHelper<U> menu;
    menu.initMenu();
}
