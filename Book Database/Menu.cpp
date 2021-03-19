// menu.cpp

#include "Menu.h"

using namespace std;

Menu::Menu()
: name("")
{ }


void Menu::addMenu(Database& record) {
	cout << "Add a book to the database:\n";

	bool done = false;
	while (!done) {

		// take user input for every part of book record
		cout << "Enter the title of the book you would like to add: ";
		string addTitle;
		cin.ignore();
		getline(cin, addTitle);

		cout << "Enter the name of the author (FORMAT: \"first last\"): ";
		string author;
		getline(cin, author);

		cout << "Enter the year this book was published: ";
		int year = 0;
		cin >> year;
		bool x = false;
		while (!x) {
			if (year < 1850) {
				cout << "Year must be greater than 1849. Please try again: ";
				cin >> year;
			} else {
				x = true;
			}
		}

		cout << "Is this a hardcover, softcover, or digital book?\n"
			 << "(Please enter option exactly as listed): ";
		string type;
		cin >> type;
		bool e = false;
		while (!e) {
			if (type == "hardcover" || type == "softcover" || type == "digital") {
				e = true;
			} else {
				cout << "Must be hardcover, softcover, or digital: ";
				cin >> type;
			}
		}

		cout << "Enter the International Standard Book Number (ISBN).\n";
		cout << "Please Note, the ISBN must be 10 digits with no spaces/hyphens: ";
		string id;
		cin >> id;

		bool f = false;
		while (!f) {
			if (id.length() == 10) {
				f = true;
			} else {
				cout << "ISBN must be exactly 10 digits with no spaces or hyphens. Try again: ";
				cin >> id;
			}
		}

		cout << "Enter the number of pages in this book: ";
		int pages = 0;
		cin >> pages;
		bool y = false;
		while (!y) {
			if (pages <= 0) {
				cout << "There must be at least one page. Please try again: ";
				cin >> pages;
			} else {
				y = true;
				cout << "\n";
			}
		}

		// print user input and confirm before adding
		cout << "These is the information you've entered:\n";
		cout << "Title: " << addTitle << "\n";
		cout << "Author: " << author << "\n";
		cout << "Publication Date: " << year << "\n";
		cout << "Book Type: " << type << "\n";
		cout << "ISBN: " << id << "\n";
		cout << "Page count: " << pages << "\n\n";

		bool isCorrect = false;
		while(!isCorrect) {

			cout << "If this information is correct, please enter \"yes\".\n"
				 << "If you would like to redo your entry, please enter \"redo\": ";

			string confirm;
			cin >> confirm;
			if (confirm == "yes") {

				Book newAddition(addTitle, author, year, type, id, pages);
				if (isEntry(record, newAddition)) {
					cout << "This book is already in the database, please try a different book.\n";
					isCorrect = true;
				} else {
					record.add_book(newAddition);
					cout << "Book added to database.\n\n";
					done = true;
					isCorrect = true;
				}

			} else if (confirm == "redo") {
				isCorrect = true;
			} else {
				bool check = false;
				while (!check) {
					cout << "Please enter either \"yes\" or \"redo\".";
					cin >> confirm;
					if (confirm == "yes" || confirm == "redo") {
						check = true;
					}
				}
			}
		}
	}
}

void Menu::deleteMenu(Database& record) {
	cout << "Delete a book from the database:\n\n";

	bool done = false;
	while (!done) {
		if(record.num_books() == 0) {
			cout << "The database is empty, therefore there are no books to delete.\n\n";
			done = true;
			break;
		}

		cout << "Please enter the ISBN of the book you want to delete: ";
		string entry;
		cin >> entry;
		cout << "\n";

		vector<Book> res = record.search_by_id(entry);
		if (res.empty()) {
			cout << "This ISBN does not match any book in the database. Please try again.\n";
			
		} else {
			bool confirmation = false;
			while (!confirmation) {
				cout << "Is this the book you want to delete? (Y/N)\n";
				cout << res.at(0).to_str() << "\n";
				string yesOrNo;
				cin >> yesOrNo;

				if (yesOrNo == "y") {
					confirmation = true;
					for(Book x : record.allBooks()) {
						if (res.at(0).get_id() == x.get_id()) {
							record.delete_book(x);
							cout << "This book has been deleted.\n";
							done = true;
						}
					}

				} else if (yesOrNo == "n") {
					confirmation = true;
					cout << "Please make your entry again\n";
					
				} else {
					cout << "Enter either y or n.\n";
				}
			}
		}
	}
}

