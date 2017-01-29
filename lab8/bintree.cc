#include "bintree.h"

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

// Insert ignores repeated values
void BSTree::insert(BSTNode **p, int d) {
    if (! *p) {
        // insert node here
        (*p) = new BSTNode(d);
    } else {
        // call recursively
        if ((*p)->data < d) insert(&((*p)->right), d);
        else if ((*p)->data > d) insert(&((*p)->left), d);
    }
}

void BSTree::insert(int d) {
    insert(&root, d);
}

void BSTree::preorder(BSTNode *p, std::vector<int> *values) {
    if (p) {
        values->push_back(p->data);
        preorder(p->left, values);
        preorder(p->right, values);
    }
}

void BSTree::inorder(BSTNode *p, std::vector<int> *values) {
    if (p) {
        inorder(p->left, values);
        values->push_back(p->data);
        inorder(p->right, values);
    }
}

void BSTree::postorder(BSTNode *p, std::vector<int> *values) {
    if (p) {
        postorder(p->left, values);
        postorder(p->right, values);
        values->push_back(p->data);
    }
}

void BSTree::traversal(int type, std::vector<int> *values) {
    values->clear();
    switch (type) {
        case PREORDER:
            preorder(root, values);
            break;
        case INORDER:
            inorder(root, values);
            break;
        case POSTORDER:
            postorder(root, values);
            break;
    }
}

void BSTree::range_query(BSTNode *p, int k1, int k2, std::vector<int> *values) {
    // TODO
    if(p){
        if(p->data >= k1 &&  p->data <= k2){
            range_query(p->left, k1, k2, values);
            values->push_back(p->data);
            range_query(p->right, k1, k2, values);
        }else if(p->data > k2){
            range_query(p->left, k1, k2, values);
        }else if(p->data < k1){
            range_query(p->right, k1, k2, values);
        }
    }
}

void BSTree::range_query(int k1, int k2, std::vector<int> *values) {
    values->clear();
    // TODO
    range_query(root, k1, k2, values);
}