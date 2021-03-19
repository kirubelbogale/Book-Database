// Book.cpp

#include "Book.h"


Book::Book(const string& t, const string& a, const int& d, const string& b, const string& i, const int& p)
: title(t), author(a), publicationDate(d), bookType(b), ISBN(i), pages(p)
{ }

Book::Book()
: title(""), author(""), publicationDate(0), bookType(""), ISBN(""), pages(0)
{ }

string Book::get_title() const {
	return title;
}

string Book::get_author() const {
	return author;
}

int Book::get_date() const {
	return publicationDate;
}

string Book::get_type() const {
	return bookType;
}

string Book::get_id() const {
	return ISBN;
}

int Book::get_pages() const {
	return pages;
}

void Book::set_title(const string& s) {
	title = s;
}

void Book::set_author(const string& x) {
	author = x;
}

void Book::set_date(const int& year) {
	publicationDate = year;
}

void Book::set_type(const string& type) {
	bookType = type;
}

void Book::set_id(const string& id) {
	ISBN = id;
}

void Book::set_pages(const int& num) {
	if (num > 0) {
		pages = num;
	}
}

string Book::to_str() {
	return "[" + get_title()  + ", "
			   + get_author() + ", "
			   + to_string(get_date()) + ", "
			   + get_type() + ", "
			   + get_id() + ", "
			   + to_string(get_pages()) + "]";
}

ostream& operator<<(ostream& out, Book& b) {
	out << b.to_str();
	return out;
}
