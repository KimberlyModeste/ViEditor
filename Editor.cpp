#pragma once
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include "Editor.h"
#include "LinkedList.h"
#include <string>
#include "BinarySearchTree.h"
#define ESC 27


template <class TYPE>
void placeCursorAt(Point <TYPE> coordinate)
{
	COORD coord;
	coord.X = coordinate.getmX();
	coord.Y = coordinate.getmY();
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord);
}

void colorText(int value)
{
	COORD coord;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	FlushConsoleInputBuffer(hConsole);
	SetConsoleTextAttribute(hConsole, value);

}


bool Editor::readFile()
{
	int lineCount = 1;
	bool result = true;
	string line;
	ifstream inData;

//	linePtr = new LinkedList <string>;
	
	inData.open(FileName);
	if (!inData)
	{
		cout << "Could not read file!!!";
		result = false;
		return result;
	
	}

	while (!inData.eof())
	{
		getline(inData, line);
		lineList.insert(lineCount, line);
		lineCount++;
	}
	inData.close();
	return result;

}

bool Editor::readFileTree(string fileName)
{
	ifstream inData;
	string line;
	inData.open(fileName);
	if (!inData) 
	{
		cout << "We are not inData!";
		return false;
	}
	while (!inData.eof())
	{
		inData >> line;
		special.add(line);
	}
	return true;
	
}

bool Editor::saveFile()
{
	ofstream outData;
	outData.open(FileName);
	if (!outData)
		return false;
	for (int i = 1; i <= lineList.getLength(); i++)
	{
		outData << lineList.getEntry(i) << endl;
	}

	outData.close();
	return true;
}

void Editor::setFileName(string input)
{
	FileName = input;
}

//Just to run things
void Editor::run()
{
	bool value = true;
	while (value == true)
		value = processCommand();

}

//This is where the switch commands go
bool Editor::processCommand()
{
	char command;
	int multiply, i = 0;
	string lines, lines2;
	//I need two lines to compare with
	Snapshot last;
	
	
	command = _getwch();
	if (command == ESC)
		return false;
	if (command >= '0'&& command <= '9')
	{
		multiply = command - '0';
		command = _getwch();
	}
	else
		multiply = 1;
	
	switch (command)
	{
			//Up
		case 'k':
		{
			
			//if x is not equal to 0 then do this
			if (position.getmY() != 0)
			{
				do {
					//The line you're on
					lines = lineList.getEntry(position.getmY() + 1);
					//The line above you
					lines2 = lineList.getEntry(position.getmY());

					//If the position you're at is greater than the lines above you.
					if (position.getmX() > lines2.length())
					{
						//Then move the X position to the end of the top line
						position.setmX(lines2.length() - 1);

					}

					position.setmY((position.getmY() - 1));
					placeCursorAt(position);

					i++;
				} while (i < multiply);
				break;
			}
			break;
		}

		//Down Working
		case 'j':
		{


			//if y is less than the length of linelist - 1 then do this
			if (position.getmY() < lineList.getLength() - 1)
			{
				do {


					//The line you're on 
					lines = lineList.getEntry(position.getmY() + 1);
					//The line below you
					lines2 = lineList.getEntry(position.getmY() + 2);


					//If the line you're on is greater than the line below you
					if ((lines.length() > lines2.length()))
					{
						position.setmX(lines2.length() - 1);
					}
					position.setmY((position.getmY() + 1));
					placeCursorAt(position);
					i++;
				} while (i < multiply);
			}
			break;

		}
		//Right
		case 'l':
		{
			do
			{

				lines = lineList.getEntry(position.getmY() + 1);

			if (position.getmX() < lines.length() - 1)
			{
				position.setmX((position.getmX() + 1));
				placeCursorAt(position);

			}
			i++;
			} while (i < multiply);
			break;
		}

		//Left
		case 'h':
		{
			do 
			{
				if (position.getmX() >= 0)
				{
					position.setmX((position.getmX() - 1));
					placeCursorAt(position);

				}
				i++;
			} while (i < multiply);
			break;
		}
		
	//delete a specific character
	case 'x':
	{
	
		do
		{
			lines = lineList.getEntry(position.getmY() + 1);
			if (lines.length() > 0)
			{
				lines.erase(lines.begin() + position.getmX());
				last.setLastLines(lineList.replace(position.getmY() + 1, lines));
				last.setLastPositionX(position.getmX());
				last.setLastPositionY(position.getmY());
				last.setStoredCommand("x");
				undoStack.push(last);
				system("CLS");
				display();
			}
			i++;
		} while (i < multiply);
		break;
	}
	//undo
	case 'u':
	{
		do {
			if (!undoStack.isEmpty())
			{
				Snapshot current;
				current = undoStack.peek();

				if (current.getStoredCommand() == "dd")
				{
					lineList.insert((current.getLastY() + 1), current.getLastLines());
				}
				if (current.getStoredCommand() == "x")
				{
					lineList.replace((current.getLastY() + 1), current.getLastLines());
				}
				if (current.getStoredCommand() == "IA")//Insert Add
				{
					lineList.replace(current.getLastY() + 1, current.getLastLines());
				}
				if (current.getStoredCommand() == "IE")//Insert Enter
				{
					lineList.replace(current.getLastY() + 1, current.getLastLines());
					lineList.remove(current.getLastY() + 2);
				}
				undoStack.pop();
				system("CLS");
				display();

			}
			i++;
		} while (i < multiply);
		break;
	}
	//D?
	case 'd':
	{
		
		command = _getwch();
		switch (command)
		{
			//delete
		case 'd':
		{
			do {

				last.setLastPositionX(position.getmX());
				last.setLastPositionY(position.getmY());
				last.setLastLines(lineList.getEntry(position.getmY() + 1));
				last.setStoredCommand("dd");
				undoStack.push(last);

				lineList.remove(position.getmY() + 1);
				system("CLS");
				display();
				i++;
			} while (i < multiply);
			break;
		}
		}
		break;
	}
	
	case ':':
	{
		command = _getwch();
		switch (command) 
		{
		case'w':
		{
			saveFile();
			lineList.insert(lineList.getLength() + 1, "FILE SAVED");
			system("CLS");
			display();
			Sleep(500);
			lineList.remove(lineList.getLength());
			system("CLS");
			display();
			break;
		}

		}
		return false;
		break;
	}
	//Insert
	case 'I':
	{
		lineList.insert(lineList.getLength()+1, "INSERT MODE");
		system("CLS");
		display();
		position.setmX(0);
		insertModeCommand('I');
		break;
	}
	case 'i':
	{
		lineList.insert(lineList.getLength()+1, "INSERT MODE");
		system("CLS");
		display();
		insertModeCommand('i');
		break;
	}

	}
	return true;
}


