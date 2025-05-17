#include "Soldier.h"
#include <exception>
#pragma warning (disable : 4996)
#include <cstring>
#include <utility>


Soldier::Soldier()
    :Soldier("no name", 0, 0, 0)
{
}

Soldier::Soldier(const char* name, int years, int power, int salary)
    :years(years), power(power), salary(salary)
{
    setName(name);

}

Soldier::Soldier(const Soldier& other)
    :years(other.years), power(other.power), salary(other.salary)
{
    setName(other.name);
}

Soldier& Soldier::operator=(const Soldier& other)
{
    if (&other == this) return *this;
    setName(name);
    years = other.years;
    power = other.power;
    salary = other.salary;
    return *this;
}

Soldier::~Soldier()
{
    delete[] name;
}

void Soldier::setSalary(int salary)
{
    this->salary = salary;
}

void Soldier::setYears(int years)
{
    this->years = years;
}

void Soldier::setPower(int power)
{
    this->power = power;
}

void Soldier::setName(const char* name)
{
    setString(this->name, name);
}

void Soldier::setString(char* destination,const char* other)
{
    if (!other || !destination) throw std::exception("Passed a nullptr");
    char* newStr = new char[strlen(other) + 1];
    strcpy(newStr, other);
    delete[] destination;
    destination = newStr;
}

void Soldier::swap(Soldier& other)
{
    std::swap(name, other.name);
    std::swap(years, other.years);
    std::swap(power, other.power);
    std::swap(salary, other.salary);
}
