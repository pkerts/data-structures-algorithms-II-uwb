#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename Key, typename Value>
class ass1
{
protected:
	struct Node {
		Key data;
		Value count;
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

	void Add(Key data, Node* ptr);
	Node* CreateLeaf(Key data);
	void Display(Node* ptr);
	void WriteToFile(Node* ptr, ofstream& outfile);

public:
	ass1();
	~ass1();

	void Add(Key data);
	void Display();
	void WriteToFile();

};

