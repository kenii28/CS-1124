#include "Registar.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace BrooklynPoly;
using namespace std;

//int main() {
//
//	Registar registrar;
//
//	cout << "No courses or students added yet\n";
//	registrar.printReport();
//
//	cout << "AddCourse CS101.001\n";
//	registrar.addCourse("CS101.001");
//	registrar.printReport();
//
//	cout << "AddStudent FritzTheCat\n";
//	registrar.addStudent("FritzTheCat");
//	registrar.printReport();
//
//	cout << "AddCourse CS102.001\n";
//	registrar.addCourse("CS102.001");
//	registrar.printReport();
//
//	cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
//	registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
//	cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
//	registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
//	registrar.printReport();
//
//	cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
//	cout << "Should fail, i.e. do nothing, since Bullwinkle is not a student.\n";
//	registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
//	registrar.printReport();
//
//	cout << "CancelCourse CS102.001\n";
//	registrar.cancelCourse("CS102.001");
//	registrar.printReport();
//
//	/*
//	// [OPTIONAL - do later if time]
//	cout << "ChangeStudentName FritzTheCat MightyMouse\n";
//	registrar.changeStudentName("FritzTheCat", "MightyMouse");
//	cout << registrar << endl;  // or registrar.printReport()
//
//	cout << "DropStudentFromCourse MightyMouse CS101.001\n";
//	registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
//	cout << registrar << endl;  // or registrar.printReport()
//
//	cout << "RemoveStudent FritzTheCat\n";
//	registrar.removeStudent("FritzTheCat");
//	cout << registrar << endl;  // or registrar.printReport()
//	*/
//
//	cout << "Purge for start of next semester\n";
//	registrar.purge();
//	registrar.printReport();
//	system("pause");
//}

void openFile(ifstream& ifs, string& fileName)
{
	ifs.open(fileName);
	if (!ifs)
	{
		cout << "The file doesn't exist.";
		exit(1);
	}

}

void processFile(ifstream& ifs, Registar registrar) {
	string firstWord;
	string secondWord;
	string thirdWord;
	while (ifs >> firstWord) {
		if (firstWord == "PrintReport") {
			registrar.printReport();
		}
		else if (firstWord == "AddCourse") {
			ifs >> secondWord;
			registrar.addCourse(secondWord);
		}
		else if (firstWord == "AddStudent") {
			ifs >> secondWord;
			registrar.addStudent(secondWord);
		}
		else if (firstWord == "EnrollStudentInCourse") {
			ifs >> secondWord;
			ifs >> thirdWord;
			registrar.enrollStudentInCourse(secondWord, thirdWord);
		}
		else if (firstWord == "CancelCourse") {
			ifs >> secondWord;
			registrar.cancelCourse(secondWord);
		}
		else { // purge
			registrar.purge();
		}
	}
}

int main() {
	string fileName = "registar.txt";
	ifstream ifs;
	openFile(ifs, fileName);
	Registar registrar;
	processFile(ifs, registrar);

	system("pause");
}