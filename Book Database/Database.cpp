// Database.cpp

#include "Database.h"
#include <cassert>

Database::Database()
: databaseName("")
{ }

vector<Book> Database::allBooks() {
	return bookRecords;
}

int Database::num_books() const {
	return bookRecords.size();
}

void Database::add_book(Book b) {

	for(Book x : bookRecords) {
		if (x.get_id() == b.get_id()) {
			return;
		}
	}

	bookRecords.push_back(b);
}

void Database::delete_book(Book b) {

	int element = -1;
	for(Book x : bookRecords) {
		element++;
		if (x.get_id() == b.get_id()) {
			bookRecords.erase(bookRecords.begin() + element);
		}
	}
}

vector<Book> Database::search_by_title(string title) {
	vector<Book> results;

	for (int i = 0; i < bookRecords.size(); i++) {
		if (title == bookRecords.at(i).get_title()) {
			results.push_back(bookRecords.at(i));
		}
	}
	return results;
}

vector<Book> Database::search_by_author(string author) {
	vector<Book> results;

	for (int i = 0; i < bookRecords.size(); i++) {
		if (author == bookRecords.at(i).get_author()) {
			results.push_back(bookRecords.at(i));
		}
	}
	return results;
}

vector<Book> Database::search_by_date(int year) {
	vector<Book> results;

	for (int i = 0; i < bookRecords.size(); i++) {
		if (year == bookRecords.at(i).get_date()) {
			results.push_back(bookRecords.at(i));
		}
	}
	return results;
}

vector<Book> Database::search_by_type(string type) {
	vector<Book> results = {};

	for (int i = 0; i < bookRecords.size(); i++) {
		if (type == bookRecords.at(i).get_type()) {
			results.push_back(bookRecords.at(i));
		}
	}
	return results;
}

vector<Book> Database::search_by_id(string id) {
	vector<Book> results;

	for (int i = 0; i < bookRecords.size(); i++) {
		if (id == bookRecords.at(i).get_id()) {
			results.push_back(bookRecords.at(i));
		}
	}
	return results;
}

vector<Book> Database::search_by_pages(int pages) {
	vector<Book> results;

	for (int i = 0; i < bookRecords.size(); i++) {
		if (pages == bookRecords.at(i).get_pages()) {
			results.push_back(bookRecords.at(i));
		}
	}
	return results;
}

vector<int> Database::updateSearchID(string id) {
	vector<int> res;
	for (int i = 0; i < bookRecords.size(); i++) {
		if (id == bookRecords.at(i).get_id()) {
			res.push_back(i);
		}
	}
	return res;
}
