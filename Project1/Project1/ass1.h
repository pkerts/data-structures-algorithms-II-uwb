#pragma once
#include <iostream>
#include <string>

using namespace std;

class ass1
{
protected:
	struct Node {
		string data;
		int count;
		Node* left;
		Node* right;
		Node() : count(1) {}
		~Node()
		{
			left = nullptr;
			right = nullptr;
		}
	};
	Node* root_;

	void Add(string data, Node* ptr);
	Node* CreateLeaf(string data);
	void Display(Node* ptr);
	void WriteToFile(Node* ptr, ofstream& outfile);

public:
	ass1();
	~ass1();

	void Add(string data);
	void Display();
	void WriteToFile();

};

