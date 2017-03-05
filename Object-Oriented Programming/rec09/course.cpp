#include "student.h"
#include <string>
#include <vector>
#include <iostream>

namespace BrooklynPoly
{
	Course::Course(const std::string& name) : name(name) {}

	void Course::display() const {
		std::cout << name << std::endl;
		for (Student* student : students) {
			std::cout << student->getName() << std::endl;
		}
	}

	void Course::addStudent(Student* student) {
		Course::students.push_back(student);
	}

	void Course::cancel() {
		for (Student* student : students) {
			student->removeCourse(this->getName());
		}
	}
	std::string Course::getName() const {
		return Course::name;
	}
}