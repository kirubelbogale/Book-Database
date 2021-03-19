// rand_book.cpp

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

struct Book {
	string title;
	string author;
	int year;
	string type;
	string isbn10;
	int pages;
};

ostream& operator<<(ostream& out, const Book& b) {
	out << "[" << b.title  << ", "
	           << b.author << ", "
	           << b.year   << ", "
	           << b.type   << ", "
	           << b.isbn10 << ", "
	           << b.pages  << "]";
	return out;
}

// rand() returns a non-negative int
// lo <= rand(lo, hi) <= hi
int rand(int lo, int hi) {
	int result = lo + rand() % (hi - lo + 1);
	assert(lo <= result && result <= hi);
	return result;
}

// 0 <= rand(hi) <= hi
int rand(int hi) {
	return rand(0, hi);
}

// Pre-condition:
//    v.size() > 0
// Post-condition:
//    returns a random string in v
string rand_choice(const vector<string>& v) {
	assert(v.size() > 0);
	int r = rand(v.size() - 1);
	assert(0 <= r && r < v.size());
	return v[r];
}

int rand_year() {
	return rand(1850, 2020);
}

int rand_pages() {
	return rand(10, 500);
}

vector<string> book_type = {"hardcover", "softcover", "digital"};

string rand_type() {
	return rand_choice(book_type);
}

vector<string> first_name = {"hermione", "harry", "leia", "ethel", "kirk", "asa", "john",
                             "william", "emily", "hart"};
vector<string> last_name = {"smith", "jones", "wu", "singh", "park", "mcdonald", "crane",
                            "hogan", "stevenson", "john"};

string rand_author() {
	string first = rand_choice(first_name);
	string last = rand_choice(last_name);
	return first + " " + last;
}

vector<string> syllables = {"flurb", "groop", "ingbo", "stram", "nur", "grugg", "plem",
                            "zetch", "prif", "koog", "blif", "erbom", "slub", "nargo",
                            "snoof", "trummos"};

string rand_word() {
	int r = rand(1, 2);
	switch (r) {
		case 1: return rand_choice(syllables);
		case 2: return rand_choice(syllables) + rand_choice(syllables);
	}
	// should never get here
	assert(false);  // crash on purpose
	return "";
}

string rand_title() {
	int r = rand(1, 6);
	switch (r) {
		case 1: return "the " + rand_word();
		case 2: return "a " + rand_word() + " to " + rand_word();
		case 3: return "from " + rand_word() + " to " + rand_word() + "ternity";
		case 4: return "a " + rand_word() + " for all " + rand_word() + "s";
		case 5: return "harry potter and the " + rand_word() + " " + rand_word();
		case 6: return "the big book of " + rand_word() + "s";
		default: return rand_word();
	}
}

// simple random ISBN10: first 9 digits are random, last digit is the check
// digit (could be 'X')
string rand_ISBN10() {
	string result;
	int checksum = 0;
	// first 9 digits are random
	for(int i = 0; i < 9; i++) {
		int r = rand(0, 9);
		checksum += (10 - i) * r;
		result += to_string(r);
	}

	// calculate check digit
	int check_digit = checksum % 11;
	if (check_digit == 10) {
		result += "X";
	} else {
		result += to_string(check_digit);
	}

	assert(result.size() == 10);
	return result;
}

Book rand_book() {
	Book result{rand_title(),
				rand_author(),
				rand_year(),
				rand_type(),
				rand_ISBN10(),
				rand_pages()};
	return result;
}



int main() {
	srand(time(NULL));

	for(int i = 0; i < 1000; i++) {
		cout << rand_book() << "\n";
	}
}
