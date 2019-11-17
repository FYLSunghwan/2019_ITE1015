#include "print_shape.h"

Circle::Circle(double radius)
:m_radius(radius)
{
    // Do Nothing
}

double Circle::getArea()
{
    return PI*m_radius*m_radius;
}

double Circle::getPerimeter()
{
    return 2*PI*m_radius;
}

std::string Circle::getTypeString()
{
    return "Circle";
}

Rectangle::Rectangle(double width, double height)
:m_width(width), m_height(height)
{
    // Do Nothing
}

double Rectangle::getArea()
{
    return m_width*m_height;
}

double Rectangle::getPerimeter()
{
    return 2*(m_width + m_height);
}

std::string Rectangle::getTypeString()
{
    return "Rectangle";
}