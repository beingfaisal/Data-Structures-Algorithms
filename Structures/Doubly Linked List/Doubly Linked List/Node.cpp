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
		left = right = NULL;
	}
	//the parametrized construtor that takes an int as argument
	cNode::cNode(int d) : data(d)
	{
		left = right = NULL;
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
		cout <<"The Data is "<< data <<"	"<< endl;
	}