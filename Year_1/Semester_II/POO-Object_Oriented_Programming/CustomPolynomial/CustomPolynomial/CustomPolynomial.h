#pragma once

#include <vector>
#include <ostream>
#include <iostream>
#include <cmath>
#include <stdexcept>

template <typename B>
class CustomPolynomial {
private:
    std::vector<B> coefficients;

public:
    // default constructor
    CustomPolynomial();

    // constructor with parameter
    CustomPolynomial(const std::vector<B>& coefficients);

    // copy
    CustomPolynomial(const CustomPolynomial<B>& other);

    // destructor
    ~CustomPolynomial();

    // sum of two CustomPolynomials
    CustomPolynomial<B> operator+(const CustomPolynomial<B>& other) const;

    // subtraction of two CustomPolynomials
    CustomPolynomial<B> operator-(const CustomPolynomial<B>& other) const;

    // multiplication of two CustomPolynomials
    CustomPolynomial<B> operator*(const CustomPolynomial<B>& other) const;

    // left / right multiplication by a scalar
    CustomPolynomial<B> operator*(B other) const;

    // define how objects of your class should be assigned to each other
    CustomPolynomial<B> operator=(const CustomPolynomial<B>& other);

    // checking the equality between 2 CustomPolynomials
    template <typename B>
    friend bool operator==(const CustomPolynomial<B>& customPolynomial, const CustomPolynomial<B>& other);

    // checking if CustomPolynomials1 is smaller than CustomPolynomials2
    template <typename B>
    friend bool operator<(const CustomPolynomial<B>& customPolynomial, const CustomPolynomial<B>& other);

    // return rate specified grade monomer
    B& operator[](int index);

    // display CustomPolynomial
    template <typename B>
    friend std::ostream& operator<<(std::ostream& os, const CustomPolynomial<B>& customPolynomial);

    // reading the coefficients of the keyboard
    template <typename B>
    friend std::istream& operator>>(std::istream& is, CustomPolynomial<B>& customPolynomial);

    int getBiggerSize(const CustomPolynomial<B>& other) const;

    // get type method for finding the CustomPolynomial degree
    int getGrd() const;

    // calculate the CustomPolynomial for a given x
    B Calculate(B x) const;

    // get the private vector of coefficients
    std::vector<B> getCoefficients() const;

    // set the private vector of coefficients
    void setCoefficients(const std::vector<B> coefficients);

};

template<typename B>
CustomPolynomial<B>::CustomPolynomial()
{
}

template<typename B>
CustomPolynomial<B>::CustomPolynomial(const std::vector<B>& coefficients)
{
    this->coefficients = coefficients;
}

template<typename B>
CustomPolynomial<B>::CustomPolynomial(const CustomPolynomial<B>& other)
{
    this->coefficients = other.getCoefficients();
}

template<typename B>
CustomPolynomial<B>::~CustomPolynomial()
{
    this->coefficients.clear();
}

template<typename B>
CustomPolynomial<B> CustomPolynomial<B>::operator+(const CustomPolynomial<B>& other) const
{
    std::vector<B> result(getBiggerSize(other), 0);

    for (int i = 0; i < result.size(); i++)
    {
        // if polynomial1 has the size smaller than our i, the coeff[i] will be added to the result[i]
        if (i < this->coefficients.size()) result[i] += this->coefficients[i];

        // if polynomial2 has the size smaller than our i, the coeff[i] will be added to the result[i]
        // Obs: if the result[i] already has a value, then the new value is added
        if (i < other.getCoefficients().size()) result[i] += other.getCoefficients()[i];
    }

    return CustomPolynomial<B>(result);
}

template<typename B>
CustomPolynomial<B> CustomPolynomial<B>::operator-(const CustomPolynomial<B>& other) const
{
    std::vector<B> result(getBiggerSize(other), 0);

    for (int i = 0; i < result.size(); i++)
    {

        if (i < this->coefficients.size()) result[i] += this->coefficients[i];


        if (i < other.getCoefficients().size()) result[i] -= other.getCoefficients()[i];
    }
    return CustomPolynomial<B>(result);
}

template<typename B>
CustomPolynomial<B> CustomPolynomial<B>::operator*(const CustomPolynomial<B>& other) const
{

    std::vector<B> result(this->coefficients.size() + other.getCoefficients().size() - 1, 0);
    for (int i = 0; i < this->coefficients.size(); ++i)
    {
        for (int j = 0; j < other.getCoefficients().size(); ++j)
        {
            result[i + j] += this->coefficients[i] * other.getCoefficients()[j];
        }
    }
    return CustomPolynomial<B>(result);
}

