#include<iostream>
#include<fstream>
#include "Node.h"
#pragma once

#include<iostream>
using namespace std;
	//the null constructor
	cNode::cNode()
	{
		data = 0;
		next = NULL;
	}
	//the parametrized construtor that takes an int as argument
	cNode::cNode(int d) : data(d)
	{
		next = NULL;
	}
	//Constructors for File Handling that takes input from file
	cNode::cNode(ifstream& inFile)
	{
		inFile.read((char*)this, sizeof(this->data));
	}
	//the function that returns the value of that node
	int cNode::getData() const
	{
		return data;
	}
	//the function that sets data in node
	void cNode::setData(int d)
	{
		this->data = d;
	}
	//the funtion that is used to output data
	void cNode::print() const
	{
		cout << data <<"	"<< endl;
	}

	//Function to write data of node in file
	void  cNode::writeNodetoFile(ofstream& outData)
	{
		outData.write((char*)this, sizeof(this->data));
	}
	//Function to read data from file
	void  cNode::readNodefromFile(ifstream& inData)
	{
		inData.read((char*)this, sizeof(this->data));
	}