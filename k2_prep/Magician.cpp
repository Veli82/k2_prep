#include "Magician.h"
#include <exception>

Magician::Magician(const char* name, int years, int power, int salary,const char* description, int mana,const MagicBook& magicBook)
	:Soldier(name, years, power, salary)
{
	try
	{
	setBatalionDescription(description);
	}
	catch (const std::exception&)
	{
		delete[] name;
		throw;
	}
	this->mana = mana;
	this->magicBook = magicBook;
}

Magician::Magician(const Magician& other)
	:Soldier(other.name, other.years, other.power, other.salary)
{
	try
	{
		setBatalionDescription(other.batalionDescription);
	}
	catch (const std::exception&)
	{
		delete[] name;
		throw;
	}
	mana = other.mana;
	magicBook = other.magicBook;
}

Magician& Magician::operator=(const Magician& other)
{
	if (this == &other) return *this;
	Magician temp(other);
	swap(temp);
	return *this;
}

Magician::~Magician()
{
	delete[] sergants;
}

void Magician::addSergant(Sergant& sergant)
{
	if (cap <= size) {
		Sergant** newSergants = new Sergant * [(cap + 1) * 2];
		cap = (cap + 1) * 2;
		for (int i = 0; i < size; i++)
		{
			newSergants[i] = sergants[i];
		}
		delete[] sergants;
		sergants = newSergants;
	}
	sergants[size++] = &sergant;
}

void Magician::removeSergant(Sergant& sergant)
{
	for (int i = 0; i < size; i++)
	{
		if (sergants[i] == &sergant)
		{
			for (int j = i; j < size - 1; j++)
			{
				sergants[j] = sergants[j + 1];
			}
			sergants[size--] = nullptr;
			break;
		}
	}

}

void Magician::setBatalionDescription(const char* descr)
{
	setString(batalionDescription, descr);
}

void Magician::swap(Magician& other)
{
	std::swap(batalionDescription, other.batalionDescription);
	Soldier::swap(other);
}
