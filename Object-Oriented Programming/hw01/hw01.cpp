/*
Kenneth Huynh
CS 1124
hw01

This program reads a warriors file and displays the results of what is in the file.
*/

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Warrior
{
	string name;
	int strength;
};

void openFile(ifstream& ifs, string& fileName);
void createWarrior(string& name, int strength, vector<Warrior>& warriorVec);
void displayStatus(vector<Warrior> warriorVec);
void doBattle(Warrior warriorOne, Warrior warriorTwo, vector<Warrior>& warriorVec);
Warrior assignWarrior(string& warrior, vector<Warrior>& warriorVec);
void warriorDies(Warrior warrior, vector<Warrior>& warriorVec);

int main()
{
	string fileName = "warriors.txt";
	ifstream warriors;

	openFile(warriors, fileName);
	
	vector<Warrior> warriorVec;
	string firstWord;

	while (warriors >> firstWord)
	{
		if (firstWord == "Warrior")
		{
			string warriorName;
			int warriorStrength;

			warriors >> warriorName;
			warriors >> warriorStrength;

			createWarrior(warriorName, warriorStrength, warriorVec);
		}
		else if (firstWord == "Status")
		{
			displayStatus(warriorVec);
		}
		else // firstWord == Battle
		{
			string warriorOne;
			string warriorTwo;

			warriors >> warriorOne;
			warriors >> warriorTwo;

			Warrior firstWarrior = assignWarrior(warriorOne, warriorVec);
			Warrior secondWarrior = assignWarrior(warriorTwo, warriorVec);

			doBattle(firstWarrior, secondWarrior, warriorVec);

		}
	}

	system("pause");
}


void openFile(ifstream& ifs, string& fileName)
{
	ifs.open(fileName);
	if (!ifs)
	{
		cerr << "Could not open the file.\n";
		exit(1);
	}
}


void createWarrior(string& name, int strength, vector<Warrior>& warriorVec) // creates a warrior and adds him to warriorVec
{
	Warrior warriorToAdd;
	warriorToAdd.name = name;
	warriorToAdd.strength = strength;
	warriorVec.push_back(warriorToAdd);
	// store warriors in a vec
}

void displayStatus(vector<Warrior> warriorVec) // displays the status
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
		cout << "Warrior: " << warrior.name << ", strength: " << warrior.strength << endl;
	}
}

void doBattle(Warrior warriorOne, Warrior warriorTwo, vector<Warrior>& warriorVec) // do battle between warriors!!!!!
{
	cout << warriorOne.name << " battles " << warriorTwo.name << endl;

	if ((warriorOne.strength == 0) && (warriorTwo.strength == 0)) // both dead
	{
		cout << "Oh, NO! They're both dead! Yuck!" <<  endl;

	}

	else if (warriorTwo.strength == 0) // warriorTwo is dead
	{
		cout << "He's dead, " << warriorOne.name << endl;

	}

	else if (warriorOne.strength == warriorTwo.strength) // equal strength
	{
		cout << "Mutual Annihilation: " << warriorOne.name << " and " << warriorTwo.name << " die at each other's hands" << endl;
		
		warriorDies(warriorOne, warriorVec);
		warriorDies(warriorTwo, warriorVec);

		//warriorOne.strength = 0;
		//warriorTwo.strength = 0;
	}

	else if (warriorOne.strength > warriorTwo.strength) // warriorOne is stronger than warriorTwo
	{
		cout << warriorOne.name << " defeats " << warriorTwo.name << endl;
		warriorDies(warriorTwo, warriorVec);

	}
}

Warrior assignWarrior(string& warrior, vector<Warrior>& warriorVec) // assigns the string name of a warrior to his warrior type
{
	for (size_t index = 0; index < warriorVec.size(); ++index)
	{
		if (warrior == warriorVec[index].name)
		{
			return warriorVec[index];
		}
	}
}

void warriorDies(Warrior warrior, vector<Warrior>& warriorVec) // warrior dies, strength goes to 0
{
	for (size_t index = 0; index < warriorVec.size(); ++index)
	{
		if (warrior.name == warriorVec[index].name)
		{
			warriorVec[index].strength = 0;
		}
	}
}
/*
get the first word of each line
get all the info first then create the struct for each other
*/