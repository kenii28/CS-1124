/*
Kenneth Huynh
CS 1124
hw00: Caesar Cypher
This program decrypts a text file that is encrypted using the Caesar Cypher encryption.
*/

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;


void openFile(ifstream& ifs, string& fileName);
char decryptChar(char character, int rotate); //decrypt a single character
void decryptLine(string& line, int rotate);


int main()
{
	string fileName = "hw00text.txt";
	ifstream ifs;
	openFile(ifs, fileName);

	int numRotate;

	ifs >> numRotate;

	string line;
	vector<string> vecLines;

	while (getline(ifs, line))
	{
		vecLines.push_back(line);
	}


	for (string& aLine : vecLines)
	{
		decryptLine(aLine, numRotate);
	}


	for (size_t index = vecLines.size(); index > 0; --index)
	{
		cout << vecLines[index - 1] << endl;
	}
	


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

char decryptChar(char character, int rotate) //decrypt a single character
{
	char newChar;
	if (character < 97 || character > 122)
	{
		return character;
	}
	else if (character - rotate < 97)
	{
		int diff;
		int remaining;

		diff = character - 97;
		remaining = rotate - diff;
		newChar = 123 - remaining;
		return newChar;

	}
	else
	{
		newChar = character - rotate;
		return newChar;
	}
}


void decryptLine(string& line, int rotate)
{
	for (size_t index = 0; index < line.size(); ++index)
	{
		line[index] = decryptChar(line[index], rotate);
	}
}
