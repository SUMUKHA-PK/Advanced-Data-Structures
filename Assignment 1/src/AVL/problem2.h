#ifndef _PROBLEM_2_H
#define _PROBLEM_2_H 1

#include<bits/stdc++.h>
#include "Avl.h"

namespace avltree {

enum {
    LEFT_CHILD, 
    RIGHT_CHILD,
};

// Simple search
// Returns the required node's parent.
// If it returns NULL, then searched node is root node itself.
Node* searchKey(Node *root, int key, int *X) {

    if(key == root->key) {

        if(root == root->parent->right)
            *X = RIGHT_CHILD;
        
        else if(root == root->parent->left)
            *X = LEFT_CHILD;


        return root->parent;
    }

    else if(key > root->key) {
        searchKey(root->right, key, X);
    }

    else 
        searchKey(root->left, key, X);

    
}

void expose(Node *root, Node *left, int *kptr, Node *right) {

    left = root->left;
    right = root->right;
    *kptr = root->key;
}


void join(Node *T1, int k, Node *T2) {

    std::cout<<"Should port this function from problem1.h";
}


// Return 0 if root != NULL
// If root = NULL, returns -1
int split(Node *root, int key, Node *RetLeft, bool *value, Node *RetRight) {

    if(root == NULL)
        return -1;

    Node *L, *R;
    int m;

    expose(root, L, m, R);

    if(key == m) {

        RetLeft = L;
        *value = true;
        RetRight = R;

        return;
    }

    if(key < m) {

        Node *L1, *R1;
        int b;

        split(L, key, L1, &b, R1);
        RetLeft = L;
        *value = b;
        RetRight = join(R1, m,  R);

        return;
    }

    if(key > m) {

        Node *L1, *R1;
        int b;

        split(R, key, L1, &b, R1);
        RetLeft = join(L, m, L1);
        *value = b;
        RetRight = R;

        return;
    }

    return;
}





















}   // namespace avltree end.

#endif  // _PROBLEM_2_H