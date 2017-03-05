#include "Warrior.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace WarriorCraft{

		Noble::Noble(const std::string& name, const int strengthArmy = 0) : name(name) {}

		ostream& operator<<(ostream& os, Noble noble);


		std::string Noble::getName() const // returns the name of the noble
		{
			return Noble::name;
		}

		int Noble::getArmyStrength() const // returns the army strength
		{
			return strengthArmy;
		}

		void Noble::armyLoses() // noble loses and his strength = 0 and all of his warriors strength = 0
		{
			strengthArmy = 0;
			for (Warrior* warriorPtr : warriorPtr)
			{
				warriorPtr->dies();
			}
		}
		void Noble::hire(Warrior& warrior) // hires a warrior by adding a pointer to him in the warrior pointer vec
		{
			strengthArmy += warrior.getStrength();
			Warrior* ptr = &warrior;
			warriorPtr.push_back(ptr);
			warrior.gotHired(this);
		}

		void Noble::fire(Warrior& warrior) // fire a warrior
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

		void Noble::battle(Noble& noble) // battle another noble
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

		void Noble::display() const // displays the noble
		{
			cout << name << " has an army of " << warriorPtr.size() << endl;
			for (Warrior* warriorPtr : warriorPtr)
			{
				warriorPtr->display();
			}
		}

		void Noble::remove(Warrior* warrior) {
			strengthArmy -= warrior->getStrength();

			size_t wantedIndex;

			for (size_t index = 0; index < warriorPtr.size(); ++index)
			{
				if (warrior->getName() == warriorPtr[index]->getName())
				{
					wantedIndex = index;
				}
			}

			warriorPtr[wantedIndex] = warriorPtr[warriorPtr.size() - 1];
			warriorPtr.pop_back();
		}

	ostream& operator<<(ostream& os, Noble noble) {
		os << noble.getName() << " has an army of " << noble.getWarriors().size() << endl;
		for (Warrior* warriorPtr : noble.getWarriors())
		{
			warriorPtr->display();
		}
		return os;
	}
}