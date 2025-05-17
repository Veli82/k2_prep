#pragma once
class Soldier
{
public:
	Soldier();
	Soldier(const char* name, int years, int power, int salary);
	Soldier(const Soldier& other);
	Soldier& operator=(const Soldier& other);
	~Soldier();

	const char* getName() const { return name; }
	const int getYears() const { return years; }
	const int getPower() const { return power; }
	const int getSalary() const { return salary; }

	void setSalary(int);
	void setYears(int);
	void setPower(int);
	void setName(const char* name);

	void swap(Soldier& other);

protected:
	void setString(char* destination, const char* other);
	

	char* name;
	int years;
	int power;
	int salary;
};

