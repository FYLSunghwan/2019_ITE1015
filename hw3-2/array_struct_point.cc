//HW3-2-1 array_struct_point.cc
#include <iostream>

typedef struct 
{
    int xpos;
    int ypos;
}Point;

void scale2x(Point* pp)
{
    pp->xpos *= 2;
    pp->ypos *= 2;
}

int main(void)
{
    Point pnt[3];
    for(int i=0;i<3;i++)
    {
        std::cin >> pnt[i].xpos >> pnt[i].ypos;
        scale2x(pnt+i);
    }
    for(int i=0;i<3;i++)
        std::cout<<"[" << i << "] "<< pnt[i].xpos << " " << pnt[i].ypos << std::endl;
    return 0;
}