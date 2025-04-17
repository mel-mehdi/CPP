#include "Point.hpp"
#include <iostream>

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point point1(1, 1); // Inside the triangle
    Point point2(5, 5); // Inside the triangle
    Point point3(10, 10); // Outside the triangle
    Point point4(0, 0); // On the vertex (should return false)
    Point point5(5, 0); // On the edge (should return false)

    std::cout << "Point1 is inside the triangle: " << bsp(a, b, c, point1) << std::endl;
    std::cout << "Point2 is inside the triangle: " << bsp(a, b, c, point2) << std::endl;
    std::cout << "Point3 is inside the triangle: " << bsp(a, b, c, point3) << std::endl;
    std::cout << "Point4 is inside the triangle: " << bsp(a, b, c, point4) << std::endl;
    std::cout << "Point5 is inside the triangle: " << bsp(a, b, c, point5) << std::endl;

    return 0;
}