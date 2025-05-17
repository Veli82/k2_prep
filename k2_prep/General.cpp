#include "General.h"
#include <exception>
#include <utility>

General::General(const char* name, int years, int power, int salary)
    :Soldier(name, years, power, salary)
{
}

General::General(const General& other)
    :Soldier(other)
{
	size = other.size;
	cap = other.cap;
	try
	{
		magicians = new Magician * [size];
	}
	catch (const std::exception&)
	{
		delete[] name;
		throw;
	}
	for (int i = 0; i < size; i++)
	{
		magicians[i] = other.magicians[i];
	}
}

General& General::operator=(const General& other)
{
	if (this == &other) return *this;
	General temp(other);
	swap(temp);
	return *this;
}

General::~General()
{
	delete[] magicians;
}


void General::addMagician(Magician& magician)
{
	if (cap <= size) {
		Magician** newMagicians = new Magician * [(cap + 1) * 2];
		cap = (cap + 1) * 2;
		for (int i = 0; i < size; i++)
		{
			newMagicians[i] = magicians[i];
		}
		delete[] magicians;
		magicians = newMagicians;
	}
	magicians[size++] = &magician;
}

void General::removeMagician(const Magician& magician)
{
	for (int i = 0; i < size; i++)
	{
		if (magicians[i] == &magician)
		{
			for (int j = i; j < size - 1; j++)
			{
				magicians[j] = magicians[j + 1];
			}
			magicians[size--] = nullptr;
			break;
		}
	}
}

Magician* General::operator[](int index)
{
	return magicians[index];
}

const Magician* General::operator[](int index) const
{
	return magicians[index];
}

void General::swap(General& other)
{
	Soldier::swap(other);
	std::swap(magicians, other.magicians);
}
