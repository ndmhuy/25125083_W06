//
//  Point.cpp
//  Learning
//
//  Created by Huy Nguyen on 17/11/25.
//

#include "Point.hpp"

#include <iostream>
#include <iomanip>

void inputPoint(Point& p)
{
    std::cout << "Enter x: ";
    std::cin >> p.x;
    std::cout << "Enter y: ";
    std::cin >> p.y;
    std::cout << "Enter z: ";
    std::cin >> p.z;
}

void outputPoint(const Point& p)
{
    std::cout << std::fixed << std::setprecision(2) << "(" << p.x << ", " << p.y << ", " << p.z << ")";
}

double length(const Point& p1, const Point& p2)
{
    double xDiff = p1.x - p2.x;
    double yDiff = p1.y - p2.y;
    double zDiff = p1.z - p2.z;
    
    return sqrt(xDiff * xDiff + yDiff * yDiff + zDiff * zDiff);
}
