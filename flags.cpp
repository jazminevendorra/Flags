/*
	flags.cpp

	This program will allow user to keep track of a collection of flags.
	The menu driven program will allow:
	1. Adding a flag to the collection
	2. Displaying flags in the collection
	3. Quit

*/

// Header Files
#include <iostream>
#include "flag.h"
#include <iomanip>
using namespace std;

//Global constants
const int SIZE = 50;
const int COL = 20;

int main()
{
	// Variables
	string country;
	int colors;
	int choice;

	// Array definition
	Flag fArray[SIZE];

	// Intro
	cout << "\nFlying Colors App ..." << endl;

	// Table heading line
	string line = "";
	for (int i = 0; i < 2 * COL; i++)
		line += "-";

	// Menu
	do
	{
		cout << "\nChoose one of the following options:" << endl
			<< "\t1. Add a flag to the collection" << endl
			<< "\t2. Display flags in the collection." << endl
			<< "\t3. Quit." << endl
			<< "Option: ";
		cin >> choice;

		switch (choice)
		{
		case 1: // Add flag
			cout << "\nAdding a flag ..." << endl;

			// Prompt user for flag country
			cout << endl << setw(30) << right <<  "Country Name: ";
			cin >> country;
			fArray[Flag::getFCount()].setFName(country);

			// Number of colors
			cout << endl << setw(30) << right << "Number of Colors: ";
			cin >> colors;

			// Set colors
			fArray[Flag::getFCount()].setFColors(colors);

			// Increment flag count
			Flag::incrementFCount();

			break;
		case 2: // Display flags
			cout << "\nDisplaying Flags ..." << endl;

			// Heading
			cout << endl << line << endl
				<< setw(COL) << left << "Country"
				<< "Colors" << endl
				<< line << endl;

			// Records
			for (int i = 0; i < Flag::getFCount(); i++)
				cout << fArray[i];	//?????

			break;
		case 3: // Quit
			cout << "\nGood Bye ..." << endl;
			break;
		default:
			cout << "Error ... Invalid choice. Try again." << endl;

		}
	} while (choice != 3);

	return 0;
}
