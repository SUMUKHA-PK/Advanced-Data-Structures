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
    }

    void leftRotate(Node ** root, Node * x) {
        
        Node * y = x->right;
        Node * T2 = y->left;

        y->left = x;
        x->right = T2;
        x->right->parent = x;

        if(x->parent!=NULL){
            if(x->parent->right==x){
                x->parent->right =y;
                y->parent = x->parent;
            }
            else if (x->parent->left==x){
                x->parent->left =y;
                y->parent = x->parent;
            }
        }
        else {
            y->parent = NULL;
            *root = y;
        }
        x->parent = y;
    }

    void rightRotate(Node ** root, Node * y) {
        Node * x = y->left;
        Node * T2 = x->right;

        x->right = y;
        y->left = T2;
        y->left->parent=y;

        if(y->parent!=NULL){
            if(y->parent->right==y){
                y->parent->right =x;
                x->parent = y->parent;
            }
            else if (y->parent->left==y){
                y->parent->left =x;
                x->parent = y->parent;
            }
        }
        else{
            x->parent=NULL;
            *root = x;
            // cout<<x->left->key<<" "<<*root->left->key<<endl;
            // cout<<endl<<*root->key<<endl;
        }
        y->parent = x;
        // cout<<x->left->key<<" "<<*root->left->key<<endl;
    }

    Node * createNode(int val) {
        Node * node = new Node;
        node ->key = val;
        return node;
    }


    //Did not understand this. Check it out later
    void insertFixup(Node ** head, Node * z) {
        
        while(z->parent->color == "RED"&&z->parent!=NULL) { 
            if(z->parent == z->parent->parent->left) {
                Node * y = z->parent->parent->right;
                if(y->color == "RED") {
                    z->parent->color = "BLACK" ;
                    y->color = "BLACK";
                    z->parent->parent->color = "RED";
                    z = z->parent->parent;
                }
                else if(z==z->parent->right) {
                    z = z->parent;
                    cout<<"F"<<endl;
                    leftRotate(head,z);
                    z->parent->color = "BLACK";
                    z->parent->parent->color = "RED";
                    rightRotate(head,z->parent->parent);
                    // cout<<endl<<head->key<<endl<<endl;
                }
            }
            else if(z->parent == z->parent->parent->right) {
                cout<<"Stupid1s"<<endl;
                Node * y = z->parent->parent->left;
                if(y->color == "RED") {
                    z->parent->color = "BLACK" ;
                    y->color = "BLACK";
                    z->parent->parent->color = "RED";
                    z = z->parent->parent;
                    cout<<"Stupi2ds"<<endl;
                }
                else if(z==z->parent->left) {
                    z = z->parent;
                    leftRotate(head,z);
                    z->parent->color = "BLACK";
                    z->parent->parent->color = "RED";
                    cout<<"Stupids"<<endl;
                    rightRotate(head,z->parent->parent);
                }
            }
            cout<<"LOOPING"<<endl;
        }
    }

     void insertNode(Node** root,Node * head,Node * node, Node * parent, int d){

        if(head == NULL) {
            if(d==0) {
                parent->left = node;
                node->parent = parent;
                node->color = "RED";
            }
            else if(d==1) {
                parent->right = node;
                node->parent = parent;
                node->color = "RED";
            }
            else {
                head = node;
                head->color = "BLACK";
                head->parent = NULL;
            }
            return;
        }

        if(node->key<head->key){
            insertNode(root,head->left,node,head,0);
        }
        else{
            insertNode(root,head->right,node,head,1);
        }

        // cout<<node->parent->key<<endl;
        inorder(*root);
        levelOrder(*root);
    
        insertFixup(root, node);

        cout<<"WTF"<<endl;
    } 
}