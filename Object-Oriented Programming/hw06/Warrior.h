#ifndef WARRIOR_H
#define WARRIOR_H
#include <string>
#include "Noble.h"

namespace WarriorCraft{
	class Noble;
	class Warrior
	{
	public:
		// Warrior constructor
		Warrior(const std::string& name, const int strength, Noble* noble); // initialized hired to false because warriors aren't hired when created

		string getName() const; // returns the name of the warrior
		
		void display() const; // displays the warriors name and strength

		void dies(); // warrior loses all his strength because he died

		void lowerStrength(const double ratio); // warrior loses some of his strength because he won a battle

		void gotHired(Noble* noblePtr); // warrior gets hired by a noble

		void gotFired(); // warrior gets fired. the struggle is real

		int getStrength() const; // returns the strength of the warrior

		void runaway();

	private:
		string name;
		int strength;
		Noble* noble;
	};
}

#endif