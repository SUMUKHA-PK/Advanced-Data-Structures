#include<bits/stdc++.h>
#include"RedBlack.h"

using namespace rbtree;

int main() {
    Node * root = new Node;
    Node * Left = new Node;
    Node * left1 = new Node;
    Node * left2 = new Node;
    Node * Right = new Node;
    Node * right1 = new Node;
    Node * right2 = new Node;
    Node * right3 = new Node;

    root->left = Left;
    root->right = Right;
    root->key = 11;
    root->color = "BLACK";

    Left->left = left1;
    Left->right = left2;
    Left->key = 2;
    Left->color = "RED";
    Left->parent = root;
    
    Right->right = right3;
    Right->key = 14;
    Right->color = "BLACK";
    Right->parent = root;

    left1->key = 1;
    left1->color = "BLACK";
    left1->parent = Left;

    left2->left = right1;
    left2->right = right2;
    left2->key = 7;
    left2->color = "BLACK";
    left2->parent = Left;

    right1->key = 5;
    right1->color = "RED";
    right1->parent = left2;

    right2->key = 8;
    right2->color = "RED";
    right2->parent = left2;

    right3->key = 15;
    right3->color = "RED";
    right3->parent = Right;
    
    inorder(root);

    levelOrder(root);
    leftRotate(Left);

    inorder(root);
    levelOrder(root);

    rightRotate(left2);
    inorder(root);
    levelOrder(root);

    insertNode(root,createNode(10));

    inorder(root);
    levelOrder(root);

    return 0;
}