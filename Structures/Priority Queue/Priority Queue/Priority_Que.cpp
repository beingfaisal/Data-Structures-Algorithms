#include "Priority_Que.h"
#pragma once
#include<iostream>
using namespace std;
	//the null constructor of stack
	cPriorityQue::cPriorityQue() {}
	// the parametrized constructor  Priority Queue class
	cPriorityQue::cPriorityQue(cNode*& ptr) :cQueue(ptr) {}
	//the copy constructor of Priority Queue class
	cPriorityQue::cPriorityQue(const cPriorityQue& src) :cQueue((cQueue&)src) {}
	//the Overloaded Assignment Operator of Priority Queue class
	cPriorityQue& cPriorityQue:: operator =(const cPriorityQue& obj)
	{
		((cQueue*)this)->operator=((cQueue&)obj);
		return* this;
	}
	//this function is used to check whether Priority Queue contains nodes or not
	bool cPriorityQue::isNotEmpty() const
	{
		return cQueue::isNotEmpty();
	}
	//this function is used to check whether Priority Queue contains nodes or not
	bool cPriorityQue::isEmpty() const
	{
		return cQueue::isEmpty();
	}
	//this function is used to add a node in Priority queue
	cPriorityQue& cPriorityQue::add(cNode*& ptr)
	{
		if (!top)
		{
			top = tail = ptr;
			tail->next = NULL;
			ptr = NULL;
		}
		else if (top->getPriority() < ptr->getPriority())
		{
			cStack::push(ptr);
		}
		else if (tail->getPriority() >= ptr->getPriority())
		{
			cQueue::add(ptr);
		}
		else
		{
			cNode* rptr, * bptr;
			rptr = bptr = top;
			while (rptr->getPriority() >= ptr->getPriority())
			{
				bptr = rptr;
				rptr = rptr->next;
			}
			ptr->next = rptr;
			bptr->next = ptr;
			ptr = NULL;
		}
		return *this;
	}
	//this function is used to remove a node in Priority queue
	cNode* cPriorityQue::remove()
	{
		return cQueue::remove();
	}
	//this function is used to print the values of nodes on console
	void cPriorityQue::print() const
	{
		cQueue::print();
	}
	//this is the destructor used to free all the memory used by nodes at runtime
	cPriorityQue::~cPriorityQue()
	{
		cNode* ptr = top;
		tail = NULL;                  
		while (ptr)
		{
			ptr = ptr->next;
			delete top;
			top = ptr;               
		}
	}
