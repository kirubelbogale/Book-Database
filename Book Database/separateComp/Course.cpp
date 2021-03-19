// Course.cpp

#include "Course.h"
#include <cassert>

Course::Course(const string& course_name)
: name(course_name)
{ }

// return course's name
string Course::get_name() const {
	return name;
}

// returns current number of students in the course
int Course::num_students() const {
	return roster.size();
}

// adds a Student to the course; if a Student with the same ID is already
// in the course, then s is *not* added
void Course::add_student(Student* s) {
	assert(s != nullptr);

	// if s is already a student in the course, then don't add
	for(Student* p : roster) {
		if (p->get_id() == s->get_id()) {
			return;
		}
	}

	roster.push_back(s);
}
