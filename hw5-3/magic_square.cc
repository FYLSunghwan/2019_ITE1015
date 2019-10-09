#include "magic_square.h"

void magic(int** arr, int size)
{
    int y = 1, x = size/2 - 1, iter = 1;

    while(iter <= size * size)
    {
        int newy = y-1;
        int newx = x+1;

        if(newy < 0) newy = size - 1;
        if(newx >= size) newx =  0;

        if(arr[newy][newx])
        {
            newy = y+1;
            newx = x;
        }
        arr[newy][newx] =  iter;
        y = newy;
        x = newx;
        iter++;
    }
}