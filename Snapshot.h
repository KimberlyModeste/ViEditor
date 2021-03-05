#pragma once
#include "Point.h"


class Snapshot
{
public:

	void setLastPositionX(int);
	void setLastPositionY(int);
	void setStoredCommand(string);
	void setLastLines(string);

	int getLastX();
	int getLastY();
	string getLastLines();
	string getStoredCommand();


private:
	Point <int> storedPosition;
	string storedLines;
	string storedCommand;


};
