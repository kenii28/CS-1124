#include <string>
#include <iostream>	
#include "Warrior.h"
using namespace std;

namespace WarriorCraft{
		// Warrior constructor
		Warrior::Warrior(const std::string& name, const int strength, Noble* noble) // initialized hired to false because warriors aren't hired when created
			: name(name), strength(strength), noble(nullptr) {}


		string Warrior::getName() const // returns the name of the warrior
		{
			return name;
		}

		void Warrior::display() const // displays the warriors name and strength
		{
			cout << "\t" << name << ": " << strength << endl;
		}

		void Warrior::dies() // warrior loses all his strength because he died
		{
			strength = 0;
		}

		void Warrior::lowerStrength(const double ratio) // warrior loses some of his strength because he won a battle
		{
			double amtChange;

			amtChange = 1 - ratio;
			strength = strength * amtChange;
		}

		void Warrior::gotHired(Noble* noblePtr) // warrior gets hired by a noble
		{
			noble = noblePtr;
		}

		void Warrior::gotFired() // warrior gets fired. the struggle is real
		{
			noble = nullptr;
		}

		int Warrior::getStrength() const // returns the strength of the warrior
		{
			return strength;
		}

		void Warrior::runaway() {
			cout << getName() << " flees in terror, abandoning his lord, " << noble->getName() << endl;
			noble->remove(this);
			noble = nullptr;
		}
}