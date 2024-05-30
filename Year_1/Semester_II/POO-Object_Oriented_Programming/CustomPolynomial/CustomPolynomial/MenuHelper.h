#pragma once

#include <iostream>
#include <map>
#include "MenuEnum.h"
#include "CustomPolynomial.h"
#include "TypeEnum.h"
#include <fstream> 
#include <string>

template <typename Balu>
class MenuHelper
{
public:
    std::map<std::string, CustomPolynomial<Balu>> polynomials;

    void initMenu();

    MenuHelper();

private:
    void initBackMenu();

    void printMenu();

    void printBackMenu();

    void optionRead();

    void optionReadFile();

    void optionSubtraction();

    void optionMultiplication();

    void optionScalarMultiplication();

    void optionSum();

    void optionDegree();

    void optionCalculate();

    void optionCoefficient();

    void optionEquality();

    void optionHelp();

    void optionExit();

    void showPolynomials();
};

template<typename Balu>
MenuHelper<Balu>::MenuHelper()
{

}

template<typename Balu>
void MenuHelper<Balu>::initMenu()
{
    int option;
    do {
        printMenu();
        std::cin >> option;
        switch (option)
        {
        case MenuEnum::READ:
            optionRead();
            break;
        case MenuEnum::READ_FILE:
            optionReadFile();
            break;
        case MenuEnum::SUM:
            optionSum();
            break;
        case MenuEnum::SUBSTRACTION:
            optionSubtraction();
            break;
        case MenuEnum::MULTIPLICATION:
            optionMultiplication();
            break;
        case MenuEnum::MULTIPLICATION_SCALAR:
            optionScalarMultiplication();
            break;
        case MenuEnum::EQUALITY:
            optionEquality();
            break;
        case MenuEnum::COEFFICIENT:
            optionCoefficient();
            break;
        case MenuEnum::DEGREE:
            optionDegree();
            break;
        case MenuEnum::CALCULATE:
            optionCalculate();
            break;
        case MenuEnum::HELP:
            optionHelp();
            break;
        case MenuEnum::EXIT:
            optionExit();
            break;
        default:
            std::cout << "\n\nIncorrect option !";
        }
        std::cin.get();
    } while ('a');
}

template<typename Balu>
void MenuHelper<Balu>::initBackMenu() {
    int option;
    do {
        printBackMenu();
        std::cin >> option;
        switch (option)
        {
        case MenuEnum::HELP:
            optionHelp();
            break;
        case MenuEnum::EXIT:
            optionExit();
            break;
        case MenuEnum::BACK:
            initMenu();
            break;
        default:
            std::cout << "\n\nIncorrect option !";
            initBackMenu();
        }
        std::cin.get();
    } while ('a');
}

template<typename Balu>
void MenuHelper<Balu>::printMenu() {
    system("cls"); // cleaning window

    std::cout << "\n\n1. Write polynomial";
    std::cout << "\n\n2. Read polynomial from file";
    if (polynomials.size() > 0) {
        if (polynomials.size() > 1) {
        std::cout << "\n\n3. Sum of two polynomials";
        std::cout << "\n\n4. Subtraction of two polynomials";
        std::cout << "\n\n5. Multiplication of two polynomials";
        }
        std::cout << "\n\n6. Multiplication by a scalar";
        if (polynomials.size() > 1) {
            std::cout << "\n\n7. Checking the equality between two polynomials";
        }
        std::cout << "\n\n8. Rate specified grade monomer of polynomial";
        std::cout << "\n\n9. Find the polynomial degree";
        std::cout << "\n\n10. Calculate polynomial for a given \'x\'";
    }
    std::cout << "\n\n11. Help";
    std::cout << "\n\n12. Exit";
    std::cout << "\n\nInput your option:";
}

template<typename Balu>
void MenuHelper<Balu>::printBackMenu() {

    std::cout << "\n\n11. Help";
    std::cout << "\n\n12. Exit";
    std::cout << "\n\n13. Back";
    std::cout << "\n\nInput your option:";
}

template<typename Balu>
void MenuHelper<Balu>::optionRead() {
    system("cls");
    CustomPolynomial<Balu> poly;
    std::string name;

    if (!polynomials.empty()) {
        showPolynomials();
    }

    std::cout << "\n\nPlease enter the name of polynomial:";
    std::cin >> name;
    std::cin >> poly;

    polynomials.insert(std::pair<std::string, CustomPolynomial<Balu>>(name, poly));
}

template<typename Balu>
void MenuHelper<Balu>::optionReadFile() {
    //system("cls");
    //Balu value;
    //std::string fileName;
    //std::string name;
    //int degree;

    //if (!polynomials.empty()) {
    //    showPolynomials();
    //}

    ////std::cout << "\n\nPlease enter the name of the .txt file from the resources folder:";
    ////std::cin >> fileName;

    ////fileName = "..\\resources\\" + fileName;

    ////if (fileName.find(".txt") != std::string::npos)
    ////{
    ////    fileName = fileName + ".txt";
    ////}

    ////fileName = "polynomials.txt";

    //std::ifstream fis_in;
    //fis_in.open("date.txt");

    //if (!fis_in.is_open()) {
    //    std::cout << "Error opening the file!" << std::endl;
    //    optionReadFile();
    //}

    ///*CustomPolynomial<Balu> poly;*/
    //
    //if (fis_in.tellg() < 1) {
    //    std::cout << "File empty!" << std::endl;
    //    optionReadFile();
    //}

    //while (fis_in >>name)
    //{
    //    std::cout << "name: " << name << "\n";
    //    fis_in >> degree;
    //    std::vector<Balu> coeffs;
    //    for (int i = 0; i <= degree; i++) {
    //        fis_in >> value;
    //        coeffs.push_back(value);
    //    }
    //    CustomPolynomial<Balu> poly(coeffs);

    //    polynomials.insert(std::pair<std::string, CustomPolynomial<Balu>>(name, poly));
    //}

    //fis_in.close();

    //showPolynomials();

    //while (true);

    initBackMenu();

}

