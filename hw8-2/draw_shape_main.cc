#include <iostream>
#include <string>
#include "draw_shape.h"

int main()
{
    int canvasHeight, canvasWidth;
    std::cin>>canvasHeight>>canvasWidth;

    while(true)
    {
        std::string inputStr;
        int rectWidth, rectHeight, diaDist, y, x;
        char brush;

        std::cin>>inputStr;
        if(inputStr=="quit") break;
        std::cin>>x>>y;
        if(inputStr=="rect")
        {
            std::cin>>rectHeight>>rectWidth>>brush;
            Rect rectObj(x,y,rectWidth,rectHeight,brush);
            std::cout<<"Area: "<<rectObj.GetArea()<<std::endl;
            std::cout<<"Perimeter: "<<rectObj.GetPerimeter()<<std::endl;
            rectObj.Draw(canvasWidth, canvasHeight);
        }
        else if(inputStr=="square")
        {
            std::cin>>rectHeight>>brush;
            Square squareObj(x,y,rectWidth, brush);
            std::cout<<"Area: "<<squareObj.GetArea()<<std::endl;
            std::cout<<"Perimeter: "<<squareObj.GetPerimeter()<<std::endl;
            squareObj.Draw(canvasWidth, canvasHeight);
        }
        else if(inputStr=="diamond")
        {
            std::cin>>diaDist>>brush;
            Diamond diamondObj(x,y,diaDist, brush);
            std::cout<<"Area: "<<diamondObj.GetArea()<<std::endl;
            std::cout<<"Perimeter: "<<diamondObj.GetPerimeter()<<std::endl;
            diamondObj.Draw(canvasWidth, canvasHeight);
        }
        else
        {
            std::cout << "Invalid Input" << std::endl;
        }
    }
}
