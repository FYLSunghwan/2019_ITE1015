#include "simple_shape.h"

constexpr double pi = 3.141592;

double myabs(double a)
{
    return a>0?a:-a;
}

double Circle::GetPerimeter()
{
    return 2.*pi*r;
}

double Circle::GetArea()
{
    return pi*r*r;
}

double Rect::GetPerimeter()
{
    return 2*(myabs(l_pos.x-r_pos.x)+myabs(l_pos.y-r_pos.y));
}

double Rect::GetArea()
{
    return myabs(l_pos.x-r_pos.x) * myabs(l_pos.y-r_pos.y);
}