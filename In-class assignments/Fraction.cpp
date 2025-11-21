//
//  Fraction.cpp
//  Learning
//
//  Created by Huy Nguyen on 10/11/25.
//

#include "Fraction.hpp"

#include <iostream>

std::istream& operator>>(std::istream& is, Fraction& f)
{
    char slash = '/';
    
    is >> f.numerator;
    if (is.peek() == slash)
    {
        is >> slash >> f.denominator;
        
        if (f.denominator == 0)
        {
            std::cerr << "Error: Denominator cannot be zero.\n";
            is.setstate(std::ios::failbit);
        }
    }
    else f.denominator = 1;
    
    if (is) f.normalize();
    return is;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
    os << f.numerator;
    if (f.denominator != 1)
        os << '/' << f.denominator;
    
    return os;
}

void inputFraction(Fraction& f)
{
    std::cout << "Enter fraction (a/b): ";
    std::cin >> f;
}

void outputFraction(const Fraction& f)
{
    std::cout << f;
}

Fraction add(const Fraction& a, const Fraction& b)
{
    Fraction result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    result.normalize();
    return result;
}

Fraction subtract(const Fraction& a, const Fraction& b)
{
    Fraction result;
    result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    result.normalize();
    return result;
}
