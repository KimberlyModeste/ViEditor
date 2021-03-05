#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include "ListInterface.h"
#include "Node.h"
#include "LinkedList.h"
#include "Point.h"
#include "Editor.h"
#include "PrecondViolatedExcept.h"


using namespace std;

void main()//int argC, char*argV[])
{
	Editor myEditor;
	
	myEditor.setFileName("Sample.txt");//argV[1]);
	myEditor.readFile();
	myEditor.readFileTree("keywords.txt");
	myEditor.display();
	//I put display here first because for some reason it takes a while to load  when in run
	myEditor.run();
	
}