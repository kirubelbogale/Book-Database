// Course.h

#ifndef COURSE_H
#define COURSE_H

#include "Student.h"
#include <string>
#include <vector>

using namespace std;

class Course {
	string name;
	vector<Student*> roster;
public:
	Course(const string& course_name);

	// return course's name
	string get_name() const;

	// returns current number of students in the course
	int num_students() const;

	// adds a Student to the course; if a Student with the same ID is already
	// in the course, then s is *not* added
	void add_student(Student* s);

}; // class Course

#endif
