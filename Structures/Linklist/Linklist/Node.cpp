#pragma once
#include<iostream>
#include<fstream>
#include "Node.h"
using namespace std;

	cnode::cnode()
	{
		data = 0;
		next = NULL;
	}

	cnode::cnode(int d) : data(d)
	{
		next = NULL;
	}

	int cnode::getData() const
	{
		return data;
	}

	void cnode::setData(int d)
	{
		this->data = d;
	}

	void cnode::print() const
	{
		cout << data <<"	"<< endl;
	}



	//Constructors for File Handling
		cnode::cnode(ifstream & inFile) 
		{
			inFile.read((char*)this, sizeof(this)); 
		}
	    cnode::cnode(ofstream & oFile) 
	    {
		oFile.write((char*)this, sizeof(this)); 
	    }

	//Functions for File Handling
	void  cnode::writeNodetoFile(ofstream & outData) 
	{
		outData.write((char*)this, sizeof(this)); 
	}
	void  cnode::readNodefromFile(ifstream & inData) 
	{
		inData.read((char*)this, sizeof(this)); 
	}
