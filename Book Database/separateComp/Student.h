// Student.h

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {
	string name;
	string id;
public:
	Student(const string& student_name, const string& student_id);

	// return student's name
	string get_name() const;

	// return student's identification string
	string get_id() const;

	// returns a string representation of this student
	string to_str() const;

}; // class Student

// << operator for Student objects
ostream& operator<<(ostream& out, const Student& s);

#endif
