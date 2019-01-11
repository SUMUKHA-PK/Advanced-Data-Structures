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

    root->left = Left;
    root->right = Right;
    root->key = 1;
    root->color = "BLACK";

    Left->left = left1;
    Left->right = left2;
    Left->key = 2;
    Left->color = "RED";
    Left->parent = root;
    
    Right->left = right1;
    Right->right = right2;
    Right->key = 3;
    Right->color = "BLACK";
    Right->parent = root;

    left1->key = 4;
    left1->color = "RED";
    left1->parent = Left;

    left2->key = 5;
    left2->color = "BLACK";
    left2->parent = Left;

    right1->key = 6;
    right1->color = "BLACK";
    right1->parent = Right;

    right2->key = 7;
    right2->color = "RED";
    right2->parent = Right;

    inorder(root);

    levelOrder(root);
    leftRotate(Right);

    inorder(root);
    levelOrder(root);

    rightRotate(right2);
    inorder(root);
    levelOrder(root);

    return 0;
}