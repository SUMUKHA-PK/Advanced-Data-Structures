#include<bits/stdc++.h>
using namespace std;

namespace avltree{

    typedef struct node {
        struct node * left = NULL; 
        struct node * right = NULL;
        struct node * parent = NULL;
        int key;
        int height;
    } Node;

    void inorder(Node * head) {
        
        if(head==NULL) {
            cout<<endl;
            return;
        }
        
        inorder(head->left);
        cout<<"Node-> Value: "<<head->key;
        inorder(head->right);
    }
    
    int height(Node * head) {

        if(head == NULL) {
            return 0;
        }
        int lh = height(head->left);
        int rh = height(head->right);

        return 1 + max(lh,rh);
    }

    void printOneLevel(Node * node, int level) {

        if(node == NULL) {
            return;
        }

        if(level==1) {
            cout<<node->key<<" ";
        }
        else if(level>1) {
            printOneLevel(node->left,level-1);
            printOneLevel(node->right,level-1);
        }
    }

    void levelOrder(Node * node) {
        
        int h = height(node);
        for(int i=1;i<=h;i++) 
            printOneLevel(node,i);
        cout<<endl;
    }

    void leftRotate(Node * x) {
        
        Node * y = x->right;
        Node * T2 = y->left;
        Node * par = x->parent;

        y->left = x;
        x->right = T2;

        if(x->parent->right==x){
            x->parent->right =y;
            y->parent = x->parent;
        }
        else if (x->parent->left==x){
            x->parent->left =y;
            y->parent = x->parent;
        }
        x->parent = y;
        x->height = max(height(x->left),height(x->right))+1;
        y->height = max(height(y->left),height(y->right))+1;
    }

    void rightRotate(Node * y) {

        Node * x = y->left;
        Node * T2 = x->right;

        x->right = y;
        y->left = T2;

        if(y->parent->right==y){
            y->parent->right =x;
            x->parent = y->parent;
        }
        else if (y->parent->left==y){
            y->parent->left =x;
            x->parent = y->parent;
        }
        y->parent = x;
        x->height = max(height(x->left),height(x->right))+1;
        y->height = max(height(y->left),height(y->right))+1;
    }

}