#include <iostream>
#include <algorithm>
#include "draw_shape.h"


void Shape::DrawOnScreen(int **canvas, int canvas_width, int canvas_height, char brush)
{
    std::cout << " 0123456789" << std::endl;
    for(int i=0;i<canvas_height;i++)
    {
        std::cout << i;
        for (int j = 0; j < canvas_width; j++)
            std::cout << (canvas[i][j] ? brush : '.');
        std::cout << std::endl;
    }
}

double Rect::GetArea()
{
    return _height * _width;
}

int Rect::GetPerimeter()
{
    return 2*(_height + _width);
}

void Rect::Draw(int canvas_width, int canvas_height)
{
    int **canvas = new int*[canvas_height];
    for(int i=0;i<canvas_height;i++)
    {
        canvas[i] = new int[canvas_width];
        memset(canvas[i],0,sizeof(int)*canvas_width);
    }
    for(int i=_y;i<_y+_height;i++)
    {
        for(int j=_x;j<_x+_width;j++)
        {
            if(0 <= i && i<canvas_height && 0 <= j && j < canvas_width)
                canvas[i][j]=1;
        }
    }
    DrawOnScreen(canvas, canvas_width, canvas_height, _brush);
    for(int i=0;i<canvas_height;i++)
    {
        if(canvas[i]) delete[] canvas[i];
    }
    if(canvas) delete[] canvas;
}

double Diamond::GetArea()
{
    return (_dist*2.+1.)*(_dist*2.+1.)/2.;
}

int Diamond::GetPerimeter()
{
    return (_dist+1)*8;
}

void Diamond::Draw(int canvas_width, int canvas_height)
{
    int **canvas = new int*[canvas_height];
    for(int i=0;i<canvas_height;i++)
    {
        canvas[i] = new int[canvas_width];
        memset(canvas[i],0,sizeof(int)*canvas_width);
    }
    for(int i=0;i<2*_dist+1;i++)
    {
        int horiLim = i; //Horizontal Limit
        if(i>_dist) horiLim = 2*_dist-i;
        for(int j=_x-horiLim;j<_x+horiLim+1;j++)
        {
            if(0 <= _y+i && _y+i<canvas_height && 0 <= j && j < canvas_width)
                canvas[_y+i][j]=1;
        }
    }
    DrawOnScreen(canvas, canvas_width, canvas_height, _brush);
    for(int i=0;i<canvas_height;i++)
    {
        if(canvas[i]) delete[] canvas[i];
    }
    if(canvas) delete[] canvas;
}
