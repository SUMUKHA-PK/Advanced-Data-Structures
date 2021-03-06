#ifndef _AVL_H
#define _AVL_H 1

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

    void leftRotate(Node ** root, Node * x) {
        Node * y = x->right;
        Node * T2 = y->left;

        y->left = x;
        x->right = T2;
        if(x->right!=NULL) x->right->parent = x;

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
        if(y->left!=NULL) y->left->parent=y;

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
        }
        y->parent = x;
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

    void insertNode(Node **root, Node * head,Node * node, Node * parent, int d){
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
            insertNode(root,head->left,node,head,0);
        }
        else{
            insertNode(root,head->right,node,head,1);
        }

        head->height = 1 + max(height(head->left),height(head->right));

        int balance = getBalance(head);
        
        if(balance>1 && node->key<head->left->key) {
            rightRotate(root,head);
            return;
        }
        if(balance<-1 && node->key>head->right->key) {
            leftRotate(root,head);
            return;
        }
        if(balance>1 && node->key>head->left->key){
            leftRotate(root,head->left);
            rightRotate(root,head);
            return;
        }
        if(balance<-1 && node->key<head->right->key) {
            rightRotate(root,head->right);
            leftRotate(root,head);
            return;
        }
        return;
    }

    Node * inorderSuccessor(Node* node,int &n) {
        Node * nodeTemp = node;
        while(nodeTemp!=NULL){
            node = nodeTemp;
            nodeTemp=nodeTemp->left;
            n=0;
        }
        return node;
    }

    void deleteNode(Node ** root,Node * head,int key, Node * parent, int d) {
        if(head==NULL)
            return;
        if(key<head->key) {
            deleteNode(root,head->left,key,head,0);
        }
        else if(key>head->key){
            deleteNode(root,head->right,key,head,1);
        }
        else{
            if(head->left==NULL&&head->right==NULL){
                if(head->parent!=NULL){
                    if(head->parent->right==head){
                        head->parent->right=NULL;
                    }
                    else {
                        head->parent->left=NULL;
                    }
                    delete head;
                }
                else{
                    * root = NULL;
                    delete head;
                    return;
                }
            }
            else if(head->left==NULL){
                if(head->parent!=NULL){
                    if(head->parent->right==head){
                        head->parent->right = head->right;
                        head->right->parent = head->parent;
                        Node * temp = head;
                        head=head->right;
                        delete temp;
                    }
                    else if(head->parent->left==head){
                        head->parent->left = head->right;
                        head->right->parent = head->parent;
                        Node * temp = head;
                        head=head->right;
                        delete temp;
                    }
                }
                else{
                    head->right->parent = NULL;
                    * root = head->right;
                    delete head;
                    return;
                }
            }
            else if(head->right==NULL){
                if(head->parent!=NULL){
                    if(head->parent->right==head){
                        head->parent->right = head->left;
                        head->left->parent = head->parent;
                        Node * temp = head;
                        head=head->left;
                        delete temp;
                    }
                    else if(head->parent->left==head){
                        head->parent->left = head->left;
                        head->left->parent = head->parent;
                        Node * temp = head;
                        head=head->left;
                        delete temp;
                    }
                }
                else{
                    head->left->parent = NULL;
                    * root = head->left;
                    delete head;
                    return;
                }
            }
            // n is set to 1, because it always is right, else if there is a left, it changes
            else {
                int n = 1;
                Node * nodeTemp = new Node;
                nodeTemp = inorderSuccessor(head->right,n);
                head->key = nodeTemp->key;
                deleteNode(root,head->right,nodeTemp->key,head->parent,n); 
            }
        }

        if(head==NULL)
            return;
        
	head->height = 1 + max(height(head->left),height(head->right));

        int balance = getBalance(head);

        if(balance>1 && getBalance(head->left)>=0){
            rightRotate(root,head);
            return;
        }

        if(balance>1 && getBalance(head->left)<0){
            leftRotate(root,head->left);
            rightRotate(root,head);
            return;
        }

        if(balance<-1 && getBalance(head->right)<=0) {
            leftRotate(root,head);
            return;
        }
        
        if(balance<-1 && getBalance(head->right)>0) {
            rightRotate(root,head->right);
            leftRotate(root,head);
            return;
        }

        return;
    }


    void displayTree(Node *ptr) {

        std::cout<<ptr->key;
        // if(ptr->color == RED)
        //     std::cout<<"R";

        // else if(ptr->color == BLACK)
        //     std::cout<<"B";

        if(ptr->left == NULL && ptr->right == NULL)
            return;

        else if(ptr->left != NULL && ptr->right == NULL) {

            std::cout<<"(";
            displayTree(ptr->left);
            std::cout<<",X)";
        }

        else if(ptr->left == NULL && ptr->right != NULL) {

            std::cout<<"(X,";
            displayTree(ptr->right);
            std::cout<<")";
        }

        else {
            std::cout<<"(";
            displayTree(ptr->left);
            std::cout<<",";
            displayTree(ptr->right);
            std::cout<<")";
        }
    }

}   // namespace avltree end.

#endif  // _AVL_H






















