#pragma once

#include<iostream>
#include"Stack.h"
using namespace std;

class cQueue : public cStack
{
protected:
	cNode* tail;
public:
	//the null constructor of Queue
	cQueue();
	// the parametrized constructor Queue class
	cQueue(cNode*& ptr);
	//the copy constructor of Queue class
	cQueue(const cQueue& src);
	//the Overloaded Assignment Operator
	cQueue& operator = (const cQueue& obj);
	//this function is used to check whether Queue contains nodes or not
	bool IsNotEmpty() const;
	//this function is used to check whether Queue contains nodes or not
	bool IsEmpty() const;
	//this function is used to add a node in queue
	cQueue& add(cNode*& ptr);
	//this function is used to remove a node in queue
	cNode* remove();
	//this function is used to print the values of nodes on console
	void print()const;
	//this is the destructor used to free all the memory used by nodes at runtime
	~cQueue();

};


