#ifndef STACK_H
#define STACK_H

#include "Node.h"   //"header filename" --> the programmer-defined headerfile

struct Stack {    //LIFO, SLL
    //data members;
    Node* head;

    //member functions;
    //1. Constructor, can be overloaded
    Stack(); //initializing the head.

    //2. Essential functions to implement LIFO behavior of the stack.
    void push(int data);
    void pop();

    //3. Deconstructor
    //3.1 ~DataTypeName();
    //3.2 Role: typically clean up the head occupied by an object of Stack
    //3.2 cannot be overloaded.
    ~Stack();
};

#endif