void Editor::display()
{
	bool isKeyword;
	string myLine;

	for (int k = 1; k < lineList.getLength() + 1; k++) {
		myLine = lineList.getEntry(k);
		int j = 0;
		// print without 'words'
		for (int i = 0; i < myLine.size(); i++) {
			if (tolower(myLine[i]) >= 'a' && tolower(myLine[i]) <= 'z') {  //letter
				string currentWord;
				for (j = i; (tolower(myLine[j]) >= 'a' && tolower(myLine[j]) <= 'z'); j++) {
					currentWord += myLine[j];
				}
				isKeyword = special.contains(currentWord);
				if (isKeyword)
					colorText(FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0X80);  //blue
				else
					colorText(0XF0);
				cout << currentWord;
				if (j != 0)
					i = j - 1;
			}
			else
				cout << myLine[i];
			//if (i >= myLine.size()-1) 
			// cout << endl;
		}
		cout << endl;

	}
	placeCursorAt(position);
}

void Editor::insertModeCommand(char anI)
{
	Snapshot last;
	string line, line2;
	char command;


	placeCursorAt(position);
	command = _getch();


	while (command!=ESC)
	{
		
		line = lineList.getEntry(position.getmY() + 1);

			if (command != '\r')
			{
				last.setLastLines(line);
				last.setLastPositionX(position.getmX());
				last.setLastPositionY(position.getmY());
				last.setStoredCommand("IA");
				//This is a string operation
				line.insert(position.getmX(), 1, command);
				lineList.replace(position.getmY() + 1, line);

				if (command == '\b')
				{

					position.setmX(position.getmX() - 1);
				}
				else
					position.setmX(position.getmX() + 1);

			}
			else
			{
				last.setLastLines(line);
				last.setLastPositionX(position.getmX());
				last.setLastPositionY(position.getmY());
				last.setStoredCommand("IE");

				line2 = line;
				//This is for the letters to get entered
				line2.erase(0, position.getmX());

				//This is for the numbers that stay
				line.erase(position.getmX(), line.length());

				lineList.replace(position.getmY() + 1, line);
				lineList.insert(position.getmY() + 2, line2);
				position.setmY(position.getmY() + 1);
				position.setmX(0);

			}
			undoStack.push(last);

			placeCursorAt(position);
			system("CLS");
			display();
		
		command = _getch();
	}
	lineList.remove(lineList.getLength());
	system("CLS");
	display();
}


