/*
 * =====================================================================================
 *
 *       Filename:  BinSearchTree.hpp
 *
 *    Description:  Header file for BinSearchTree
 *
 *        Version:  1.0
 *        Created:  11/07/2016 11:56:21 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Grigor Bezirganyan
 *
 * =====================================================================================
 */

//headers from this project
#include "node.hpp"
template <class T>
class BinSearchTree
{
	private:
		//Private Data Members
		Node<T>* m_root;
	public:
		//Public member functions
		void insert(T); //overloaded with one argument
		Node<T>* getRoot();
		void preOrder(Node<T>*);
		void inOrder(Node<T>*);
		void postOrder(Node<T>*);
		/* Though in the assignment, the find
		 * function had to return whether the
		 * node exists or not (bool), I found
		 * returning the pointer to the
		 * node more useful for my other
		 * functions*/
		Node<T>* find(T);
                int getHeight();
		bool isLeaf(T);
		void remove(T); //Remove by Value
		void remove(Node<T>*); //Remove by Address
	private:
		//Private members functions
		Node<T>* find(T, Node<T>*);
		Node<T>* findMinimum(Node<T>*);
		Node<T>* findParent(T, Node<T>*);
                int getHeight(Node<T>*);
		void insert(T, Node<T>*&);
		void clean(Node<T>*);

	public:
		//Public constructor and destructor
		BinSearchTree();
		~BinSearchTree();

};
