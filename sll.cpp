#include <iostream>

using namespace std;

//a new data type defined before main()
struct Node
{
    //data members, or member variables
    int data;
    Node* next;

    //member functions
    Node(); // default constructor, or no-arg constructor
            // must be a member of a struct type or class type: cannot be a free function like main()
            // role: initialize data members
            // no return type
            // the name of the function must be the same as the struct/class type
    Node(int, Node*); //arg-constructor, or overloaded functions
};

Node::Node() //the first Node means struct type, second Node is the constructor, comes with ()
// :: -> the scope resolution operator
{
    cout << "this : " << this << endl;
    data= -1; //member function directly access member variables of the same type.
    next = nullptr;
}

Node::Node(int value, Node* next)
{
    cout << "this : " << this << endl;
    data = value; //data member = local variable declared in the function header
    this->next = next; //this->next on the left of = : data member of Node
                 //next on the right of = : the local variable declared in the function header
                 //this: a keyword, the address of a node which is currently being initialized.
                 //->: member access operator using a pointer.
                 //p->member of a struct/class.
}

void push(Node*&, int); //insert. the new node containing data becomes head -> last-in
void pushb(Node*&, Node*&, int); //queue
void popb(Node*&, Node*&); // remove the newest node -> first out
void pop(Node*&);

int main()
{
//A. The newest node in the head: Stack
//create a SLL
cout << "----------- Stack --------" << endl;
Node* head = nullptr;
int count = 0;

while(count < 4)
{
    Node* new_node = new Node; //Node() is called automatically for new Node or Node x;
    cout << "new node = " << new_node << endl;
    new_node->data = 10*count;
    new_node->next = head;
    head = new_node;
    count++;
}

//push operation
for(int i=0; i<3; i++) {
    push(head, 10*count);
    count++;
}

//A-2 display data
Node* current = head;
while(current != nullptr)
{
    cout << current->data << endl;
    current = current->next;
}

//pop operation
for(int i=0; i<2; i++) {
    pop(head);
}

//A-3: delete the sll
current = head;
while(head != nullptr)
{
    current = current->next;
    cout << "address of node to delete = " << head << endl;
    delete head;
    head = current;
}

//B: The newest node is at the end of the SLL: queue
//B-1: creating a SLL
cout << " " << endl;
cout << "----------- Queue --------" << endl;
Node* b_head = nullptr;
Node* b_end = nullptr;
count = 0;

while(count < 4) {
    pushb(b_head, b_end, 10 * count);
    count++;
}

//B-2: display the data
Node* b_current = b_head;
while(b_current != nullptr)
{
    cout << b_current->data << endl;
    b_current = b_current->next;
}

for (int i = 0; i < 4; ++i) 
{
    pushb(b_head, b_end, i * 10); // Call the pushb function for the queue
}

//B-3: delete the sll

for (int i=0; i<4; i++)
{
    popb(b_head, b_end);
}

return 0;
}

void push(Node*& head, int value) //declaring variables, local to push
{
    Node* new_node = new Node(value, head); //set data of the new_node to value, next to the head 
    //Node(int, Node*); called automatically call of Node -> initialize data and the next of the new_node
    //when line 137 is being executed, this is the address of the new_node.
    head = new_node;
}

void pushb(Node*& head, Node*& end, int value)
{
    Node* new_node = new Node(value, nullptr);
    if (end != nullptr)
    {
        end->next = new_node;
    }
    else
    {
        head = new_node;
    }
    end = new_node;
    cout << "new node = " << new_node << endl;
}

void popb(Node*& head, Node*& end)
{
    if (head == nullptr)
        return;
    Node* temp = head;
    head = head->next;
    cout << "address of node to delete = " << temp << endl;
    if (head == nullptr)
    {
        end = nullptr;
    }
    delete temp;
}

void pop(Node*& head)
{
    if (head == nullptr)
        return;
    Node* temp = head;
    head = head->next;
    delete temp;
}