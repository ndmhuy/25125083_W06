// 25125083
// Nguyen Dinh Minh Huy
// 25A01

#include "Date.hpp"
#include "Student.hpp"
#include "Course.hpp"
#include "Functions.hpp"

#include <iostream>

void P421();
void P422();
void P423();

int main()
{
    char choice;
        
    do {
        std::cout << "\n--- MAIN MENU ---\n";
        std::cout << "1. P421 (Valid Number)\n";
        std::cout << "2. P422 (Pow(x, n))\n";
        std::cout << "3. P423 (Course struct handling)\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        
        std::cin >> choice;
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case '1': P421(); break;
            case '2': P422(); break;
            case '3': P423(); break;
            case '0':
                std::cout << "Exitting the program...\n";
                break;
            default:
                std::cout << "Invalid command! Please try again.\n";
                break;
        }
    } while (choice != '0');
    
    return EXIT_SUCCESS;
}

// === P421 (Valid Number) ===
void P421()
{
    // in leetcode it is string
    std::string s;
    std::cout << "Enter the string: ";
    std::getline(std::cin, s);
    
    if (isNumber(s)) std::cout << "Valid number\n";
    else std::cout << "Invalid number\n";
}

void P422()
{
    double x;
    int n;
    char buffer;
    std::cout << "Enter pow (x^n): ";
    std::cin >> x >> buffer >> n;
    std::cout << "Result: " << myPow(x, n) << '\n';
}

// === P423 (Course) Menu ===
void P423()
{
    Course c;
    Student s;
    Student list[500];
    int count;
    char inFileName[200], outFileName[200], listOutFileName[200], findFileName[200];
    memcpy(inFileName, "input.txt", 200);
    memcpy(outFileName, "output.txt", 200);
    memcpy(listOutFileName, "list_output.txt", 200);
    memcpy(findFileName, "student_find_output.txt", 200);
    
    char choice;
    do {
        std::cout << "\n--- P423: Course struct handling ---\n";
        std::cout << "1. Input a course from text file\n";
        std::cout << "2. Output a course to text file\n";
        std::cout << "3. Save current course\n";
        std::cout << "4. Add a student to course\n";
        std::cout << "5. Remove a student from course\n";
        std::cout << "6. Get students who born this month\n";
        std::cout << "7. Get students who born this date\n";
        std::cout << "8. Get students who are legal to have driving licenses\n";
        std::cout << "9. Get students who are in class\n";
        std::cout << "a. Find student by ID\n";
        std::cout << "b. Find student by name\n";
        std::cout << "c. Sort students by ID\n";
        std::cout << "d. Sort students by first name\n";
        std::cout << "e. Sort students by GPA\n";
        std::cout << "f. Sort students by date of birth\n";
        std::cout << "0. Return to Main Menu\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case '1':
//                std::cout << "Enter input file name: ";
                //std::cin.getline(inFileName, 200);
                if (inputCourseFromFile(c, inFileName))
                    std::cout << "Data loaded sucessfully.\n";
                break;
            case '2':
//                std::cout << "Enter output file name: ";
                //std::cin.getline(outFileName, 200);
                if (outputCourseToRead(c, outFileName))
                    std::cout << "Data written sucessfully.\n";
                break;
            case '3':
//                std::cout << "Enter save file name: ";
                //std::cin.getline(outFileName, 200);
                if (outputCourseToSave(c, inFileName))
                    std::cout << "Data written sucessfully.\n";
                break;
            case '4':
                std::cout << "Enter student info:\n";
                inputStudentFromConsole(s);
                if (addStudent(c, s))
                    std::cout << "Add student successfully.\n";
                break;
            case '5':
                std::cout << "Enter student info:\n";
                inputStudentFromConsole(s);
                if (removeStudent(c, s))
                    std::cout << "Remove student successfully.\n";
                break;
            case '6':
                GetBornThisMonth(c, list, count);
                if (outputStudentListToFile(list, count, listOutFileName))
                    std::cout << "Data written successfully.\n";
                break;
            case '7':
                GetBornThisDate(c, list, count);
                if (outputStudentListToFile(list, count, listOutFileName))
                    std::cout << "Data written successfully.\n";
                break;
            case '8':
                GetLegalDrivingLicenses(c, list, count);
                if (outputStudentListToFile(list, count, listOutFileName))
                    std::cout << "Data written successfully.\n";
                break;
            case '9':
                char className[4];
                std::cout << "Enter class name (e.g. K19): ";
                std::cin.getline(className, 4);
                GetStudentsOfClass(c, className, list, count);
                if (outputStudentListToFile(list, count, listOutFileName))
                    std::cout << "Data written successfully.\n";
                break;
            case 'a':
                char searchId[MAX_STUDENT_ID_LENGTH];
                std::cout << "Enter search ID: ";
                std::cin.getline(searchId, MAX_STUDENT_ID_LENGTH);
                s = GetStudentWithId(c, searchId);
                if (outputStudentWithAgeToFile(s, findFileName))
                    std::cout << "Data written successfully.\n";
                break;
            case 'b':
                char searchName[MAX_STUDENT_NAME_LENGTH];
                std::cout << "Enter search name: ";
                std::cin.getline(searchName, MAX_STUDENT_NAME_LENGTH);
                GetStudentsWithName(c, searchName, list, count);
                if (outputStudentListToFile(list, count, listOutFileName))
                    std::cout << "Data written successfully.\n";
                break;
            case 'c':
                std::cout << "Sorted by ID\n";
                sortStudentById(c);
                if (outputCourseToRead(c, outFileName))
                    std::cout << "Data written sucessfully.\n";
                break;
            case 'd':
                std::cout << "Sorted by first name\n";
                sortStudentByFirstName(c);
                if (outputCourseToRead(c, outFileName))
                    std::cout << "Data written sucessfully.\n";
                break;
            case 'e':
                std::cout << "Sorted by GPA\n";
                sortStudentByGpa(c);
                if (outputCourseToRead(c, outFileName))
                    std::cout << "Data written sucessfully.\n";
                break;
            case 'f':
                std::cout << "Sorted by date of birth\n";
                sortStudentByDOB(c);
                if (outputCourseToRead(c, outFileName))
                    std::cout << "Data written sucessfully.\n";
                break;
            case '0':
                std::cout << "Returning to main menu...\n";
                break;
            default:
                std::cout << "Unknown command!\n";
                break;
        }
    } while (choice != '0');
}
