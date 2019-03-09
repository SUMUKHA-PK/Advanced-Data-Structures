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

void expose(Node *root, Node **left, int *kptr, Node **right) {

    *left = root->left;
    *right = root->right;
    *kptr = root->key;
}

Node* join1(Node *root1, int x1, Node *root2) {

    // Height of the new AVL tree after deleting x.
    int h = height(root2);

    // This has to reduced till we get a sub-tree which is balanced with root2 tree.
    int h1 = height(root1);

    Node* v = root1;
    Node* v_parent;

    int x = 0;

    while(x < h1 - h) {
        v_parent = v;
        v=v->right;
        x++;
    }

    if(v != NULL) {
         std::cout<<"The following tree is balanced with Tree 2 : "<<std::endl;
         displayTree(v);
         std::cout<<"\n"<<std::endl;
    }
    
    // Root of the new tree. 
    Node* root3 = createNode(x1);

    // Left Subtree is rooted at v. 
    root3->left = v;
    if(v != NULL)
        v->parent = root3;
    
    // Right Subtree is t2 itself. 
    root3->right = root2;
    
    if(root2 != NULL)
        root2->parent=root3;

    std::cout<<"Tree constructed by taking Smallest key of Tree2, Modified Tree2 and corresponding balanced tree removed from Tree 1: "<<std::endl;
    displayTree(root3);
    std::cout<<"\n"<<std::endl;

    if(h1 == h)
        return root3;

    v_parent->right = root3;
    root3->parent = v_parent;


    std::cout<<"Merged Tree - may not be an AVL"<<std::endl;
    displayTree(root1);
    std::cout<<"\n"<<std::endl;

    Node *current = v_parent;
    Node *node = v_parent->right;
    
    if(node != NULL) {

    while(current != NULL) {

        if(getBalance(current) > 1 && node->key < current->left->key) {
            rightRotate(&root1, current);
        }

        else if(getBalance(current) < -1 && node->key > current->right->key) {
            leftRotate(&root1, current);
        }

        else if(getBalance(current) > 1 && node->key > current->left->key) {
            leftRotate(&root1, current->left);
            rightRotate(&root1, current);
        }

        else if(getBalance(current) < -1 && node->key < current->right->key) {
            rightRotate(&root1, current->right);
            leftRotate(&root1, current);
        }

        current = current->parent;
    }

    }

    return root1;


}

Node* join2(Node *root1, int x1, Node *root2) {

    // Height of new AVL tree after deleting it's largest key.
    int h = height(root1);

    // This has to be reduced till we get a sub-tree which is balanced with tree-1.
    int h2 = height(root2);

    Node *v = root2;
    Node *v_parent;

    int x = 0;

    std::cout<<"h2 = "<<h2<<", h = "<<h<<std::endl;

    while(x < h2 - h) {
        v_parent = v;
        v = v->left;
        if(v == NULL)
            break;
        x++;
    }

    if(v != NULL) {
         std::cout<<"The following tree is balanced with Tree 1 : "<<std::endl;
         displayTree(v);
         std::cout<<"\n"<<std::endl;
    }

    // Root of new intermediate tree with largest key of tree-1 as root.
    Node *root3 = createNode(x1);

    // Right sub-tree is rooted at v
    root3->right = v;    
    if(v != NULL) {
        v->parent = root3;
    }

    // Left subtree is t1 itself
    root3->left = root1;
    
    if(root1 != NULL)
        root1->parent = root3;
    

    std::cout<<"Tree constructed by taking largest key of Tree1, Modified Tree1 and corresponding balanced tree removed from Tree 2 : "<<std::endl;
    displayTree(root3);
    std::cout<<"\n"<<std::endl;
    
    v_parent->left = root3;
    root3->parent = v_parent;

    std::cout<<"Merged Tree - may not be an AVL"<<std::endl;
    displayTree(root2);
    std::cout<<"\n"<<std::endl;

    Node *current = v_parent;
    Node *node = v_parent->left;
    

    if(node != NULL) {

    while(current != NULL) {

        if(getBalance(current) > 1 && node->key < current->left->key) {
            rightRotate(&root1, current);
        }

        else if(getBalance(current) < -1 && node->key > current->right->key) {
            leftRotate(&root1, current);
        }

        else if(getBalance(current) > 1 && node->key > current->left->key) {
            leftRotate(&root1, current->left);
            rightRotate(&root1, current);
        }

        else if(getBalance(current) < -1 && node->key < current->right->key) {
            rightRotate(&root1, current->right);
            leftRotate(&root1, current);
        }

        current = current->parent;
        
    }

    }

    // rightRotate(&root2, v_parent);

    return root2;


}


Node* join(Node *T1, int k, Node *T2) {

    if(height(T1) >= height(T2))
        return join1(T1, k, T2);
    
    else
        return join2(T1, k, T2);
}


// Return 0 if root != NULL
// If root = NULL, returns -1
int split(Node *root, int key, Node **RetLeft, bool *value, Node **RetRight) {

    if(root == NULL)
        return -1;

    Node *L, *R;
    int m;

    expose(root, &L, &m, &R);

    displayTree(L);
    displayTree(R);
    std::cout<<"m = "<<m<<std::endl;

    if(key == m) {

        std::cout<<"key == m case"<<std::endl;

        *RetLeft = L;
        *value = true;
        *RetRight = R;

        return 0;
    }

    if(key < m) {

            std::cout<<"key < m case"<<std::endl;

        Node *L1, *R1;
        bool b;

        split(L, key, &L1, &b, &R1);
        *RetLeft = L;
        *value = b;
        *RetRight = join(R1, m,  R);

        return 0;
    }

    if(key > m) {

        std::cout<<"key > m case"<<std::endl;

        Node *L1, *R1;
        bool b;

        split(R, key, &L1, &b, &R1);
        *RetLeft = join(L, m, L1);
        *value = b;
        *RetRight = R;

        return  0;
    }

    // return;
}





















}   // namespace avltree end.

#endif  // _PROBLEM_2_H