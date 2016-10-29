#include "dll.h"
#include <iostream>

Node::Node(int d) {
    data = d;
    next = NULL;
    prev = NULL;
}

Node::~Node() {
}

D_L_List::D_L_List() {
	head = NULL;
	tail = NULL;
}

D_L_List::~D_L_List() {
    Node *p;
    while (head) {
        p = head;
        head = p->next;
        delete p;
    }
}

void D_L_List::print_list() {
 	// make a temporary pointer
	Node *temp = head;
	
	// Case 1:
	// The List is empty
	if (!temp) {
	    std::cout << "EMPTY" << std::endl;
	    return;
	}
	
	// Case 2:
	// the list is not empty
	// visit each node and print its data
	while (temp) {
	    std::cout << temp->data << " --> ";
	    temp = temp->next;
	}
		    
	std::cout << "NULL" << std::endl;
}

void D_L_List::print_list_backwards() {
	 // make a temporary pointer
	Node *temp = tail;
	
	// Case 1:
	// The List is empty
	if (!temp) {
	    std::cout << "EMPTY" << std::endl;
	    return;
	}
	
	// Case 2:
	// the list is not empty
	// visit each node and print its data
	while (temp) {
	    std::cout << temp->data << " --> ";
	    temp = temp->prev;
	}
	std::cout << "NULL" << std::endl;
}

void D_L_List::insert_end(int d) {
	// if there is something at the head then we add to the tail
	if (head) {
		tail->next = new Node(d);
		tail->next->prev = tail;
		tail = tail->next;
	}
	// otherwise make the head and tail point to the new node
	else {
		head = tail = new Node(d);
	}
}

void D_L_List::remove(int d) {
    // make a temporary pointer
    Node *temp = head;
    
    // iterate through list until
	// we find element we are looking for

    while (temp && temp->data != d) {
        temp = temp->next;
    }
    // if temp is null then element not in list
	// or list is empty
    if(!temp) {
	return;	
    }
    // check that prev is not null	
    if (temp->prev) {
        // Adjust the pointers
        temp->prev = temp->next;
        // check if we need to update the tail
        if (temp == tail) {
	    // set tail to the previous
	    tail = temp->prev;
	}
    }
	// if prev is null it means remove head
    else {
	head = temp->next;
    }
    // Delete the current node
    delete temp;
    
}

void D_L_List::remove(Node * n) {
    // make a temporary pointer
    Node *temp = head;
    
    // iterate through list until
    // we find element we are looking for
    while (temp && temp != n) {
        temp = temp->next;
    }
    // if temp is null then element not in list
    // or list is empty
    if(!temp) {
        return;	
    }
    // check that prev is not null	
    if (temp->prev) {
        // Adjust the pointers
        temp->prev = temp->next;
        // check if we need to update the tail
        if (temp == tail) {
	    // set tail to the previous node
	    tail = temp->prev;
	}		
    }
    // if prev is null it means remove head
    else {
	head = temp->next;		
    }
    // Delete the current node
    delete temp;	
}

Node * D_L_List::find_node(int d) {
			   
    // make a temporary pointer
    Node *temp = head;
    
    // iterate through list until
    // we find element we are looking for
    while (temp && temp->data != d) {
        temp = temp->next;
    }
    
    return temp;
}
