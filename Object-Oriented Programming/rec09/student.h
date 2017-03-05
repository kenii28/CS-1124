#ifndef STUDENT_H
#define STUDENT_H
#include "course.h"
#include <string>
#include <vector>

namespace BrooklynPoly
{
	class Course;
	class Student
	{
		std::string name;
		std::vector<Course*> classes;
	public:
		Student(const std::string& name);

		void display() const;
		std::string getName() const;
		void addCourse(Course* course);
		void removeCourse(const std::string& name);

	};
}


#endif