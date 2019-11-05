#pragma once
#pragma once
#include<iostream>
#include"Queue.h"


using namespace std;


class cPriorityQue : public cQueue
{
public:
	//the null constructor of Priority Queue
	cPriorityQue();
	// the parametrized constructor Priority Queue class
	cPriorityQue(cNode*& ptr);
	//the copy constructor of Priority Queue class
	cPriorityQue(const cPriorityQue& src);
	//the Overloaded Assignment Operator of Priority  Queue
	cPriorityQue& operator =(const cPriorityQue& obj);
	//this function is used to check whether Priority Queue contains nodes or not
	bool isEmpty() const;
	//this function is used to check whether Priority Queue contains nodes or not
	bool isNotEmpty() const;
	//this function is used to add a node in Priority Queue
	cPriorityQue& add(cNode*& ptr);
	//this function is used to remove a node in Priority Queue
	cNode* remove();
	//this function is used to print the values of nodes on console
	void print() const;
	//this is the destructor used to free all the memory used by nodes at runtime
	~cPriorityQue();


};