void Menu::updateMenu(Database& record) {
	cout << "Update a piece of information from a book\n\n";

	bool done = false;
	while (!done) {
		if(record.num_books() == 0) {
			cout << "The database is empty, therefore there are no books to update.\n\n";
			done = true;
			break;
		}

		cout << "Please enter the ISBN of the book you want to make changes to: ";
		string book;
		cin >> book;

		vector<Book> res = record.search_by_id(book);
		if(res.empty()) {
			cout << "This ISBN does not match anything in the database, please try again.\n";
		} else {

			cout << "Which part of the book record do you want to update?\n";
			cout << "Please select from one of the following: title, author, date, type, isbn, pages\n";
			string updater;
			cin >> updater;
			cout << "\n";

			if (updater == "title") {
				cout << "What do you want to change the title to? ";
				string newTitle;
				cin.ignore();
				getline(cin, newTitle);

				vector<int> titleElem = record.updateSearchID(book);
				record.allBooks().at(titleElem.at(0)).set_title(newTitle);
				cout << "\n";
				cout << "The title of this book is now: " << record.allBooks().at(titleElem.at(0)).get_title() << "\n\n";
				done = true;

			} else if (updater == "author") {
				cout << "What do you want to change the author's name to? ";
				string newAuthor;
				getline(cin, newAuthor);

				vector<int> authorElem = record.updateSearchID(book);
				record.allBooks().at(authorElem.at(0)).set_author(newAuthor);
				cout << "\n";
				cout << "The updated author of this book is: " << record.allBooks().at(authorElem.at(0)).get_author() << "\n\n";
				done = true;

			} else if (updater == "date") {
				cout << "What year do you want to change the publication date to? ";
				int newDate = 0;
				cin >> newDate;
				cout << "\n";

				bool a = false;
				while (!a) {
					if (newDate < 1850) {
						cout << "Please enter a year greater than 1849: ";
						cin >> newDate;
						cout << "\n";
					} else {
						a = true;
					}
				} 

				vector<int> dateElem = record.updateSearchID(book);
				record.allBooks().at(dateElem.at(0)).set_date(newDate);
				cout << "\n";
				cout << "The publication date is now: " << record.allBooks().at(dateElem.at(0)).get_date() << "\n\n";
				done = true;

			} else if (updater == "type") {
				bool typeCheck = false;
				while (!typeCheck) {
					cout << "What do you want to change this book's type to?\n";
					cout << "(digital, hardcover, softcover): ";
					string newType;
					cin >> newType;

					if (newType == "digital") {
						vector<int> typeElem = record.updateSearchID(book);
						record.allBooks().at(typeElem.at(0)).set_type(newType);
						cout << "\n";
						cout << "The book type has been changed to: " << record.allBooks().at(typeElem.at(0)).get_type() << "\n\n";
						done = true;
						typeCheck = true;

					} else if (newType == "hardcover") {
						vector<int> typeElem = record.updateSearchID(book);
						record.allBooks().at(typeElem.at(0)).set_type(newType);
						cout << "\n";
						cout << "The book type has been changed to: " << record.allBooks().at(typeElem.at(0)).get_type() << "\n\n";
						done = true;
						typeCheck = true;

					} else if (newType == "softcover") {
						vector<int> typeElem = record.updateSearchID(book);
						record.allBooks().at(typeElem.at(0)).set_type(newType);
						cout << "\n";
						cout << "The book type has been changed to: " << record.allBooks().at(typeElem.at(0)).get_type() << "\n\n";
						done = true;
						typeCheck = true;

					} else {
						cout << "Please enter either digital, softcover, or hardcover.\n";
					}
				}

			} else if (updater == "isbn") {
				bool x = false;
				while (!x) {
					cout << "Enter the ISBN you want to update to: ";
					string newID;
					cin >> newID;

					vector<Book> idCheck = record.search_by_id(newID);
					if (idCheck.empty()) {
						vector<int> idElem = record.updateSearchID(book);
						record.allBooks().at(idElem.at(0)).set_id(newID);
						cout << "\n";
						cout << "The ISBN has been changed to: " << record.allBooks().at(idElem.at(0)).get_id() << "\n\n";
						done = true;
						x = true;
					} else {
						cout << "This ISBN is already is the same as another book. Please try again.\n";
					}
				}
			} else if (updater == "pages") {
				bool y = false;
				while (!y) {
					cout << "Enter the updated number of pages: ";
					int newPages = 0;
					cin >> newPages;
					if (newPages <= 0) {
						cout << "Please enter a number greater than 0.\n";
					} else {
						vector<int> pagesElem = record.updateSearchID(book);
						record.allBooks().at(pagesElem.at(0)).set_pages(newPages);
						cout << "\n";
						cout << "The number of pages is now: " << record.allBooks().at(pagesElem.at(0)).get_pages() << "\n\n";
						done = true;
						y = true;
					}
				}

			} else {
				cout << "Please enter your choice again. Note that it must be entered exactly as shown above.\n";
			}
		}
	}
}

