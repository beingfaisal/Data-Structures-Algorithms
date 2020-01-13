#include<iostream>
#include "cDoublyLinkList.h"
using namespace std;

cDoublyLinkList::cDoublyLinkList() : leftHead(NULL), rightHead(NULL), count(0) {}
cDoublyLinkList::cDoublyLinkList(cNode*& ptr) : count(1)
{
	leftHead = ptr;
	rightHead = ptr;
	rightHead->left = leftHead->right = NULL;
}
cDoublyLinkList::cDoublyLinkList(const cDoublyLinkList& src)
{
	this->rightHead = src.rightHead;
	this->leftHead = src.leftHead;
	this->count = src.count;
	if (count > 0)
	{
		cNode* sptr;
		cNode* dptr;
		leftHead = dptr = new cNode(*src.leftHead);
		sptr = src.leftHead->right;
		while (sptr)
		{
			dptr->right = new cNode(*sptr);
			(dptr->right)->left = dptr;
			sptr = sptr->right;
			dptr = dptr->right;
		}
		rightHead = dptr;
	}
}
void cDoublyLinkList::print() const
{
	cNode* rptr = leftHead;
	for (int i = 0; i < count; i++)
	{
		rptr->print();
		rptr = rptr->right;
	}
}
cDoublyLinkList& cDoublyLinkList::insertRight(cNode*& ptr)
{
	ptr->left = rightHead;
	if (rightHead) rightHead->right = ptr;
	else leftHead = ptr;
	rightHead = ptr;
	rightHead->right = ptr = NULL;
	++count;
	return *this;
}
cDoublyLinkList& cDoublyLinkList::insertLeft(cNode*& ptr)
{
	ptr->right = leftHead;
	if (leftHead) leftHead->left = ptr;
	else rightHead = ptr;
	leftHead = ptr;
	leftHead->left = ptr = NULL;
	++count;
	return *this;
}
cNode* cDoublyLinkList::removeLeft()
{
	cNode* ptr;
	ptr = leftHead;
	leftHead = leftHead->right;
	leftHead->left = NULL;
	--count;
	return ptr;
}
cNode* cDoublyLinkList::removeRight()
{
	cNode* ptr = rightHead;
	rightHead = rightHead->left;
	rightHead->right = NULL;
	--count;
	return ptr;
}
cDoublyLinkList& cDoublyLinkList::insertAt(int index, cNode*& ptr)
{
	if (index <= 0)
	{
		insertLeft(ptr);
		return *this;
	}
	if (index >= count)
	{
		insertRight(ptr);
		return *this;
	}
	cNode* rptr;
	if (index < (count / 2))
	{
		rptr = leftHead;
		for (int i = 1; i < index; i++)
		{
			rptr = rptr->right;
		}
	}
	else
	{
		rptr = rightHead;
		for (int i = count - 1; i >= index; i--)
		{
			rptr = rptr->left;
		}
	}
	ptr->left = rptr;
	(rptr->right)->left = ptr;
	ptr->right = rptr->right;
	rptr->right = ptr;
	++count;
	return *this;
}
cNode* cDoublyLinkList::removeAt(int index)
{
	if (index <= 0)
	{
		return removeLeft();
	}
	if (index >= count-1)
	{
		return removeRight();
	}
	cNode* rptr;
	if (index < (count / 2))
	{
		rptr = leftHead;
		for (int i = 1; i <= index; i++)
		{
			rptr = rptr->right;
		}
	}
	else
	{
		rptr = rightHead;
		for (int i = count-1; i > index; --i)
		{
			rptr = rptr->left;
		}
		
	}
	(rptr->left)->right = rptr->right;
	(rptr->right)->left = rptr->left;
	rptr->right = NULL;
	rptr->left = NULL;
	--count;
	return rptr;
}
void cDoublyLinkList::swap(int index1, int index2)
{
	if (index1 < 0) index1 = 0;
	if (index2 < 0) index2 = 0;
	if (index1 >= count) index1 = count - 1;
	if (index2 >= count) index2 = count - 1;
	cNode* rptr = leftHead;
	cNode* sptr = rightHead;
	cNode* bptr;
	for (int i = 0; i < index1; i++)    rptr = rptr->right;
	for (int i = count - 1; i > index2; i--) sptr = sptr->left;
	
	if (rptr->right)
	{
		(rptr->right)->left = sptr;
		bptr = rptr->right;
		rptr->right = sptr->right;
		if (sptr->right) (sptr->right)->left = rptr;
		sptr->right = bptr;
	
	}
	else
	{
		rptr->right = sptr->right;
		if (sptr->right)  (rptr->right)->left = rptr;
		sptr->right = NULL;
	}
	
	if (rptr->left)
	{
		(rptr->left)->right = sptr;
		bptr = rptr->left;
		rptr->left = sptr->left;
		if (sptr->left)
		{
			(sptr->left)->right = rptr;
		}
		sptr->left = bptr;
	} 
	else
	{
		rptr->left = sptr->left;
		if(sptr->left) (rptr->left)->right = rptr;
		sptr->left = NULL;
	}
	
	
	if (index1 <= 0)	leftHead = sptr;
	if (index2 >= count - 1)	rightHead = rptr;

}

cDoublyLinkList::~cDoublyLinkList()
{
	for (int i = 0; i < count; i++)
	{
		rightHead = leftHead;
		leftHead = leftHead->right;
		delete rightHead;
	}
}