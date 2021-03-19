// course_test.cpp

#include "Course.h"
#include "Student.h"

using namespace std;

int main() {
	Course cmpt100("CMPT 100");
	Student a{"Lorraine Cooper", "9983-33"};
	Student b{"Kal Mitta", "3822-93"};
	Student c{"Pat Tibors", "9900-02"};

	cmpt100.add_student(&a);
	cmpt100.add_student(&b);
	cmpt100.add_student(&c);
	cmpt100.add_student(&a); // oops: a added twice

	cout << cmpt100.get_name() << " has " << cmpt100.num_students()
	     << " students\n";
}
