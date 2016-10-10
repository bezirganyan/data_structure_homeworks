/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  the main file for testing stack and queu classes
 *
 *        Version:  1.0
 *        Created:  10/09/2016 09:55:21 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Grigor Bezirganyan
 *
 * ============================================================================
 */

//headers from standard libraries
#include <iostream>

//headers from this project
#include "stack.hpp"
#include "queue.hpp"

int main()
{
        std::cout << "********** STACK **********" << std::endl;
        stack<int> a;
        std::cout << "Is the stack empty: " << a.isEmpty() << std::endl;
        a.print();
        std::cout << "Pushed numbers 5, 9, 1" << std::endl;
        a.push(5);
        a.push(9);
        a.push(1);
        a.print();
        std::cout << "Is the stack empty: " << a.isEmpty() << std::endl;
        std::cout << "Poped: " << a.pop() << std::endl;
        a.print();
        std::cout << "Get top: " << a.getTop() << std::endl;
        a.print();

        std::cout << "********** QUEUE **********" << std::endl;
        queue<int> q;
        std::cout << "Is the queue empty: " << q.isEmpty() << std::endl;
        q.print();
        std::cout << "Enqueued numbers 5, 9, 1" << std::endl;
        q.enqueue(5);
        q.enqueue(9);
        q.enqueue(1);
        q.print();
        std::cout << "Is the queue empty: " << q.isEmpty() << std::endl;
        q.dequeue();
        std::cout << "dequeued" << std::endl;
        q.print();
        std::cout << "Get top: " << q.getFront() << std::endl;
        q.print();
        return 0;
}
