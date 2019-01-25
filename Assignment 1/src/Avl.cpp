#include "Avl.h"

using namespace avltree;

int main() {
    
    Node * root = new Node;
    Node * Left = new Node;
    Node * left1 = new Node;
    Node * left2 = new Node;
    Node * Right = new Node;
    Node * right1 = new Node;
    Node * right2 = new Node;
    // Node * right3 = new Node;

    root->left = Left;
    root->right = Right;
    root->key = 4;

    Left->left = left1;
    Left->right = left2;
    Left->key = 2;
    Left->parent = root;

    Right->left = right1;
    Right->right = right2;
    Right->key = 6;
    Right->parent = root;

    left1->key = 1;
    left1->parent = Left;

    left2->key = 3;
    left2->parent = Left;

    right1->key = 5;
    right1->parent = Right;

    right2->key = 7;
    right2->parent = Right;

    inorder(root);
    levelOrder(root);

    leftRotate(Right);
    inorder(root);
    levelOrder(root);

    rightRotate(right2);
    inorder(root);
    levelOrder(root);

    leftRotate(Left);
    inorder(root);
    levelOrder(root);

    rightRotate(left2);
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