template<typename B>
CustomPolynomial<B> CustomPolynomial<B>::operator*(B other) const
{
    std::vector<B> result(this->coefficients.size());
    for (int i = 0; i < this->coefficients.size(); ++i)
    {
        result[i] = this->coefficients[i] * other;

    }
    return CustomPolynomial<B>(result);
}

template<typename B>
CustomPolynomial<B> CustomPolynomial<B>::operator=(const CustomPolynomial<B>& other)
{
    std::vector<B> result(other.getCoefficients().size(), 0);

    for (int i = 0; i < result.size(); i++)
    {
        result[i] = other.getCoefficients()[i];
    }

    return CustomPolynomial<B>(result);
}

template<typename B>
B& CustomPolynomial<B>::operator[](int index)
{
    if (index >= this->coefficients.size()) {
        // Handle out-of-range access, for example, throw an exception
        throw std::out_of_range("Index out of range");
    }
    return this->coefficients[index];
}


template<typename B>
std::vector<B> CustomPolynomial<B>::getCoefficients() const
{
    return this->coefficients;
}

template<typename B>
void CustomPolynomial<B>::setCoefficients(const std::vector<B> coefficients) {
    this->coefficients = coefficients;
}

template<typename B>
B CustomPolynomial<B>::Calculate(B x) const{
    B sum = 0;
    for (int i = 0; i < this->coefficients.size(); i++)
    {
        sum = sum + this->coefficients[i] * pow(x, i);
    }

    return sum;
}

template<typename B>
int CustomPolynomial<B>::getGrd() const {
    return getCoefficients().size() - 1;
}

template<typename B>
int CustomPolynomial<B>::getBiggerSize(const CustomPolynomial<B>& other) const {
    if (this->coefficients.size() < other.getCoefficients().size())
    {
        return other.getCoefficients().size();
    }
    else
    {
        return this->coefficients.size();
    }
}

template<typename B>
bool operator==(const CustomPolynomial<B>& customPolynomial, const CustomPolynomial<B>& other)
{
    if (customPolynomial.getCoefficients().size() != other.getCoefficients().size())
    {
        return false;
    }
    for (int i = 0; i <= customPolynomial.getCoefficients().size(); ++i)
    {
        if (customPolynomial.getCoefficients()[i] != other.getCoefficients()[i]) {
            return false;
        }
    }
    return true;
}

template<typename B>
bool operator<(const CustomPolynomial<B>& customPolynomial, const CustomPolynomial<B>& other)
{
    if (customPolynomial.getCoefficients().size() > other.getCoefficients().size())
    {
        return true;
    }
    else if (customPolynomial.getCoefficients().size() < other.getCoefficients().size()) {
        return false;
    }
    for (int i = customPolynomial.getCoefficients().size() - 1; i >= 0; i--)
    {
        if (customPolynomial.getCoefficients()[i] > other.getCoefficients()[i]) {
            return false;
        }
    }
    return true;
}

template<typename B>
std::ostream& operator<<(std::ostream& os, const CustomPolynomial<B>& customPolynomial) {
    for (int i = customPolynomial.getCoefficients().size() - 1; i >= 0; --i) {
        if (customPolynomial.getCoefficients()[i] != 0) {
            if (i < customPolynomial.getCoefficients().size() - 1 && customPolynomial.getCoefficients()[i] > 0) {
                os << "+ ";
            }
            os << customPolynomial.getCoefficients()[i];
            if (i > 1) {
                os << "x^" << i << " ";
            }
            else if (i > 0) {
                os << "x ";
            }
        }
    }
    return os;
}

template<typename B>
std::istream& operator>>(std::istream& is, CustomPolynomial<B>& customPolynomial) {

    B coeff = 0;
    int degree = -1;

    do
    {
        std::cout << "Input the polynomial's degree: ";
        is >> degree;
        std::cout << "\n";
    } while (degree <= 0);

    std::vector<B> coeffs(degree + 1);

    for (int i = 0; i <= degree; i++) {
        std::cout << "Input the coefficient of x^" << i << ": ";
        is >> coeff;
        if (coeff)
            coeffs[i] = coeff;
    }
    customPolynomial.setCoefficients(coeffs);
    return is;
}