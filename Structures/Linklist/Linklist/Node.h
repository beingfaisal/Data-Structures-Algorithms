#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class cnode
{
	int data;

public:
	cnode* next;
	cnode();
	cnode(int d);
	cnode(ifstream& inFile);
	cnode(ofstream& oFile);
	void writeNodetoFile(ofstream& outData);
	void readNodefromFile(ifstream& inData);
	int getData() const;
	void setData(int d);
	void print() const;

};
