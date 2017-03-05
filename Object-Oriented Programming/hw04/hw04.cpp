/*
Kenneth Huynh
CS 1124
hw04

This program reads a file and processes it for hw04.
*/

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Warrior;
class Noble;

void openFile(ifstream& ifs, string& fileName);
size_t doesWarriorExist(const string& name, vector<Warrior*>& unemployed);
size_t doesNobleExist(const string& name, vector<Noble*>& noblePtrs);
void processFile(ifstream& ifs, vector<Noble*>& noblePtrs, vector<Warrior*>& unemployed);
void displayStatus(vector<Noble*>& noblePtrs, vector<Warrior*>& unemployed);
void clear(vector<Noble*>& noblePtrs, vector<Warrior*>& unemployed);
string isWarriorInNoble(string name, vector<Noble*>& noblePtrs);

class Warrior
{
public:
	// constructor
	Warrior(const string& name, const double strength)
		: name(name), strength(strength) {}

	double getStrength() const // returns the strength of the warrior
	{
		return strength;
	}

	string getName() const // returns the name of the warrior
	{
		return name;
	}

	void display() const // displays the warriors name and strength
	{
		cout << name << ": " << strength << endl;
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

private:
	string name;
	double strength;
};

class Noble
{
public:
	// constructor
	Noble(const string& name, const int strengthArmy = 0)
		: name(name) {}

	vector<Warrior*> getWarriors()  // returns the warrior vector to check if he is already in the noble's army
	{
		return warriorPtr;
	}

	void display() const // displays the noble
	{
		cout << name << " has an army of " << warriorPtr.size() << endl;
		for (Warrior* warriorPtr : warriorPtr)
		{
			warriorPtr->display();
		}
	}

	string getName() const // returns the name of the warrior
	{
		return name;
	}

	void hire(Warrior* warrior) // hires a warrior and adds warrior to warrior pointers
	{
		warriorPtr.push_back(warrior);
	}


	void fire(Warrior* warrior) // fires a warrior and adds warrior to unemployed
	{
		cout << "You don't work for me anymore " << warrior << "! -- " << name << endl;

		size_t foundIndex;
		for (size_t index = 0; index < warriorPtr.size(); index++) // checks for warrior
		{
			if (warriorPtr[index]->getName() == warrior->getName()) {
				foundIndex = index;
			}
		}
	
		if (foundIndex == warriorPtr.size() - 1) // pop back if warrior is already in last index
		{
			warriorPtr.pop_back();
		}

		else // if not last index will copy over each index after the warrior and pop back last one
		{
			for (size_t index2 = foundIndex; index2 < warriorPtr.size() - 1; index2++) 
			{
				warriorPtr[index2] = warriorPtr[index2 + 1];
			}
			warriorPtr.pop_back();
		}
	}


	Warrior* searchWarrior(const string& name) // searches for warrior that is already in noble
	{
		for (size_t index = 0; index < warriorPtr.size(); index++) {
			if (warriorPtr[index]->getName() == name) {
				return warriorPtr[index];
			}
		}
		return nullptr;
	}

	void armyLoses() // noble loses and his strength = 0 and all of his warriors strength = 0
	{
		for (Warrior* warriorPtr : warriorPtr)
		{
			warriorPtr->dies();
		}
	}

