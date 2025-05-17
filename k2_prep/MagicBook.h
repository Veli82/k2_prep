#pragma once
#include "Spell.h"

class MagicBook
{
public:
	MagicBook() = default;
	MagicBook(const MagicBook& other);
	MagicBook& operator=(const MagicBook other);
	~MagicBook();

	void addSpell(Spell& spell);

	int getSize() const { return size; }
	int getCap() const { return cap; }

protected:
	Spell* spells = nullptr;
	int size = 0;
	int cap = 0;

};

