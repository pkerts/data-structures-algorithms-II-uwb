#include "ass1.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ass1::ass1() : root_(nullptr)
{
}

ass1::~ass1()
{
}

// public add
void ass1::Add(string data)
{
	// lets add stuff to the tree
	// first check if tree is empty
	if (root_)
	{
		Add(data, root_);
	}
	else
		root_ = CreateLeaf(data);
}

// priv add
void ass1::Add(string data, Node * ptr)
{
	if (data < ptr->data)
	{
		if (ptr->left)
			Add(data, ptr->left);
		else
			ptr->left = CreateLeaf(data);
	}
	else if (data == ptr->data)
		++ptr->count;
	else if (data > ptr->data)
	{
		if (ptr->right)
			Add(data, ptr->right);
		else
			ptr->right = CreateLeaf(data);
	}
}

ass1::Node* ass1::CreateLeaf(string data)
{
	Node* n = new Node;
	n->data = data;
	n->left = nullptr;
	n->right = nullptr;

	return n;
}

void ass1::Display()
{
	if (root_)
		Display(root_);
	else
		cout << "Tree is empty" << endl;
}

void ass1::Display(Node* ptr)
{
	if (ptr->left)
		Display(ptr->left);
	cout << ptr->count << " " << ptr->data << endl;
	if (ptr->right)
		Display(ptr->right);
}

void ass1::WriteToFile()
{
	if (root_)
	{
		ofstream outfile("Write.txt");
		if (outfile.is_open())
			WriteToFile(root_, outfile);
		else cout << "Cannot open file to write in.\n";
		outfile.close();
	}
	else
		cout << "Tree is empty" << endl;
}

void ass1::WriteToFile(Node * ptr, ofstream& outfile)
{
	if (ptr->left)
		WriteToFile(ptr->left, outfile);
	// cout << ptr->count << " " << ptr->data << endl;
		outfile << ptr->count << " " << ptr->data << endl;
	if (ptr->right)
		WriteToFile(ptr->right, outfile);
}

int main()
{
	ass1 yo;
	cout << "hello" << endl;
	ifstream file("Read.txt");
	string str;
	if (file.is_open()) 
	{
		while (getline(file, str))
			{
				// Process str
				yo.Add(str);
				// cout << str << endl;
			}
		file.close();
	}
	
	else cout << "Unable to open file\n";

	yo.Display(); // here the function simply prints the words to the console
	// we must have this function open the file and write to it then close
	// should we rename it?
	// no, maybe lets just clone it and call it something else, like WriteToFile
	yo.WriteToFile();

	cin.get();
	return 0;
}