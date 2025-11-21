// 25125083
// Nguyen Dinh Minh Huy
// 25A01

#include "Fraction.hpp"
#include "Triangle.hpp"
#include "Functions.hpp"

#include <iostream>

void P411();
void P412();
void P413();

int main()
{
    char choice;
        
    do {
        std::cout << "\n--- MAIN MENU ---\n";
        std::cout << "1. P411 (String to Integer (atoi))\n";
        std::cout << "2. P412 (Fraction struct handling)\n";
        std::cout << "3. P413 (Triangle struct handling)\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        
        std::cin >> choice;
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case '1': P411(); break;
            case '2': P412(); break;
            case '3': P413(); break;
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

void P411()
{
    std::string s;
    std::cout << "Enter the string: ";
    std::getline(std::cin, s);
    std::cout << "String to ineger: " << myAtoi(s) << '\n';
}

// === P412 (Fraction) Menu ===
void P412()
{
    Fraction a, b;
    Fraction c;
            
    char choice;
    do {
        std::cout << "\n--- P12: Fraction struct handling ---\n";
        std::cout << "1. Input fraction 1 (console)\n";
        std::cout << "2. Input fraction 2 (console)\n";
        std::cout << "3. Output fraction 1 (console)\n";
        std::cout << "4. Output fraction 2 (console)\n";
        std::cout << "5. Add two fractions)\n";
        std::cout << "6. Subtract two fractions)\n";
        std::cout << "0. Return to Main Menu\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case '1':
                inputFraction(a);
                std::cout << "Fraction 1 stored.\n";
                break;
            case '2':
                inputFraction(b);
                std::cout << "Fraction 2 stored.\n";
                break;
            case '3':
                std::cout << "Fraction 1: ";
                outputFraction(a);
                std::cout << '\n';
                break;
            case '4':
                std::cout << "Fraction 2: ";
                outputFraction(b);
                std::cout << '\n';
                break;
            case '5':
                c = add(a, b);
                std::cout << a << " + " << b << " = " << c << '\n';
                break;
            case '6':
                c = subtract(a, b);
                std::cout << a << " - " << b << " = " << c << '\n';
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

// === P413 (Triangle) Menu ===
void P413()
{
    int n = 0;
    double p = 0;
    Triangle t;
    Triangle tris[100];
    
    char choice;
    do {
        std::cout << "\n--- P413: Student struct handling ---\n";
        std::cout << "1. Input a triangle (console)\n";
        std::cout << "2. Output a triangle (console)\n";
        std::cout << "3. Perimeter calculator\n";
        std::cout << "4. Centroid calculator\n";
        std::cout << "5. Input triangle list\n";
        std::cout << "6. Output triangle list\n";
        std::cout << "7. Largest perimeter triagle in list\n";
        std::cout << "0. Return to Main Menu\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case '1':
                inputTriangle(t);
                std::cout << "Triangle stored.\n";
                break;
            case '2':
                std::cout << "Triangle: ";
                outputTriangle(t);
                std::cout << '\n';
                break;
            case '3':
                std::cout << "Perimeter of triangle = " << perimeter(t) << '\n';
                break;
            case '4':
                std::cout << "Centroid of triangle: ";
                outputPoint(centroid(t));
                std::cout << '\n';
                break;
            case '5':
                inputTriangleList(tris, n);
                break;
            case '6':
                outputTriangleList(tris, n);
                break;
            case '7':
                std::cout << "Largest perimter triangle: ";
                outputTriangle(largestPerimeter(tris, n , p));
                if (n > 0) {
                    std::cout << '\n';
                    std::cout << "Perimeter: " << p << '\n';
                }
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
