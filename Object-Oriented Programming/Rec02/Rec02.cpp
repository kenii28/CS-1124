/*
Kenneth Huynh
CS 1124
Rec02

This program stores the values of the file line by line into a vector then outputs them to the screen using two different for loops.
*/

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

void openFile(ifstream& ifs, string& fileName);
void fillVec(ifstream& ifs, vector<vector<string>>& vectorOfVectors);
void displayFor1(const vector<vector<string>>& vectorOfVectors);
void displayFor2(const vector<vector<string>>& vectorOfVectors);

int main()
{
	string fileName = "Rec02text.txt";

	ifstream ifs;

	openFile(ifs, fileName);

	vector <vector<string>> vectorOfVectors;
	fillVec(ifs, vectorOfVectors);

	displayFor1(vectorOfVectors);
	displayFor2(vectorOfVectors);

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

void fillVec(ifstream& ifs, vector<vector<string>>& vectorOfVectors)
{
	string chemicalName;
	string chemicalFormula;

	while (ifs >> chemicalName >> chemicalFormula)
	{
		vector <string> moleculeVector;
		moleculeVector.push_back(chemicalName);
		moleculeVector.push_back(chemicalFormula);
		vectorOfVectors.push_back(moleculeVector);
	}

	
}

void displayFor1(const vector<vector<string>>& vectorOfVectors)
{
	for (size_t index = 0; index < vectorOfVectors.size(); ++index)
		cout << vectorOfVectors[index][1] << " " << vectorOfVectors[index][0] << endl;

}

void displayFor2(const vector<vector<string>>& vectorOfVectors)
{
	for (vector<string> smallVector : vectorOfVectors)
	{
		cout << smallVector[1] << " " << smallVector[0] << endl;
	
	}
}