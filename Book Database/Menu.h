// Menu.h

#ifndef MENU_H
#define MENU_H

#include "Book.h"
#include "Database.h"
#include <algorithm>
#include <fstream>

using namespace std;

class Menu {
	string name;

public:

	Menu();

	// Sub-menu to add a book to the database
	void addMenu(Database& record);

	// deleting menu
	void deleteMenu(Database& record);

	// updating menu
	void updateMenu(Database& record);

	// view and search (sorted) menu
	void searchMenu(Database& record);

	// load and save menu
	void fileMenu(Database& record);

	// Create the main menu
	void mainMenu();

}; // class Menu

bool isEntry(Database record, Book b) {
	for (Book x : record.allBooks()) {
		if (x.get_id() == b.get_id()) {
			return true;
		}
	}
	return false;
}

#endif
