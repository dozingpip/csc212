#include "dll.h"
#include <iostream>


int main() {
    D_L_List mylist;
    
    std::cout << "Testing the List Class" << std::endl;
    
    //insert some numbers
    mylist.insert_end(10);
    mylist.print_list();
    mylist.insert_end(20);
    mylist.print_list();
    mylist.insert_end(30);
    mylist.print_list();
    mylist.insert_end(40);
    mylist.print_list();
    mylist.insert_end(50);
    mylist.print_list();	

    //print list backwards
    mylist.print_list_backwards();
	
    //remove the head make sure we are still tracking head
    //after removal
    mylist.remove(10);
    mylist.print_list();
  
    //remove non existent node
    mylist.remove(60);
    mylist.print_list();

    
  
    //remove from tail and add to tail to make sure
    //we are still tracking tail correctly
    mylist.remove(50);
    mylist.print_list();   
    mylist.insert_end(50);
    mylist.print_list();
    
    
    //Find a node, return node pointer, remove using pointer
    Node *temp;
    temp = mylist.find_node(50);
    mylist.remove(temp);
    mylist.print_list();
    
    //Condensed version of remove()
    mylist.remove(mylist.find_node(20));
    mylist.print_list();
    
    //Empty the list
    mylist.remove(30);
    mylist.print_list();
    mylist.remove(40);
    mylist.print_list();
    //List should be empty
    
    //Add to empty list so we know everything got reset correctly
    mylist.insert_end(10);
    mylist.print_list();
    
    return 0;
    
}// end main

