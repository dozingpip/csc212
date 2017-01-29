#include "stack.h"
#include <iostream>
//DO NOT ADD HEADERS
//NODE CONSTRUCTOR DO NOT CHANGE
Node::Node(int d) {
    data = d;
    next = NULL;
}
//NODE DESTRUCTOR DO NOT CHANGE
Node::~Node() {
}
//STACK CONSTRUCTOR DO NOT CHANGE
Stack::Stack() {
    head = NULL;
}
//STACK DESTRUCTOR DO NOT CHANGE
Stack::~Stack() {
    Node *p;
    while (head) {
        p = head;
        head = p->next;
        delete p;
    }
}
//
//
//DO NOT CHANGE ABOVE THIS LINE
///////////////////////////////
//DO NOT CHANGE ABOVE THIS LINE
//
//THE TWO METHODS YOU WILL CHANGE
//ARE PUSH AND POP BELOW
//

//PUSH
//PUSHES ONTO THE STACK
void Stack::push(int i) {

    //YOUR CODE HERE
    //CREATE A NEW NODE
    //CHECK IF THE LIST IS EMPTY
    //IF LIST IS EMPTY HEAD IS SET TO NEW NODE
    //OTHERWISE SET NEW NODE'S NEXT NODE TO HEAD
    //AND THEN SET HEAD TO THE NEW NODE
    Node *newNode = new Node(i);
    if(head==NULL){
        head = newNode;
    }else{
        head = newNode->next;
    }

}

//POP
//POPS THE HEAD OFF THE STACK
int Stack::pop() {

    //YOUR CODE HERE
    //MAKE AN INT SET IT TO HEAD'S DATA
    //MAKE A TEMP NODE POINTER SET TO HEAD
    //SET HEAD TO HEAD'S NEXT NODE
    //DELETE TEMP
    //RETURN THE VALUE OF THE INT
    
    //Change retun value
    //Default -1
    int p = head->data;
    Node *tempNode = head;
    head = head->next;
    delete tempNode;
    return p;
}