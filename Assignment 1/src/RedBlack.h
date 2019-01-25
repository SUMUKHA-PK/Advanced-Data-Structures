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

    void leftRotate(Node * head , Node * x) {
        
        Node * y = x->right;
        
        x->right = y->left;
        if(y->left!=NULL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if(x->parent!=NULL){
            if (x == x->parent->left) {
                x->parent->left = y;
            }
            else {
                x->parent->right = y;
            }
        }
        else{
            // head = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node * head , Node * y) {
        
        Node * x = y->left;
            
        y->left = x->right;

        if(x->right!=NULL) {
            x->right->parent = y;
        }

        x->parent = y->parent;
        if(y->parent!=NULL){
            if(y==y->parent->left) {
                y->parent->left = x;
                
            }
            else {
                y->parent->right = x;
            }
        }
        else{
            // head = x;
            // cout<<head->left->key<<endl;
            // head->left = x->left;
            // cout<<head->left->key<<endl;
            // cout<<"ERE"<<endl;
        }
        
        x->right = y;
        y->parent = x;
    }

    Node * createNode(int val) {
        Node * node = new Node;
        node ->key = val;
        return node;
    }


    //Did not understand this. Check it out later
    void insertFixup(Node * head, Node * z) {
        
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
                    leftRotate(head,z);
                    cout<<endl;
                    inorder(head);
                    levelOrder(head);
                    z->parent->color = "BLACK";
                    z->parent->parent->color = "RED";
                    cout<<endl;
                    inorder(head);
                    levelOrder(head);
                    cout<<"Stupidsss"<<endl;
                    cout<<head->key<<endl;
                    rightRotate(head,z->parent->parent);
                    cout<<head->key<<endl;
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

    void insertNode(Node * head, Node * z) {
        
        Node * y = NULL;
        Node * x = head;

        while(x!=NULL) {
            y = x;
            if(z->key<x->key) {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }

        z->parent = y;
        
        if(y==NULL) {
            head = z;
        }
        else if(z->key<y->key) {
            y->left = z;
        }
        else {
            y->right = z;
        }
        z->color = "RED";

        insertFixup(head, z);
        cout<<"WTF"<<endl;
    } 
}