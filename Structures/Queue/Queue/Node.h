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
	//the function to return the data of node
	int getData() const;
	//the function that sets data in node
	void setData(int d);
	//the funtion that is used to output data
	void print() const;
};
