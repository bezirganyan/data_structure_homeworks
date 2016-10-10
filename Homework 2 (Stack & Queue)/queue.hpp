/*
 * ============================================================================
 *
 *       Filename:  queue.hpp
 *
 *    Description:  the header file for queue implemetation class
 *
 *        Version:  1.0
 *        Created:  10/09/2016 10:37:48 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Grigor Bezirganyan
 *
 * ============================================================================
 */

#include "list.hpp"

template <class T>
class queue
{
        private:
                //Private data members
                list<T> *m_list;
        public:
                //Public member functions
                void enqueue(T);
                T dequeue();
                bool isEmpty();
                T getFront();
                void print();

        public:
                //Constructor and destructor;
                queue();
                ~queue();

};

        template <class T>
void queue<T>::enqueue(T el)
{
        m_list->insert(m_list->getSize(), el);
}

        template <class T>
T queue<T>::dequeue()
{
        m_list->remove(0);
}

        template <class T>
bool queue<T>::isEmpty()
{
        if (m_list->getSize() == 0) {
                return true;
        } else {
                return false;
        }
}

        template <class T>
T queue<T>::getFront()
{
        return m_list->get(0);
}

        template <class T>
void queue<T>::print()
{
//        if (!isEmpty()) {
//                for (int i = m_top; i >= 0; i--) {
//                        std::cout << "| " <<m_list[i] << " |" << std::endl;
//                }
//        } else {
//                std::cout << "|   |" << std::endl;
//        }
        m_list->print();
}

        template <class T>
queue<T>::queue()
{
        m_list = new list<T>;
}

        template <class T>
queue<T>::~queue()
{
        delete m_list;
}
