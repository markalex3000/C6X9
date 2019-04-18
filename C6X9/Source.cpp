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



/*
functions declarations
*/

bool yes_no(string s);
bool get_user_input(vector<char>& vc);		//get the vector of character digits
void output(vector<char>& vc);				//send the vector to cout digit/char by digit
int make_integer(vector<char>& vc);			//takes the vector and return the integer value
string make_string(vector<char>& vc);		//takes the vecto and returns a string description of the integer

/*
main
*/

int main() {

	vector<char> user_input;
	bool return_value = { false };   // return_value is not used anywhere - seemed like a good idea tho

	/*
	Welcoming message
	*/

	cout << "Welcome to C6x9\nThis program takes a serires of 4 chracters between 0 and 9 inclusive.\n";
	cout << "It returns a statement of the general form WXYZ is W thousands(s) and X hundred(s) and Y ten(s) and Z one(s).\n";

	/*
	Start the program/play again loop
	*/
	do {
		cout << "Enter up to four digits > ";
		user_input.clear();								// clears the content of the user_input vector for each iteration
		return_value = get_user_input(user_input);
		output(user_input);
		cout << "The Integer value is: " << make_integer(user_input) << "\n";
		cout << make_integer(user_input) << " is " << make_string(user_input) << "\n";
	} while (yes_no("\n Play again? "));
}


/*
funcion definitions
*/

bool yes_no(string s) {						// self exlanatory - y return true anything else retirns false
	char response{ 'X' };
	cout << s << " (y/n): ";
	cin >> response;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');   //clears all remaining content from cin

	switch (response)
	{
	case 'y':
		return true;
	case 'n':
		return false;
	default:
		return false;
	}
}

bool get_user_input(vector<char>& vc) {      //gets the 4 digits of input - puts in vector provided
	char temp = { 0 };
	int digit_count = { 0 };
	
	while (cin.get(temp) && temp != '\n') {
		if (!isdigit(temp)) simple_error("You can only enter digits...\n\n");     //could be more forgiving
		else {
			if (digit_count < 4) {			// '4' hear should be a constant
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
	for (auto it = begin(vc); it != end(vc); ++it) cout << *it;			//iterators seem pretty cool
	cout << "\n\n";														// 'it' is a pointer apparently
}

int make_integer(vector<char>& vc)  {									//takes the vector and produces and return its value as an integer
	int the_integer = { 0 };
	int power_of_ten = { 1 };
	int countdown = vc.size() - 1;

	for (auto it = begin(vc); it != end(vc); ++it) {
		power_of_ten = pow(10,countdown);
		the_integer += (*it - '0' )* power_of_ten;    // *it is a char and subtracing '0' gets the integer value of the char
		--countdown;
	}
	return the_integer;
}

string make_string(vector<char>& vc)									//takes the vector and produces the descriptive string
{
	vector<string> powers_of_ten = { " thousand", " hundred", " ten", " one" };
	string the_string = { NULL };
	string temp_string = { NULL };

	int power_of_ten = { 1 };
	int countdown = vc.size();

	for (auto it = begin(vc); it != end(vc); ++it) {		//it just works			
		if (*it == '0') temp_string.append(" no");
		else temp_string.append(1,*it);
		temp_string.append(powers_of_ten[powers_of_ten.size() - countdown]);
		if (*it == '0' || (*it - '0') > 1) temp_string.append(1, 's');
		if(it + 1 != end(vc)) temp_string.append(" and ");
		the_string = temp_string;
		--countdown;
	}
	return the_string;
}



