/*
Kenneth Huynh
CS 1124
Rec01

This program reads the given file and outputs lines as well as the number of lines and words in the file.
*/


#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	ifstream ifs("Rec01file.txt");

	//ifs.open("Rec01file.txt");

	if (!ifs)
	{
		cout << "The file doesn't exist.";
		exit(1);
	}

	string lines;
	int numLines = 0;

	while (getline(ifs, lines))
	{
		cout << lines << endl;
		++numLines;
	}
	cout << "The number of lines is: " << numLines << endl;

	ifs.close();

	//ifstream ifs("Rec01file.txt");

	ifs.open("Rec01file.txt");

	string words;
	int numWords = 0;

	while (ifs >> words)
	{
		++numWords;

	}
	
	cout << "The number of words is: " << numWords;

	ifs.close();

	ifs.open("Rec01file.txt");

	char characters;
	int numChar = 0;

	while (ifs >> characters)
	{
		cout << characters;
		++numChar;

	}

	cout << "The number of characters is: " << numChar;

	system("pause");
}