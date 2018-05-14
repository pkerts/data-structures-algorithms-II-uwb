#include "ass1.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <typename Key, typename Value>
ass1<Key, Value>::ass1() : root_(nullptr)
{
}

template <typename Key, typename Value>
ass1<Key, Value>::~ass1()
{
}

// public add
template <typename Key, typename Value>
void ass1<Key, Value>::Add(Key data)
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
template <typename Key, typename Value>
void ass1<Key, Value>::Add(Key data, Node * ptr)
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

template <typename Key, typename Value>
typename ass1<Key, Value>::Node* ass1<Key, Value>::CreateLeaf(Key data)
{
	Node* n = new Node;
	n->data = data;
	n->left = nullptr;
	n->right = nullptr;

	return n;
}

template <typename Key, typename Value>
void ass1<Key, Value>::Display()
{
	if (root_)
		Display(root_);
	else
		cout << "Tree is empty" << endl;
}

template <typename Key, typename Value>
void ass1<Key, Value>::Display(Node* ptr)
{
	if (ptr->left)
		Display(ptr->left);
	cout << ptr->count << " " << ptr->data << endl;
	if (ptr->right)
		Display(ptr->right);
}

template <typename Key, typename Value>
void ass1<Key, Value>::WriteToFile()
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

template <typename Key, typename Value>
void ass1<Key, Value>::WriteToFile(Node * ptr, ofstream& outfile)
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
	ass1<string, int> yo;
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