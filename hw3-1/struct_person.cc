#include <iostream>

struct Person {
    char name[10];
    int age;
};

int main() {
    Person testPerson;
    std::cin>>testPerson.name>>testPerson.age;
    std::cout<<"name: ";
    std::cout<<testPerson.name<<std::endl;
    std::cout<<"age: ";
    std::cout<<testPerson.age<<std::endl;
    return 0;
}