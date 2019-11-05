#pragma once
#include<iostream>
#include "Queue.h"
using namespace std;
    //the null constructor of stack
	cQueue::cQueue() :tail(NULL) {}
	// the parametrized constructor Queue class
	cQueue::cQueue(cNode*& ptr) : cStack(ptr), tail(top) {}
	//the copy constructor of Queue class
	cQueue::cQueue(const cQueue& src) :cStack((cStack&)src)
	{
		tail = top;
		while (tail)
		{
			if (!tail->next)
			{
				break;
			}
			tail = tail->next;
		}
	}
	//the Overloaded Assignment Operator
	cQueue& cQueue::operator = (const cQueue& obj)
	{

		if (this == &obj)
		{
			return *this;
		}
		if (true)
		{
			cQueue temp;
			temp.top = top;
			temp.tail = tail;

		}
		if (true)
		{
			cQueue temp = obj;
			top = temp.top;
			tail = temp.tail;
			temp.top = NULL;
			temp.tail = NULL;
		}
		return *this;
	}
	//this function is used to check whether stack contains nodes or not
	bool cQueue::IsNotEmpty() const
	{
		return cStack::isNotEmpty();
	}
	//this function is used to check whether stack contains nodes or not
	bool cQueue::IsEmpty() const
	{
		return cStack::isEmpty();
	}
	//this function is used to add a node in queue
	cQueue& cQueue::add(cNode*& ptr)
	{
		if (tail)
		{
			tail->next = ptr;
			tail = tail->next;
		}
		else
		{
			tail = top = ptr;
		}
		tail->next = NULL;
		ptr = NULL;
		return *this;
	}
	//this function is used to remove a node in queue
	cNode* cQueue::remove()
	{
		if (!tail->next)
		{
			tail = NULL;
		}
		return cStack::pop();
	}
	//this function is used to print the values of nodes on console
	void cQueue::print()
	{
		cStack::print();
	}
	//this is the destructor used to free all the memory used by nodes at runtime

	cQueue::~cQueue()
	{
		cNode* ptr = top;
		tail = NULL;                                              // Tail is going to NULL and we can make remaining code.
		while (ptr)
		{
			ptr = ptr->next;
			delete top;
			top = ptr;                                           // In last loop Top will become Null. 
		}
	}