template<typename Balu>
void MenuHelper<Balu>::optionSubtraction() {
    system("cls");

    showPolynomials();

    std::string name1;
    std::string name2;

    std::cout << "\n\nPlease enter the name of first polynomial:";
    std::cin >> name1;

    std::cout << "\n\nPlease enter the name of second polynomial:";
    std::cin >> name2;
    system("cls");

    std::cout << "(" << polynomials[name1] << " )";
    std::cout << " - (" << polynomials[name2] << ") = ";
    std::cout << polynomials[name1] - polynomials[name2];

    initBackMenu();
}

template<typename Balu>
void MenuHelper<Balu>::optionMultiplication() {
    system("cls");

    showPolynomials();

    std::string name1;
    std::string name2;

    std::cout << "\n\nPlease enter the name of first polynomial:";
    std::cin >> name1;

    std::cout << "\n\nPlease enter the name of second polynomial:\n\n";
    std::cin >> name2;
    system("cls");

    std::cout << "(" << polynomials[name1] << " )";
    std::cout << " * (" << polynomials[name2] << ") = ";
    std::cout << polynomials[name1] * polynomials[name2];

    initBackMenu();
}

template<typename Balu>
void MenuHelper<Balu>::optionScalarMultiplication() {
    system("cls");

    std::string name;
    Balu scalar;


    showPolynomials();

    std::cout << "\n\nPlease enter the name of polynomial:\n\n";
    std::cin >> name;

    std::cout << "\n\nPlease enter the scalar:\n\n";
    std::cin >> scalar;
    system("cls");

    std::cout << "(" << polynomials[name] << " )";
    std::cout << " * (" << scalar << ") = ";
    std::cout << polynomials[name] * scalar;

    initBackMenu();
}

template<typename Balu>
void MenuHelper<Balu>::optionSum() {
    system("cls");

    showPolynomials();

    std::string name1;
    std::string name2;

    std::cout << "\n\nPlease enter the name of first polynomial:";
    std::cin >> name1;

    std::cout << "\n\nPlease enter the name of second polynomial:\n\n";
    std::cin >> name2;
    system("cls");

    std::cout << "(" << polynomials[name1] << " )";
    std::cout << " + (" << polynomials[name2] << ") = ";
    std::cout << polynomials[name1] + polynomials[name2];

    initBackMenu();
}

template<typename Balu>
void MenuHelper<Balu>::optionDegree() {
    system("cls");

    showPolynomials();

    std::string name;

    std::cout << "\n\nPlease enter the name of polynomial:";
    std::cin >> name;

    std::cout << "\n\nThe degree of the polynomial " << name << " is " << polynomials[name].getGrd();

    initBackMenu();
}

template<typename Balu>
void MenuHelper<Balu>::optionCalculate() {
    system("cls");

    showPolynomials();

    std::string name;
    Balu x;

    std::cout << "\n\nPlease enter the name of polynomial:";
    std::cin >> name;

    std::cout << "\n\nPlease enter the X value:";
    std::cin >> x;

    std::cout << "\n\n" << name << "(" << x << ") = " << polynomials[name].Calculate(x);

    initBackMenu();
}

template<typename Balu>
void MenuHelper<Balu>::optionCoefficient() {
    system("cls");

    showPolynomials();

    std::string name;
    int grade;

    std::cout << "\n\nPlease enter the name of first polynomial:";
    std::cin >> name;

    std::cout << "\n\nPlease enter the grade monomer:\n\n";
    std::cin >> grade;

    std::cout << "\n\nCoefficient of x^" << grade;
    std::cout << " is " << polynomials[name][grade];

    initBackMenu();
}

template<typename Balu>
void MenuHelper<Balu>::optionEquality() {
    system("cls");

    showPolynomials();

    std::string name1;
    std::string name2;

    std::cout << "\n\nPlease enter the name of first polynomial:";
    std::cin >> name1;

    std::cout << "\n\nPlease enter the name of second polynomial:";
    std::cin >> name2;
    system("cls");

    if (polynomials[name1] == polynomials[name2]) {
        std::cout << "(" << polynomials[name1] << " )";
        std::cout << " == (" << polynomials[name2] << ") ";
    }
    else {
        std::cout << "(" << polynomials[name2] << " )";
        std::cout << " != (" << polynomials[name1] << ") ";
    }

    initBackMenu();
}

template<typename Balu>
void MenuHelper<Balu>::optionHelp() {
    system("cls");
    std::cout << "This project involves defining a generic Polynomial class to represent polynomials of any degree "
        "with coefficients of any numeric type. The class must provide a range of functionalities, including "
        "various constructors, binary operators, scalar multiplication, and methods for polynomial "
        "evaluation and degree determination.";

    initBackMenu();
}

template<typename Balu>
void MenuHelper<Balu>::optionExit() {
    std::cout << "\nCompleted!\n";
    std::cin.ignore(1);
    std::cin.get();
    exit(0);
}

template<typename Balu>
void MenuHelper<Balu>::showPolynomials() {
    system("cls");

    std::cout << "These are the polynomials:\n";
    for (auto it = polynomials.begin(); it != polynomials.end(); ++it) {
        std::cout << it->first << " = " << it->second << "\n";
    }
}