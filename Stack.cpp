#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack()
{
    cout << "Stack() called: " << this << endl;
    head = nullptr;
}

void Stack::push(int data)
{
    cout << "Stack:Push(" << data << ") called: " << this << endl;
    Node* new_node = new Node(data, head); //Node() is called automatically for new Node or Node x;
    head = new_node;
}
void Stack::pop()
{
    cout << "Stack:Pop() called : " << this << endl;
    /*Node* current = head;
    current = current->next;
    delete head;
    head = current;
    */
   if (head == nullptr)
   {
    return;
   }
   Node* temp = head;
   head = head->next;
   delete temp;

}

Stack::~Stack()
{
cout << "~Stack() called : " << this << endl;
Node* current = head;
while(current != nullptr) //current was head
{
    Node* temp = current; //
    current = current->next;
    cout << "\taddress of node to delete = " << temp << endl; //head
    cout << "\tdata in the node = " << temp->data << endl; //head->data
    //head = current;
    delete temp; // was head
}
}