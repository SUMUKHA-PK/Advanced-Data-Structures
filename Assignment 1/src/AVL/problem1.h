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
        return findSmallestKey(root->left);
}

int findLargestKey(Node *root) {

    if(root->right == NULL)
        return root->key;
    
    else
        return findLargestKey(root->right);
}

/******************************************************
 * 
 * The below functions are problem1 functions. 
 * 
 ******************************************************/

Node* populateTree(Node *root, int treeNumber) {

    std::cout<<"Populate Tree-"<<treeNumber<<": "<<std::endl;

    int key, choice, flag = 0;

    Node *newroot = NULL;

    if(treeNumber == 2) {
        std::cout<<"Smallest key of this tree should be larger than largest key of the other tree."<<std::endl;
    }

    while(1) {

        // std::cout<<"1. Insert a node"<<std::endl;
        // std::cout<<"2. I am done with tree-"<<treeNumber<<std::endl;

        std::cin>>choice;

        if(choice == 1) {
            // std::cout<<"Enter a key: "<<std::endl;
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

        // std::cout<<"Tree: "<<std::endl;
        // displayTree(newroot);
        // std::cout<<"\n\n\n"<<std::endl;
    }

    return newroot;
}


// Tree1 is taller than Tree2
Node *case1(Node *root1, Node* root2) {

    std::cout<<"Case1: Tree1 is taller than or same height as Tree2\n\n"<<std::endl;

    // If Tree2 is NULL, then root1 is the required tree. 
    if(root2 == NULL)
        return root1;

    int x1 = findSmallestKey(root2);

    // Delete that smallest key from tree-2
    deleteNode(&root2, root2, x1 , NULL, -1);

    std::cout<<"Tree 2 after deletion of smallest key : "<<std::endl;
    if(root2 != NULL)
        displayTree(root2);
    else
        std::cout<<"No Tree-2 exists after deletion"<<std::endl;

    std::cout<<"\n"<<std::endl;

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


// Tree1 is shorter than Tree 2
Node* case2(Node *root1, Node *root2) {
   
    std::cout<<"Case2: Tree1 is shorter than Tree2\n\n"<<std::endl;

    // If Tree1 is NULL, then root2 is the required tree. 
    if(root1 == NULL)
        return root2;
    
    int x1 = findLargestKey(root1);

    // Delete that largest key from tree-1
    deleteNode(&root1, root1, x1, NULL, -1);

    std::cout<<"Tree 1 after deletion of largest key : "<<std::endl;

    if(root1 != NULL)
        displayTree(root1);
    else
        std::cout<<"There is no Tree 1 after deletion"<<std::endl;
    
    std::cout<<"\n"<<std::endl;

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


// t2 - an AVL Tree
// t1 - an AVL Tree whose largest key is less than smallest key of t2. 

// root1 - root of t1
// root2 - root of t2
Node* mergeTrees(Node* root1, Node* root2) {

    if(root1 == NULL && root2 == NULL)
        return NULL;
    
    else if(root1 == NULL && root2 != NULL)
        return root2;
    
    else if(root1 != NULL && root2 == NULL)
        return root1;

    else {

        if(height(root1) >= height(root2)) {
            return case1(root1, root2);
        }
        else {
            return case2(root1, root2);
        }
    
    }
}


}   // namespace avltree end. 

#endif // _PROBLEM_1_H