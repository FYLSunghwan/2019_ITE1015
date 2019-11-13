#include <iostream>
#include <vector>
#include <string>
#include "draw_shape.h"

void DrawFunc(std::vector<Shape*>& shapes, Canvas* canv)
{
    for(auto& i: shapes)
    {
        i->Draw(canv);
    }
}

int main()
{
    int row, col;
    std::cin >> row >> col;

    Canvas* canv = new Canvas(row, col);
    std::vector<Shape*> shapes;

    canv->Print();
    while(true)
    {
        std::string inp;
        std::cin >> inp;
        if(inp == "add")
        {
            std::string shape;
            std::cin >> shape;
            int x, y, h, w;
            char brush;
            if(shape == "rect")
            {
                std::cin >> x >> y >> w >> h >> brush;
                shapes.push_back(new Rectangle(x, y, w, h, brush));
            }
            if(shape == "tri_down")
            {
                std::cin >> x >> y >> h >> brush;
                shapes.push_back(new DownTriangle(x, y, h, brush));
            }
            if(shape == "tri_up")
            {
                std::cin >> x >> y >> h >> brush;
                shapes.push_back(new UpTriangle(x, y, h, brush));
            }
            if(shape == "diamond")
            {
                std::cin >> x >> y >> h >> brush;
                shapes.push_back(new Diamond(x, y, h, brush));
            }
        }
        if(inp == "delete")
        {
            int idx;
            std::cin >> idx;
            if(shapes.size() && idx>=0 && idx<shapes.size())
            {
                for(int i=idx;i<shapes.size()-1;i++)
                {
                    shapes[i] = shapes[i+1];
                }
                delete shapes.back();
                shapes.pop_back();
            }
        }
        if(inp == "draw")
        {
            canv->Clear();
            DrawFunc(shapes, canv);
            canv->Print();
        }
        if(inp == "dump")
        {
            int cnt=0;
            for(auto& i : shapes)
            {
                std::cout << cnt++ << " ";
                i->GetInfo();
                std::cout << std::endl;
            }
        }
        if(inp == "resize")
        {
            int w, h;
            std::cin >> w >> h;
            canv->Resize(w, h);
        }
        if(inp == "quit") break;
    }
    for(auto& i : shapes)
    {
        if(i!=nullptr) delete i;
    }
    if(canv!=nullptr) delete canv;
}