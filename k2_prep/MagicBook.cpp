#include "MagicBook.h"


MagicBook::MagicBook(const MagicBook& other)
{
	for (int i = 0; i < size; i++)
	{
		addSpell(other.spells[i]);
	}
}

MagicBook& MagicBook::operator=(const MagicBook other)
{
	if (this == &other) return *this;
	MagicBook temp(other);
	delete[] spells;
	spells = other.spells;
	size = other.size;
	cap = other.cap;
	return *this;
}

MagicBook::~MagicBook()
{
	delete[] spells;
}

void MagicBook::addSpell(Spell& spell)
{
	if (cap <= size) {
		if (cap > size) { //to fix (it works for now)
			Spell* newSpells = new Spell[(cap + 1) * 2];
			cap = (cap + 1) * 2;
			for (int i = 0; i < size; i++)
			{
				newSpells[i] = spells[i];
			}
			delete[] spells;
			spells = newSpells;
		}
	}
	
	spells[size++] = spell;
}