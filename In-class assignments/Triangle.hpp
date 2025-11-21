//
//  Triangle.hpp
//  Learning
//
//  Created by Huy Nguyen on 17/11/25.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include "Point.hpp"

#include <iostream>

struct Triangle
{
    Point A;
    Point B;
    Point C;
};

void inputTriangle(Triangle& t);
void outputTriangle(const Triangle& t);
double perimeter(const Triangle& t);
Point centroid(const Triangle& t);
void inputTriangleList(Triangle tris[], int &n);
void outputTriangleList(Triangle tris[], int n);
Triangle largestPerimeter(Triangle tris[], int n, double& peri);

#endif /* Triangle_hpp */
