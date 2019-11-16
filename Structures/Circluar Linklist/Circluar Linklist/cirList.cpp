#include "cirList.h"
using namespace std;

	cirList::cirList() : head(NULL), count(0) {}
	cirList::cirList(cNode*& ptr) : head(ptr), count(1)
	{
		head->next = NULL;
		ptr = NULL;
	}
	cirList::cirList(const cirList& src)
	{
		this->head = src.head;
		this->count = src.count;
		if (count > 0)
		{
			cNode* sptr, * dptr;
			dptr = head = new cNode(*src.head);
			sptr = src.head->next;
			for (int i = 1; i < count; i++)
			{
				dptr->next = new cNode(*sptr);
				dptr = dptr->next;
				sptr = sptr->next;
			}
			dptr->next = head;
		}
	}
	cirList& cirList::operator=(const cirList& src)
	{
		if (this == &src)
		{
			return *this;
		}
		if (true)
		{
			cirList temp;
			temp.head = head;
			temp.count = count;
		}
		if (true)
		{
			cirList temp = src;
			head = temp.head;
			count = temp.count;
			temp.head = NULL;
			temp.count = 0;
			return *this;
		}

	}
	cNode& cirList::operator[] (int index)
	{
		if (index <= 0)
		{
			return *(head->next);
		}
		if (index >= count)
		{
			index = count - 1;
		}
		cNode* rptr = head->next;
		for (int i = 1; i <= index; i++)
		{
			rptr = rptr->next;
		}
		return *rptr;
	}

	cirList& cirList::insert(cNode*& ptr)
	{
		if (!head)
		{
			head = ptr;
			head->next = head;
		}
		else
		{
			ptr->next = head->next;
			head->next = ptr;
		}
		ptr = NULL;
		++count;
		return *this;
	}
	cirList& cirList::insertAt(int index, cNode*& ptr)
	{
		if (!head || count == 0)
		{
			return insert(ptr);
		}
		else
		{
			if (index <= 0)
			{
				return insert(ptr);
			}
			if (index > count)
			{
				index = count;
			}
			cNode* rptr = head->next;
			for (int i = 1; i < index; i++)
			{
				rptr = rptr->next;
			}
			ptr->next = rptr->next;
			if (count == index)
			{
				head = ptr;
			}
			rptr->next = ptr;
			ptr = NULL;
			++count;

		}
		return *this;
	}

	cNode* cirList::remove()
	{
		cNode* ptr = head;
		if (count < 1)
		{
			ptr = head;
			head = NULL;
		}
		else
		{
			ptr = head->next;
			head->next = ptr->next;
		}
		ptr->next = NULL;
		--count;
		return ptr;
	}


	cNode* cirList::removeAt(int index)
	{
		if (index <= 0 || count == 1)
		{
			return remove();
		}
		if (index >= count)
		{
			index = count - 1;
		}
		cNode* rptr = head->next;
		cNode* ptr;
		for (int i = 1; i < index; i++)
		{
			rptr = rptr->next;
		}
		if (index == (count - 1))
		{
			head = rptr;
		}
		ptr = rptr->next;
		rptr->next = ptr->next;
		ptr->next = NULL;
		--count;
		return ptr;

	}

	cirList& cirList::swapOfNodesAt(int index1, int index2)
	{
		if (index1 < 0) index1 = 0;
		if (index2 < 0) index2 = 0;
		if (index1 >= count) index1 = count - 1;
		if (index2 >= count) index2 = count - 1;
		if (index1 == index2) return *this;
		if (index1 < index2)
		{
			cNode* ptr1 = (removeAt(index1));
			insertAt((index2 - 1), ptr1);
			cNode* ptr2 = (removeAt(index2));
			insertAt((index1), ptr2);
		}
		else
		{
			cNode* ptr3 = (removeAt(index2));
			insertAt((index1 - 1), ptr3);
			cNode* ptr4 = (removeAt(index1));
			insertAt((index2), ptr4);
		}
		return*this;
	}

	cirList& cirList::reverse()
	{
		if (count < 2)
		{
			return *this;
		}
		cNode* rptr = head->next;
		cNode** ARR = new cNode * [count];
		for (int i = 0; i < count; i++)
		{
			ARR[i] = rptr;
			rptr = rptr->next;
		}
		for (int i = 1; i < count; i++)
		{
			ARR[i]->next = ARR[i - 1];
		}

		ARR[0]->next = ARR[count - 1];
		head = ARR[0];
		delete[]ARR;
		return *this;
	}
	cirList& cirList::flip()
	{
		reverse();
		head = head->next;

		return *this;
	}

	void cirList::print() const
	{
		if (count > 0)
		{
			cNode* ptr = head->next;
			for (int i = 0; i < count; i++)
			{
				ptr->print();
				ptr = ptr->next;
			}
			cout << endl;
		}
		else
		{
			cout << "The Following Structure is Empty " << endl;
		}
	}

	cirList::~cirList()
	{
		cNode* ptr;
		ptr = head;
		for (int i = 0; i < count; i++)
		{
			ptr = ptr->next;
			delete head;
			head = ptr;
		}
	}