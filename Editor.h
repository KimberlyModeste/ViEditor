#pragma once
#include <string>
#include "Point.h"
#include "LinkedList.h"
#include "ArrayStack.h"
#include "Snapshot.h"
#include "BinarySearchTree.h"


class Editor
{
public:
	//Editor();
	bool readFile();
	bool readFileTree(string);
	bool saveFile();
	void setFileName(string);
	void run();
	bool processCommand();
	void display();
	void insertModeCommand(char);

	

private:
	LinkedList <string> lineList;
	ArrayStack <Snapshot> undoStack;
	Point <int> position;
	BinarySearchTree <string> special;
	string FileName;

};
