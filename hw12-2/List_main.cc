#include <iostream>
#include "List.h"
#include "List.cc"

int main(){
    int array[5] = {12, 7, 9, 21, 13 };
    List<int> li(array, 5);

    std::cout<<li<<std::endl; //12,7,9,21,13

    li.pop_back();
    std::cout<<li<<std::endl; //12,7,9,21

    li.push_back(15);
    std::cout<<li<<std::endl; //12,7,9,21,15

    li.pop_front();
    std::cout<<li<<std::endl; //7,9,21,15

    li.push_front(8);
    std::cout<<li<<std::endl; //8,7,9,21,15

    li.insert_at(4, 19);
    std::cout<<li<<std::endl; //8,7,9,21,19,15

    li.remove_at(1);
    std::cout<<li<<std::endl; //8,9,21,19,15

    return 0;		
    
}	
