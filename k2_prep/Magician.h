#pragma once
#include "Soldier.h"
#include "Sergant.h"
#include "MagicBook.h"

class Magician : public Soldier
{
public:
	Magician(const char* name, int years, int power, int salary,const char* description, int mana,const MagicBook& magicBook);
	Magician(const Magician& other);
	Magician& operator=(const Magician& other);
	~Magician();

	void addSergant(Sergant& sergant);
	void removeSergant(Sergant& sergant);

	int getMana() const { return mana; }
	void setBatalionDescription(const char* descr);

protected:
	void swap(Magician& other);


	char* batalionDescription = nullptr;
	Sergant** sergants = nullptr;
	int size;
	int cap;
	int mana;
	MagicBook magicBook;
};