	void battle(Noble* noble) // battle another noble
	{
		cout << getName() << " battles " << noble->getName() << endl;

		double strength1 = 0;
		for (const Warrior* const warrior : warriorPtr) 
		{
			strength1 += warrior->getStrength();
		}
		double strength2 = 0;
		for (const Warrior* const warrior : noble->warriorPtr) 
		{
			strength2 += warrior->getStrength();
		}
		if ((strength1 == 0) && (strength2== 0)) // both dead
		{
			cout << "Oh, NO! They're both dead! Yuck!" << endl;

		}

		else if (strength2 == 0) // warriorTwo is dead
		{
			cout << "He's dead " << name << endl;
		}

		else if (strength1 == strength2) // equal strength
		{
			cout << "Mutual Annihilation: " << getName() << " and " << noble->getName() << " die at each other's hands" << endl;

			armyLoses();
			noble->armyLoses();
		}

		else if (strength1 > strength2)
		{
			cout << name << " defeats " << noble->getName() << endl;

			noble->armyLoses();

			double ratio;
			ratio = (strength1 - strength2);

			for (Warrior* warriorPtr : warriorPtr)
			{
				warriorPtr->lowerStrength(ratio);
			}

		}
		else
		{
			cout << noble->getName() << " defeats " << name << endl;

			armyLoses();

			double ratio;
			ratio = (strength2 - strength1);

			for (Warrior* warriorPtr : warriorPtr)
			{
				warriorPtr->lowerStrength(ratio);
			}

		}

	}
private:
	string name;
	vector<Warrior*> warriorPtr;

};



void openFile(ifstream& ifs, string& fileName)
{
	ifs.open(fileName);
	if (!ifs)
	{
		cout << "The file doesn't exist.";
		exit(1);
	}

}

size_t doesWarriorExist(const string& name, vector<Warrior*>& unemployed) // checks if the warrior exists in the unemployed
{
	for (size_t index = 0; index < unemployed.size(); ++index)
	{
		if (unemployed[index]->getName() == name)
		{
			return index;
		}
	}
	return unemployed.size();
}

size_t doesNobleExist(const string& name, vector<Noble*>& noblePtrs) // checks if the noble exists in the unemployed
{
	for (size_t index = 0; index < noblePtrs.size(); ++index)
	{
		if (noblePtrs[index]->getName() == name)
		{
			return index;
		}
	}
	return noblePtrs.size();
}

void processFile(ifstream& ifs, vector<Noble*>& noblePtrs, vector<Warrior*>& unemployed) // process the file
{
	string firstWord;

	while (ifs >> firstWord)
	{
		if (firstWord == "Warrior")
		{
			string warrior;
			double strength;
			ifs >> warrior >> strength;

			size_t warriorIndex = doesWarriorExist(warrior, unemployed);
			string check = isWarriorInNoble(warrior, noblePtrs);
			if ( warriorIndex != unemployed.size())
			{
				cout << "There is a duplicate of this warrior. Warrior was not created but program will continue.\n";
			}
			else // no duplicate
			{
				Warrior* wPtr = new Warrior(warrior, strength);
				unemployed.push_back(wPtr);
			}
		}
		else if (firstWord == "Noble")
		{
			string noble;
			ifs >> noble;

			size_t nobleIndex = doesNobleExist(noble, noblePtrs);
			if ( nobleIndex != noblePtrs.size())
			{
				cout << "There is a duplicate of this noble. Noble was not created but program will continue.\n";
			}
			else // no duplicate
			{
				Noble* nPtr = new Noble(noble);
				noblePtrs.push_back(nPtr);
			}
		}
		else if (firstWord == "Hire")
		{
			string noble, warrior;
			ifs >> noble >> warrior;

			size_t nobleIndex = doesNobleExist(noble, noblePtrs);
			size_t warriorIndex = doesWarriorExist(warrior, unemployed);
			string hired = isWarriorInNoble(warrior, noblePtrs);
			if (nobleIndex == noblePtrs.size())
			{
				cout << "Noble doesn't exist.\n";
			}
			else if (warriorIndex == unemployed.size() && hired == "no")
			{
				cerr << "Warrior doesn't exist.\n";
			}
			else if (hired == "yes")
			{
				cout << "Warrior already hired.\n";
			}
			else {
				for (size_t index = 0; index < noblePtrs.size(); index++) {
					if (noblePtrs[index]->getName() == noble) {
						for (size_t index2 = 0; index2 < unemployed.size(); index2++) {
							if (unemployed[index2]->getName() == warrior) {
								noblePtrs[index]->hire(unemployed[index2]);
								if (index2 == unemployed.size() - 1) {
									unemployed.pop_back();
								}
								else {
									for (size_t index3 = index2; index3 < unemployed.size() - 1; index3++) {
										unemployed[index3] = unemployed[index3 + 1];
									}
									unemployed.pop_back();
								}
							}
						}
					}
				}
			}
		}
		else if (firstWord == "Fire")
		{
			string noble, warrior;
			ifs >> noble >> warrior;

			size_t nobleIndex = doesNobleExist(noble, noblePtrs);
			size_t warriorIndex = doesWarriorExist(warrior, unemployed);
			string hired = isWarriorInNoble(warrior, noblePtrs);

			if (nobleIndex == noblePtrs.size())
			{
				cout << "Noble doesn't exist.\n";
			}
			else if (warriorIndex == unemployed.size() && hired == "no")
			{
				cerr << "Warrior doesn't exist.\n";
			}
			else if (hired == "yes")
			{
				cout << "Warrior already hired.\n";
			}
			else {
				for (size_t index = 0; index < noblePtrs.size(); index++) {
					if (noblePtrs[index]->getName() == noble) {
						Warrior* firedWarrior = noblePtrs[index]->searchWarrior(warrior);
						unemployed.push_back(firedWarrior);
						noblePtrs[index]->fire(firedWarrior);
					}
				}
			}

		}
		else if (firstWord == "Status")
		{
			displayStatus(noblePtrs, unemployed);
		}
		else if (firstWord == "Clear")
		{
			clear(noblePtrs, unemployed);
		}
		else // firstWord == Battle
		{
			size_t nobleOneIndex;
			size_t nobleTwoIndex;

			string firstNoble;
			string secondNoble;

			ifs >> firstNoble;
			ifs >> secondNoble;

			nobleOneIndex = doesNobleExist(firstNoble, noblePtrs);
			nobleTwoIndex = doesNobleExist(secondNoble, noblePtrs);

			if (nobleOneIndex == noblePtrs.size() && nobleTwoIndex == noblePtrs.size())
			{
				cout << "Both don't exist.\n";
			}
			else if (nobleTwoIndex == noblePtrs.size()) 
			{
				cout << secondNoble << " does not exist." << endl;
			}
			else if (nobleOneIndex == noblePtrs.size()) 
			{
				cout << firstNoble << " does not exist." << endl;
			}
			else 
			{
				for (size_t index = 0; index < noblePtrs.size(); index++) {
					if (noblePtrs[index]->getName() == firstNoble) {
						for (size_t index2 = 0; index2 < noblePtrs.size(); index2++) {
							if (noblePtrs[index2]->getName() == secondNoble) {
								noblePtrs[index]->battle(noblePtrs[index2]);
							}
						}
					}
				}
			}

		}
	}
}

void displayStatus(vector<Noble*>& noblePtrs, vector<Warrior*>& unemployed) // displays the status
{
	cout << "Status\n=====\nNobles:\n";
	if (unemployed.size() == 0)
	{
		cout << "NONE\n";
	}
	else // there is at least 1 unemployed warrior
	{
		for (Noble* noblePtr : noblePtrs)
		{
			noblePtr->display();
		}
	}
	

	cout << "Unemployed Warriors:\n";
	if (unemployed.size() == 0)
	{
		cout << "NONE\n";
	}
	else // there is at least 1 unemployed warrior
	{
		for (Warrior* warriorPtr : unemployed)
		{
			warriorPtr->display();
		}
	}
}

string isWarriorInNoble(string name, vector<Noble*>& noblePtrs) // checks if the warrior is already in the warrior vector of noble
{
	for (size_t index = 0; index < noblePtrs.size(); index++) {
		for (size_t index2 = 0; index2 < noblePtrs[index]->getWarriors().size(); index2++)
			if (noblePtrs[index]->getWarriors()[index2]->getName() == name) {
				return "yes";
			}
	}
	return "no";
}
void clear(vector<Noble*>& noblePtrs, vector<Warrior*>& unemployed) // clear vectors
{
	for (Noble* noblePtr : noblePtrs)
	{
		delete noblePtr;
	}
	noblePtrs.clear();

	for (Warrior* warriorPtr : unemployed)
	{
		delete warriorPtr;
	}
	unemployed.clear();
}

int main()
{
	ifstream ifs;
	string fileName;
	fileName = "nobleWarriors.txt";
	openFile(ifs, fileName);

	vector<Noble*> noblePtrs;
	vector<Warrior*> unemployed;

	processFile(ifs, noblePtrs, unemployed);

	ifs.close();

	system("pause");
}