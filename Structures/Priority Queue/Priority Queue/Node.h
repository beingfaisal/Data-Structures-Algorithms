#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class cNode
{
	//the data memeber to store the value of the node
	int data;
	//the data memeber to store the value of the node
	int priority;
public:
	//the pointer of node class is used to point at the next node
	cNode* next;
	//the null constructor
	cNode();
	//the constructor that takes an int for an argument
	cNode(int d);
	//the function that is used to set the data in node
	int getData() const;
	//the function that sets data in node
	void setData(int d);
	//the function that is used to set the  priority of node
	int getPriority() const;
	//the function that sets priority in node
	void setPriority(int p);
	//the funtion that is used to output data
	void print() const;
};
