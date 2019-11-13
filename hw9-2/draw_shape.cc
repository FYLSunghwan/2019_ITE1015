#include "draw_shape.h"

Canvas::Canvas(int row, int col)
{
    m_canvas.resize(100);
    for(auto& i: m_canvas)
    {
        i.resize(100, '.');
    }
    m_row = row;
    m_col = col;
}

void Canvas::Resize(int w, int h)
{
    m_row = h;
    m_col = w;
}

bool Canvas::DrawPixel(int x, int y, char brush)
{
    if(x>=m_col || y>=m_row || x<0 || y<0) return false;
    m_canvas[y][x] = brush;
    return true;
}

void Canvas::Print()
{
    std::cout << " ";
    for(int i=0;i<m_col;i++) std::cout << i%10;
    std::cout << std::endl;
    for(int i=0;i<m_row;i++)
    {
        std::cout << i;
        for(int j=0;j<m_col;j++)
        {
            std::cout << m_canvas[i][j];
        }
        std::cout << std::endl;
    }
}

void Canvas::Clear()
{
    for(int i=0; i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            m_canvas[i][j] = '.';
        }
    }
}

void Rectangle::Draw(Canvas* canvas)
{
    for(int y=y_; y<y_+h_; y++)
    {
        for(int x=x_; x<x_+w_;x++)
        {
            canvas->DrawPixel(x ,y, brush_);
        }
    }
}

void UpTriangle::Draw(Canvas* canvas)
{
    for(int y=y_;y<y_+h_;y++)
    {
        int offset = y-y_;
        for(int x=x_-offset;x<=x_+offset;x++)
        {
            canvas->DrawPixel(x, y, brush_);
        }
    }
}

void DownTriangle::Draw(Canvas* canvas)
{
    for(int y=y_;y>y_-h_;y--)
    {
        int offset = y_-y;
        for(int x=x_-offset;x<=x_+offset;x++)
        {
            canvas->DrawPixel(x, y, brush_);
        }
    }
}

void Diamond::Draw(Canvas* canvas)
{
    for(int y=y_;y<y_+h_;y++)
    {
        int offset = y-y_;
        for(int x=x_-offset;x<=x_+offset;x++)
        {
            canvas->DrawPixel(x, y, brush_);
        }
    }
    for(int y=y_+h_;y<=y_+2*h_;y++)
    {
        int offset = y_+2*h_-y;
        for(int x=x_-offset;x<=x_+offset;x++)
        {
            canvas->DrawPixel(x, y, brush_);
        }
    }
}

void Rectangle::GetInfo()
{
    std::cout << " rect ";
    std::cout << x_ << " ";
    std::cout << y_ << " ";
    std::cout << w_ << " ";
    std::cout << h_ << " ";
    std::cout << brush_;
}

void UpTriangle::GetInfo()
{
    std::cout << " tri_up ";
    std::cout << x_ << " ";
    std::cout << y_ << " ";
    std::cout << h_ << " ";
    std::cout << brush_;
}

void DownTriangle::GetInfo()
{
    std::cout << " tri_down ";
    std::cout << x_ << " ";
    std::cout << y_ << " ";
    std::cout << h_ << " ";
    std::cout << brush_;
}

void Diamond::GetInfo()
{
    std::cout << " diamond ";
    std::cout << x_ << " ";
    std::cout << y_ << " ";
    std::cout << h_ << " ";
    std::cout << brush_;
}