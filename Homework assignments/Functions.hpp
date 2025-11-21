//
//  Functions.hpp
//  Learning
//
//  Created by Huy Nguyen on 10/11/25.
//

#ifndef Functions_hpp
#define Functions_hpp

#include <iostream>

// Date
void replaceSubString(char* str, const char* from, const char* to);

bool isLeapYear(int year);

int daysInMonth(int month, int year);

// Student
void getFirstName(const char* fullName, char* resultBuffer);

void getLastName(const char* fullName, char* resultBuffer);

// Others
bool isNumber(std::string s);

double myPow(double x, int n);

#endif /* Functions_hpp */
