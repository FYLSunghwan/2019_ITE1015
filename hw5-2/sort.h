#pragma once

#include <iostream>

class Sort {
    public:
        Sort(int* arr, size_t size);
        void DoSort();
        int* GetArr();
    
    private:
        int* m_arr;
        size_t m_size;
};