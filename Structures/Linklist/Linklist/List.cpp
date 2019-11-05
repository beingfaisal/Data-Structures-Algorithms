#include "List.h"
#pragma once
#include<iostream>
#include<fstream>
#include"Node.h"
using namespace std;

	list::list() :head(NULL), count(0) {}

	list::list(cnode*& ptr) : head(ptr), count(1)
	{
		head->next = NULL;
		ptr = NULL;
	}

	list::list(const list& src) :head(src.head), count(src.count)
	{
		if (count > 0)
		{
			cnode* dptr, * sptr;
			dptr = head = new cnode(*src.head);
			sptr = src.head->next;
			while (sptr)
			{
				dptr->next = new cnode(*sptr);
				sptr = sptr->next;
				dptr = dptr->next;
			}

			dptr->next = NULL;
		}
	}

	void list::deleteNodes(cnode* ptr)
	{
		if (ptr)
		{
			deleteNodes(ptr->next);
			delete ptr;
		}
	}

	list& list::insert(cnode*& ptr)
	{
		ptr->next = head;
		head = ptr;
		ptr = NULL;
		++count;
		return *this;
	}

	list& list::inserAt(int index, cnode*& ptr)
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
		cnode* rptr = head;
		for (int i = 1; i < index - 1; ++i)
		{
			rptr = rptr->next;
		}
		ptr->next = rptr->next;
		rptr->next = ptr;
		ptr = NULL;
		++count;
		return *this;
	}

	cnode* list::remove()
	{
		cnode* temp = head;
		head = head->next;
		temp->next = NULL;
		--count;
		return temp;
	}

	cnode* list::removeAt(int index)
	{
		if (index <= 0)
		{
			return remove();
		}
		if (index >= count)
		{
			index = count ;
		}
		cnode* rptr = head;
		for (int i = 1; i < index - 1; ++i)
		{
			rptr = rptr->next;
		}
		cnode* ptr;
		ptr = rptr->next;
		rptr->next = ptr->next;
		ptr->next = NULL;
		--count;
		return ptr;

	}

	list& list::reverse()
	{
		if (count < 2)
		{
			return *this; //When only one node is present in the list 
		}
		cnode* rptr=head;
		cnode** ARR = new cnode * [count];
		
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

	list& list::operator+(const list& robj)
	{
		if (robj.count == 0)
		{
			return *this;
		}//when second list is empty
		list rCopy = robj;
		if (!head) head = rCopy.head;
		else 
		{
			cnode* ptr = head;
			for (int i = 0; i < count; ++i) 
			{
				ptr = ptr->next; 
			}
			ptr->next = rCopy.head;
			count += rCopy.count;
		}
		rCopy.head = NULL;
		return *this;
	}


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
			list temp =src;
			this->head = temp.head; 
			temp.head = NULL; 
		}
		return *this;
	}

	list& list::swapOfNodesAt(int index1, int index2)
	{
		if (index1 < 0)
		{
			index1 = 0;
		}
		if (index2 < 0)
		{
			index2 = 0;
		}
		if (index1 >= count) 
		{
			index1 = count - 1;
		}
		if (index2 >= count) 
		{
			index2 = count - 1;
		}
		if (index1 == index2)
		{
			return *this;
		}
		if (index1 < index2)
		{
			cnode* ptr1 = removeAt(index1);
			inserAt((index2-1 ), ptr1);
			cnode *ptr2 = removeAt(index2);
			inserAt((index1-1), ptr2);
		}
		else
		{
			cnode* ptr3 = (removeAt(index2));
			inserAt((index1 - 1), ptr3);
			cnode* ptr4 = (removeAt(index1));
			inserAt((index2 ), ptr4);
		}
		return *this;
	}

	void list::print() const
	{
		if (!head)
		{
			cout << "the following structure is empty " << endl;
		}
		else
		{
			cnode* ptr = head;
			for(int i=0;i<count;i++)
			{
				ptr->print();
				ptr = ptr->next;
			}
		}

	}




	//Constructors for FILE HANDLING 'INPUT DATA FROM FILE'
	list::list(ifstream& inFile) :head(NULL), count(0) {
		inFile.read((char*)&count, sizeof(count));
		if (count > 0) {
			cnode* ptr;
			ptr = head = new cnode(inFile);
			for (int i = 1; i < count; ++i) {
				ptr->next = new cnode(inFile);
				ptr = ptr->next;
			}
			ptr->next = NULL;
		}
	}

	//Constructors for FILE HANDLING 'OUTPUT DATA TO FILE'
	list::list(ofstream& outFile) {
		outFile.write((char*)&count, sizeof(count));
		if (count > 0) {
			cnode* ptr = head;
			ptr = new cnode(outFile);
			for (int i = 1; i < count; i++) {
				ptr->next = new cnode(outFile);
				ptr = ptr->next;
			}
		}
	}

	//Function for writing LIST data to file
	void list::writeListToFile(ofstream& oFile) {
		if (!(oFile.is_open())) {
			cout << "File is not opened for writing !" << endl;
		}
		else {
			oFile.write((char*)&count, sizeof(count));

			if (count > 0) {
				cnode* rptr = head;
				for (int i = 0; i < count; ++i) {
					rptr->writeNodetoFile(oFile);
					rptr = rptr->next;
				}
			}
		}
	}

	//Function for reading LIST data from file
	void list::readListFromFile(ifstream& inFile) {
		if (true) { list temp; temp.head = this->head; }

		if (!(inFile.is_open())) {
			cout << "File is not opened for writing !" << endl;
		}
		else {
			inFile.read((char*)&count, sizeof(count));
			cout << "The count read is " << count << endl;
			if (count > 0) {
				cnode* rptr = head = new cnode(inFile);
				for (int i = 1; i < count; ++i) {
					rptr->next = new cnode(inFile);
					rptr = rptr->next;
				}
				rptr->next = NULL;
			}
		}
	}





	list::~list()
	{
		deleteNodes(head);
	}



