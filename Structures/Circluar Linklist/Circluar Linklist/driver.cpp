#include<iostream>
#include"cirList.h"
using namespace std;
int main()
{
	cNode* n1 = new cNode(10);
	cNode* n2 = new cNode(20);
	cNode* n3 = new cNode(30);
	cNode* n4 = new cNode(40);
	cNode* n5 = new cNode(50);
	cNode* n6 = new cNode(60);
	cNode* n7 = new cNode(70);
	cNode* n8 = new cNode(80);

	cirList l1;
	l1.insert(n1).insert(n2).insert(n3).insert(n4).insert(n5).insert(n6);
	l1.print();
	
	l1.remove();
	l1.print();

	l1.insertAt(5, n7);
	l1.print();

	l1.removeAt(6);
	l1.print();

	l1.reverse();
	l1.print();

	l1.swapOfNodesAt(2, 4);
	l1.print();

}