#include "Sergant.h"
#include <exception>
#include <utility>

Sergant::Sergant(const char* name, int years, int power, int salary, const char* descr)
	:Soldier(name,years,power,salary)
{
	try
	{
	setSquadDescription(descr);
	}
	catch (const std::exception&)
	{
		delete[] name;
	}
}

Sergant::Sergant(const Sergant& other)
	:Soldier(other)
{
	size = other.size;
	cap = other.cap;
	try
	{
	setSquadDescription(other.squadDescription);
	squad = new Soldier * [size];
	}
	catch (const std::exception&)
	{
		delete[] squadDescription;
		delete[] name;
		delete[] squad;
		throw;
	}
	for (int i = 0; i < size; i++)
	{
		squad[i] = other.squad[i];
	}
	
}

Sergant& Sergant::operator=(const Sergant& other)
{
	if (this == &other) return *this;
	Sergant temp(other);
	swap(temp);
	return *this;
}

Sergant::~Sergant()
{
	delete[] squadDescription;
}

void Sergant::addSoldier(Soldier& soldier)
{
	if (cap <= size) {
		Soldier** newSquad = new Soldier * [(cap + 1) * 2];
		cap = (cap + 1) * 2;
		for (int i = 0; i < size; i++)
		{
			newSquad[i] = squad[i];
		}
		delete[] squad;
		squad = newSquad;
	}
	squad[size++] = &soldier;
}

void Sergant::removeSoldier(Soldier& soldier)
{
	for (int i = 0; i < size; i++)
	{
		if (squad[i] == &soldier) 
		{
			for (int j = i; j < size-1; j++)
			{
				squad[j] = squad[j + 1];
			}
			squad[size--] = nullptr;
			break;
		}
	}
}

void Sergant::setSquadDescription(const char* descr)
{
	setString(this->squadDescription, descr);
}

Soldier* Sergant::operator[](int index)
{
	return squad[index];
}

const Soldier* Sergant::operator[](int index) const
{
	return squad[index];
}

void Sergant::swap(Sergant& other)
{
	std::swap(squadDescription, other.squadDescription);
	std::swap(squad, other.squad);
	Soldier::swap(other);
}