void Menu::searchMenu(Database& record) {
	bool done = false;
	while (!done) {
		cout << "To view a list of the raw data in this database, please enter \"view\".\n";
		cout << "To search for a list of books that meet certain criteria, please enter \"search\": ";
		string input;
		cin >> input;
		cout << "\n";

		if (input == "view") {
			for (int i = 0; i < record.allBooks().size(); i++) {
				cout << record.allBooks().at(i).to_str() << "\n";
			}
			done = true;

		} else if (input == "search") {
			bool searchCheck = false;
			while (!searchCheck) {
				cout << "Enter one of the following options to search by that parameter: \n";
				cout << "(title, author, date, type, isbn, pages)\n";
				string search;
				cin >> search;
				cout << "\n";

				if (search == "title") {
					bool titleCheck = false;
					while (!titleCheck) {
						cout << "Enter the title of the book you want to view: ";
						string title;
						getline(cin, title);
						cout << "\n";

						vector<Book> titleRes = record.search_by_title(title);
						if (titleRes.empty()) {
							cout << "No books match this search. Please try again.\n";
							titleCheck = true;

						} else {
							// std::sort(begin(titleRes), end(titleRes));
							cout << "List of " << titleRes.size() << " book(s) that match(es) this search:\n";
							for (int i = 0; i < titleRes.size(); i++) {
								cout << titleRes.at(i).to_str();
							}
							titleCheck = true;
							searchCheck = true;
							done = true;
						}
					}
					
				} else if (search == "author") {
					bool authorCheck = false;
					while (!authorCheck) {
						cout << "Enter the author you would like to search for: ";
						string author;
						getline(cin, author);
						cout << "\n";

						vector<Book> authorRes = record.search_by_author(author);
						if(authorRes.empty()) {
							cout << "No author matches this search. Please try again.\n";
							authorCheck = true;

						} else {
							// std::sort(begin(authorRes), end(authorRes));
							cout << "List of " << authorRes.size() << " book(s) written by " << author << ":\n";
							for (int i = 0; i < authorRes.size(); i++) {
								cout << authorRes.at(i).to_str();
							}
							authorCheck = true;
							searchCheck = true;
							done = true;
						}
					}

				} else if (search == "date") {
					bool dateCheck = false;
					while (!dateCheck) {
						cout << "Enter the year you would like to search: ";
						int year = 0;
						cin >> year;

						bool a = false;
						while (!a) {
							if (year < 1850) {
							cout << "Year must be greater than 1850. Please try again: ";
							cin >> year;
							} else {
								a = true;
							}
						}

						vector<Book> dateRes = record.search_by_date(year);
						if (dateRes.empty()) {
							cout << "No books published in this year. Please try again.\n";
							dateCheck = true;

						} else {
							// std::sort(begin(dateRes), end(dateRes));
							cout << "List of " << dateRes.size() << " book(s) published in " << year << ":\n";
							for (int i = 0; i < dateRes.size(); i++) {
								cout << dateRes.at(i).to_str();
							}
							dateCheck = true;
							searchCheck = true;
							done = true;
						}

					}

				} else if (search == "type") {
					bool typeCheck = false;
					while (!typeCheck) {
						cout << "Enter the type of book you want to search for: ";
						string type;
						cin >> type;
						cout << "\n";

						vector<Book> typeRes = record.search_by_type(type);
						if (typeRes.empty()) {
							cout << "No books of this type. Please try again.\n";
							typeCheck = true;

						} else {
							// std::sort(begin(typeRes), end(typeRes));
							cout << "List of books that are " << type << ":\n";
							for (int i = 0; i < typeRes.size(); i++) {
								cout << typeRes.at(i).to_str();
							}
							typeCheck = true;
							searchCheck = true;
							done = true;
						}
					}

				} else if (search == "isbn") {
					bool idCheck = false;
					while (!idCheck) {
						cout << "Enter the ISBN of the book you want to find: ";
						string id;
						cin >> id;
						cout << "\n";

						vector<Book> idRes = record.search_by_id(id);
						if(idRes.empty()) {
							cout << "No book matches this ISBN. Please try again.\n";
							idCheck = true;

						} else {
							// std::sort(begin(idRes), end(idRes));
							cout << "Matching book to entered ISBN:\n";
							cout << idRes.at(0).to_str();
						}
						idCheck = true;
						searchCheck = true;
						done = true;
					}

				} else if (search == "pages") {
					bool pageCheck = false;
					while (!pageCheck) {
						cout << "Enter the number of pages you wish to find matches to: ";
						int pages = 0;
						cin >> pages;
						cout << "\n";

						bool b = false;
						while (!b) {
							if (pages <= 0) {
								cout << "There must be at least one page. Try again: ";
								cin >> pages;
								cout << "\n";
							} else {
								b = true;
							}
						}

						vector<Book> pageRes = record.search_by_pages(pages);
						if (pageRes.empty()) {
							cout << "No book with this number of pages. Please try again.\n";
							pageCheck = true;

						} else {
							// std::sort(begin(pageRes), end(pageRes));
							cout << "Books with " << pages << "pages:\n";
							for (int i = 0; i < pageRes.size(); i++) {
								cout << pageRes.at(i).to_str();
							}
							pageCheck = true;
							searchCheck = true;
							done = true;
						}
					}

				} else {
					cout << "Please try again.\n";
				} 
			}

		} else {
			cout << "Please enter either \"view\" or \"search\".\n";
		}
	}
}

