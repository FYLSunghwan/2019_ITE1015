#include <iostream>
#include "sort.h"

int main()
{
    size_t size;
    std::cin >> size;
    if(size<=0) return 0;

    int* arr = new int[size];

    for(size_t i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    Sort sortObj(arr, size);

    sortObj.DoSort();
    arr = sortObj.GetArr();

    for(size_t i = 0; i<size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}