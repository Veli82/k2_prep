#pragma once

#include "Soldier.h"
#include "Magician.h"

class General : public Soldier
{
public:
	General(const char* name, int years, int power, int salary);
	General(const General& other);
	General& operator=(const General& other);
	~General();
	void addMagician(Magician& magician);
	void removeMagician(const Magician& magician);

	Magician* operator[](int index);
	const Magician* operator[](int index) const;

protected:
	void swap(General& other);

	Magician** magicians = nullptr;
	int size = 0;
	int cap = 0;
};


