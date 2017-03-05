#ifndef NOBLE_H
#define NOBLE_H
#include <string>
#include <vector>
#include "Warrior.h"

namespace WarriorCraft{
	class Warrior;
	class Noble
	{
		friend ostream& operator<<(ostream& os, Noble noble); // output operator overload
	public:
		// Noble constructor
		Noble(const std::string& name, const int strengthArmy);

		std::string getName() const; // returns the name of the noble

		int getArmyStrength() const; // returns the army strength

		void armyLoses(); // noble loses and his strength = 0 and all of his warriors strength = 0

		void hire(Warrior& warrior); // hires a warrior by adding a pointer to him in the warrior pointer vec

		void fire(Warrior& warrior); // fire a warrior

		void battle(Noble& noble); // battle another noble

		void display() const;

		vector<Warrior*> getWarriors();
		
		void remove(Warrior* warrior);

	private:
		string name;
		int strengthArmy;
		vector<Warrior*> warriorPtr;
	};
}

#endif