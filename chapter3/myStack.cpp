/* myStack.cpp
 * Implementation of class MyStack
 */

#include <iostream>
#include <cstdlib>
#include <queue>
#include "myStack.h"

#define INITIALLEN 10

MyStack::MyStack() {
    arr = new int[INITIALLEN];
    arrlen = INITIALLEN;
    stackSize = 0;
}

MyStack::~MyStack() {
    delete [] arr;
}

int MyStack::size() const {
    return stackSize;
}

bool MyStack::isEmpty() const {
    return stackSize == 0;
}

void MyStack::push(int elem) {
    if (stackSize >= arrlen)
        doubleMem();
    arr[stackSize++] = elem;       
}

int MyStack::pop() {
    if (stackSize == 0) {
        std::cout << "pop error: stack is empty!" << std::endl;
        exit(1);
    }

    int retVal = arr[stackSize - 1];
    stackSize--;
    if (arrlen > INITIALLEN && stackSize <= arrlen / 2)
        halfMem();
    
    return retVal;
}

int MyStack::peek() const {
    if (stackSize == 0) {
        std::cout << "peek error: stack is empty!" << std::endl;
        exit(1);
    }

    return arr[stackSize - 1];
}

void MyStack::sort() {
    std::priority_queue<int, std::vector<int>, std::less<int> > pq;
    while (!isEmpty()) 
        pq.push(pop());

    while (!pq.empty()) {
        push(pq.top());
        pq.pop();
    }
}

void MyStack::printStack() const {
    std::cout << "Printing stack:" << std::endl;
    int i;
    for (i = 0; i < stackSize; i++)
        std::cout << arr[i] << ", ";

    std::cout << std::endl;
}

void MyStack::doubleMem() {
    arrlen *= 2;
    int* newarr = new int[arrlen];
    int i;
    for (i = 0; i < stackSize; i++) {
        newarr[i] = arr[i];
    }   

    delete [] arr;
    arr = newarr;
}

void MyStack::halfMem() {
    arrlen /= 2;
    int* newarr = new int[arrlen];
    int i;
    for (i = 0; i < stackSize; i++) {
        newarr[i] = arr[i];
    }

    delete [] arr;
    arr = newarr;
}

