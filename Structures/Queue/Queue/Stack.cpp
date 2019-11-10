
#pragma once
#include<iostream>
#include<fstream>
#include "Stack.h"
using namespace std;

   //the null constructor of stack
	cStack::cStack() : top(NULL) , count(0) {}
	//the parametrized constructor stack class
	cStack::cStack(cNode*& ptr) : top(ptr)
	{
		top->next = NULL;
		ptr = NULL;
		count = 1;
	}
	//the copy constructor of stack class
	cStack::cStack(const cStack& src)
	{
		this->top = src.top;
		if (src.top)
		{
			cNode* sptr, * dptr;
			dptr = top = new cNode(*src.top);
			sptr = src.top->next;
			count = 1;
			
			while (sptr)
			{
				dptr->next = new cNode(*sptr);
				sptr = sptr->next;
				dptr = dptr->next;
				count++;
			}
			dptr->next = NULL;

		}
	}
	//the overloaded operator of =
	cStack& cStack::operator =(const cStack& obj)
	{
		if (this == &obj)
		{
			return *this;
		}
		if (true)
		{
			cStack temp;
			temp.top = top;

		}
		if (true)
		{
			cStack temp(obj);
			top = temp.top;
			temp.top = NULL;
			return *this;
		}
	}
	//this function is used to check whether stack contains nodes or not
	bool cStack::isNotEmpty() const
	{
		if (top)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	//this function is used to check whether stack is empty or not
	bool cStack::isEmpty() const
	{
		if (top)
		{
			return false;
		}
		else
		{
			return true;
		}

	}
	//this function of push is used add a node in stack
	cStack& cStack::push(cNode*& ptr)
	{
		ptr->next = top;
		top = ptr;
		ptr = NULL;
		return *this;
		count++;
	}
	//this function is used remove a node from stcak
	cNode* cStack::pop()
	{
		cNode* ptr = top;
		top = top->next;
		ptr->next = NULL;
		return ptr;
		count--;
	}
	//this function is used to print the values of nodes on console
	void cStack::print() const
	{
		if (!top)
		{
			cout << "the following structure is empty " << endl;
		}
		else
		{
			cNode* ptr = top;
			while (ptr)
			{
				ptr->print();
				ptr = ptr->next;
			}
		}

	}
	//this is the destructor used to free all the memory used by nodes at runtime
	cStack::~cStack()
	{
		cNode* ptr = top;
		while (ptr)
		{
			ptr = ptr->next;
			delete top;
			top = ptr;
		}

	}

