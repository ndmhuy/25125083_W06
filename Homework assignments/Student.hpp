//
//  Student.hpp
//  Learning
//
//  Created by Huy Nguyen on 16/11/25.
//

#ifndef Student_hpp
#define Student_hpp

#include "Date.hpp"

#include <iostream>

const int MAX_STUDENT_ID_LENGTH = 20;
const int MAX_STUDENT_NAME_LENGTH = 200;
const int MAX_STUDENT_ADDRESS_LENGTH = 200;
const int PRECISION = 2;

struct Student
{
    char id[MAX_STUDENT_ID_LENGTH];
    char fullName[MAX_STUDENT_NAME_LENGTH];
    double gpa;
    char address[MAX_STUDENT_ADDRESS_LENGTH];
    Date dob;
};

std::istream& operator >>(std::istream& is, Student& s);

std::ostream& operator <<(std::ostream& os, const Student& s);

void outputStudent(std::ostream& os, const Student& s);

void inputStudentFromConsole(Student& s);

void outputStudentToConsole(const Student& s);

bool inputStudentFromFile(Student& s, const char* filename);

bool outputStudentToFile(const Student& s, const char* filename);

bool outputStudentWithAgeToFile(const Student& s, const char* filename);

void outputStudentList(std::ostream& os, const Student* list, int count);

bool outputStudentListToFile(const Student* list, int count, const char* filename);

void extractClass(const Student& s, char* resultBuffer);

int compareByID(const Student& s1, const Student& s2);

int compareByGPA_ID(const Student& s1, const Student& s2);

int compareByName_ID(const Student& s1, const Student& s2);

int compareByFirstName_ID(const Student& s1, const Student& s2);

int compareByLastName_ID(const Student& s1, const Student& s2);

int compareByDOB_ID(const Student& s1, const Student& s2);

#endif /* Student_hpp */
