#include<iostream>
#include "Priority_Que.h"
using namespace std;
int main()
{
	/*------------------------------------------------------------------------------------------------------
		In this Code block we are going to create some nodes and we are going to set their data and priority
	 -------------------------------------------------------------------------------------------------------*/
	cNode* n1 = new cNode();
	n1->setData(10);
	n1->setPriority(4);
	cNode* n2 = new cNode();
	n2->setData(440);
	n2->setPriority(10);
	cNode* n3 = new cNode();
	n3->setData(3450);
	n3->setPriority(1);
	cNode* n4 = new cNode;
	n4->setData(234);
	n4->setPriority(12);
	/*------------------------------------------------------------------------------------------------
	In this Code block we are going to create Queue and check whether its empty or not
---------------------------------------------------------------------------------------------------*/
	cPriorityQue q1;
	cout << "Using isEmpty function to check whether Queue is empty or not " << endl;
	cout << q1.isEmpty() << endl << "As we can see output is 1 so Queue is empty " << endl;
	/*-------------------------------------------------------------------------------------------------------------------
		In this Code block we are going to ADD and REMOVE some nodes in Queue according to their priority and print them
	  -------------------------------------------------------------------------------------------------------------------*/
	q1.add(n1).add(n2).add(n3).add(n4);
	cout << "Inserting nodes in class \nThe values are :" << endl;
	q1.print();
	q1.remove();
	cout << "Removing node And printing values" << endl << "The values are :" << endl;
	q1.print();
	/*------------------------------------------------------------------------------------------------------------------------------------
		In this Code block we are going to use Copy Constructor and Overloaded Assignment Operator and then print the values of Queues.
	 -------------------------------------------------------------------------------------------------------------------------------------*/
	cPriorityQue q2(q1);
	cout << "Using Copy Constructor on new queue " << endl << "The values are :" << endl;
	q2.print();
	cPriorityQue q3;
	cout << "Uisng Assignment operator " << endl;
	q3 = q1;
	cout << "Printing the values of new queue " << endl;
	q3.print();



}