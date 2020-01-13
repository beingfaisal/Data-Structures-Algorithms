#pragma once
#include<iostream>
#include"Node.h"
using namespace std;
class cDoublyLinkList
{
private:
	cNode* leftHead;
	cNode* rightHead;
	int count;
public:
	cDoublyLinkList();
	cDoublyLinkList(cNode*& ptr);
	cDoublyLinkList(const cDoublyLinkList& src);
	void print()const;
	cDoublyLinkList& insertRight(cNode*& ptr);
	cDoublyLinkList& insertLeft(cNode*& ptr);
	cNode* removeLeft();
	cNode* removeRight();
	cDoublyLinkList& insertAt(int index, cNode*& ptr);
	cNode* removeAt(int index);
	void swap(int index1, int index2);
	~cDoublyLinkList();

};