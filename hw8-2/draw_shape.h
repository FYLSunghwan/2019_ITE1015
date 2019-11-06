#ifndef __DRAW_SHAPE_H__
#define __DRAW_SHAPE_H__

class Shape
{
public:
    Shape(int x=0, int y=0, char brush='#')
        :_x(x), _y(y), _brush(brush) {};
    double GetArea() {};
    int GetPerimeter() {};
    void Draw(int canvas_width, int canvas_height) {};
    void DrawOnScreen(int **canvas, int canvas_width, int canvas_height, char brush);

protected:
    int _x;
    int _y;
    char _brush;
};

class Rect : public Shape
{
public:
    Rect(int x=0, int y=0, int height=1, int width=1, char brush='#')
        : _height(height), _width(width), Shape(x,y,brush) {};
    double GetArea();
    int GetPerimeter();
    void Draw(int canvas_width, int canvas_height);

protected:
    int _height;
    int _width;
};

class Square : public Rect
{
public:
    Square(int x=0, int y=0, int length=1, char brush='#')
        : _length(length), Rect(x, y, length, length, brush) {};

protected:
    int _length;
};

class Diamond : public Shape
{
public:
    Diamond(int x=0, int y=0, int dist=0, char brush='#')
        : _dist(dist), Shape(x,y,brush) {};
    double GetArea();
    int GetPerimeter();
    void Draw(int canvas_width, int canvas_height);

protected:
    int _dist;
};

#endif
