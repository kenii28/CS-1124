/*
Kenneth Huynh
CS 1124
Rec03

This program opens and reads a file containing chemical names and their formulas and creates a class for them.
Then it sorts them based on the number of carbon atoms there are and prints them out.
*/

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Chemical
{
	int numCarbon;
	int numHydrogen;
	vector<string> names;
};

void openFile(ifstream& ifs, string& fileName);
size_t doesTokenExist(int numCarbon, int numHydrogen, const vector<Chemical>& chemVec);
void addNameOnly(size_t index, const string& chemical, vector<Chemical>& chemVec);
void addNewChem(int numCarbon, int numHydrogen, const string& name, vector<Chemical>& chemVec);
int findMaxCarbons(vector<Chemical>& chemVec);
void printInOrder(int maxCarbon, const vector<Chemical>& chemVec);
void readFile(ifstream& ifs, vector<Chemical>& chemVec);

int main()
{
	string fileName = "hydrocarbons.txt";

	ifstream ifs;

	openFile(ifs, fileName);

	vector<Chemical> chemVec;

	readFile(ifs, chemVec);

	int maxCarbon = findMaxCarbons(chemVec);
	printInOrder(maxCarbon, chemVec);

	ifs.close();

	system("pause");

}

void openFile(ifstream& ifs, string& fileName)
{
	ifs.open(fileName);
	if (!ifs)
	{
		cout << "The file doesn't exist.";
		exit(1);
	}

}

size_t doesTokenExist(int numCarbon, int numHydrogen, const vector<Chemical>& chemVec) // checks if the token already exists in the vector
{
	for (size_t index = 0; index < chemVec.size(); ++index)
	{
		if ((numCarbon == chemVec[index].numCarbon) && (numHydrogen == chemVec[index].numHydrogen))
		{
			return index;
		}
	}

	return chemVec.size();
}

void addNameOnly(size_t index, const string& chemical, vector<Chemical>& chemVec) // adds another name to a chemical
{
	chemVec[index].names.push_back(chemical);
}

void addNewChem(int numCarbon, int numHydrogen, const string& name, vector<Chemical>& chemVec) // creates and adds new instance of Chemical
{
	Chemical chemical;
	chemical.numCarbon = numCarbon;
	chemical.numHydrogen = numHydrogen;
	chemical.names.push_back(name);

	chemVec.push_back(chemical);
}

int findMaxCarbons(vector<Chemical>& chemVec) // finds the max number of carbons
{
	int max = 0;
	for (const Chemical& chemical : chemVec)
	{
		if (chemical.numCarbon > max)
		{
			max = chemical.numCarbon;
		}
	}
	return max;
}


void printInOrder(int maxCarbon, const vector<Chemical>& chemVec) // prints the number of carbon atoms in ascending order
{
	for (int numCarbon = 1; numCarbon <= maxCarbon; ++numCarbon)
	{
		for (size_t index = 0; index < chemVec.size(); ++index)
		{
			if (numCarbon == chemVec[index].numCarbon)
			{
				cout << "C" << chemVec[index].numCarbon << "H" << chemVec[index].numHydrogen << " ";
				for (const string& names : chemVec[index].names)
				{
					cout << names << " ";
				}
				cout << endl;
			}
			
		}
	}
}

void readFile(ifstream& ifs, vector<Chemical>& chemVec) // reads the file and acts accordingly
{
	string name;
	char junk; // this is where the useless C and H go
	int numCarbon;
	int numHydrogen;

	while (ifs >> name >> junk >> numCarbon >> junk >> numHydrogen)
	{
		size_t foundIndex = doesTokenExist(numCarbon, numHydrogen, chemVec);
		if (foundIndex != chemVec.size()) // already exists
		{
			addNameOnly(foundIndex, name, chemVec);
		}
		else // make new instance of Chemical
		{
			addNewChem(numCarbon, numHydrogen, name, chemVec);
		}
	}
}