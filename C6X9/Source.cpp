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

vector<char> user_input;

/*
functions declarations
*/

bool get_user_input(vector<char>& vc);
void output(vector<char>& vc);
int make_integer(vector<char>& vc);
string make_string(vector<char>& vc);

/*
fucntion definitions
*/

bool get_user_input(vector<char>& vc) {
	char temp = { 0 };
	int digit_count = { 0 };
	
	while (cin.get(temp) && temp != '\n') {
		if (!isdigit(temp)) simple_error("You can only enter digits...\n\n");
		else {
			if (digit_count < 4) {
				vc.push_back(temp);
				digit_count++;
			}
			else simple_error("Too many digits - only take 4...\n\n");

			
		}
	}
	return true;
}

void output(vector<char>& vc) {
	cout << "The following digits were input: ";
	for (auto it = begin(vc); it != end(vc); ++it) cout << *it;
	cout << "\n\n";
}

int make_integer(vector<char>& vc)  {
	int the_integer = { 0 };
	int power_of_ten = { 1 };
	int countdown = vc.size() - 1;

	for (auto it = begin(vc); it != end(vc); ++it) {
		power_of_ten = pow(10,countdown);
		the_integer += (*it - '0' )* power_of_ten;
		--countdown;
	}
	return the_integer;
}

int main() {

	bool return_value = { false };

	cout << "Welcome to C6x9\nThis program takes a serires of 4 chracters between 0 and 9 inclusive.\n";
	cout << "It returns a statement of the general form WXYZ is W thousands(s) and X hundred(s) and Y ten(s) and Z one(s).\n";

	/*
	Start the program/play again loop
	*/
	cout << "Enter up to four digits > ";
	return_value = get_user_input(user_input);
	output(user_input);
	cout << "The Integer value is: " << make_integer(user_input)<< "\n";
	keep_window_open();
}

