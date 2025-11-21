//
//  Date.cpp
//  Learning
//
//  Created by Huy Nguyen on 15/11/25.
//

#include "Date.hpp"
#include "Functions.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

std::istream& operator >>(std::istream& is, Date& d)
{
    char buffer;
    is >> d.day >> buffer >> d.month >> buffer >> d.year;
    is.ignore();
    return is;
}

std::ostream& operator <<(std::ostream& os, const Date& d)
{
    char formatted[40];
    getFormattedDate(d, "dd/MM/yyyy", formatted);
    os << formatted;
    return os;
}


void getFormattedDate(const Date& d, const char* format, char* resultBuffer)
{
    const char* monthNames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    
    char yyyy_str[5];
    char yy_str[3];
    char MM_str[3];
    char M_str[3];
    char dd_str[3];
    char d_str[3];
        
    snprintf(yyyy_str, 5, "%d", d.year);
    snprintf(yy_str, 3, "%02d", d.year % 100);
    snprintf(MM_str, 3, "%02d", d.month);
    snprintf(M_str, 3, "%d", d.month);
    snprintf(dd_str, 3, "%02d", d.day);
    snprintf(d_str, 3, "%d", d.day);

    strcpy(resultBuffer, format);
    
    replaceSubString(resultBuffer, "yyyy", yyyy_str);
    replaceSubString(resultBuffer, "yy", yy_str);
    
    replaceSubString(resultBuffer, "MMM", monthNames[d.month - 1]);
    replaceSubString(resultBuffer, "MM", MM_str);
    replaceSubString(resultBuffer, "M", M_str);

    replaceSubString(resultBuffer, "dd", dd_str);
    replaceSubString(resultBuffer, "d", d_str);
}

void inputDateFromConsole(Date& d)
{
    std::cout << "Enter day: ";
    std::cin >> d.day;
    std::cout << "Enter month: ";
    std::cin >> d.month;
    std::cout << "Enter year: ";
    std::cin >> d.year;
}

void outputDateToConsole(const Date& d)
{
    std::cout << d;
}

bool inputDateFromFile(Date& d, const char* filename)
{
    std::ifstream fin;
    fin.open(filename);
    if (!fin) {
        std::cout << "File cannot be opened.\n";
        return false;
    }
    
    // Suppose format: dd/MM/yyyy
    fin >> d;
    fin.close();
    return true;
}

bool outputDateToFile(const Date& d, const char* filename)
{
    std::ofstream fout;
    fout.open(filename);
    if (!fout) {
        std::cout << "File cannot be opened.\n";
        return false;
    }
    
    // Format: yyyy-MM-dd
    fout << std::setfill('0');
    fout << std::setw(4) << d.year << "-";
    fout << std::setw(2) << d.month << "-";
    fout << std::setw(2) << d.day << '\n';
    fout.close();
    return true;
}

bool outputDateWithFormat(const Date& d, const char* format, const char* filename)
{
    char formatted[40];
    getFormattedDate(d, format, formatted);
    
    std::ofstream fout;
    fout.open(filename);
    if (!fout) {
        std::cout << "File cannot be opened.\n";
        return false;
    }
    
    fout << formatted << '\n';
    fout.close();
    return true;
}

// return: -1 (d1 < d2) 0 (d1 = d2) 1 (d1 > d2)
int compareDate(const Date& d1, const Date& d2)
{
    if (d1.year < d2.year) return -1;
    if (d1.year > d2.year) return 1;
    
    if (d1.month < d2.month) return -1;
    if (d1.month > d2.month) return 1;
    
    if (d1.day < d2.day) return -1;
    if (d1.day > d2.day) return 1;
    
    return 0;
}

Date findTomorrow(Date d)
{
    int maxDays = daysInMonth(d.month, d.year);
    if (d.day < maxDays) ++d.day;
    else {
        d.day = 1;
        if (d.month < 12) ++d.month;
        else {
            d.month = 1;
            ++d.year;
        }
    }
    return d;
}

Date findYesterday(Date d)
{
    if (d.day > 1) --d.day;
    else {
        if (d.month > 1) --d.month;
        else {
            d.month = 12;
            --d.year;
        }
        d.day = daysInMonth(d.month, d.year);
    }
    return d;
}

void increaseDate(Date& d, int k)
{
    for (int i = 0; i < k; ++i)
        d = findTomorrow(d);
}

void decreaseDate(Date& d, int k)
{
    for (int i = 0; i < k; ++i) {
        d = findYesterday(d);
    }
}

long long countTotalDaysSince1970(const Date& d)
{
    long long totalDays = 0LL;
    for (int y = 1970; y < d.year; ++y) {
        totalDays += (isLeapYear(y)) ? 366 : 365;
    }
    
    for (int m = 1; m < d.month; ++m) {
        totalDays += daysInMonth(m, d.year);
    }
    
    totalDays += d.day - 1;
    return totalDays;
}

int distanceToStartOfYear(const Date& d)
{
    int days = 0;
    for (int m = 1; m < d.month; ++m) {
        days += daysInMonth(m, d.year);
    }
    days += d.day - 1;
    return days;
}

long long distanceTo1970(const Date& d)
{
    return countTotalDaysSince1970(d);
}

long long distanceBetweenDates(const Date& d1, const Date& d2)
{
    return abs(countTotalDaysSince1970(d2) - countTotalDaysSince1970(d1));
}

// 1/1/1970 Thursday
const char* getDayOfWeek(const Date& d)
{
    const char* weekDay[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    long long days = countTotalDaysSince1970(d);
    int offset = (days + 3) % 7;
    return weekDay[offset];
}

Date getTodayDate()
{
    time_t now = time(0);
    tm ltm;
    
#ifdef _WIN32
    localtime_s(&ltm, &now);
#else
    localtime_r(&now, &ltm);
#endif
    
    Date today;
    today.year = 1900 + ltm.tm_year;
    today.month = 1 + ltm.tm_mon;
    today.day = ltm.tm_mday;
    return today;
}

Date calculateAge(const Date& dob)
{
    Date age;
    Date today = getTodayDate();
    
    age.day = today.day - dob.day;
    age.month = today.month - dob.month;
    age.year = today.year - dob.year;
    
    if (age.day < 0) {
        --age.month;
        int prevMonth, prevMonthYear;
        
        if (today.month == 1) {
            prevMonth = 12;
            prevMonthYear = today.year - 1;
        } else {
            prevMonth = today.month - 1;
            prevMonthYear = today.year;
        }
        
        age.day += daysInMonth(prevMonth, prevMonthYear);
    }
    if (age.month < 0) {
        --age.year;
        age.month += 12;
    }
    
    return age;
}
