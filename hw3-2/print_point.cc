#include <iostream>

typedef struct po
{
    int xpos;
    int ypos;
}Point;

Point getScale2xPoint(const Point* p)
{
    std::cout << "Calling getScale2xPoint()" << std::endl;
    Point newP;
    newP.xpos = p->xpos*2;
    newP.ypos = p->ypos*2;
    return newP;
}

void swapPoint(Point& p1, Point& p2)
{
    std::cout << "Calling swapPoint()" << std::endl;
    Point p;
    p = p1;
    p1 = p2;
    p2 = p;
}

int main()
{
    Point p;
    std::cin >> p.xpos >> p.ypos;
    Point newp = getScale2xPoint(&p);
    std::cout << "P1 : " << p.xpos << " " << p.ypos << std::endl;
    std::cout << "P2 : " << newp.xpos << " " << newp.ypos << std::endl;
    swapPoint(p, newp);
    std::cout << "P1 : " << p.xpos << " " << p.ypos << std::endl;
    std::cout << "P2 : " << newp.xpos << " " << newp.ypos << std::endl;
    return 0;  
}