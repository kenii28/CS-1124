#include "Registar.h"
#include "course.h"
#include "student.h"

namespace BrooklynPoly
{
	Registar::Registar() {}

	void Registar::printReport() const {
		std::cout << "Students:\n" << std::endl;
		for (Student* student : students) {
			std::cout << student->getName() << std::endl;
		}
		std::cout << "Courses:\n" << std::endl;
		for (Course* course : courses) {
			std::cout << course->getName() << std::endl;
		}
	}

	size_t Registar::checkCourse(const std::string& name) const {
		for (size_t i = 0; i < courses.size(); ++i) {
			if (courses[i]->getName() == name) {
				return i;
			}
		}
		return courses.size();
	}

	size_t Registar::checkStudent(const std::string& name) const {
		for (size_t i = 0; i < students.size(); ++i) {
			if (students[i]->getName() == name) {
				return i;
			}
			else { // student doesn't exist
				return students.size();
			}

		}
	}

	void Registar::addCourse(const std::string& name) {
		size_t i = Registar::checkCourse(name);
		if (i == courses.size()) {
			Course* ptr = new Course(name);
			courses.push_back(ptr);
		}
	}

	void Registar::addStudent(const std::string& name) {
		size_t i = Registar::checkStudent(name);
		if (i == students.size()) {
			Student* ptr = new Student(name);
			students.push_back(ptr);
		}
	}

	void Registar::enrollStudentInCourse(const std::string& student, const std::string& course) {
		size_t courseCheck = checkCourse(course);
		size_t studentCheck = checkStudent(course);
		if ((studentCheck != Registar::students.size()) && (courseCheck != Registar::courses.size())) {
			courses[courseCheck]->addStudent(students[studentCheck]);
			students[studentCheck]->addCourse(courses[courseCheck]);
		}
	}

	void Registar::cancelCourse(const std::string& name) {
		size_t courseCheck = checkCourse(name);
		courses[courseCheck]->cancel();
		delete courses[courseCheck];
		courses[courseCheck] = courses[courses.size() - 1];
		courses.pop_back();
	}

	void Registar::purge() {
		for (size_t i = 0; i < students.size(); ++i) {
			delete students[i];
		}
		students.clear();

		for (size_t i = 0; i < courses.size(); ++i) {
			delete courses[i];
		}
		courses.clear();
	}
}