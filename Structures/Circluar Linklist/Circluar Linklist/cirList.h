#pragma once
#include"Node.h"
class cirList
{
	cNode* head;
	int count;
public:
	cirList();
	cirList(cNode*& ptr);
	cirList(const cirList& src);
	cNode& operator[] (int index);
	cirList& operator=(const cirList& src);
	cirList& insert(cNode*& ptr);
	cirList& insertAt(int index, cNode*& ptr);
	cNode* remove();
	cNode* removeAt(int index);
	cirList& swapOfNodesAt(int index1, int index2);
	cirList& reverse();
	cirList& flip();
	void print() const;
	~cirList();


};

