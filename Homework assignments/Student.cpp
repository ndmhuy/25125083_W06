//
//  Student.cpp
//  Learning
//
//  Created by Huy Nguyen on 16/11/25.
//

#include "Student.hpp"
#include "Date.hpp"
#include "Functions.hpp"

#include <iostream>
#include <fstream>
#include <iomanip>

std::istream& operator >>(std::istream& is, Student& s)
{
    is.getline(s.id, MAX_STUDENT_ID_LENGTH);
    is.getline(s.fullName, MAX_STUDENT_NAME_LENGTH);
    is >> s.gpa;
    is.ignore();
    is.getline(s.address, MAX_STUDENT_ADDRESS_LENGTH);
    is >> s.dob;
    
    return is;
}

std::ostream& operator <<(std::ostream& os, const Student& s)
{
    os << s.id << '\n';
    os << s.fullName << '\n';
    os << std::fixed << std::setprecision(PRECISION) << s.gpa << '\n';
    os << s.address << '\n';
    os << s.dob << '\n';
    
    return os;
}

void inputStudentFromConsole(Student& s)
{
    std::cout << "Enter ID: ";
    std::cin.getline(s.id, MAX_STUDENT_ID_LENGTH);
    std::cout << "Enter full name: ";
    std::cin.getline(s.fullName, MAX_STUDENT_NAME_LENGTH);
    std::cout << "Enter GPA: ";
    std::cin >> s.gpa;
    std::cin.ignore();
    std::cout << "Enter address: ";
    std::cin.getline(s.address, MAX_STUDENT_ADDRESS_LENGTH);
    std::cout << "Enter date of birth (dd/MM/yyyy): ";
    std::cin >> s.dob;
}

void outputStudent(std::ostream& os, const Student& s)
{
    os << "ID: " << s.id << '\n';
    os << "Full name: " << s.fullName << '\n';
    os << "GPA: " << std::fixed << std::setprecision(2) << s.gpa << '\n';
    os << "Address: " << s.address << '\n';
    char formatted[40];
    getFormattedDate(s.dob, "dd/MM/yyyy", formatted);
    os << "Date of birth: " << formatted << '\n';
}

void outputStudentToConsole(const Student& s)
{
    outputStudent(std::cout, s);
}

bool inputStudentFromFile(Student& s, const char* filename)
{
    std::ifstream fin;
    fin.open(filename);
    if (!fin) {
        std::cout << "File cannot be opened.\n";
        return false;
    }
    
    // Suppose each info in each line
    fin.getline(s.id, MAX_STUDENT_ID_LENGTH);
    fin.getline(s.fullName, MAX_STUDENT_NAME_LENGTH);
    fin >> s.gpa;
    fin.ignore();
    fin.getline(s.address, MAX_STUDENT_ADDRESS_LENGTH);
    fin >> s.dob;
    
    fin.close();
    return true;
}

bool outputStudentToFile(const Student& s, const char* filename)
{
    std::ofstream fout;
    fout.open(filename);
    if (!fout) {
        std::cout << "File cannot be opened.\n";
        return false;
    }
    
    fout << s;
    
    fout.close();
    return true;
}

bool outputStudentWithAgeToFile(const Student& s, const char* filename)
{
    std::ofstream fout;
    fout.open(filename);
    if (!fout) {
        std::cout << "File cannot be opened.\n";
        return false;
    }
    
    char firstName[50];
    char lastName[150];
    
    getFirstName(s.fullName, firstName);
    getLastName(s.fullName, lastName);
    
    Date age = calculateAge(s.dob);
    
    // for observing
    fout << "ID: " << s.id << '\n';
    fout << "First name: " << firstName << '\n';
    fout << "Last name: " << lastName << '\n';
    fout << "GPA: " << std::fixed << std::setprecision(2) << s.gpa << '\n';
    fout << "Address: " << s.address << '\n';
    char formatted[40];
    getFormattedDate(s.dob, "dd/MM/yyyy", formatted);
    fout << "Date of birth: " << formatted << '\n';
    
    char yearManip[8], monthManip[9], dayManip[7];
    strcpy(yearManip, (age.year > 1) ? " years " : " year ");
    strcpy(monthManip, (age.month > 1) ? " months " : " month ");
    strcpy(dayManip, (age.day > 1) ? " days " : " day ");
    fout << "Age: " << age.year << yearManip << age.month << monthManip << age.day << dayManip << '\n';
    
    fout.close();
    return true;
}

void outputStudentList(std::ostream& os, const Student* list, int count)
{
    for (int i = 0; i < count; ++i) {
        os << i + 1 << ". ";
        outputStudent(os, list[i]);
    }
}

bool outputStudentListToFile(const Student* list, int count, const char* filename)
{
    std::ofstream fout;
    fout.open(filename);
    if (!fout) {
        std::cout << "File cannot be opened.\n";
        return false;
    }
    
    outputStudentList(fout, list, count);
    return true;
}

void extractClass(const Student& s, char* resultBuffer)
{
    if (strlen(s.id) < 2) {
        strcpy(resultBuffer, "K_Invalid");
        return;
    }
    
    resultBuffer[0] = 'K';
    resultBuffer[1] = s.id[0];
    resultBuffer[2] = s.id[1];
    resultBuffer[3] = '\0';
}

int compareByID(const Student& s1, const Student& s2)
{
    return strcmp(s1.id, s2.id);
}

int compareByGPA_ID(const Student& s1, const Student& s2)
{
    if (s1.gpa < s2.gpa) return -1;
    if (s1.gpa > s2.gpa) return 1;
    return compareByID(s1, s2);
}
int compareByName_ID(const Student& s1, const Student& s2)
{
    int cmp = strcmp(s1.fullName, s2.fullName);
    if (cmp != 0) return cmp;
    return compareByID(s1, s2);
}

int compareByFirstName_ID(const Student& s1, const Student& s2)
{
    char fn1[50];
    char fn2[50];
    
    getFirstName(s1.fullName, fn1);
    getFirstName(s2.fullName, fn2);
    
    int cmp = strcmp(fn1, fn2);
    if (cmp != 0) return cmp;
    return compareByID(s1, s2);
}

int compareByLastName_ID(const Student& s1, const Student& s2)
{
    char ln1[150];
    char ln2[150];
    
    getLastName(s1.fullName, ln1);
    getLastName(s2.fullName, ln2);
    
    int cmp = strcmp(ln1, ln2);
    if (cmp != 0) return cmp;
    return compareByID(s1, s2);
}

int compareByDOB_ID(const Student& s1, const Student& s2)
{
    int dobCompare = compareDate(s1.dob, s2.dob);
    if (dobCompare != 0) return dobCompare;
    return compareByID(s1, s2);
}
