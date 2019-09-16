#include <iostream>

struct Person {
    char name[10];
    int age;
};

int main() {
    Person testPerson[3];
    for(int i=0;i<3;i++) {
        std::cin>>testPerson[i].name>>testPerson[i].age;
    }
    for(int i=0;i<3;i++) {
        std::cout<<"Name:";
        std::cout<<(testPerson+i)->name;
        std::cout<<", Age:";
        std::cout<<(testPerson+i)->age<<std::endl;
    }    
    return 0;
}