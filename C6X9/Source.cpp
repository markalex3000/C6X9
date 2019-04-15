/*  C6X9 - from Programming PRinciples and Practices using C++ Bjarn Stroustrep
Program: Input a series of up to four digits (as characters) and compose them into integers.
For example: 123 is read as the characters 1,2, and 3. The program should output "123 is 1 hundred and 
2 tens and 3 ones.  The number should be output as an integer.
*/

/*
Standard opening
*/

#include "C:\Users\mark.alexieff\source\repos\std_lib_facilities.h"

/*
global variables
*/

vector<char> user_input = { 0 };

/*
functions declarations
*/

bool get_user_input(vector<char>& vc);
void output(vector<char>& vc);
int make_ingeger(vector<char>& vc);
string make_string(vector<char>& vc);

/*
fucntion definitions
*/

bool



int main() {
	cout << "Welcome to C6x9\nThis program takes a serires of 4 chracters between 0 and 9 inclusive.\n";
	cout << "It returns a statement of the general form WXYZ is W thousands(s) and X hundred(s) and Y ten(s) and Z one(s).\n";

	/*
	Start the program/play again loop
	*/

}

