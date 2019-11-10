#pragma once
#include<iostream>
#include<fstream>
#include"Node.h"
#include "List.h"
using namespace std;
	//this is the null constructor
	list::list() :head(NULL), count(0) {}
	//this is the parametrized constructor that takes a node as an argument.
	list::list(cNode*& ptr) : head(ptr), count(1)
	{
		head->next = NULL;
		ptr = NULL;
	}
	//this is the Copy Constructor of list.
	list::list(const list& src) :head(src.head), count(src.count)
	{
		if (count > 0)
		{
			cNode* dptr, * sptr;
			dptr = head = new cNode(*src.head);
			sptr = src.head->next;
			while (sptr)
			{
				dptr->next = new cNode(*sptr);
				sptr = sptr->next;
				dptr = dptr->next;
			}

			dptr->next = NULL;
		}
	}
	//Constructors for FILE HANDLING 'INPUT DATA FROM FILE'
	list::list(ifstream& inFile) :head(NULL), count(0)
	{
		inFile.read((char*)&count, sizeof(count));
		if (count > 0)
		{
			cNode* ptr;
			ptr = head = new cNode(inFile);
			for (int i = 1; i < count; ++i)
			{
				ptr->next = new cNode(inFile);
				ptr = ptr->next;
			}
			ptr->next = NULL;
		}
	}
	//this is the overloaded function of addition that concatinates two lists.
	list& list::operator+(const list& src)
	{
		if (src.count == 0)
		{
			return *this;
		}
		list copy = src;
		if (!head)
		{
			head = copy.head;
		}
		else
		{
			cNode* ptr;
			ptr = head;
			for (int i = 1; i < count; i++)
			{
				ptr = ptr->next;
			}
			ptr->next = copy.head;
			count += copy.count;
		}
		copy.head = NULL;
		return *this;

	}
	//this is the overloaded function of Assignment used to copy two lists after initialization
	list& list::operator =(const list& src)
	{
		if (this == &src)
		{
			return *this;
		}
		if (true)
		{
			list temp;
			temp.head = this->head;
		}
		if (true)
		{
			list temp = src;
			this->head = temp.head;
			this->count = temp.count;
			temp.head = NULL;
			temp.count = 0;
		}
		return *this;
	}
	//this is the overloaded funtion of square brackets that is used highlight the Indexed Nature of Lists.
	cNode& list::operator[] (int index)
	{
		if (index <= 0)
		{
			return *head;
		}
		if (index >= count)
		{
			index = count;
		}
		cNode* rptr = head;
		for (int i = 0; i < index; i++)
		{
			rptr = rptr->next;
		}
		return *rptr;
	}
	//this function of insert adds node at start of list
	list& list::insert(cNode*& ptr)
	{
		ptr->next = head;
		head = ptr;
		ptr = NULL;
		++count;
		return *this;
	}
	//this function of insertAt adds node at certain index of list
	list& list::inserAt(int index, cNode*& ptr)
	{
		if (index <= 0)
		{
			insert(ptr);
			return *this;
		}
		if (index > count)
		{
			index = count;
		}
		cNode* rptr = head;
		for (int i = 1; i < index; ++i)
		{
			rptr = rptr->next;
		}
		ptr->next = rptr->next;
		rptr->next = ptr;
		ptr = NULL;
		++count;
		return *this;
	}
	//this function of remove removes a node from list
	cNode* list::remove()
	{
		cNode* temp = head;
		head = head->next;
		temp->next = NULL;
		--count;
		return temp;
	}
	//this function of removeAt removes node from certain index
	cNode* list::removeAt(int index)
	{
		if (index <= 0)
		{
			return remove();
		}
		if (index >= count)
		{
			index = count-1 ;
		}
		cNode* rptr = head;
		for (int i = 1; i < index; ++i)
		{
			rptr = rptr->next;
		}
		cNode* ptr;
		ptr = rptr->next;
		rptr->next = ptr->next;
		ptr->next = NULL;
		--count;
		return ptr;

	}
	//this function of Reverse changes the order of list.
	list& list::reverse()
	{
		if (count < 2)
		{
			return *this; //When only one node is present in the list 
		}
		cNode* rptr=head;
		cNode** ARR = new cNode * [count];
		
		for (int i = 0; i < count; ++i) 
		{
			ARR[i] = rptr;
			rptr = rptr->next;
			
		}
		for (int i = 1; i < count; i++)
		{
			ARR[i]->next = ARR[i - 1];
		}
		ARR[0]->next = NULL;
		head = ARR[count - 1];
		delete[] ARR;
		return *this;
	}
	//this function of Swap exchanges the position of these two nodes.
	list& list::swapOfNodesAt(int index1, int index2)
	{
		if (index1 < 0) index1 = 0;
		if (index2 < 0)	index2 = 0;
		if (index1 >= count) index1 = count - 1;
		if (index2 >= count) index2 = count - 1;
		if (index1 == index2) return *this;
		if (index1 < index2)
		{
			cNode* ptr1 = removeAt(index1);
			inserAt((index2 - 1), ptr1);
			cNode* ptr2 = removeAt(index2);
			inserAt((index1), ptr2);
		}
		else
		{
			cNode* ptr1 = (removeAt(index2));
			inserAt((index1 - 1), ptr1);
			cNode* ptr2 = (removeAt(index1));
			inserAt((index2), ptr2);
		}
		return *this;
	}
	
	//this is the print function that prints the value of nodes.
	void list::print() const
	{
		if (!head)
		{
			cout << "the following structure is empty " << endl;
		}
		else
		{
			cNode* ptr = head;
			for(int i=0;i<count;i++)
			{
				ptr->print();
				ptr = ptr->next;
			}
		}

	}
	//Function for writing LIST data to file
	void list::writeListToFile(ofstream& outFile) 
	{
		if (!(outFile.is_open())) 
		{
			cerr << "File did not open in writeListToFile Function ";
			exit(1);
		}
		else 
		{
			outFile.write((char*)&count, sizeof(count));

			if (count > 0) 
			{
				cNode* rptr = head;
				for (int i = 0; i < count; ++i) 
				{
					rptr->writeNodetoFile(outFile);
					rptr = rptr->next;
				}
			}
		}
	}
	//Function for reading LIST data from file
	void list::readListFromFile(ifstream& inFile) 
	{
		if (true) 
		{ list temp; 
		temp.head = this->head; 
		}
		if (!(inFile.is_open())) 
		{
			cerr << "File is not opened for reading !";
			exit(1);
		}
		else 
		{
			inFile.read((char*)&count, sizeof(count));
			if (count > 0) 
			{
				cNode* rptr = head = new cNode(inFile);
				for (int i = 1; i < count; ++i) 
				{
					rptr->next = new cNode(inFile);
					rptr = rptr->next;
				}
				rptr->next = NULL;
			}
		}
	}
	//this is the recursive function that is used to delete nodes from list.
	void list::deleteNodes(cNode* ptr)
	{
		if (ptr)
		{
			deleteNodes(ptr->next);
			delete ptr;
		}
	}
	//this is destructor that is used to free the dynamically allocated memory to system
	list::~list()
	{
		deleteNodes(head);
	}



