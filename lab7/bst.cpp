#include "bst.h"

#include <iostream>

BSTree::BSTree() {
    root = NULL;
}

BSTree::~BSTree() {
    destroy(root);
}

void BSTree::destroy(BSTNode *p) {
    if (p) {
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
}

void BSTree::insert(BSTNode **p, int d) {

    //YOUR CODE HERE
    //Check is the BST_Node is not null
    //if(!*p) {set *p to new BST_Node(d)}
    //If the BST_Node is not null
    //Check if d is less the data in the BST_node
    //if(d < (*p)->data) {Insert to the left) recursively
    //id(d >= (*p)->data {Insert to the right) recursively

    if(*p == NULL){
        *p = new BSTNode(d);
    }else{
        if(d<(*p)->data){
            insert(&((*p)->left), d);
        }else if(d>= (*p)->data){
            insert(&((*p)->right), d);
        }
    }
}

void BSTree::insert(int d) {
    insert(&root, d);
}

bool BSTree::remove(int d) {
    return false;
}

BSTNode *BSTree::search(BSTNode *p, int d) {
    if (p) { 
        if (p->data == d) return p;
        else if (p->data < d) return search(p->right, d);
        else return search(p->left, d);
    }
    return NULL;
}

BSTNode *BSTree::search(int d) {
    return search(root, d);
}

void BSTree::preorder(BSTNode *p) {
    if (p) {
        std::cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

void BSTree::inorder(BSTNode *p) {
    if (p) {
        inorder(p->left);
        std::cout << p->data << " ";
        inorder(p->right);
    }
}

void BSTree::postorder(BSTNode *p) {
    if (p) {
        postorder(p->left);
        postorder(p->right);
        std::cout << p->data << " ";
    }
}

void BSTree::traversal(int type) {
    switch (type) {
        case PREORDER:
            std::cout << "Preorder: ";
            preorder(root);
            break;
        case INORDER:
            std::cout << "Inorder: ";
            inorder(root);
            break;
        case POSTORDER:
            std::cout << "Postorder: ";
            postorder(root);
            break;
    }    
    std::cout << std::endl;
}

int BSTree::BST_Height(BSTNode *p)
{
    int l = -1, r = -1;
    //YOUR CODE HERE
    if((p)->left != NULL){
        l = BST_Height(p->left);
    }
    if((p)->right != NULL){
        r = BST_Height(p->right);
    }

    return 1+MAX(l, r);
    
}

int BSTree::BST_Height()
{    
    if(root)
        return BST_Height(root);
    else
        return 0;
}