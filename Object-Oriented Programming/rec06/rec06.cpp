/*
Kenneth Huynh
CS 1124
Rec06

This program contains the classes for modeling a lab for rec06.
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Student
{
public:
	Student(const string& name)
		: name(name), grades(13, -1) {}

	void display() // displays the list of student grades
	{
		cout << "Student: " << name << "; Grades: ";
		for (int grade : grades)
		{
			cout << grade << " ";
		}
		cout << endl;
	}

	void changeGrade(const int grade, const size_t week) // changes the grade of the student of the given week
	{
		grades[week] = grade;
	}

	string getName() const // gets the student's name
	{
		return name;
	}
private:
	string name;
	vector<int> grades;
};

class Time
{
public:
	// constructor
	Time(const string& day, const int hour)
		: day(day), hour(hour) {}

	void display() // displays time
	{
		cout << day << " ";

		if (hour < 12)
		{
			cout << hour << "AM" << endl;
		}
		else if (hour == 0)
		{
			cout << "12AM" << endl;
		}
		else // PM TIME
		{
			int pmTime;
			pmTime = hour - 12;
			cout << pmTime << "PM" << endl;
		}
	}

private:
	const string day;
	const int hour;

};

class Section
{
public:
	// constructor
	Section(const string& name, const string& day, const int time)
		: sectionName(name), time(day, time) {}

	void addStudent(const string& student) // adds student pointer to the vector of student pointers
	{
		Student* studentPtr = new Student(student);
		studentVec.push_back(studentPtr);
	}

	void addGrades(const string& student, const int grade, const size_t week) // adds grades to the student
	{
		for (size_t index = 0; index < studentVec.size(); ++index)
		{
			if (studentVec[index]->getName() == student)
			{
				studentVec[index]->changeGrade(grade, week);
			}
			
		}
		
	}

	void displayStudents() // displays students
	{
		for (size_t index = 0; index < studentVec.size(); ++index)
		{ 
			studentVec[index]->display();
		}
		
	}

	void display() // displays section
	{
		cout << "Section: " << sectionName << "; ";
		time.display();
		displayStudents();
	}

	void reset() // clears all the student data
	{
		for (Student* studentPtr : studentVec)
		{
			delete studentPtr;
		}
		studentVec.clear();
	}
private:
	string sectionName;
	Time time;
	vector<Student*> studentVec;

};


class LabWorker
{
public:
	// constructor
	LabWorker(const string& name, Section* = nullptr)
		: name(name) {}

	void addGrade(const string& student, const int grade, const size_t week) // adds grade to a student
	{
		section->addGrades(student, grade, week);
	}

	void addSection(Section& sectionName) // add a section to the lab worker
	{
		section = &sectionName;
	}

	void displayGrades() // displays the grades of the section's students
	{
		cout << name << " has ";
		section->display();
	}
private:
	string name;
	Section* section;
};

int main()
{
	// lab workers
	LabWorker moe("Moe");
	LabWorker jane("Jane");

	// sections and setup and testing
	Section secA2("A2", "Tuesday", 16);
	//secA2.loadStudentsFromFile( "A2.txt" );
	secA2.addStudent("John");
	secA2.addStudent("George");
	secA2.addStudent("Paul");
	secA2.addStudent("Ringo");

	cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked
	secA2.display();          // YOU'll DO THIS LATER AS: cout << secA2 << endl;
	moe.addSection(secA2);
	moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked

	Section secB3("B3", "Thursday", 11);
	//secB3.loadStudentsFromFile( "B3.txt" );
	secB3.addStudent("Thorin");
	secB3.addStudent("Dwalin");
	secB3.addStudent("Balin");
	secB3.addStudent("Kili");
	secB3.addStudent("Fili");
	secB3.addStudent("Dori");
	secB3.addStudent("Nori");
	secB3.addStudent("Ori");
	secB3.addStudent("Oin");
	secB3.addStudent("Gloin");
	secB3.addStudent("Bifur");
	secB3.addStudent("Bofur");
	secB3.addStudent("Bombur");

	cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
	secB3.display();          // YOU'll DO THIS LATER AS: cout << secB3 << endl;
	jane.addSection(secB3);
	jane.displayGrades();      // here the modeler-programmer checks that adding Instructor worked


	// setup is complete, now a real world scenario can be written in the code
	// [NOTE: the modeler-programmer is only modeling joe's actions for the rest of the program]

	// week one activities  
	cout << "\nModeling week: 1\n";
	moe.addGrade("John", 7, 1);
	moe.addGrade("Paul", 9, 1);
	moe.addGrade("George", 7, 1);
	moe.addGrade("Ringo", 7, 1);
	cout << "End of week one\n";
	moe.displayGrades();

	// week two activities
	cout << "\nModeling week: 2\n";
	moe.addGrade("John", 5, 2);
	moe.addGrade("Paul", 10, 2);
	moe.addGrade("Ringo", 0, 2);
	cout << "End of week two\n";
	moe.displayGrades();

	//test that reset works  // NOTE: can we check that the heap data was dealt with?
	cout << "\ntesting reset()\n";
	secA2.reset();
	secA2.display();
	moe.displayGrades();

	system("pause");
}