#pragma once

class Pos
{
    public:
        int y;
        int x;
};

class Rect
{
    public:
        Rect(Pos l_inp, Pos r_inp): l_pos(l_inp), r_pos(r_inp) {}
        double GetPerimeter();
        double GetArea();

    private:
        Pos l_pos, r_pos;
};

class Circle
{
    public:
        Circle(Pos pos, double rinp):m_pos(pos), r(rinp) {}
        double GetPerimeter();
        double GetArea();

    private:
        Pos m_pos;
        double r;
};
