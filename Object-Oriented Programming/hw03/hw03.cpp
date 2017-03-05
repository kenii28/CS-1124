/*
Kenneth Huynh
CS 1124
hw03

This program reads a warriors file and displays the results of what is in the file after creating  an instance of each warrior with his weapon.
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Warrior
{
public:
	// Warrior constructor
	Warrior(const string& name, const int strength, bool hired = false) // initialized hired to false because warriors aren't hired when created
		: name(name), strength(strength) {}


	
	string getName() const // returns the name of the warrior
	{
		return name;
	}

	void display() const // displays the warriors name and strength
	{
		cout << "\t" << name << ": " << strength << endl;
	}

	void dies() // warrior loses all his strength because he died
	{
		strength = 0;
	}

	void lowerStrength(const double ratio) // warrior loses some of his strength because he won a battle
	{
		double amtChange;

		amtChange = 1 - ratio;
		strength = strength * amtChange;
	}

	void gotHired() // warrior gets hired by a noble
	{
		hired = true;
	}

	void gotFired() // warrior gets fired. the struggle is real
	{
		hired = false;
	}

	int getStrength() const // returns the strength of the warrior
	{
		return strength;
	}

private:
	string name;
	int strength;
	bool hired;
};

class Noble
{
public:
	// Noble constructor
	Noble(const string& name, const int strengthArmy = 0)
		: name(name) {}

	string getName() const // returns the name of the noble
	{
		return name;
	}

	int getArmyStrength() const // returns the army strength
	{
		return strengthArmy;
	}

	void armyLoses() // noble loses and his strength = 0 and all of his warriors strength = 0
	{
		strengthArmy = 0;
		for (Warrior* warriorPtr : warriorPtr)
		{
			warriorPtr->dies();
		}
	}
	void hire(Warrior& warrior) // hires a warrior by adding a pointer to him in the warrior pointer vec
	{
		strengthArmy += warrior.getStrength();
		Warrior* ptr = &warrior;
		warriorPtr.push_back(ptr);
	}

	void fire(Warrior& warrior) // fire a warrior
	{
		cout << warrior.getName() << " you're fired!  --  " << name << endl;

		strengthArmy -= warrior.getStrength();

		size_t wantedIndex;

		for (size_t index = 0; index < warriorPtr.size(); ++index)
		{
			if (warrior.getName() == warriorPtr[index]->getName())
			{
				wantedIndex = index;
			}
		}

		warriorPtr[wantedIndex] = warriorPtr[warriorPtr.size() - 1];
		warriorPtr.pop_back();
	}

	void battle(Noble& noble) // battle another noble
	{
		cout << getName() << " battles " << noble.getName() << endl;

		if ((getArmyStrength() == 0) && (noble.getArmyStrength() == 0)) // both dead
		{
			cout << "Oh, NO! They're both dead! Yuck!" << endl;

		}

		else if (noble.getArmyStrength() == 0) // warriorTwo is dead
		{
			cout << "He's dead " << getName() << endl;

		}

		else if (getArmyStrength() == noble.getArmyStrength()) // equal strength
		{
			cout << "Mutual Annihilation: " << getName() << " and " << noble.getName() << " die at each other's hands" << endl;

			armyLoses();
			noble.armyLoses();

		}

		else if (getArmyStrength() > noble.getArmyStrength()) // warriorOne is stronger than warriorTwo
		{
			cout << getName() << " defeats " << noble.getName() << endl;

			noble.armyLoses();

			double ratio;
			ratio = (noble.getArmyStrength() - getArmyStrength());
			
			for (Warrior* warriorPtr : warriorPtr)
			{
				warriorPtr->lowerStrength(ratio);
			}
			
		}

	}

	void display() const // displays the noble
	{
		cout << name << " has an army of " << warriorPtr.size() << endl;
		for (Warrior* warriorPtr : warriorPtr)
		{
			warriorPtr->display();
		}
	}
private:
	string name;
	int strengthArmy;
	vector<Warrior*> warriorPtr;
};


int main()
{
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);


	system("pause");
}