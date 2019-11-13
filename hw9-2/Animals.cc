#include "Animals.h"
#include <iostream>

Animal::Animal(std::string& name, int age)
:m_name(name), m_age(age)
{
    // Do Nothing
}

Zebra::Zebra(std::string& name, int age, int numStripes)
:m_numStripes(numStripes), Animal(name, age)
{
    // Do Nothing
}

Cat::Cat(std::string& name, int age, std::string& favoriteToy)
:m_favoriteToy(favoriteToy), Animal(name, age)
{
    // Do Nothing
}

void Animal::printInfo()
{
    std::cout << "Animal";
    std::cout << ", Name: " << m_name;
    std::cout << ", Age:" << m_age;
    std::cout << std::endl;
}

void Zebra::printInfo()
{
    std::cout << "Zebra";
    std::cout << ", Name: " << m_name;
    std::cout << ", Age:" << m_age;
    std::cout << ", Number of stripes: " << m_numStripes;
    std::cout << std::endl;
}

void Cat::printInfo()
{
    std::cout << "Cat";
    std::cout << ", Name: " << m_name;
    std::cout << ", Age:" << m_age;
    std::cout << ", Favorite toy: " << m_favoriteToy;
    std::cout << std::endl;
}