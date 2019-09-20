//HW3-2-2 score_graph.cc
#include <iostream>

typedef struct po
{
    char name[7];
    int score;
}Person;

void printScoreStars(Person* persons, int len)
{
    for(int i=0;i<len;i++)
    {
        std::cout << (persons+i)->name << " ";
        for(int j=0;j<(persons+i)->score/5;j++)
            std::cout<<"*";
        std::cout<<std::endl;
    }
}

int main(void)
{
    Person per[3];
    for(int i=0;i<3;i++)
    {
        std::cin>>per[i].name;
        std::cin>>per[i].score;
    }
    printScoreStars(per, 3);
    return 0;
}