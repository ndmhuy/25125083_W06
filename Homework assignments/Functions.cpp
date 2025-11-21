//
//  Functions.cpp
//  Learning
//
//  Created by Huy Nguyen on 10/11/25.
//

#include "Functions.hpp"

#include <iostream>

int countOccurences(const char* str, const char* subStr)
{
    int count = 0;
    size_t lenSub = strlen(subStr);
    const char* p = str;
    
    while ((p = strstr(p, subStr)) != nullptr)
    {
        ++count;
        p += lenSub;
    }
    
    return count;
}

void replaceSubString(char* str, const char* from, const char* to)
{
    if (str == nullptr || from == nullptr || to == nullptr)
        return;
    
    size_t lenFrom = strlen(from);
    if (lenFrom == 0)
        return;
    
    size_t lenTo = strlen(to);
    
    int count = countOccurences(str, from);
    if (count == 0) return;
    
    size_t len = strlen(str);
    size_t shift = (lenTo - lenFrom) * count;
    size_t newLen = len + shift;
    
    if (shift > 0)
    {
        str[newLen] = '\0';
        
        char* readPtr = str + len - 1;
        char* writePtr = str + newLen - 1;
        
        while (readPtr >= str)
        {
            if (readPtr - lenFrom + 1 >= str && strncmp(readPtr - lenFrom + 1, from, lenFrom) == 0)
            {
                writePtr -= lenTo;
                memcpy(writePtr + 1, to, lenTo);
                readPtr -= lenFrom;
            }
            else *writePtr-- = *readPtr--;
        }
    }
    else
    {
        char* readPtr = str;
        char* writePtr = str;
        
        while (*readPtr != '\0')
        {
            if (strncmp(readPtr, from, lenFrom) == 0)
            {
                memcpy(writePtr, to, lenTo);
                readPtr += lenFrom;
                writePtr += lenTo;
            }
            else *writePtr++ = *readPtr++;
        }
        
        *writePtr = '\0';
    }
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year)
{
    if (month == 2)
        return (isLeapYear(year)) ? 29 : 28;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else return 31;
}

void getFirstName(const char* fullName, char* resultBuffer)
{
    const char* p = fullName;
    while (*p != '\0' && !isspace(*p))
        *resultBuffer++ = *p++;
    *resultBuffer = '\0';
}

void getLastName(const char* fullName, char* resultBuffer)
{
    const char* p = fullName;
    while (*p != '\0' && !isspace(*p)) ++p;
    while (*p != '\0' && isspace(*p)) ++p;
    
    while (*p != '\0')
        *resultBuffer++ = *p++;
    *resultBuffer = '\0';
}

bool isNumber(std::string s)
{
    size_t i = 0, n = s.size();

    if (i < n && (s[i] == '+' || s[i] == '-')) i++;

    bool isNumeric = false;
    bool hasDot = false;

    while (i < n && (isdigit(s[i]) || s[i] == '.')) {
        if (s[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else {
            isNumeric = true;
        }
        ++i;
    }
    
    if (!isNumeric) return false;

    if (i < n && (s[i] == 'e' || s[i] == 'E')) {
        ++i;

        if (i < n && (s[i] == '+' || s[i] == '-')) i++;

        bool hasExpDigits = false;

        while (i < n && isdigit(s[i])) {
            hasExpDigits = true;
            ++i;
        }

        if (!hasExpDigits) return false;
    }

    return i == n;
}

double myPow(double x, int n)
{
    long long exp = n;
    if (exp < 0)
    {
        x = 1.0 / x;
        exp = -exp;
    }

    double result = 1.0;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result *= x;
        x *= x;
        exp /= 2;
    }

    return result;
}
