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
		priority=0;
	}
	//the parametrized construtor that takes an int as argument
	cNode::cNode(int d) : data(d),priority(0)
	{
		next = NULL;
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
	//the function that returns the Priority of that node
	int cNode::getPriority() const
	{
		return priority;
	}
	//the function that sets data in node
	void cNode::setPriority(int p)
	{
		this->priority = p;
	}
	//the funtion that is used to output data
	void cNode::print() const
	{
		cout <<"The Data is :	"<< data <<"	And the priority is :	"<<priority<< endl;
	}