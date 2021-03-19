# ADD FILES AS YOU GO ALONG

final: Book.o Database.o Menu.o
	g++ -o final Book.o Database.o Menu.o

Book: Book.h Book.cpp
	g++ -c Book.cpp

Database: Database.h Database.cpp
	g++ -c Database.cpp

Menu: Menu.h Menu.cpp
	g++ -c Menu.cpp

clean:
	rm -f final Book.o

CPPFLAGS = -std=c++14 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g
