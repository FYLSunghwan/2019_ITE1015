#pragma once

class Shape
{
 public:
    Shape(int width, int height) : width_(width), height_(height) {}
    virtual int getArea() = 0;
 protected:
    int width_, height_;
};

class Triangle : public Shape
{
 public:
    Triangle(int width, int height) : Shape(width, height) {}
    int getArea();
};

class Rectangle : public Shape
{
 public:
    Rectangle(int width, int height) : Shape(width, height) {}
    int getArea();
};