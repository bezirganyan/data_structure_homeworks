/*
 * =====================================================================================
 *
 *       Filename:  tree.cpp
 *
 *    Description:  BinSearchTree source file
 *
 *        Version:  1.0
 *        Created:  11/02/2016 01:36:14 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Grigor Bezirganyan
 *
 * =====================================================================================
 */
//Headers from standard libraries
#include <iostream>
#include <cassert>

//Headers from this project
#include "BinSearchTree.hpp"

//Template type explicit definitions
template class BinSearchTree<int>;
template class BinSearchTree<unsigned int>;
template class BinSearchTree<long>;
template class BinSearchTree<long long>;
template class BinSearchTree<float>;
template class BinSearchTree<double>;

	template <class T>
void BinSearchTree<T>::insert(T d, Node<T> *&root)
{
	if (root == nullptr || root->data == 0) {
		Node<T> *new_node = new Node<T>;
		new_node->data = d;
		root = new_node;
	} else if (root->data < d) {
		insert(d, root->right);
	} else if (root->data > d) {
		insert(d, root->left);
	}
}

	template <class T>
void BinSearchTree<T>::insert(T d)
{
	insert(d, m_root);
}

template <class T>
Node<T>* BinSearchTree<T>::getRoot() {
	return m_root;
}

	template <class T>
BinSearchTree<T>::BinSearchTree()
{
	m_root = new Node<T>;
}

	template <class T>
void BinSearchTree<T>::preOrder(Node<T> *root)
{
	std::cout << root->data << " ";
	if (root->left != NULL) {
		preOrder(root->left);
	}
	if (root->right != NULL) {
		preOrder(root->right);
	}
}

	template <class T>
void BinSearchTree<T>::inOrder(Node<T> *root)
{
	if (root->left != NULL) {
		inOrder(root->left);
	}
	std::cout << root->data << " ";
	if (root->right != NULL) {
		inOrder(root->right);
	}
}

	template <class T>
void BinSearchTree<T>::postOrder(Node<T> *root)
{
	if (root->left != NULL) {
		postOrder(root->left);
	}
	if (root->right != NULL) {
		postOrder(root->right);

	}
	std::cout << root->data << " ";
}

template <class T>
Node<T>* BinSearchTree<T>::find(T d)
{

	/* Though in the assignment, the find
	 * function had to return whether the
	 * node exists or not (bool), I found
	 * returning the pointer to the
	 * node more useful for my other
	 * functions*/
	return find(d, m_root);
}

template <class T>
int BinSearchTree<T>::getHeight(Node<T>* root) {
        if (root == NULL) {
            return -1;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if (left >= right) {
            return 1 + left;
        } else {
            return 1 + right;
        }
    }

template <class T>
Node<T>* BinSearchTree<T>::find(T d, Node<T>* root)
{
	if (root->data == d) {
		return root;
	} if (root == NULL || root->data == 0) {
		return nullptr;
	} else if (root->data < d) {
		return find(d, root->right);
	} else if (root->data > d) {
		return find(d, root->left);
	}
        return nullptr;
}

template <class T>
Node<T>* BinSearchTree<T>::findParent(T d, Node<T>* root)
{
	if (nullptr != root->left && root->left->data == d) {
		return root;
	} else if (nullptr != root->right && root->right->data == d) {
                return root;
        } else if (root == NULL || root->data == 0) {
		return nullptr;
	} else if (root->data < d) {
		return find(d, root->right);
	} else if (root->data > d) {
		return find(d, root->left);
	}
        return nullptr;
}

template <class T>
Node<T>* BinSearchTree<T>::findMinimum(Node<T>* n)
{
	if (n->left == nullptr) {
		return n;
	} else {
		findMinimum(n->left);
	}
        return 0;
}

template <class T>
int BinSearchTree<T>::getHeight()
{
        return getHeight(m_root);
}
template <class T>
bool BinSearchTree<T>::isLeaf(T d)
{
	Node<T>* n = find(d);
        assert(nullptr != n);
	if (n->left == nullptr && n->right == nullptr) {
		return true;
	} else {
		return false;
	}
}

//Remove by Value
template <class T>
void BinSearchTree<T>::remove(T d)
{
        remove(find(d));
}

//Remove by Address
template <class T>
void BinSearchTree<T>::remove(Node<T>* n)
{
	if (isLeaf(n->data)) {
		delete n;
	} else {
		if (n->right == nullptr) {
                        Node<T>* parent = findParent(n->data, m_root);
                        if (n->data < parent->data) {
                                parent->left = n->left;
                        } else {
                                parent->right = n->left;
                        }
			delete n;
		} else if (n->left == nullptr) {
                        Node<T>* parent = findParent(n->data, m_root);
                        if (n->data < parent->data) {
                                parent->left = n->right;
                        } else {
                                parent->right = n->right;
                        }
                        delete n;
		} else {
			Node<T>* min = findMinimum(n->right);
			n->data = min->data;
			remove(min);
		}
	}
}
