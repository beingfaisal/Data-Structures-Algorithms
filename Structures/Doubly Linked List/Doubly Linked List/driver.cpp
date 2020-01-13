#include<iostream>
#include"cDoublyLinkList.h"
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

	cDoublyLinkList l1;
	l1.insertLeft(n2).insertLeft(n1).insertRight(n3).insertRight(n4).insertRight(n5).insertRight(n6).insertRight(n7);	
	cout << "After Fast Insertions" << endl;
	l1.print();
	
	l1.insertAt(10, n8);
	cout << "after directed insertion" << endl;
	l1.print();
	
	l1.removeLeft();
	cout << "After Fast Removal" << endl;
	l1.print();

	l1.removeAt(3);
	cout << "After Directed Removal" << endl;
	l1.print();

	l1.swap(9, 0);
	cout << "After Swapping of Two Nodes" << endl;
	l1.print();
	

}