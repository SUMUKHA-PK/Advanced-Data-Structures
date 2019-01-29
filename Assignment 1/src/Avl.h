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

    Node * createNode(int key){

        Node * node = new Node;
        node->key = key;
        return node;
    }

    int getBalance(Node* node){
        if(node==NULL){
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    void insertNode(Node * head,Node * node, Node * parent, int d){

        if(head == NULL) {
            if(d==0) {
                parent->left = node;
                node->parent = parent;
            }
            else if(d==1) {
                parent->right = node;
                node->parent = parent;
            }
            else head = node;
            return;
        }

        if(node->key<head->key){
            insertNode(head->left,node,head,0);
        }
        else{
            insertNode(head->right,node,head,1);
        }

        head->height = 1 + max(height(head->left),height(head->right));

        int balance = getBalance(head);
        
        if(balance>1 && node->key<head->left->key) {
            rightRotate(head);
            return;
        }
        if(balance<-1 && node->key>head->right->key) {
            leftRotate(head);
            return;
        }
        if(balance>1 && node->key>head->left->key){
            leftRotate(head->left);
            rightRotate(head);
            return;
        }
        if(balance<-1 && node->key<head->right->key) {
            rightRotate(head->right);
            leftRotate(head);
            return;
        }
        return;
    }

    Node * inorderSuccessor(Node* node,int &n) {
        Node * nodeTemp = new Node;
        while(nodeTemp!=NULL){
            nodeTemp=nodeTemp->left;
            n=0;
        }
        return nodeTemp;
    }

    void deleteNode(Node * head,int key, Node * parent, int d) {
        
        if(head==NULL)
            return;
        if(key<head->key) {
            deleteNode(head->left,key,head,0);
        }
        else if(key>head->key){
            deleteNode(head->right,key,head,1);
        }
        else{
            if((head->left==NULL)||(head->right==NULL)){
                Node * nodeTemp = new Node;
                if(head->left==NULL) {
                    nodeTemp = head->right;
                }
                if(head->right==NULL) {
                    nodeTemp = head->left;
                }
                if(nodeTemp ==NULL){
                    nodeTemp = head;
                    head = NULL;
                }
                else {
                    * head = * nodeTemp;
                }
                delete nodeTemp;
            }
            else {
                int n = 1;
                Node * nodeTemp = inorderSuccessor(head->right,n);
                head->key = nodeTemp->key;
                deleteNode(head->right,nodeTemp->key,nodeTemp->parent,n); 
            }
        }

        if(head==NULL)
            return;

        head->height = 1 + max(height(head->left),height(head->right));

        int balance = getBalance(head);

        if(balance>1 && getBalance(head->left)>=0){
            rightRotate(head);
            return;
        }

        if(balance>1 && getBalance(head->left)<0){
            leftRotate(head->left);
            rightRotate(head);
            return;
        }

        if(balance<-1 && getBalance(head->right)<=0) {
            leftRotate(head);
            return;
        }
        
        if(balance<-1 && getBalance(head->right)>0) {
            rightRotate(head->right);
            leftRotate(head);
            return;
        }

        return;
    }
}