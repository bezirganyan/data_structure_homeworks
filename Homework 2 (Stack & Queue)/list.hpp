/*
 * =============================================================================
 *
 *       Filename:  list.hpp
 *
 *    Description:  implementation of list data structure
 *
 *        Version:  1.0
 *        Created:  10/10/2016 01:22:49 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Grigor Bezirganyan
 *
 * =============================================================================
 */

//Headers from standard libraries
#include <iostream>

template <class N>
class Node
{
        public:
                //Public data members
                N data;
                Node<N> *next;
};

template <class T>
class list
{
        private:
                //Private data members
                Node<T> *m_head;
                int m_size;

        public:
                //Public member functions
                void insert(int, T);
                void remove(int);
                void set(int, T);
                T get(int);
                int getSize();
                bool isEmpty();
                void clear();
                void print();

        private:
                //Private member funtions
                Node<T>* getNode(int);
        public:
                //Overloaded operators
                T operator[](int);
        public:
                //Constructor and Destructor
                list();
                ~list();
};

template <class T>
void list<T>::insert(int p, T el)
{
        if (p > m_size || p < 0) {
                throw "Invalid position";
        } else if (p < m_size){
                Node<T> *new_node = new Node<T>;
                new_node->data = el;
                Node<T> *temp = getNode(p-1);
                new_node->next = temp->next;
                temp->next = new_node;
                m_size++;
        } else if (p == m_size) {

                Node<T> *new_node = new Node<T>;
                new_node->data = el;
                Node<T> *temp = getNode(p-1);
                temp->next = new_node;
                m_size++;
        }
}

template <class T>
void list<T>::remove(int p)
{
        if (p > m_size || p < 0) {
                throw "Invalid position";
        } else {
                Node<T>* temp = getNode(p-1);
                Node<T>* target = temp->next;
                temp->next = temp->next->next;
                delete target;
                m_size--;
        }
}

template <class T>
void list<T>::set(int p, T el)
{
        if (p > m_size || p < 0) {
                throw "Invalid position";
        } else {
                getNode(p)->data = el;
        }
}

template <class T>
T list<T>::get(int p)
{
        if (p > m_size || p < 0) {
                throw "Invalid position";
        } else {
                return getNode(p)->data;
        }
}

template <class T>
int list<T>::getSize()
{
        return m_size;
}

template <class T>
bool list<T>::isEmpty()
{
        if (m_head == nullptr) {
                return true;
        } else {
                return false;
        }
}

template <class T>
void list<T>::clear()
{
        Node<T>* temp = m_head;
        while (temp != nullptr) {
                temp = temp->next;
                delete temp;
        }
        m_head = nullptr;
}

template <class T>
Node<T> *list<T>::getNode(int p)
{
        if (p > m_size || p < -1) {
                throw "Invalid position";
        } else {
                Node<T>* temp = m_head;
                int i = -1;
                while (i != p) {
                        temp = temp->next;
                        i++;
                }
                return temp;
        }
}

template <class T>
void list<T>::print()
{
        Node<T>* temp = m_head;
        while (temp->next != nullptr) {
                temp = temp->next;
                std::cout << temp->data << " " << std::endl;
        }
}

template <class T>
T list<T>::operator[](int i)
{
        return get(i);
}

template <class T>
list<T>::list()
{
        m_head = new Node<T>;
        m_size = 0;
}

template <class T>
list<T>::~list()
{
        clear();
}
