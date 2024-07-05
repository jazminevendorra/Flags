/*
flag.h

flag class definition
*/

#pragma once

// Header File
#include <iostream>
#include <string>
#include <iomanip>
#include "Colors.h"
using namespace std;

class Flag
{
private:
	string fName;		// Name of flag
	Colors* fColors;	// Pointer to Colors object
	int fNColors;		// Number of colors in a flag

	static int fCount;	// Update every time a flag is added

public:
	// Constructor
	Flag()
	{
		fName = ' ';
		fColors = nullptr;
		fNColors = 0;
	}
	// Destructor
	~Flag()
	{
		delete[] fColors;
	}
	//Accessors
	string getFName()
	{
		return fName;
	}
	string getFColor(int c)
	{		
		// string formatted as: <color name> \t (<R>,<G>,<B>)
		std::string fColorInfo = Flag::fColors[c].getCName() + "\t(" + to_string(Flag::fColors[c].getRed())
			+ ", " + to_string(Flag::fColors[c].getGreen()) 
			+ ", " + to_string(Flag::fColors[c].getBlue()) + ")";
		return fColorInfo;
	}
	// Mutators
	void setFName(string name)
	{
		fName = name;
	}
	void setFColors(int num)
	{
		string name;		// User input
		int r, g, b;		// RGB colors user input
		

		// Dynamically allocate number of colors
		fColors = new Colors[num];

		// for each color:
		//prompt user for color name, rgb codes
		for (int i = 0; i < num; i++)
		{
			//color name
			cout << endl << setw(22) << right << "Color " << (i + 1) << " Name: ";
			cin >> name;

			//red
			cout << setw(30) << right << "Red (0-255): ";
			cin >> r;
			//green
			cout << setw(30) << right << "Green (0-255): ";
			cin >> g;
			//blue
			cout << setw(30) << right << "Blue (0-255): ";
			cin >> b;

			fColors[i].setCName(name);
			fColors[i].setRGB(r, g, b);
		}
			
	}

	// Friend Operator
	friend ostream& operator << (ostream& ostObj, Flag& flagObj)
	{
		for (int i = 0; i < Flag::getFCount(); i++)
		{
			ostObj << setw(20) << left << flagObj.getFName();

			for (int c = 0; c < 3; c++)
			{
				ostObj << flagObj.getFColor(c) << endl;
				ostObj << "\t\t    " << left << setw(20);
				 
			}
			cout << endl;
		}
		return ostObj;
	}

	// Static member functions
	static int getFCount();
	static void incrementFCount();
};

// Definition of static member variable fCount
int Flag::fCount = 0;

/*
Definition of static member function getFCount()
This function returns fCount static variable.
*/
int Flag::getFCount()
{
	return fCount;
}

/*
Definition of static member function incermentFCount()
This function adds one to the fCount static variable.
*/
void Flag::incrementFCount()
{
	fCount++;
}