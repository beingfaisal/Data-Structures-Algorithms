#pragma once
#pragma once
#include<iostream>
#include<fstream>
#include"Node.h"
using namespace std;

class list
{
	cNode* head;
	
public:
	int count;
	//this is the null constructor
	list();
	//this is the parametrized constructor that takes a node as an argument.
	list(cNode*& ptr);
	//this is the Copy Constructor of list.
	list(const list& src);
	//Constructors for FILE HANDLING 'INPUT DATA FROM FILE'
	list(ifstream& inFile);
	//this is the overloaded function of addition that concatinates two lists.
	list& operator+(const list& robj);
	//this is the overloaded function of Assignment used to copy two lists after initialization
	list& operator =(const list& src);
	//this is the overloaded funtion of square brackets that is used highlight the Indexed Nature of Lists.
	cNode& operator[](int index);
	//this function of insert adds node at start of list
	list& insert(cNode*& ptr);
	//this function of insertAt adds node at certain index of list
	list& inserAt(int index, cNode*& ptr);
	//this function of remove removes a node from list
	cNode* remove();
	//this function of removeAt removes node from certain index
	cNode* removeAt(int index);
	//this function of Reverse changes the order of list.
	list& reverse();
	//this function of Swap exchanges the position of these two nodes.
	list& swapOfNodesAt(int index1, int index2);
	//Function for writing LIST data to file
	void writeListToFile(ofstream& oFile);
	//Function for reading LIST data from file
	void readListFromFile(ifstream& inFile);
	//this is the recursive function that is used to delete nodes from list.
	void deleteNodes(cNode* ptr);
	//this is the print function that prints the value of nodes.
	void print() const;
	~list();

};



