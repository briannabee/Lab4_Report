#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

struct Queue {
    Node* head;
    Node* end;

    void push(int data);
    void pop();

    Queue();

    ~Queue();
};
#endif