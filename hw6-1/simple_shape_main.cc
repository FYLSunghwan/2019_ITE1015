#include <iostream>
#include "simple_shape.h"

int main()
{
    char inp;
    while(true){
        std::cout << "shape?" << std::endl;
        std::cin >> inp;
        if(inp=='Q') break;
        Pos lef, rig;
        int r;
        if(inp=='C')
        {
            std::cin>>lef.x>>lef.y>>r;
            Circle circle(lef, r);
            std::cout << "area: " << circle.GetArea() << ", perimeter:" << circle.GetPerimeter() << std::endl;
        }
        if(inp=='R')
        {
            std::cin>>lef.x>>lef.y>>rig.x>>rig.y;
            Rect rect(lef,rig);
            std::cout << "area: " << rect.GetArea() << ", perimeter:" << rect.GetPerimeter() << std::endl;
        }
    }
    return 0;
}