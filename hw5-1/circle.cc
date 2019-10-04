#include "circle.h"

constexpr double pi = 3.141592;

double getCirclePerimeter(double r) {
    return 2.*pi*r;
}

double getCircleArea(double r) {
    return pi*r*r;
}