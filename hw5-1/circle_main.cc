#include <iostream>
#include "circle.h"

int main() {
    double r;
    std::cin >> r;
    std::cout << "Perimeter: " << getCirclePerimeter(r) << std::endl;
    std::cout << "Area: " << getCircleArea(r) << std::endl;
    return 0;
}