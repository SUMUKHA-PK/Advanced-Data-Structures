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

/******************************************************
 * 
 * The below functions are problem1 functions. 
 * 
 ******************************************************/

Node* populateTree(Node *root, int treeNumber) {

    std::cout<<"Populate Tree-"<<treeNumber<<": "<<std::endl;

    int key, choice, flag = 0;

    Node *newroot;

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
            
            if(flag == 0) {
                newroot = createNode(key);
                flag = 1;
            }
            else
                insertNode(&newroot, newroot, createNode(key), NULL, -1);

        }
        else if(choice == 2) {
            return newroot;
        }

        std::cout<<"Tree: "<<std::endl;
        displayTree(newroot);
        std::cout<<"\n\n\n"<<std::endl;
    }

    return newroot;
}



Node *case1(Node *root1, Node* root2) {

    displayTree(root1);
    displayTree(root2);

    std::cout<<"root1 = "<<root1<<", root2 = "<<root2<<std::endl;

    int x = findSmallestKey(root2);

    displayTree(root2);

    // deleteNode(root2, x);
    deleteNode(&root2, root2, x, NULL, -1);

    int h = height(root2);

    int h1 = height(root1);

    Node* v = root1;
    Node *v_parent;

    std::cout<<"h = "<<h<<", h1 = "<<h1<<std::endl;

    // In the internet, h1 > h+1 is given which I think is not correct. h1 >= h is correct. 
    while(h1 >= h + 1 ) {

        if(getBalance(v) == -1)
            h1 = h - 2;
        else
            h1 = h - 1;

        v_parent = v;    
        v = v->right;
    }

    // Root of the new tree. 
    Node* root3 = createNode(x);

    // Left Subtree is rooted at v. 
    root3->left = v;

    // Right Subtree is t2 itself. 
    root3->right = root2;

    std::cout<<"\n\n\n"<<std::endl;
    displayTree(root3);

    v_parent->right = root3;

    std::cout<<"\n\n\nfinal tree without balancing: "<<std::endl;

    // This display is exactly what I wanted. 
    displayTree(root1);

    std::cout<<"\n\n\n"<<std::endl;

    leftRotate(&root1, root1->right);
    
    std::cout<<"\n\n\n"<<std::endl;

    displayTree(root1);

    std::cout<<"\n\n\n"<<std::endl;
    


    // // Then this fucked up everything!
    // balance(root1);

    // // That fuckup is demonstrated by this display.
    // displayTree(root1);

    return root1;
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