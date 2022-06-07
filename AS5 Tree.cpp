#include "Tree.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "ukr");
	Tree tree;
	tree.AddNode(5);
	tree.AddNode(20);
	tree.AddNode(15);
	tree.AddNode(10);
	tree.AddNode(65);

	cout << "Інформація про дерево:" << endl;
	tree.ShowTree();

	cout << endl << "Введіть номер для видалення: ";
	int number;
	cin >> number;

	tree.DeleteNode(number);

	cout << endl << "Інформація про дерево:" << endl;
	tree.ShowTree();

	return 0;
}