void Menu::fileMenu(Database& record) {
	bool done = false;
	while (!done) {
		cout << "Do you want to load text from a file or save text to a file?\n";
		cout << "(Enter either \"load\" or \"save\"): ";
		string input;
		cin >> input;
		cout << "\n";

		if (input == "load") {
			cout << "Loading file...\n";
			ifstream inFile("randomBooks.txt");
			if(inFile.fail()) {
				cout << "Unable to open data file.\n";
				exit(EXIT_FAILURE);
			}

			while (true) {

				string title;
				string author;
				int date = 0;
				string type;
				string id;
				int pages = 0;

				std::getline(inFile, title);
				if(inFile.fail() && inFile.eof()) {
					break;
				}

				std::getline(inFile, author);
				inFile >> date;
				inFile >> type;
				inFile >> id;
				inFile >> pages;

				Book book(title, author, date, type, id, pages);
				record.add_book(book);

				if(inFile.fail()) {
					cout << "Unable to read file.\n";
					exit(EXIT_FAILURE);
				}
			}
			inFile.close();
			cout << "Database loaded.\n";
			done = true;

		} else if (input == "save") {
			ofstream outFile("output.txt");
			for (int i = 0; i < record.allBooks().size(); i++) {
				outFile << record.allBooks().at(i).to_str() << "\n";
			}
			outFile.close();
			done = true;

		} else {
			cout << "Please try again.\n";
		}
	}
}

void Menu::mainMenu() {
	// title screen
	cout << "*************************************\n";
	cout << "Welcome to the CMPT 135 Book Database!\n";
	cout << "*************************************\n"
		 << "Please select one of the following options:\n\n";

	//Initialize Database
	Database record;

	bool done = false;
	while (!done) {
		cout << "If you want to add a book to the database, enter the word, \"add\"\n";
		cout << "To delete a book, type \"delete\"\n";
		cout << "To update any part of a book record, please enter, \"update\"\n";
		cout << "If you want to search for a particular book in the database, type, \"search\"\n";
		cout << "To load or save a file from a database, enter \"file\"\n";
		cout << "If you want to exit the database, enter \"0\". This will end the program.\n";
		cout << "Note that for the entire database, everything you type MUST be lowercase\n";

		string firstChoice;
		cin >> firstChoice;
		cout << "\n";

		if (firstChoice == "add") {
			addMenu(record);

		} else if (firstChoice == "delete") {
			deleteMenu(record);

		} else if (firstChoice == "update") {
			updateMenu(record);

		} else if (firstChoice == "search") {
			searchMenu(record);

		} else if (firstChoice == "file") {
			fileMenu(record);

		} else if (firstChoice == "0") {
			cout << "Goodbye!\n";
			done = true;
			exit(EXIT_SUCCESS);

		} else {
			cout << "Please try again.\n";
		}
	}
}

int main() {
	Menu menu;
	menu.mainMenu();
}
