#include "shapes.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string inp;
    int tw, th, rw, rh;
    std::cin >> tw >> th >> rw >> rh;
    std::vector<Shape*> sh;
    sh.push_back(new Triangle(tw, th));
    sh.push_back(new Rectangle(rw, rh));
    for(auto& i:sh)
    {
        std::cout << i->getArea() << std::endl;
    }
    return 0;
}