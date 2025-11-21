//
//  Date.hpp
//  Learning
//
//  Created by Huy Nguyen on 15/11/25.
//

#ifndef Date_hpp
#define Date_hpp

#include <iostream>

struct Date
{
    int day;
    int month;
    int year;
};

std::istream& operator >>(std::istream& is, Date& d);

std::ostream& operator <<(std::ostream& os, const Date& d);

void getFormattedDate(const Date& d, const char* format, char* resultBuffer);

void inputDateFromConsole(Date& d);

void outputDateToConsole(const Date& d);

bool inputDateFromFile(Date& d, const char* filename);

bool outputDateToFile(const Date& d, const char* filename);

bool outputDateWithFormat(const Date& d, const char* format, const char* filename);

int compareDate(const Date& d1, const Date& d2);

Date findTomorrow(Date d);

Date findYesterday(Date d);

void increaseDate(Date& d, int k);

void decreaseDate(Date& d, int k);

long long countTotalDaysSince1970(const Date& d);

int distanceToStartOfYear(const Date& d);

long long distanceTo1970(const Date& d);

long long distanceBetweenDates(const Date& d1, const Date& d2);

const char* getDayOfWeek(const Date& d);

Date getTodayDate();

Date calculateAge(const Date& dob);


#endif /* Date_hpp */
