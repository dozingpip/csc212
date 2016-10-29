#ifndef __DLL_H__ 
#define __DLL_H__ 

#ifndef NULL
#define NULL 0x00
#endif

class Node {

    private:
        int data;    // this data can be of any type
        Node *next;  // this is a pointer to the next node
	Node *prev;  // this is a pointer to the previous node

    public:
        Node(int);
        ~Node();

    friend class D_L_List;  // a friend class means private and 
	                    // protected methods can be accessed
};

class D_L_List {

    private:
        Node *head; // the node at the beginning of the list
        Node *tail; // the node at the end of the list

    public:
        D_L_List();
        ~D_L_List();

        void print_list();           // prints the list
	void print_list_backwards(); // prints the list backwards
        void insert_end(int);        // inserts at the end of the list
        void remove(int);            // removes a node with the data
        void remove(Node *);         // removes the node pointed to
        Node * find_node(int);       // finds the node with the given data
		

};

#endif

