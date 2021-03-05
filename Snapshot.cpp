#include "Snapshot.h"

void Snapshot::setLastPositionX(int lastPointX)
{
	storedPosition.setmX(lastPointX);
}

void Snapshot::setLastPositionY(int lastPointY)
{
	storedPosition.setmY(lastPointY);
}

void Snapshot::setStoredCommand(string lastCommand)
{
	storedCommand = lastCommand;
}

void Snapshot::setLastLines(string lastLines)
{
	storedLines = lastLines;
}


int Snapshot::getLastX()
{
	return storedPosition.getmX();
}

int Snapshot::getLastY()
{
	return storedPosition.getmY();
}

string Snapshot::getLastLines()
{
	return storedLines;
}

string Snapshot::getStoredCommand()
{
	return storedCommand;
}
