#include "shapes.h"

int Triangle::getArea()
{
    return width_ * height_ / 2;
}

int Rectangle::getArea()
{
    return width_ * height_;
}