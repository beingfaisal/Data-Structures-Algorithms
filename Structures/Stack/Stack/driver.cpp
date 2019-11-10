#include<iostream>
#include<fstream>
#include "Node.h"
#include "Stack.h"
using namespace std;
int main()
{   
   /*-------------------------------------------------------------------------------------------------------------------------------------
						In this Code block we are going to create some nodes and we are going to set their data.
	---------------------------------------------------------------------------------------------------------------------------------------*/
	cNode* n1 = new cNode(10);
	cNode* n2 = new cNode(20);
	cNode* n3 = new cNode(30);
	cNode* n4 = new cNode(40);
	/*-------------------------------------------------------------------------------------------------------------------------------------
							In this Code block we are going to create stack and check whether its empty or not.
	----------------------------------------------------------------------------------------------------------------------------------------*/
	cStack s1;
	cout << "Using isEmpty function to check whether stack is Empty or Not " << endl;
	cout << s1.isEmpty() << endl << "As we can see output is 1 so stack is Empty " << endl;
	/*---------------------------------------------------------------------------------------------------------------------------------------
								In this Code block we are going to PUSH and POP some nodes in stack and print them
	------------------------------------------------------------------------------------------------------------------------------------------*/
	s1.push(n1).push(n2).push(n3).push(n4);
	cout << "\nInserting nodes in class \nThe values are :" << endl;
	s1.print();
	s1.pop();
	cout << "Removing node And printing values"<<endl<<"The values are :"<<endl;
	s1.print();
	/*-------------------------------------------------------------------------------------------------------------------------------------------
			In this Code block we are going to use Copy Constructor and Overloaded Assignment Operator and then print the values of stacks
     --------------------------------------------------------------------------------------------------------------------------------------------*/
	cStack s2(s1);
	cout << "\nUsing Copy Constructor on new stack " << endl << "The values are :" << endl;
	s2.print();
	cStack s3;
	cout << "\nUisng Assignment operator " << endl;
	s3 = s1;
	cout << "Printing the values of new stack " << endl;
	s3.print();
	/*---------------------------------------------------------------------------------------------------------------------------------------
									In this Code block we are going to ouptput the data into a file
	  ----------------------------------------------------------------------------------------------------------------------------------------*/
	ofstream outFile;
	outFile.open("data.txt");
	cout << "\nStarted writing to file !" << endl;
	s1.writeToFile(outFile);
	cout << "Done writing to file !" << endl;
	outFile.close();
	/*------------------------------------------------------------------------------------------------------------------------------------------
						In this Code block we are going to create take input from file and print the value in the stack
	  -------------------------------------------------------------------------------------------------------------------------------------------*/
	ifstream inFile;
	inFile.open("data.txt");
	cStack s4;
	cout << "\nReading the data from files into Stack." << endl;
	s4.readFromFile(inFile);
	cout << "Done Reading from file!\n";
	inFile.close();
	cout << "\nPrinting Stack that has gained values from File Handling." << endl;
	s1.print();

	

}