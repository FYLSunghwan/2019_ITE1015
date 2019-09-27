#include <iostream>

struct Person
{
    char name[10];
    int age;
};

int main()
{
    int n;
    std::cin>>n;
    Person* per = new Person[n];

    for(int i=0;i<n;i++)
    {
        std::cin>>per->name>>per->age;
    }
    for(int i=0;i<n;i++)
    {
        std::cout << "Name:" << per-> name << ", ";
        std::cout << "Age:" << per->age << std::endl;
    }
    delete[] per;
    return 0;
}