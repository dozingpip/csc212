#ifndef __STACK_H__ 
#define __STACK_H__ 

#ifndef NULL
#define NULL 0x00
#endif

class Node {


    private:
        int data;    // this data can be of any type
        Node *next;  // this is a pointer to the next node

    public:
        Node(int);
        ~Node();

    friend class Stack;  // a friend class means private and 
                         // protected methods can be accessed
};

class Stack {

    private:
        Node *head; // the node at the beginning of the list

    public:
        Stack();
        ~Stack();

        int pop();  // pops the top element of the stack and returns\
                    // the value of that node
        void push(int);   // pushes a new element onto the stack
};

#endif