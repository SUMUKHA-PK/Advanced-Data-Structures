#ifndef _PROBLEM_1_H
#define _PROBLEM_1_H

#include<bits/stdc++.h>

#include "Avl.h"

namespace avltree {

/**********************************************************
 * 
 * 
 * All functions from here are related to problem1.
 *
 ***********************************************************/

    // Assumes root is not NULL
int findSmallestKey(Node* root) {

    if(root->left == NULL)
        return root->key;

    else 
        return root->left->key;
}

void populateTree(Node *root, int treeNumber) {

    std::cout<<"Populate Tree-"<<treeNumber<<": "<<std::endl;

    int key, choice, flag = 0;

    if(treeNumber == 2) {
        std::cout<<"Smallest key of this tree should be larger than largest key of the other tree."<<std::endl;
    }

    while(1) {

        std::cout<<"1. Insert a node"<<std::endl;
        std::cout<<"2. I am done with tree-"<<treeNumber<<std::endl;

        std::cin>>choice;

        if(choice == 1) {
            std::cout<<"Enter a key: "<<std::endl;
            std::cin>>key;
            std::cout<<"Before insertNode"<<std::endl;
            
            if(flag == 0) {
                root->key = key;
                flag = 1;
            }
            else 
                insertNode(root, createNode(key), NULL, -1);
            
            std::cout<<"After insertNode"<<std::endl;
        }
        else if(choice == 2) {
            return;
        }
        std::cout<<"Tree: "<<std::endl;
        displayTree(root);
        std::cout<<std::endl;
    }
}


// When height(root1) >= height(root2)
Node *case1(Node *root1, Node* root2) {

    int x = findSmallestKey(root2);
    deleteNode(root2, x, NULL, 1);

    int h = height(root2);

    int h1 = height(root1);
    Node* v = root1;

    while(h1 > h+1) {

        if(getBalance(v) == -1)
            h1 = h - 2;
        else
            h1 = h - 1;
        
        v = v->right;
    }

    // Root of the new tree. 
    Node* root3 = createNode(x);

    // Left Subtree is rooted at v. 
    root3->left = v;

    // Right Subtree is t2 itself. 
    root3->right = root2;

    // At this point, tree rooted at root3 is a valid AVL Tree.

    // Cut the connection between v and it's parent in t1.
    v->parent->right = NULL;

    displayTree(root3);

    return NULL;
}


Node* case2(Node *root1, Node *root2) {
    std::cout<<"Under construction!"<<std::endl;
}


// t2 - an AVL Tree
// t1 - an AVL Tree whose largest key is lessthan smallest key of t2. 

// root1 - root of t1
// root2 - root of t2
Node* mergeTrees(Node* root1, Node* root2) {

    if(height(root1) >= height(root2))
        return case1(root1, root2);
    
    else
        return case2(root1, root2);
}

}   // namespace avltree end. 

#endif      // _PROBLEM_1_H 