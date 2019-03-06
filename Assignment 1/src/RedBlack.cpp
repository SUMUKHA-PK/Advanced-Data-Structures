#include<bits/stdc++.h>
#include"RedBlack.h"

using namespace rbtree;

int main() {
    Node * root = new Node;
    // Node * Left = new Node;
    // Node * left1 = new Node;
    // Node * left2 = new Node;
    // Node * Right = new Node;
    // Node * right1 = new Node;
    // Node * right2 = new Node;
    // Node * right3 = new Node;

    // root->left = Left;
    // root->right = Right;
    root->key = 4;
    root->color = "BLACK";

    // Left->left = left1;
    // Left->right = left2;
    // Left->key = 2;
    // Left->color = "RED";
    // Left->parent = root;
    
    // Right->right = right3;
    // Right->key = 14;
    // Right->color = "BLACK";
    // Right->parent = root;

    // left1->key = 1;
    // left1->color = "BLACK";
    // left1->parent = Left;

    // left2->left = right1;
    // left2->right = right2;
    // left2->key = 7;
    // left2->color = "BLACK";
    // left2->parent = Left;

    // right1->key = 5;
    // right1->color = "RED";
    // right1->parent = left2;

    // right2->key = 8;
    // right2->color = "RED";
    // right2->parent = left2;

    // right3->key = 15;
    // right3->color = "RED";
    // right3->parent = Right;
    
    // // inorder(root);
    // // levelOrder(root);
    // // leftRotate(Right);

    // // inorder(root);
    // // levelOrder(root);
    // // rightRotate(right3);
  
    inorder(root);
    levelOrder(root);
    insertNode(&root,root,createNode(10),NULL,-1);

    inorder(root);
    levelOrder(root);
    insertNode(&root,root,createNode(6),NULL,-1);

        inorder(root);
    levelOrder(root);
    insertNode(&root,root,createNode(1),NULL,-1);

    inorder(root);
    levelOrder(root);
    insertNode(&root,root,createNode(5),NULL,-1);
        inorder(root);
    levelOrder(root);
    insertNode(&root,root,createNode(3),NULL,-1);

    inorder(root);
    levelOrder(root);
    insertNode(&root,root,createNode(8),NULL,-1);
        inorder(root);
    levelOrder(root);
    insertNode(&root,root,createNode(12),NULL,-1);

    inorder(root);
    levelOrder(root);
    insertNode(&root,root,createNode(16),NULL,-1);
        inorder(root);
    levelOrder(root);
    insertNode(&root,root,createNode(19),NULL,-1);

    inorder(root);
    levelOrder(root);
    insertNode(&root,root,createNode(20),NULL,-1);
        inorder(root);
    levelOrder(root);
    insertNode(&root,root,createNode(40),NULL,-1);

    inorder(root);
    levelOrder(root);
    insertNode(&root,root,createNode(100),NULL,-1);
    inorder(root);
    levelOrder(root);

    insertNode(&root,root,createNode(200),NULL,-1);
    inorder(root);
    levelOrder(root);

    insertNode(&root,root,createNode(7),NULL,-1);
    inorder(root);
    levelOrder(root);


    insertNode(&root,root,createNode(9),NULL,-1);
    inorder(root);
    levelOrder(root);

    insertNode(&root,root,createNode(1000),NULL,-1);
    inorder(root);
    levelOrder(root);


    insertNode(&root,root,createNode(11),NULL,-1);
    inorder(root);
    levelOrder(root);


    insertNode(&root,root,createNode(13),NULL,-1);
    inorder(root);
    levelOrder(root);

    // deleteNode(root,1000);
    inorder(root);
    levelOrder(root);
    return 0;
}
