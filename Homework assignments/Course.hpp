//
//  Course.hpp
//  Learning
//
//  Created by Huy Nguyen on 18/11/25.
//

#ifndef Course_hpp
#define Course_hpp

#include "Date.hpp"
#include "Student.hpp"
#include "Functions.hpp"

#include <iostream>

const int MAX_COURSE_ID_LENGTH = 20;
const int MAX_COURSE_NAME_LENGTH = 200;

struct Course
{
    char id[MAX_COURSE_ID_LENGTH];
    char name[MAX_COURSE_NAME_LENGTH];
    Student attendants[500];
    int studentNum;
    bool isOpening;
    int maxStudent;
    int minStudent;
};

std::istream& operator >>(std::istream& is, Course& c);

std::ostream& operator <<(std::ostream& os, const Course& c);

bool inputCourseFromFile(Course& c, const char* filename);

bool outputCourseToSave(const Course& c, const char* filename);

bool outputCourseToRead(const Course& c, const char* filename);

bool addStudent(Course& c, const Student& s);

bool removeStudent(Course& c, const Student& s);

void GetBornThisMonth(const Course& c, Student* resultBuffer, int& number);

void GetBornThisDate(const Course& c, Student* resultBuffer, int& number);

void GetLegalDrivingLicenses(const Course& c, Student* resultBuffer, int& number);

void GetStudentsOfClass(const Course& c, const char* className, Student* resultBuffer, int& number);

Student GetStudentWithId(const Course& c, const char* id);

void GetStudentsWithName(const Course& c, const char* searchName, Student* resultBuffer, int& number);

void sortStudentById(Course& c);

void sortStudentByFirstName(Course& c);

void sortStudentByGpa(Course& c);

void sortStudentByDOB(Course& c);

#endif /* Course_hpp */
