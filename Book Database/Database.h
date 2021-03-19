// Database.h

#ifndef DATABASE_H
#define DATABASE_H

#include "Book.h"
#include <vector>

using namespace std;

class Database {
	string databaseName;
	vector<Book> bookRecords;

public:

	Database();

	// return the database as a vector of books
	vector<Book> allBooks();

	// return number of books in database
	int num_books() const;

	// add a book to the database without allowing duplicates
	void add_book(Book b); 

	// delete a book from the database
	void delete_book(Book b);

	// search for book records
	vector<Book> search_by_title(string title);
	vector<Book> search_by_author(string author);
	vector<Book> search_by_date(int year);
	vector<Book> search_by_type(string type);
	vector<Book> search_by_id(string id);
	vector<Book> search_by_pages(int pages);

	// search function meant only for update menu
	vector<int> updateSearchID(string id);

}; // class Database

#endif
