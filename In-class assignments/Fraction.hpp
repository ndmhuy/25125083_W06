//
//  Fraction.hpp
//  Learning
//
//  Created by Huy Nguyen on 10/11/25.
//

#ifndef Fraction_hpp
#define Fraction_hpp

#include "Functions.hpp"

#include <iostream>

/// A fraction
struct Fraction
{
    int numerator;
    int denominator;
    
    void normalize() {
        if (denominator == 0) {
            return;
        }

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        int common = gcd(numerator, denominator);

        numerator /= common;
        denominator /= common;
    }
};

std::istream& operator>>(std::istream& is, Fraction& f);
std::ostream& operator<<(std::ostream& os, const Fraction& f);

void inputFraction(Fraction& f);
void outputFraction(const Fraction& f);

/// Add two fractions
/// - Parameters:
///   - a:first
///   - b:second
Fraction add(const Fraction& a, const Fraction& b);

/// Subtract two factions
/// - Parameters:
///   - a: minuend
///   - b: subtrahend
Fraction subtract(const Fraction& a, const Fraction& b);

#endif /* Fraction_hpp */
