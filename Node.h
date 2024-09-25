#ifndef NODE_H
#define NODE_H

struct Node
{
    //data members
    int data;
    Node* next;

    //member functions
    Node();
    Node(int, Node*);
    ~Node();
};

#endif