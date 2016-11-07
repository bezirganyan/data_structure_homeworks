/*
 * =====================================================================================
 *
 *       Filename:  node.h
 *
 *    Description:  Node header file
 *
 *        Version:  1.0
 *        Created:  11/07/2016 11:53:42 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Grigor Bezirganyan
 *
 * =====================================================================================
 */

template <class T>
class Node
{
	public:
		T data;
		Node* left;
		Node* right;
};
