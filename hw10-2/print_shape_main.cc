#include <iostream>
#include <vector>
#include "print_shape.h"

int main()
{
    std::vector<Shape*> shapes;
    std::string command;
    double inp1, inp2;

    while(true)
    {
        std::cin >> command;
        if(command == "0") break;
        if(command == "c")
        {
            std::cin >> inp1;
            shapes.push_back(new Circle(inp1));
        }
        if(command == "r")
        {
            std::cin >> inp1 >> inp2;
            shapes.push_back(new Rectangle(inp1, inp2));
        }
    }

    for(auto& i : shapes)
    {
        std::cout << i->getTypeString() << ", ";
        std::cout << i->getArea() << ", ";
        std::cout << i->getPerimeter() << std::endl;
        delete i;
    }
    return 0;
}