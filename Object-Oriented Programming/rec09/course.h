#ifndef COURSE_H
#define COURSE_H
#include "student.h"
#include <string>
#include <vector>

namespace BrooklynPoly
{
	class Student;
	class Course
	{
		std::string name;
		std::vector<Student*> students;
	public:
		Course(const std::string& name);

		void display() const;
		std::string getName() const;
		void addStudent(Student *student);
		void cancel();
	};
}


#endif