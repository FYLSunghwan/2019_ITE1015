#pragma once
#include <string>

class Shape
{
 public:  
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
    virtual std::string getTypeString() = 0;
 };

class Circle : public Shape
{
 public:
    Circle(double radius);
    double getArea();
    double getPerimeter();
    std::string getTypeString();

 private:
    double m_radius;
    const double PI = 3.141592;
};

class Rectangle : public Shape
{
 public:
    Rectangle(double width, double height);
    double getArea();
    double getPerimeter();
    std::string getTypeString();

 private:
    double m_width, m_height;    
};