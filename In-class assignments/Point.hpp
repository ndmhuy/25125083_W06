//
//  Point.hpp
//  Learning
//
//  Created by Huy Nguyen on 17/11/25.
//

#ifndef Point_hpp
#define Point_hpp

#include <iostream>

struct Point
{
    double x;
    double y;
    double z;
};

void inputPoint(Point& p);
void outputPoint(const Point& p);
double length(const Point& p1, const Point& p2);

#endif /* Point_hpp */
