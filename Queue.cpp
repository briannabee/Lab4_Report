#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue()
{
    cout << "Queue() called: " << this << endl;
    head = nullptr;
    end = nullptr;
}

void Queue::push(int data)
{
    cout << "Queue:Push(" << data << ") called: " << this << endl;
    Node* new_node = new Node(); //Node() is called automatically for new Node or Node x;
    new_node->data = data;
    new_node->next = nullptr;
    if (end == nullptr)
    {
        head = end = new_node;
    }
    else
    {
        end->next = new_node;
        end = new_node;
    }
}

void Queue::pop()
{
cout << "Queue:Pop() called : " << this << endl;
   if (head != nullptr)
   {
    Node* temp = head;
    head = head->next;
    delete temp;
   }
   else
   {
    end = nullptr;
   }
}

Queue::~Queue()
{
cout << "~Queue() called : " << this << endl;
while(head != nullptr) //current was head
{
    Node* temp = head; //
    head = head->next;
    cout << "\taddress of node to delete = " << temp << endl; //head
    cout << "\tdata in the node = " << temp->data << endl; //head->data
    //head = current;
    delete temp; // was head
}
}