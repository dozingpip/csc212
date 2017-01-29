#ifndef __BINTREE_H__
#define __BINTREE_H__

#include <vector>

#ifndef NULL
#define NULL nullptr
#endif

#define PREORDER 0x01
#define INORDER 0x02
#define POSTORDER 0x03

class BSTNode {
    private:
        int data;
        BSTNode *left;
        BSTNode *right;

    public:
        BSTNode(int d) {
            data = d;
            left = right = NULL;
        }
        ~BSTNode() {
        }

    friend class BSTree;
};

class BSTree {
    private:
        BSTNode *root;

        void insert(BSTNode **p, int d);
        void destroy(BSTNode *p);
        void preorder(BSTNode *p, std::vector<int> *values);
        void inorder(BSTNode *p, std::vector<int> *values);
        void postorder(BSTNode *p, std::vector<int> *values);
        void range_query(BSTNode *p, int k1, int k2, std::vector<int> *values);

    public:
        BSTree();
        ~BSTree();

        void insert(int d);
        void traversal(int type, std::vector<int> *values);
        void range_query(int k1, int k2, std::vector<int> *values);
};

#endif