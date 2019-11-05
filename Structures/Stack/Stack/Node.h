#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class cNode
{
	//the data memeber to store the value of the node
	int data;
public:
	cNode* next;
	//the null constructor
	cNode();
	//the constructor that takes an int for an argument
	cNode(int d);
	//Constructors for File Handling that takes input from file
	cNode(ifstream& inFile);
	//the function that returns the value of that node
	int getData() const;
	//the function that sets data in node
	void setData(int d);
	//the funtion that is used to output data
	void print() const;
	//Function to write data of node in file
	void writeNodetoFile(ofstream& outData);
	//Function to read data from file
	void readNodefromFile(ifstream& inData);

};
