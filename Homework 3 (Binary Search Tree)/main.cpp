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

int main() {
        BinSearchTree<int>* tree = new BinSearchTree<int>;
	std::cout << "+-----------------------+" <<std::endl;
	std::cout << "| Empty tree is created |" <<std::endl;
	std::cout << "+-----------------------+" <<std::endl;
	std::cout << "\nInserting values: 3, 5, 2, 1, 4, 6, 2" <<std::endl;
	tree->insert(3);
        tree->insert(5);
        tree->insert(2);
        tree->insert(1);
        tree->insert(4);
        tree->insert(6);
	std::cout << "\n+-------------------------------------" <<std::endl;
        std::cout << "|pre-order traversal :";
        tree->preOrder(tree->getRoot());
	std::cout << "\n+-------------------------------------" <<std::endl;
        std::cout << "|In-order traversal  : ";
        tree->inOrder(tree->getRoot());
	std::cout << "\n+-------------------------------------" <<std::endl;
        std::cout << "|Post-order traversal : ";
        tree->postOrder(tree->getRoot());
	std::cout << "\n+-------------------------------------" <<std::endl;
	std::cout << "\nRemoving Value: 2" <<std::endl;
        tree->remove(2);
	std::cout << "\n+-------------------------------------" <<std::endl;
        std::cout << "pre-order traversal: ";
        tree->preOrder(tree->getRoot());
	std::cout << "\n+-------------------------------------" <<std::endl;
        std::cout << "in-order traversal: ";
        tree->inOrder(tree->getRoot());
	std::cout << "\n+-------------------------------------" <<std::endl;
        std::cout << "post-order traversal: ";
        tree->postOrder(tree->getRoot());
	std::cout << "\n+-------------------------------------" <<std::endl;
	std::cout << "\nThe height of the tree is: " <<
		tree->getHeight() <<std::endl;
        return 0;
}
