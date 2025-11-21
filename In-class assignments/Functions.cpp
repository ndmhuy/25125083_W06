//
//  Functions.cpp
//  Learning
//
//  Created by Huy Nguyen on 10/11/25.
//

#include "Functions.hpp"

#include <iostream>
#include <string>

// === Fraction ===
int gcd(int a, int b)
{
    a = std::abs(a);
    b = std::abs(b);
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

int myAtoi(std::string s)
{
    int sign = 1, number = 0;
    int i = 0;
    auto size = s.size();

    while (i < size && isspace(s[i])) ++i;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-') sign = -1;
        ++i;
    }

    while (i < size && isdigit(s[i]))
    {
        int digit = s[i] - '0';
        if (number > INT_MAX / 10 ||
         (number == INT_MAX / 10 && digit > INT_MAX % 10))
            return (sign == 1) ? INT_MAX : INT_MIN;
        
        number = number * 10 + digit;
        i++;
    }
    return number * sign;
}
