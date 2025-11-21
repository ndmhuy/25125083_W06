//
//  Course.cpp
//  Learning
//
//  Created by Huy Nguyen on 18/11/25.
//

#include "Course.hpp"
#include "Date.hpp"
#include "Student.hpp"
#include "Functions.hpp"

#include <iostream>
#include <fstream>

std::istream& operator >>(std::istream& is, Course& c)
{
    is.getline(c.id, MAX_COURSE_ID_LENGTH);
    is.getline(c.name, MAX_COURSE_NAME_LENGTH);
    is >> c.studentNum;
    is.ignore();
    
    for (int i = 0; i < c.studentNum; ++i)
        is >> c.attendants[i];
    
    char temp[10]; // "Opening" or "Closing"
    is.getline(temp, 10);
    if (strcmp(temp, "Opening") == 0) c.isOpening = true;
    if (strcmp(temp, "Closing") == 0) c.isOpening = false;
    
    is >> c.maxStudent;
    is >> c.minStudent;
    is.ignore();
    
    return is;
}

std::ostream& operator <<(std::ostream& os, const Course& c)
{
    os << c.id << '\n';
    os << c.name << '\n';
    os << c.studentNum << '\n';
    
    for (int i = 0; i < c.studentNum; ++i) {
        os << c.attendants[i];
    }
    
    if (c.isOpening) os << "Opening\n";
    else os << "Closing\n";
    os << c.maxStudent << '\n';
    os << c.minStudent << '\n';
    
    return os;
}

bool inputCourseFromFile(Course& c, const char* filename)
{
    std::ifstream fin;
    fin.open(filename);
    if (!fin) {
        std::cout << "File cannot be opened.\n";
        return false;
    }

    fin >> c;
    
    fin.close();
    return true;
}

bool outputCourseToSave(const Course& c, const char* filename)
{
    std::ofstream fout;
    fout.open(filename);
    if (!fout) {
        std::cout << "File cannot be opened.\n";
        return false;
    }
    
    fout << c;
    
    fout.close();
    return true;
}

bool outputCourseToRead(const Course& c, const char* filename)
{
    std::ofstream fout;
    fout.open(filename);
    if (!fout) {
        std::cout << "File cannot be opened.\n";
        return false;
    }
    
    fout << "Course ID: " << c.id << '\n';
    fout << "Course name: " << c.name << '\n';
    fout << "Number of students: " << c.studentNum << '\n';
    fout << "List of student:\n";
    outputStudentList(fout, c.attendants, c.studentNum);
    
    fout.close();
    return true;
}

bool addStudent(Course& c, const Student& s)
{
    if (!c.isOpening) {
        std::cout << "Course is closed.\n";
        return false;
    }
    if (c.studentNum >= c.maxStudent) {
        std::cout << "Course is full.\n";
        return false;
    }
    
    for (int i = 0; i < c.studentNum; ++i) {
        if (strcmp(c.attendants[i].id, s.id) == 0) {
            std::cout << "Student already exists in course.\n";
            return false;
        }
    }
    
    c.attendants[c.studentNum++] = s;
    return true;
}

bool removeStudent(Course& c, const Student& s)
{
    if (c.studentNum <= c.minStudent)
    {
        std::cout << "Course must have at least " << c.minStudent << " students.\n";
        return false;
    }
    
    int index = -1;
    for (int i = 0; i < c.studentNum; ++i) {
        if (strcmp(c.attendants[i].id, s.id) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        std::cout << "Student not found in course.\n";
        return false;
    }
    
    for (int i = index; i < c.studentNum - 1; ++i) {
        c.attendants[i] = c.attendants[i + 1];
    }
    
    c.studentNum--;
    return true;
}

void GetBornThisMonth(const Course& c, Student* resultBuffer, int& number)
{
    Date today = getTodayDate();
    int count = 0;
    
    for (int i = 0; i < c.studentNum; ++i) {
        if (c.attendants[i].dob.month == today.month) {
            resultBuffer[count++] = c.attendants[i];
        }
    }
    
    number = count;
}

void GetBornThisDate(const Course& c, Student* resultBuffer, int& number)
{
    Date today = getTodayDate();
    int count = 0;
    
    for (int i = 0; i < c.studentNum; ++i) {
        if (c.attendants[i].dob.month == today.month && c.attendants[i].dob.day == today.day) {
            resultBuffer[count++] = c.attendants[i];
        }
    }
    
    number = count;
}

void GetLegalDrivingLicenses(const Course& c, Student* resultBuffer, int& number)
{
    int count = 0;
    
    for (int i = 0; i < c.studentNum; ++i) {
        Date age = calculateAge(c.attendants[i].dob);
        if (age.year >= 18) {
            resultBuffer[count++] = c.attendants[i];
        }
    }
    
    number = count;
}

void GetStudentsOfClass(const Course& c, const char* className, Student* resultBuffer, int& number)
{
    int count = 0;
    char bufferClass[20];
    
    for (int i = 0; i < c.studentNum; ++i) {
        extractClass(c.attendants[i], bufferClass);
        if (strcmp(bufferClass, className) == 0) {
            resultBuffer[count++] = c.attendants[i];
        }
    }
    
    number = count;
}

Student GetStudentWithId(const Course& c, const char* id)
{
    for (int i = 0; i < c.studentNum; ++i) {
        if (strcmp(c.attendants[i].id, id) == 0) {
            return c.attendants[i];
        }
    }
    
    Student emptyS;
    emptyS.id[0] = '\0';
    return emptyS;
}

void GetStudentsWithName(const Course& c, const char* searchName, Student* resultBuffer, int& number)
{
    int count = 0;
    for (int i = 0; i < c.studentNum; ++i) {
        if (strstr(c.attendants[i].fullName, searchName) != nullptr) {
            resultBuffer[count++] = c.attendants[i];
        }
    }
    
    number = count;
}

void swapStudent(Student& a, Student& b)
{
    Student temp = a;
    a = b;
    b = temp;
}

typedef int (*Comparator)(const Student& a, const Student& b);

void quicksort(Student* arr, int left, int right, Comparator comp)
{
    int i = left, j = right;
    Student pivot = arr[(left + right) / 2];
    
    while (i <= j)
    {
        while (comp(arr[i], pivot) < 0) ++i;
        while (comp(arr[j], pivot) > 0) --j;
        if (i <= j)
        {
            swapStudent(arr[i], arr[j]);
            ++i;
            --j;
        }
    }
    
    if (left < j) quicksort(arr, left, j, comp);
    if (right > i) quicksort(arr, i, right, comp);
}

void sortStudentById(Course& c)
{
    quicksort(c.attendants, 0, c.studentNum - 1, compareByID);
}

void sortStudentByFirstName(Course& c)
{
    quicksort(c.attendants, 0, c.studentNum - 1, compareByFirstName_ID);
}

void sortStudentByGpa(Course& c)
{
    quicksort(c.attendants, 0, c.studentNum - 1, compareByGPA_ID);
}

void sortStudentByDOB(Course& c)
{
    quicksort(c.attendants, 0, c.studentNum - 1, compareByDOB_ID);
}
