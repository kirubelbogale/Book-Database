// Student.cpp

#include "Student.h"
#include <iostream>
#include <string>

Student::Student(const string& student_name, const string& student_id)
: name(student_name), id(student_id)
{ }

string Student::get_name() const {
	return name;
}

string Student::get_id() const {
	return id;
}

string Student::to_str() const {
	return "(\"" + get_name() + "\", " + get_id() + ")";
}

// << operator for Student objects
ostream& operator<<(ostream& out, const Student& s) {
	out << s.to_str();
	return out;
}
