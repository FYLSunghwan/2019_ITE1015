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
        std::cin>>(per+i)->name>>(per+i)->age;
    }
    for(int i=0;i<n;i++)
    {
        std::cout << "Name:" << (per+i)-> name << ", ";
        std::cout << "Age:" << (per+i)->age << std::endl;
    }
    delete[] per;
    return 0;
}