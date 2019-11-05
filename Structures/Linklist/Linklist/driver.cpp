#include<iostream>
#include<fstream>
#include"List.h"
using namespace std;
int main()
{
	cnode* n1 = new cnode();
	n1->setData(129);
	cnode* n2 = new cnode();
	n2->setData(714);
	cnode* n3 = new cnode();
	n3->setData(141);
	cnode* n4 = new cnode;
	n4->setData(685);
	cnode* n5 = new cnode();
	n5->setData(986);

	list l1;
	l1.insert(n1).insert(n2).insert(n3);
	cout << "After inserting the values \nThe values are :" << endl;
	l1.print();
	l1.remove();
	cout << "After removing a node \nThe values are :" << endl;
	l1.print();
	l1.inserAt(2, n4);
	cout << "After inserting the value at index 2 \nThe values are :" << endl;
	l1.print();
	l1.removeAt(1);
	cout << "After removing a node at index 1 \nThe values are :" << endl;
	l1.print();
	list l2(l1);
	cout << "Using a copy constructor to initialize another list \nThe Values are : " << endl;
	l2.print();
	l2.insert(n5);
	cout << "Now adding a new node in Copied list \nThe values are : " << endl;
	l2.print();
	cout << "Using The Function of Reverse " << endl;
	l2.reverse();
	l2.print();
	cout << "Using Swap_nodes to swap two nodes " << endl;
	l2.swapOfNodesAt(1, 2);
	l2.print();

	list l3;
	ofstream outFile;
	outFile.open("data.txt");

	if (outFile.is_open()) 
	{
		cout << "\nStarted writing to file !" << endl;
		l1.writeListToFile(outFile);
		cout << "Done writing to file !" << endl;
	}
	else {
		cout << "File not opened for writing !" << endl;
	}

	outFile.close();



	ifstream inFile;
	inFile.open("data.txt");
	

	if (inFile.is_open()) {
		cout << "\nReading data of linkList from file data.txt" << endl;
		l3.readListFromFile(inFile);
		cout << "Done Reading from file !\n";
	}
	else 
	{
		cout << "The file is not opened for the Read operation !" << endl;
	}

	cout << "Printing list object Read from file" << endl;
	l3.print();

	inFile.close();



	system("pause");

}
