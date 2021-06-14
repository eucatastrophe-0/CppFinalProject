/*
Sam Schock
Exam 2 Part C: Inheritance
Due 5/13/21
*/

#include <iostream>
#include <string>

using namespace std;

class Item
{
	public:
		Item();
		Item(const string& newName, const int& newCost);
		string getName() const { return name; };
		int getCost() const { return cost; };
		void setName(string newName);
		void setCost(int newCost);
	protected:
		string name;
		int cost;
};

class Potion : public Item
{
	public:
		Potion();
		Potion(const string& newName, const int& newCost, const int& newHealAmt);
		int getHealAmt() const { return healAmt; };
		void setHealAmt(int newHealAmt);
		string toString();
	protected:
		int healAmt;
};

class Weapon : public Item
{
public:
	Weapon();
	Weapon(const string& newName, const int& newCost, const int& newAtkMod, const string& newWeaponType);
	int getAtkMod() const { return atkMod; };
	string getWeaponType() const { return weaponType; };
	void setAtkMod(int newAtkMod);
	void setWeaponType(string newWeaponType);
	string toString();
protected:
	int atkMod;
	string weaponType;
};

int main()
{
	Potion lesserHeal = Potion("Lesser Heal", 10, 10);
	Weapon Narsil = Weapon();

	cout << lesserHeal.toString() << endl;

	cout << Narsil.toString() << endl;

	Narsil.setName("Narsil");
	Narsil.setCost(100000);
	Narsil.setAtkMod(100);
	Narsil.setWeaponType("sword");

	cout << Narsil.toString() << endl;

	return 0;
}

// Item member functions

Item::Item() : name("new item"), cost(0) {

}

Item::Item(const string& newName, const int& newCost) : name(newName), cost(newCost) {

}

void Item::setName(string newName)
{
	name = newName;
}

void Item::setCost(int newCost)
{
	cost = newCost;
}

// Potion member functions

Potion::Potion() : Item(), healAmt(0) {

}

Potion::Potion(const string& newName, const int& newCost, const int& newHealAmt) : Item(newName, newCost), healAmt(newHealAmt) {

}

void Potion::setHealAmt(int newHealAmt)
{
	healAmt = newHealAmt;
}

string Potion::toString()
{
	string output;
	output = "Potion of " + getName() + ": +" + to_string(getHealAmt()) + " hp, " + to_string(getCost()) + " gold";
	return output;
}

// Weapon member functions

Weapon::Weapon() : Item(), atkMod(0), weaponType("weapon") {

}

Weapon::Weapon(const string& newName, const int& newCost, const int& newAtkMod, const string& newWeaponType)
	: Item(newName, newCost), atkMod(newAtkMod), weaponType(newWeaponType) {

}

void Weapon::setAtkMod(int newAtkMod)
{
	atkMod = newAtkMod;
}

void Weapon::setWeaponType(string newWeaponType)
{
	weaponType = newWeaponType;
}

string Weapon::toString()
{
	string output;
	output = getName() + ", +" + to_string(getAtkMod()) + " " + getWeaponType() + ", " + to_string(getCost()) + " gold";
	return output;
}