#include <iostream>
typedef struct
{
    double x;
    double y;
}Point;

typedef struct
{
    char name[7];
    Point points[3];
}Person;

int main(void)
{
    Person per[3];
    for(int i=0;i<3;i++)
    {
        std::cin>>per[i].name;
        for(int j=0;j<3;j++)
        {
            std::cin>>per[i].points[j].x>>per[i].points[j].y; 
        }
    }
    for(int i=0;i<3;i++)
    {
        double maxs=-1;
        int argmaxs = 0;
        std::cout<< per[i].name;
        for(int j=0;j<3;j++)
        {
            int x = per[i].points[j].x;
            int y = per[i].points[j].y;
            if(x*x + y*y > maxs)
            {
                maxs = x*x + y*y;
                argmaxs = j;
            }
        }
        std::cout << " (" << 
                    per[i].points[argmaxs].x << ", " <<
                    per[i].points[argmaxs].y << ")" <<
                    std::endl;
    }
    return 0;
}