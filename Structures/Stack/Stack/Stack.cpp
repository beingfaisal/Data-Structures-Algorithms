
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
	//cStack constructor to input nodes from file 
	cStack::cStack(ifstream& inFile) : top(NULL), count(0) 
	{
		int size = 0;
		inFile.read((char*)this, sizeof(*this));
		if (size > 0) 
		{
			cNode* rptr;
			rptr = top = new cNode(inFile);
			count = size;
			for (int i = 0; i < count; ++i) 
			{
				rptr->next = new cNode(inFile);
				rptr = rptr->next;
			}
			rptr->next = NULL;
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
	//Member function to write cStack nodes to file
	void cStack::writeToFile(ofstream& oFile) 
	{
		if (!(oFile.is_open())) 
		{
			cout << "File is not opened !" << endl;
		}
		else 
		{
			oFile.write((char*)&count, sizeof(count));

			if (count > 0) 
			{
				cNode* rptr = top;
				for (int i = 0; i < count; ++i) 
				{
					rptr->writeNodetoFile(oFile);
					rptr = rptr->next;
				}
			}
		}
	}
	//Member function to read input nodes from file
	void cStack::readFromFile(ifstream& inFile) 
	{
		if (!(inFile.is_open()))
		{
			cerr << "File can not be opened in read from file function.";
			exit(1);
		}
		else 
		{
			if (true)
			{
				cStack temp;
				temp.top = this->top;
			}
			inFile.read((char*)&count, sizeof(count));
			cout << "count = " << count << endl;
			if (count > 0)
			{
				cNode* temp;
				temp = top = new cNode(inFile);

				for (int i = 1; i < count; ++i)
				{
					temp->next = new cNode(inFile);
					temp = temp->next;
				}
				temp->next = NULL;
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

