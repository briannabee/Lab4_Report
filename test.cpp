#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{
    //create an object of Stack
    Stack s;    //default constructor of Stack
    for(int i=0; i<4; i++)
    {
        s.push(i * 10); //object.function()
    }
       for(int i=0; i<4; i++)
    {
        s.pop(); //object.function()
    }

    //create an object of QUEUE!!
    Queue q;    //default constructor of Stack
    for(int i=0; i<4; i++)
    {
        q.push(i * 10); //object.function()
    }
       for(int i=0; i<4; i++)
    {
        q.pop(); //object.function()
    }
    return 0;
}