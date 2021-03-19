// Book.h

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book {
	string title;
	string author;
	int publicationDate;
	string bookType;
	string ISBN;
	int pages;

public:

	Book(const string& t, const string& a, const int& d, const string& b,
		 const string& i, const int& p);

	Book();

	// return book title
	string get_title() const;

	// return author
	string get_author() const;

	// return publishing date
	int get_date() const;

	// return type
	string get_type() const;

	// return ISBN
	string get_id() const;

	// return number of pages
	int get_pages() const;

	// change book title
	void set_title(const string& s);

	// change author name
	void set_author(const string& x);

	// change publication date
	void set_date(const int& year);

	// change book type
	void set_type(const string& type);

	// update ISBN
	void set_id(const string& id);

	// change number of pages
	void set_pages(const int& num);

	// return a string representation of this book
	string to_str();

}; // class Book

ostream& operator<<(ostream& out, Book& b);

#endif
