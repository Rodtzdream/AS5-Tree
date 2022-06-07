#pragma once
#include <iostream>

using namespace std;

struct Node
{
	Node(int data) { this->data = data; left = nullptr; right = nullptr; }
	int data;
	Node* left, * right;
};

class Tree
{
public:
	Tree();
	~Tree();

	void AddNode(int data);
	void DeleteNode(int data);
	void ShowTree();
	void ClearTree();

	Node* PARENT(Node* n);
	Node* LEFTMOST_CHILD(Node* n);
	Node* RIGHT_SIBLING(Node* n);
	int LABEL(Node* n);
	Node* ROOT();

private:
	Node* root;
	Node* DeleteNode(int data, Node* temp);
	void ShowNode(Node* node);
	void ClearNode(Node* node);
};