#include<bits/stdc++.h>
using namespace std;

namespace rbtree {
    
    typedef struct node {
        struct node * left = NULL;
        struct node * right = NULL;
        struct node * parent = NULL;
        string color;
        int key;
    } Node;
    
    void inorder(Node * head) {
        
        if(head==NULL) {
            cout<<endl;
            return;
        }
        
        inorder(head->left);
        cout<<"Node-> Value: "<<head->key<<" Color: "<<head->color;
        inorder(head->right);
    }

    void leftRotate(Node * x) {
        Node * y = x->right;
        // Node * temp = y->left;
        // y->left = x;
        // x->right = temp;
        x->right = y->left;
        if(y->left!=NULL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        // // if(x->parent == NULL) {

        // // }
        if (x == x->parent->left) {
            x->parent->left = y;
        }
        else 
            x->parent->right = y;
        y->left = x;
        x->parent = y;
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

        if(node ==NULL) {
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
    }
}