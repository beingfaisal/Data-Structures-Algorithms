#pragma once
#include<iostream>
#include<fstream>
#include"List.h"
using namespace std;
int main()
{
	/*--------------------------------------------------------------------------------------------------------------------------------
							 In this Code block we are going to create some nodes and we are going to set their values.
       ---------------------------------------------------------------------------------------------------------------------------------*/
	cNode* n1 = new cNode(10);
	cNode* n2 = new cNode(20);
	cNode* n3 = new cNode(30);
	cNode* n4 = new cNode(40);
	cNode* n5 = new cNode(50);
	cNode* n6 = new cNode(60);
	cNode* n7 = new cNode(70);
	cNode* n8 = new cNode(80);
	/*-----------------------------------------------------------------------------------------------------------------------------------
								In this Code block we are going to create a list and insert some nodes in list.
	  ------------------------------------------------------------------------------------------------------------------------------------*/
	list l1;
	l1.insert(n1).insert(n2).insert(n3);
	cout << "After inserting the values \nThe values are :" << endl;
	l1.print();
	/*------------------------------------------------------------------------------------------------------------------------------------
										In this Code block we are going to remove a node from list
	---------------------------------------------------------------------------------------------------------------------------------------*/
    l1.remove();
	cout << "After removing a node \nThe values are :" << endl;
	l1.print();
	/*-----------------------------------------------------------------------------------------------------------------------------------
								  In this Code block we are going to add a node at certain index of list.
	  ------------------------------------------------------------------------------------------------------------------------------------*/
	l1.inserAt(2, n4);
	cout << "After inserting the value at index 2 \nThe values are :" << endl;
	l1.print();
	/*-----------------------------------------------------------------------------------------------------------------------------------
								     In this Code block we are going to remove a node at certain index.
	  ------------------------------------------------------------------------------------------------------------------------------------*/
	l1.removeAt(1);
	cout << "After removing a node at index 1 \nThe values are :" << endl;
	l1.print();
	/*-----------------------------------------------------------------------------------------------------------------------------------
						  In this Code block we are going to use Copy Constructor to initialize a new list
	  ------------------------------------------------------------------------------------------------------------------------------------*/
	list l2(l1);
	cout << "Using a asssignment operaor to initialize another list \nThe Values are : " << endl;
	l2.print();
	/*-----------------------------------------------------------------------------------------------------------------------------------
								In this Code block we are going to add some news nodes in new list.
	  ------------------------------------------------------------------------------------------------------------------------------------*/
	l2.insert(n5).insert(n6);
	cout << "Now adding a new node in Copied list \nThe values are : " << endl;
	l2.print();
	/*-----------------------------------------------------------------------------------------------------------------------------------
								In this Code block we are going to use Reverse Function on 2nd List.
	  ------------------------------------------------------------------------------------------------------------------------------------*/
	cout << "Using The Function of Reverse " << endl;
	l2.reverse();
	l2.print();
	/*-----------------------------------------------------------------------------------------------------------------------------------
								In this Code block we are going to Swap two nodes from list.
	  ------------------------------------------------------------------------------------------------------------------------------------*/
	cout << "Using Funtion of SwapNodes to Swap two nodes from index of 1 and 4 "<< endl;
	l2.swapOfNodesAt(1, 10);
	l2.print();
	/*-----------------------------------------------------------------------------------------------------------------------------------
								In this Code block we are going to test the Indexed Nature of List
	  ------------------------------------------------------------------------------------------------------------------------------------*/
	cout << "Now using the overloaded operator of square brackets to test \n";
	l2[2].print();
	/*-----------------------------------------------------------------------------------------------------------------------------------
				     	In this Code block we are going to test the Overloaded Operator of Addition on Two lists. 
	  ------------------------------------------------------------------------------------------------------------------------------------*/
	cout << "Now we are goiing to use the overloaded operator of Addition \n";
	cout << "Before addition of lists the values of 1st list are : \n";
	l1.print();
	cout << "And the values of second list are : \n";
	l2.print();
	cout << "After addition the values are : \n";
	l1 + l2;
	l1.print();
	/*-----------------------------------------------------------------------------------------------------------------------------------
					In this Code block we are going to test the file handling in list and write the nodes in file.
	  ------------------------------------------------------------------------------------------------------------------------------------*/
	ofstream outFile;
	outFile.open("data.txt");
	cout <<endl<< "Writng the data into File\n";
	l1.writeListToFile(outFile);
	cout << "Wrote Data into File \n\n";
	outFile.close();
	/*-----------------------------------------------------------------------------------------------------------------------------------
				 In this Code block we are going to test the file handling in list and read nodes from file and print them
	  ------------------------------------------------------------------------------------------------------------------------------------*/
	ifstream inFile;
	inFile.open("data.txt");
	list l3;
	cout << "Reading Data from list \n";
	l3.readListFromFile(inFile);
	cout << "Read Data From List \n";
	inFile.close();
	cout << "\nPrinting the values of nodes of new List added by File Handling of new list " << endl;
	l3.print();
	
	system("pause");

}
