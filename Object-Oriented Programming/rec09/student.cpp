#include "course.h"
#include <string>
#include <vector>
#include <iostream>

namespace BrooklynPoly
{
	Student::Student(const std::string& name) : name(name) {}

	void Student::display() const {
		std::cout << name << std::endl;
		for (Course* course : classes) {
			std::cout << course->getName() << std::endl;
		}
	}

	std::string Student::getName() const {
		return Student::name;
	}

	void Student::removeCourse(const std::string& name) {
		size_t index = 0;
		for (size_t i = 0; i < classes.size(); ++i) {
			if (classes[i]->getName() == name) {
				index = i;
			}
		}
		classes[index] = classes[classes.size() - 1];
		classes.pop_back();
	}

	void Student::addCourse(Course* course) {
		Student::classes.push_back(course);
	}
}