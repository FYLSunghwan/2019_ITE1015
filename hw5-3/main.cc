#include <iostream>
#include <cstring>
#include "magic_square.h"

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cout << "argc is less than 2" << std::endl;
        return 0;
    }
    int newc = atoi(argv[1]);
    if(!newc || (newc+1)%2) return 0;

    int** arr = new int*[newc];
    for(int i=0;i<newc;i++)
    {
        arr[i] = new int[newc];
    }

    magic(arr, newc);

    for(int i = 0; i<newc; i++)
    {
        for(int j = 0; j<newc; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for(int i=0;i<newc;i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}