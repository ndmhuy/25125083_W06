//
//  Triangle.cpp
//  Learning
//
//  Created by Huy Nguyen on 17/11/25.
//

#include "Triangle.hpp"
#include <algorithm>

void inputTriangle(Triangle& t)
{
    // Suppose valid triangle
    Point A, B, C;
    double a, b, c, largest;
    int i = 0;
    do {
        if (i > 0) std::cout << "Invalid triangle, try again\n";
        std::cout << "Input first point\n";
        inputPoint(A);
        std::cout << "Input second point\n";
        inputPoint(B);
        std::cout << "Input third point\n";
        inputPoint(C);
        
        a = length(B, C);
        b = length(C, A);
        c = length(A, B);
        largest = std::max({a, b, c});
        ++i;
    } while (2 * largest >= a + b + c);
    
    t.A = A; t.B = B; t.C = C;
}

void outputTriangle(const Triangle& t)
{
    std::cout << "First point: ";
    outputPoint(t.A);
    std::cout << " Second point: ";
    outputPoint(t.B);
    std::cout << " Third point: ";
    outputPoint(t.C);
}

double perimeter(const Triangle& t)
{
    return length(t.A, t.B) + length(t.B, t.C) + length(t.C, t.A);
}

Point centroid(const Triangle& t)
{
    Point centroid;
    centroid.x = (t.A.x + t.B.x + t.C.x) / 3.0;
    centroid.y = (t.A.y + t.B.y + t.C.y) / 3.0;
    centroid.z = (t.A.z + t.B.z + t.C.z) / 3.0;
    return centroid;
}

void inputTriangleList(Triangle tris[], int &n)
{
    std::cout << "Enter the number of triangles: ";
    std::cin >> n;
    
    std::cout << "Enter " << n << " triangles\n";
    for (int i = 0; i < n; ++i) {
        std::cout << i << ". ";
        inputTriangle(tris[i]);
    }
}

void outputTriangleList(Triangle tris[], int n)
{
    std::cout << "List of triangles:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << i << ". ";
        outputTriangle(tris[i]);
        std::cout << '\n';
    }
}

Triangle largestPerimeter(Triangle tris[], int n, double& peri)
{
    if (n == 0) {
        std::cout << "There are no triangles in the list.\n";
        return {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    }
    
    int id = 0;
    double largestPerimeter = perimeter(tris[0]);
    for (int i = 1; i < n; ++i) {
        double p = perimeter(tris[i]);
        if (p > largestPerimeter) {
            largestPerimeter = p;
            id = i;
        }
    }
    peri = largestPerimeter;
    return tris[id];
}
