/*
Colors.h

Colors class definition
*/

#pragma once

using namespace std;

class Colors
{
private:
	string cName;	// Color name
	int RGB[3];		// RGB codes (0-255)
public:
	// Constructor
	Colors()
	{
		cName = "black";
		RGB[0] = 0;
		RGB[1] = 0;
		RGB[2] = 0;
	}
	// Accessors
	string getCName()
	{
		return cName;
	}
	int getRed()
	{
		return RGB[0];
	}
	int getGreen()
	{
		return RGB[1];
	}
	int getBlue()
	{
		return RGB[2];
	}
	// Mutators
	void setCName(string name)
	{
		cName = name;
	}
	void setRGB(int r, int g, int b)
	{

		RGB[0] = r;	// Red
		RGB[1] = g; // Green
		RGB[2] = b; // Blue
	}
};


