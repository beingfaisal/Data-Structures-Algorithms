#pragma once

#include<iostream>
#include<fstream>
#include"Node.h"

using namespace std;
class cStack
{
private:
	cNode* top;                           //this data memeber is used to point the top node						
	int count;							  //this data memeber is used to keep account of nodes while file handling
public:
	cStack();				              //this the null constructor
	cStack(cNode*& ptr);	              //this the parametrized constructor it takes a node as parameter
	cStack(const cStack& src);            //this the copy constructor it takes a stack as argument
	cStack& operator= (const cStack& obj); //this is the ovweloaded = operator and it can be used to copy two stacks
	bool isNotEmpty() const;              //this function is used to check whether stack is empty or not
	bool isEmpty() const;		          //this function has same functionality same as above but used in different perspective	
	cStack(ifstream& inFile);	          //this is the constructor that is used in file handling i.e. take input from files
	void writeToFile(ofstream& oFile);    //this the function that has functonality same as above but its a function
	void readFromFile(ifstream& inFile);  //this function is used to handle output in files
	cStack& push(cNode*& ptr);            //this function of push is used add a node in stack
	cNode* pop();						  //this function is used remove a node from stcak
	void print() const;					  //this function is used to print the values of nodes on console
	~cStack();							  //this is the destructor used to free all the memory used by nodes at runtime	
	
};