
test: course_test.o Student.o Course.o
	g++ -o test course_test.o Student.o Course.o 

# only need to link if course_test.cpp has changed
course_test: course_test.cpp
	g++ -c course_test.cpp

# only compile if Student.h or Student.cpp has changed since last compile
Student: Student.h Student.cpp
	g++ -c Student.cpp

# only compile if Course.h or Course.cpp has changed since last compile
Course: Course.h Course.cpp
	g++ -c Course.cpp

clean:
	rm -f test course_test.o Student.o Course.o

# Set the C++ compiler options:
#   -std=c++14 compiles using the C++14 standard (or at least as 
#    much as is implemented by the compiler, e.g. for g++ see
#    http://gcc.gnu.org/projects/cxx0x.html)
#   -Wall turns on all warnings
#   -Wextra turns on even more warnings
#   -Werror causes warnings to be errors 
#   -Wfatal-errors stops the compiler after the first error
#   -Wno-sign-compare turns off warnings for comparing signed and 
#    unsigned numbers
#   -Wnon-virtual-dtor warns about non-virtual destructors
#   -g puts debugging info into the executables (makes them larger)
CPPFLAGS = -std=c++14 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g
