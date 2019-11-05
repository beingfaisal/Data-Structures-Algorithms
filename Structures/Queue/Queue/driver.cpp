#include<iostream>
#include"Queue.h"
using namespace std;
int main()
{
	/*------------------------------------------------------------------------------------------------
		In this Code block we are going to create some nodes and we are going to set their data
	---------------------------------------------------------------------------------------------------*/
	cNode* n1 = new cNode();
	n1->setData(20);
	cNode* n2 = new cNode();
	n2->setData(70);
	cNode* n3 = new cNode();
	n3->setData(100);
	cNode* n4 = new cNode;
	n4->setData(200);
	/*------------------------------------------------------------------------------------------------
	In this Code block we are going to create Queue and check whether its empty or not
---------------------------------------------------------------------------------------------------*/
	cQueue q1;
	cout << "Using isEmpty function to check whether Queue is empty or not " << endl;
	cout << q1.isEmpty() << endl << "As we can see output is 1 so Queue is empty " << endl;
	/*------------------------------------------------------------------------------------------------
		In this Code block we are going to ADD and REMOVE some nodes in Queue and print them
	---------------------------------------------------------------------------------------------------*/
	q1.add(n1).add(n2).add(n3).add(n4);
	cout << "Inserting nodes in class \nThe values are :" << endl;
	q1.print();
	q1.remove();
	cout << "Removing node And printing values" << endl << "The values are :" << endl;
	q1.print();
	/*------------------------------------------------------------------------------------------------------------------------------------
		In this Code block we are going to use Copy Constructor and Overloaded Assignment Operator and then print the values of Queues.
	 -------------------------------------------------------------------------------------------------------------------------------------*/
	cQueue q2(q1);
	cout << "Using Copy Constructor on new queue " << endl << "The values are :" << endl;
	q2.print();
	cQueue q3;
	cout << "Uisng Assignment operator " << endl;
	q3 = q1;
	cout << "Printing the values of new queue " << endl;
	q3.print();


}
