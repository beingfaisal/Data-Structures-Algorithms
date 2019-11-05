#pragma once
#pragma once
#include<iostream>
#include<fstream>
#include"Node.h"
using namespace std;

class list
{
	cnode* head;
	
public:
	int count;
	list();
	list(cnode*& ptr);
	list(const list& src);
	list(ifstream& inFile);
	list(ofstream& outFile);
	void writeListToFile(ofstream& oFile);
	void readListFromFile(ifstream& inFile);
	list& operator+(const list& robj);
	list& insert(cnode*& ptr);
	list& inserAt(int index, cnode*& ptr);
	list& operator =(const list& src);
	void deleteNodes(cnode* ptr);
	cnode* remove();
	cnode* removeAt(int index);
	list& swapOfNodesAt(int index1, int index2);
	list& reverse();
	void print() const;
	~list();

};



