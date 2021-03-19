    Full name: Kirubel Bogale
SFU student #: 301392403


Compilation Instructions
------------------------

Use the makefile in the zip folder to compile the program. To run the program in
wholly, use "make final" in the linux terminal. Here is what the makefile looks like exactly



Running Instructions
--------------------

The only notable piece of information needed to run the program is that unfortunately
all of the user input needs to be lowercase. Also, the ISBN must be a 10 digit ISBN.
Besides that, the program clearly indicates how the other user inputs should be formatted.

As for loading the database, I used the rand_book.cpp to create randomBooks.txt, which holds 100
books and is also included in the zip file

Key Features
------------

The program's best feature is that it is able to quickly find a matching book to complete
any one of the given tasks with it (using linear search), whether it be to update a part of a book or something else.


Bugs and Limitations
--------------------

The biggest limitation is the simplicity of the search functions, the issue being that the program can only search for books using one argument at a time. The sort functions also could have been more complex, and some parts of the program don't check input as well as other parts.


All People, Websites, and Sources of Help
-----------------------------------------

https://stackoverflow.com/questions/19390059/program-skips-second-cin - program was skipping one of the user inputs to add a book, used cin.ignore() to fix that problem

ifstream and ofstream - notes and labs from CMPT 130



