/*
Kenneth Huynh
CS 1124
hw02

This program reads a warriors file and displays the results of what is in the file after creating  an instance of each warrior with his weapon.
*/

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Weapon
{

public:
	// constructor for weapon
	Weapon(const string& name, const int strength)
		: name(name), strength(strength) {}

	void display(ostream& os = cout) const
	{
		cout << "weapon: " << name << ", " << strength << endl;
	}

	int getStrength() const // returns the strength of the weapon
	{
		return strength;
	}

	void changeStrength(const int newStrength) // changes the strength of the weapon
	{
		strength = newStrength;
	}

private:
	string name;
	int strength;
};

class Warrior
{
public:
	// constructor for Warrior
	Warrior(const string& name, const string& weaponName, const int weaponStrength)
		:name(name), weapon(weaponName, weaponStrength)
	{}

	// Warrior(){}

	string getName() const  // returns the name of the warrior
	{
		return name;
	}

	int getWeaponStrength() const  // returns the strength of the weapon
	{
		return weapon.getStrength();
	}

	void changeStrength(const int newStrength)
	{
		weapon.changeStrength(newStrength);
	}

	void display() const
	{
		cout << "Warrior: " << name << ", ";
		weapon.display();
	}

	void doBattle(Warrior& warriorTwo) // do battle between warriors!!!!!
	{
		cout << getName() << " battles " << warriorTwo.getName() << endl;

		if ((getWeaponStrength() == 0) && (warriorTwo.getWeaponStrength() == 0)) // both dead
		{
			cout << "Oh, NO! They're both dead! Yuck!" << endl;

		}

		else if (warriorTwo.getWeaponStrength() == 0) // warriorTwo is dead
		{
			cout << "He's dead, " << getName() << endl;

		}

		else if (getWeaponStrength() == warriorTwo.getWeaponStrength()) // equal strength
		{
			cout << "Mutual Annihilation: " << getName() << " and " << warriorTwo.getName() << " die at each other's hands" << endl;

			changeStrength(0);
			warriorTwo.changeStrength(0);
			
		}

		else if (getWeaponStrength() > warriorTwo.getWeaponStrength()) // warriorOne is stronger than warriorTwo
		{
			cout << getName() << " defeats " << warriorTwo.getName() << endl;

			int newStrength;
			newStrength = getWeaponStrength() - warriorTwo.getWeaponStrength();
			changeStrength(newStrength);

			warriorTwo.changeStrength(0);

		}
	}

private:
	string name;
	Weapon weapon;
};



void openFile(ifstream& ifs, string& fileName)
{
	ifs.open(fileName);
	if (!ifs)
	{
		cerr << "Could not open the file.\n";
		exit(1);
	}
}

void displayStatus(const vector<Warrior>& warriorVec) // displays the status
{
	size_t numWarriors = warriorVec.size();

	cout << "There are: " << numWarriors;
	if (numWarriors > 1)
	{
		cout << " warriors" << endl;
	}
	else // only one warrior
	{
		cout << " warrior" << endl;
	}

	for (Warrior warrior : warriorVec)
	{
		warrior.display();
	}
}

void createWarrior(ifstream& ifs, vector<Warrior>& warriorVec) // creates and adds an instance of warrior to the warriorVec
{
	string name;
	string weaponName;
	int strength;

	ifs >> name >> weaponName >> strength;
	Warrior warrior(name, weaponName, strength);

	warriorVec.push_back(warrior);
}

size_t findWarrior(const string& warriorName, vector<Warrior>& warriorVec) // finds and returns the warrior to be changed index
{
	for (size_t index = 0; index < warriorVec.size(); ++index)
	{
		if (warriorName == warriorVec[index].getName())
		{
			return index;
		}
	}
}

void processFile(ifstream& ifs, vector<Warrior>& warriorVec)
{
	string firstWord;

	while (ifs >> firstWord)
	{
		if (firstWord == "Warrior")
		{
			createWarrior(ifs, warriorVec);
		}
		else if (firstWord == "Status")
		{
			displayStatus(warriorVec);
		}
		else // firstWord == Battle
		{
			size_t warriorOneIndex;
			size_t warriorTwoIndex;

			string firstWarrior;
			string secondWarrior;

			ifs >> firstWarrior;
			ifs >> secondWarrior;

			warriorOneIndex = findWarrior(firstWarrior, warriorVec);
			warriorTwoIndex = findWarrior(secondWarrior, warriorVec);

			warriorVec[warriorOneIndex].doBattle(warriorVec[warriorTwoIndex]);

		}
	}
}

int main()
{
	ifstream ifs;
	string fileName;
	fileName = "warriors.txt";

	openFile(ifs, fileName);

	vector<Warrior> warriorVec;

	processFile(ifs, warriorVec);
	system("pause");

}