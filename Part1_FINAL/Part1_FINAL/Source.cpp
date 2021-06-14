/*
Sam Schock
Exam 2 Part A: Strings
Due 5/13/21
*/

#include <cctype>
#include <iostream>
#include <string>
using namespace std;

void sPoNgEbOb();
void newLine();

int main()
{
	string Again;
	bool repeat = true;

	cout << "~~~~ Mocking Spongebob Text Generator ~~~~" << endl;
	do
	{
		sPoNgEbOb();
		
		cout << "----------------------------------------------\nRepeat? (Y/N)\n" << endl;
		cin >> Again;
		newLine();

		if (tolower(Again[0]) == 'n')
		{
			repeat = false;
		}
	} while (repeat);
	

	return 0;
}

// Function takes a line of input text and converts it to alternating caps
void sPoNgEbOb()
{
	string Input, Output;
	int i;
	bool makeLower = true;

	cout << "\nAsk Spongebob a question:\n" << endl;

	getline(cin, Input);

	// For each character in 'Input'...
	for (i = 0; i < Input.length(); i++)
	{
		// ...if the character is a letter...
		if (isalpha(Input[i]))
		{
			// ...if makeLower is true...
			if (makeLower)
			{
				// ...add the lowercase of that character to Output
				//		and set makeLower to false
				Output += tolower(Input[i]);
				makeLower = false;
			}
			// ...or, if makeLower is false...
			else
			{
				// ...add the uppercase of that character to Output
				//		and set makeLower to true
				Output += toupper(Input[i]);
				makeLower = true;
			}
		}
		// If the character is not a letter...
		else
		{
			// ...add the character to Output (do not change it)
			Output += Input[i];
		}
	}

	// Finally, output Output
	cout << "\n" << Output << endl;
}

// 'newLine()' is taken from the textbook, p.391
// This function clears the input line

void newLine()
{
	char symbol;
	do
	{
		cin.get(symbol);
	} while (symbol != '\n');
}