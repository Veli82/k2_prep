#include "Spell.h"
#include <cstring>
#include <exception>
#pragma warning (disable : 4996)

Spell::Spell()
    :Spell("no description", "Unknown", 0)
{
}

Spell::Spell(const char* description, const char* type, int manaCost)
{
    setDescription(description);
    setType(type);
    this->manaCost = manaCost;
}

Spell::Spell(const Spell& other)
{
    setDescription(other.description);
    setType(other.type);
    manaCost = other.manaCost;
}

Spell& Spell::operator=(const Spell& other)
{
    if (this == &other) return *this;
    setDescription(other.description);
    setType(other.type);
    manaCost = other.manaCost;

    return *this;
}

Spell::~Spell()
{
    delete[] description;
}

void Spell::setDescription(const char* description)
{
    if (!description) throw std::exception("Passed a nullptr");
    char* newStr = new char[strlen(description) + 1];
    strcpy(newStr, description);
    delete[] this->description;
    this->description = newStr;
}


void Spell::setType(const char* type)
{
    if (strlen(type) > 15) throw std::exception("Can't do that!");
    strcpy(this->type, type);
}

void Spell::setManaCost(int manaCost)
{
    this->manaCost = manaCost;
}
