#ifndef __DRAW_SHAPE_H__
#define __DRAW_SHAPE_H__

#include <vector>
#include <iostream>

class Canvas {
 public:
    Canvas(int row, int col);

    // Canvas 크기를 w x h 로 변경한다. 그려진 내용은 보존한다.
    void Resize(int w, int h);

    // (x,y) 위치에 ch 문자를 그린다. 범위 밖의 x,y 는 무시한다.
    bool DrawPixel(int x, int y, char brush);

    //캔버스의 내용을 화면에 출력한다.
    void Print();

    // 그려진 내용을 모두 지운다 ('.'으로 초기화)
    void Clear();

 private:
    std::vector<std::vector<char>> m_canvas;
    int m_row, m_col;
};

class Shape {
 public:
    Shape(int x, int y, int h, char brush)
    :x_(x), y_(y), h_(h), brush_(brush) {}
    virtual void Draw(Canvas* canvas) = 0;
    virtual void GetInfo() = 0;
    
 protected:
    int x_, y_, h_;
    char brush_;
};

class Rectangle : public Shape
{
 public:
    Rectangle(int x, int y, int w, int h, char brush)
    :w_(w), Shape(x, y, h, brush) {}
    virtual void Draw(Canvas* canvas);
    virtual void GetInfo();
 private:
    int w_;
};

class UpTriangle: public Shape
{
 public:
    UpTriangle(int x, int y, int h, char brush)
    :Shape(x, y, h, brush) {}
    virtual void Draw(Canvas* canvas);
    virtual void GetInfo();
};

class DownTriangle: public Shape
{
 public:
    DownTriangle(int x, int y, int h, char brush)
    :Shape(x, y, h, brush) {}
    virtual void Draw(Canvas* canvas);
    virtual void GetInfo();
};

class Diamond: public Shape
{
 public:
    Diamond(int x, int y, int h, char brush)
    :Shape(x, y, h, brush) {}
    virtual void Draw(Canvas* canvas);
    virtual void GetInfo();
};

#endif
