#ifndef _PROBLEM_3_H
#define _PROBLEM_3_H 1

#include<bits/stdc++.h>

#include "RedBlack.h"

namespace rbtree {


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

Node* populateTree(Node *root, int treeNumber) {

    std::cout<<"Populate Tree-"<<treeNumber<<": "<<std::endl;

    int key, choice, flag = 0;

    Node *newroot;

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

// h1 >= h2
Node *case1(Node *root1, Node *root2) {

    int x = findSmallestKey(root2);

    std::cout<<"x = "<<x<<std::endl;

    // deleteNode(root2, x);
    deleteNode(&root2, root2, x , NULL, -1);

    std::cout<<"Delete is getting fucked"<<std::endl;

    int h = blackHeight(root2);

    int h1 = blackHeight(root1);

    std::cout<<"h = "<<h<<", h1 = "<<h1<<std::endl;

    displayTree(root2);

    Node* v = root1;
    Node *v_parent;

    // // In the internet, h1 > h+1 is given which I think is not correct. h1 >= h is correct. 
    // while(h1 > h + 1 ) {

    //     if(getBalance(v) == -1)
    //         h1 = h - 2;
    //     else
    //         h1 = h - 1;

    //     v_parent = v;    
    //     v = v->right;
    // }

    // // Root of the new tree. 
    // Node* root3 = createNode(x);

    // // Left Subtree is rooted at v. 
    // root3->left = v;

    // // Right Subtree is t2 itself. 
    // root3->right = root2;

    // v_parent->right = root3;

    // std::cout<<"\n\n\nfuck: "<<std::endl;
    // displayTree(root1);

    // leftRotate(&root1, root1);

    return root1;


}

// h1 < h2
Node *case2(Node *root1, Node *root2) {


}


// t2 - a RB Tree
// t1 - a RB Tree whose largest key is less than smallest key of t2.

// root1 - root of t1
// root2 - root of t2
Node* mergeTrees(Node* root1, Node* root2) {

    if(blackHeight(root1) >= blackHeight(root2)) {

        std::cout<<"bh1 >= bh2"<<std::endl;
    
        return case1(root1, root2);
    }
    else {
        
        std::cout<<"bh1 < bh2"<<std::endl;
        
        return case2(root1, root2);

    
    }
}


}   // namespace rbtree end.

#endif  // _PROBLEM_3_H