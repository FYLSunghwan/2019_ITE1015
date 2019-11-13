#pragma once
#include <string>

class Animal
{
 public:
    Animal(std::string& name, int age);
    virtual void printInfo();
 protected:
    std::string m_name;
    int m_age;
};

class Zebra : public Animal
{
 public:
    Zebra(std::string& name, int age, int numStripes);
    virtual void printInfo();
 private:
    int m_numStripes;
};

class Cat : public Animal
{
 public:
    Cat(std::string& name, int age, std::string& m_favoriteToy);
    virtual void printInfo();
 private:
    std::string m_favoriteToy;

};