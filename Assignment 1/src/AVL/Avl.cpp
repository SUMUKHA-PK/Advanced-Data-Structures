#include "Avl.h"

using namespace avltree;

int main() {
    
    // Node * root = new Node;
    // Node * Left = new Node;
    // Node * left1 = new Node;
    // Node * left2 = new Node;
    // Node * Right = new Node;
    // Node * right1 = new Node;
    // Node * right2 = new Node;
    // // Node * right3 = new Node;

    // root->left = Left;
    // root->right = Right;
    // root->key = 4;

    // Left->left = left1;
    // Left->right = left2;
    // Left->key = 2;
    // Left->parent = root;

    // Right->left = right1;
    // Right->right = right2;
    // Right->key = 6;
    // Right->parent = root;

    // left1->key = 1;
    // left1->parent = Left;

    // left2->key = 3;
    // left2->parent = Left;

    // right1->key = 5;
    // right1->parent = Right;

    // right2->key = 13;
    // right2->parent = Right;

    // inorder(root);
    // levelOrder(root);

    // leftRotate(Right);
    // inorder(root);
    // levelOrder(root);

    // rightRotate(right2);
    // inorder(root);
    // levelOrder(root);

    // leftRotate(Left);
    // inorder(root);
    // levelOrder(root);

    // rightRotate(left2);
    // inorder(root);
    // levelOrder(root);

    // leftRotate(Right);
    // inorder(root);
    // levelOrder(root);

    // rightRotate(right2);
    // inorder(root);
    // levelOrder(root);

    // // insertNode(root,createNode(7),NULL,-1);
    // // inorder(root);
    // // levelOrder(root);

    
    // insertNode(root,createNode(8),NULL,-1);
    // inorder(root);
    // levelOrder(root);

    
    // insertNode(root,createNode(9),NULL,-1);
    // inorder(root);
    // levelOrder(root);

    
    // insertNode(root,createNode(10),NULL,-1);
    // inorder(root);
    // levelOrder(root);

    // deleteNode(root,13,NULL,1);
    // inorder(root);
    // levelOrder(root);

    // std::cout<<"Stupids here"<<std::endl;
    Node *root = createNode(1);

    // std::cout<<"Stupids here"<<std::endl;

    // displayTree(root);

    // std::cout<<"Stupids here"<<std::endl;

    insertNode(&root,root, createNode(1), NULL, -1);
    // displayTree(root);


    // insertNode(&root,root, createNode(2), NULL, -1);
    // displayTree(root);

    insertNode(&root,root, createNode(1), NULL, -1);
    displayTree(root);
    // std::cout<<"Stupids here"<<std::endl;


    // deleteNode(&root, root, 1, NULL, -1);
    // // insertNode(&root,root, createNode(4), NULL, -1);
    // // std::cout<<"Stupids here"<<std::endl;
    
    // displayTree(root);

    // deleteNode(&root,root,1,NULL,-1);

    // displayTree(root);
    // std::cout<<"Stupids here"<<std::endl;

    return 0;
}