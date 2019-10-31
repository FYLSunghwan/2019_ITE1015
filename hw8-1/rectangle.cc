#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(int width, int height)
{
    width_ = width;
    height_ = height;
}

int Rectangle::getArea()
{
    return width_ * height_;
}

int Rectangle::getPerimeter()
{
    return 2*(width_ + height_);
}

Square::Square(int width) : Rectangle(width, width)
{
    // Do Nothing
}

void Square::print()
{
    std::cout << width_ << "x" << width_ << " Square" << std::endl;
    std::cout << "Area: " << getArea() << std::endl;
    std::cout << "Perimeter: " << getPerimeter() << std::endl;
}

NonSquare::NonSquare(int width, int height) : Rectangle(width, height)
{
    // Do Nothing
}

void NonSquare::print()
{
    std::cout << width_ << "x" << height_ << " NonSquare" << std::endl;
    std::cout << "Area: " << getArea() << std::endl;
    std::cout << "Perimeter: " << getPerimeter() << std::endl;
}