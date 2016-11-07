/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  mian file for tree implementation
 *
 *        Version:  1.0
 *        Created:  11/05/2016 01:25:54 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Grigor Bezirganyan
 *
 * =====================================================================================
 */

//Headers from standard libraries
#include <iostream>

//Headers from this project
#include "BinSearchTree.hpp"

void insert(BinSearchTree<int>* tree)
{
	int n;
	std::cout << "Please enter the number you want to insert: ";
	std::cin >>n;
	tree->insert(n);
}

void remove(BinSearchTree<int>* tree)
{
	int n;
	std::cout << "Please enter the number you want to remove: ";
	std::cin >>n;
	try {
		tree->remove(n);
	} catch (...) {
		std::cout << "Error: No such number" << std::endl;
	}
}

void print(BinSearchTree<int>* tree)
{
	std::cout << "\n+-------------------------------------" <<std::endl;
	std::cout << "|pre-order traversal : ";
	tree->preOrder(tree->getRoot());
	std::cout << "\n+-------------------------------------" <<std::endl;
	std::cout << "|In-order traversal  : ";
	tree->inOrder(tree->getRoot());
	std::cout << "\n+-------------------------------------" <<std::endl;
	std::cout << "|Post-order traversal : ";
	tree->postOrder(tree->getRoot());
	std::cout << "\n+-------------------------------------" <<std::endl;
}

void getHeight(BinSearchTree<int>* tree)
{
	std::cout << "\nThe height of the tree is: " <<
		tree->getHeight() <<std::endl;
}

int main()
{
	BinSearchTree<int>* tree = new BinSearchTree<int>;
	std::cout << "+-----------------------+" <<std::endl;
	std::cout << "| Empty tree is created |" <<std::endl;
	std::cout << "+-----------------------+" <<std::endl;
	std::cout << "\n" <<std::endl;
	while (true) {
		char op;
		std::cout << "\nPlease enter 'i' to insert,\
			\n'p' to print\
			\n'r' to remove\
			\n'h' to get height" <<std::endl;
		std::cin >> op;
		if (op == 'i') {
			insert(tree);
		} else if (op == 'p') {
			print(tree);
		} else if (op == 'r') {
			remove(tree);
		} else if (op == 'h') {
			getHeight(tree);
		}
	}
	return 0;
}
