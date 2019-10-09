#include <iostream>
#include "sort.h"

Sort::Sort(int* arr, size_t size)
{
    m_arr = arr;
    m_size = size;
}

int* Sort::GetArr()
{
    return m_arr;
}

void Sort::DoSort()
{
    for(size_t i = 0; i < m_size; i++)
    {
        for(size_t j = i; j < m_size - 1; j++)
        {
            if(m_arr[j] > m_arr[j+1])
            {
                std::swap(m_arr[j], m_arr[j+1]);
            }
        }
    }
}