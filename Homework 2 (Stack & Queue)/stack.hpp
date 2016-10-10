/*
 * ============================================================================
 *
 *       Filename:  stack.hpp
 *
 *    Description:  the header file for stack implemetation class
 *
 *        Version:  1.0
 *        Created:  10/09/2016 02:30:08 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Grigor Bezirganyan
 *
 * ============================================================================
 */
#include <iostream>

template <class T>
class stack
{
        private:
                //Private data members
                T *m_array;
                int m_capacity;
                int m_top;
        public:
                //Public member functions
                void push(T);
                T pop();
                bool isEmpty();
                T getTop();
                void print();

        public:
                // Contstructor and Destructor
                stack();
                ~stack();

};

        template <class T>
void stack<T>::push(T el)
{
        if (m_top != m_capacity) {
                m_array[++m_top] = el;
        } else {
                throw "The Stack is full";
        }
}

        template <class T>
T stack<T>::pop()
{
        T temp = m_array[m_top];
        m_array[m_top] = 0;
        m_top--;
        return temp;
}

        template <class T>
bool stack<T>::isEmpty()
{
        if (m_top == -1) {
                return true;
        } else {
                return false;
        }
}

        template <class T>
T stack<T>::getTop()
{
        return m_array[m_top];
}

        template <class T>
void stack<T>::print()
{
        if (!isEmpty()) {
                for (int i = m_top; i >= 0; i--) {
                        std::cout << "| " <<m_array[i] << " |" << std::endl;
                }
                std::cout << "-----" << std::endl;
        } else {
                std::cout << "|   |" << std::endl;
                std::cout << "-----" << std::endl;
        }
}

        template <class T>
stack<T>::stack()
{
        m_top = -1;
        m_capacity = 20;
        m_array = new T[m_capacity];
}

        template <class T>
stack<T>::~stack()
{
        delete m_array;
}
