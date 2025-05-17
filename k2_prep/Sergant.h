#pragma once

#include "Soldier.h"

class Sergant : public Soldier
{
public:
	Sergant(const char* name, int years, int power, int salary, const char* descr);
	Sergant(const Sergant& other);
	Sergant& operator=(const Sergant& other);
	~Sergant();

	void addSoldier(Soldier& soldier);
	void removeSoldier(Soldier& soldier);

	void setSquadDescription(const char* descr);

	Soldier* operator[](int index);
	const Soldier* operator[](int index) const;

protected:
	void swap(Sergant& other);

	char* squadDescription = nullptr;
	Soldier** squad = nullptr;
	int size = 0;
	int cap = 0;
};

