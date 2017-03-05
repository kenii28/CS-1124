#ifndef REGISTAR_H
#define REGISTAR_H
#include <iostream>
#include <vector>

namespace BrooklynPoly{
	class Student;
	class Course;
	class Registar
	{
		std::vector<Student*> students;
		std::vector<Course*> courses;
	public:
		Registar();

		void printReport() const;

		size_t checkCourse(const std::string& name) const;
		size_t checkStudent(const std::string& name) const;

		void addCourse(const std::string& name);
		void addStudent(const std::string& name);

		void enrollStudentInCourse(const std::string& student, const std::string& course);
		void cancelCourse(const std::string& name);

		void purge();
	};
}


#endif