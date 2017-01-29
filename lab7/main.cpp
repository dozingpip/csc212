//
//  main.cpp
//  Implementing BSTree
//

#include <iostream>
#include <algorithm>
#include <time.h>
#include "bst.h"

int main() {

    BSTree myBST1;
    
    for (int i = 0; i < 32768;i++)   
        myBST1.insert(i);
    
    std::cout << "Height myBST1: " << myBST1.BST_Height() << std::endl;
    
    BSTree myBST2; 
    
    srand(time(NULL));
    
    for (int i = 0; i < 32768;i++)
        myBST2.insert(rand() % 32768);
    
    std::cout << "Height myBST2: " << myBST2.BST_Height() << std::endl;     
    
    return 0;
    
}