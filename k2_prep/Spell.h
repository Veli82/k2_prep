#pragma once
class Spell
{
public:
	Spell();
	Spell(const char* description, const char* type, int manaCost);
	Spell(const Spell& other);
	Spell& operator=(const Spell& other);
	~Spell();

	const char* getDescription() const { return description; }
	const char* getType() const { return type; }
	int getManaCost() const { return manaCost; }

	void setDescription(const char* description);
	void setType(const char* type);
	void setManaCost(int manaCost);

protected:
	char* description = nullptr;
	char type[16];	//shoud probably be an enum
	int manaCost;
};

