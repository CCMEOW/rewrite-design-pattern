#include "Menu.h"
#include <iostream>
#include "Heater.h"
#include "Listener.h"
#include "Directory.h"
#include "File.h"
#include "Panel.h"
#include "Add.h"
#include "Remove.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Globle.h"

void Menu::selectMenu(){
	char select;
	cout << "==========================================" << endl;
	cout << "The Final Presentation. Select your menu. " << endl;
	cout << "                1 -- Observer             " << endl;
	cout << "                2 -- Composite            " << endl;
	cout << "                3 -- Undo Redo            " << endl;
	cout << "                Q -- quit                 " << endl;
	cout << "==========================================" << endl;

	bool flag = true;
	while (flag)
	{
		cout << "Menu Select: ";
		cin >> select;
		switch (select)
		{
		case '1':
			observerMenu();
			break;
		case '2':
			compositeMenu();
			break;
		case '3':
			commandMenu();
			break;
		case 'Q':
			flag = false;
			break;
		default:
			break;
		}
	}

}

void Menu::compositeMenu(){
	Directory *rootDir = new Directory("root");
	bool flag = true;
	char operation;
	string name;
	float size;
	Directory* currDir = rootDir;
	File* file;
	Directory* directory;
	cout << "Create your file system. Input ? for help. " << endl;
	while (flag){
		cout << "Input: ";
		cin >> operation;
		switch (operation)
		{
		case 'D':
			cout << "Input the name of directory: ";
			cin >> name;
			directory = Directory::createDirectory(name);
			if (directory == NULL){
				break;
			}
			currDir->add(directory);
			break;
		case 'F':
			cout << "Input the name of file: ";
			cin >> name;
			cout << "Input the size of file: ";
			cin >> size;
			if (cin.fail()){
				cin.clear();
				flushall();
				cout << "Invalid size" << endl;
				break;
			}
			file = File::createFile(name, size);
			if (file == NULL)
				break;
			currDir->add(file);
			File::createFile(name, size);
			break;
		case 'R':
			cout << "Input the name: ";
			cin >> name;
			currDir->deleteFile(name);
			break;
		case 'A':
			cout << "Input the name of directory: ";
			cin >> name;
			if (currDir->findEntry(name) != NULL){
				currDir = (Directory*)currDir->findEntry(name);
			}
			else{
				cout << "Invalid directory." << endl;
			}
			break;
		case 'C':
			cout << "Input the name of directory: ";
			cin >> name;
			directory = (Directory*)currDir->findEntryFromRoot(name, rootDir);
			if (directory != NULL){
				currDir = directory;
			}
			else{
				cout << "Invalid directory." << endl;
			}
			break;
		case 'P':
			currDir->printList();
			break;
		case 'Q':
			flag = false;
			break;
		case '/':
			currDir = rootDir;
			break;
		case '?':
			cout << "D -- create directory, F -- create file" << endl;
			cout << "C -- change directory, / -- change to root, R -- delete file/directory" << endl;
			cout << "P -- show files, Q -- quit, ? -- help. " << endl;
			break;
		default:
			break;
		}
	}
}

void Menu::observerMenu(){
	Heater* heater = new Heater();
	int flag = true;
	char operation;
	string name;
	cout << "Boil water and subscribe for notification. Input ? for help" << endl;
	while (flag){
		cout << "Input: ";
		cin >> operation;
		switch (operation)
		{
		case 'B':
			heater->start();
			break;
		case 'S':
			cout << "Input your name: ";
			cin >> name;
			heater->addObserver(new Listener(name));
			break;
		case 'Q':
			flag = false;
			break;
		case '?':
			cout << "B -- boil water, S -- subscribe" << endl;
			cout << "Q -- for quit, ? -- help" << endl;
			break;
		default:
			cout << "Input ? for help. " << endl;
			break;
		}
	}
}

void Menu::commandMenu(){
	graph_id = 0;
	Panel panel = Panel();
	char operation;
	float length, width, radius;
	char select;		int id = -1;
	Graph* graph;
	cout << "Draw your graph! Input ? for help." << endl;
	bool flag = true;
	while (flag)
	{
		id = -1;
		cout << "Input: ";
		cin >> operation;
		switch (operation)
		{
		case 'A':
			cout << "Please select your graph(input the number): 1 Circle 2 Rectangle" << endl;
			cin >> select;
			if (select == '2')
			{
				cout << "Input length and width( like 2 1): ";
				cin >> length >> width;
				graph = Rectangle::createRectangle(length, width);
			}
			else if (select == '1'){
				cout << "Input radius: ";
				cin >> radius;
				if (cin.fail()){
					cin.clear();
					flushall();
					cout << "Invalid radius" << endl;
					break;
				}
				graph = Circle::createCircle(radius); 
			}
			else
			{
				cout << "Invalid operation." << endl;
				break;
			}
			if (graph == NULL){
				break;
			}
			panel.executeCommand(new Add(graph));
			break;
		case 'R':
			cout << "Input the id of graph: ";
			cin >> id;
			if (!panel.executeCommand(new Remove(panel.findGraph(id)))){
				cout << "Id not fount!" << endl;
			}
			break;
		case 'Z':
			panel.undo();
			break;
		case 'Y':
			panel.redo();
			break;
		case 'P':
			panel.display();
			break;
		case '?':
			cout << "A -- draw a graph, R -- erase graph, Z -- undo, Y -- redo, Q for quit. " << endl;
			cout << "P -- display panel, Q -- quit, ? -- help" << endl;
			break;
		case 'Q':
			flag = false;
			break;
		default:
			cout << "Invalid operation, input ? for help." << endl;
			break;
		}
	}
}