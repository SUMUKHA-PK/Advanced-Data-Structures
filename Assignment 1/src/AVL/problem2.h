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


void generateTrees(Node *root, int k, Node *root1, Node *root2) {

std::cout<<"generateTrees is Under construction"<<std::endl;

    int child;

    Node *parent = searchKey(root, k, &child);
    Node *node;

    if(child == RIGHT_CHILD)
        node = parent->right;
    
    else if(child == LEFT_CHILD)
        node = parent->left;

    // This tree has all elements smaller than node->key.
    Node *left_subtree_root = node->left;

    
    
}






}   // namespace avltree end.

#endif  // _PROBLEM_2_H