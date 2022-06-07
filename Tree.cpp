#include "Tree.h"

Tree::Tree()
{
	root = nullptr;
}

Tree::~Tree()
{
	ClearTree();
}

void Tree::AddNode(int data)
{
	if (root == nullptr)
	{
		root = new Node(data);
		return;
	}

	Node* current = this->root;

	while (true)
	{
		if (current->data > data)
			if (current->left != nullptr) current = current->left;
			else { current->left = new Node(data); break; }
		else
			if (current->right != nullptr) current = current->right;
			else { current->right = new Node(data); break; }
	}
}

Node* Tree::DeleteNode(int data, Node* node)
{
	if (node == NULL) return 0;
	if (data < node->data) node->left = DeleteNode(data, node->left);
	else if (data > node->data) node->right = DeleteNode(data, node->right);
	else
	{
		//no branch
		if (node->left == NULL && node->right == NULL)
		{
			delete node;
			node = nullptr;
		}
		//one branch
		else if (node->left == NULL)
		{
			Node* temp = node;
			if (node == root) root = node->right;
			node = node->right;
			delete temp;
		}
		else if (node->right == NULL)
		{
			Node* temp = node;
			if (node == root) root = node->right;
			node = node->left;
			delete temp;
		}
		//two branches
		else
		{
			Node* temp = node->right;
			while (temp->left != nullptr)
			{
				temp = temp->left;
			}
			node->data = temp->data;
			node->right = DeleteNode(temp->data, node->right);
		}
	}
	return node;
}

void Tree::DeleteNode(int data)
{
	DeleteNode(data, root);
}

void Tree::ShowTree()
{
	if (root == nullptr) return;
	cout << root->data << endl;
	ShowNode(root->left);
	ShowNode(root->right);
}

void Tree::ShowNode(Node* node)
{
	if (node == nullptr) return;
	cout << node->data << endl;
	ShowNode(node->left);
	ShowNode(node->right);
}

void Tree::ClearTree()
{
	if (root == NULL) return;
	ClearNode(root->left);
	ClearNode(root->right);
	delete root;
	root = nullptr;
}

void Tree::ClearNode(Node* node)
{
	if (node == NULL) return;
	ClearNode(node->left);
	ClearNode(node->right);
	delete node;
	node = nullptr;
}

Node* Tree::PARENT(Node* root, Node* temp)
{
	if (root == NULL) return nullptr;
	if (root->left == temp || root->right == temp)
		return root;

	return PARENT(root->left, temp);
	return PARENT(root->right, temp);
}

Node* Tree::LEFTMOST_CHILD(Node* n)
{
	while (n->left != nullptr)
	{
		n = n->left;
	}
	return n;
}

Node* Tree::RIGHT_SIBLING(Node* n)
{
	return PARENT(n)->right;
}

int Tree::LABEL(Node* n)
{
	return n->data;
}

Node* Tree::ROOT()
{
	return root;
}