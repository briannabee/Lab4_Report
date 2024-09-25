#include <iostream>
#include "Node.h"

using namespace std;

Node::Node()
{
    cout << "\tNode() called: " << this << endl;
    data = -1;
    next = nullptr;
}

Node::Node(int data, Node* next)
{
    cout << "\tNode(" << data << ", " << next << ") called : " << this << endl;
    this->data = data;
    this->next = next;
}

Node::~Node()
{
    cout << "\t~Node() called: " << this << endl;
}