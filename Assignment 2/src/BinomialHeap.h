#include<bits/stdc++.h>
using namespace std;

namespace binomialheap{
    
    typedef struct node{
        // int l;//length of the vector(debated)
        vector<node*> nodes; // Contains all its children
        struct node*  parent = NULL;
        int val;
        int head = 1; // Tell whether its in the top chain
        struct node* left = NULL;
        struct node* right = NULL;
    }Node;

    Node * createNode(int n){
        Node * node = new Node;
        node->val = n;
        return node;
    }

    void printVec(Node * heapNode,int lvl){
        // if(heapNode->parent!=NULL){
        //     cout<<heapNode->parent->val<<": ";
        // }
        if(heapNode->nodes.size()>0){
            cout<<"Level "<<lvl<<",parent "<< heapNode->val<<" : ";
            for(int i=0;i<heapNode->nodes.size();i++){
                cout<<heapNode->nodes[i]->val<<" ";
            }
            cout<<endl;
            lvl++;
            for(int i=0;i<heapNode->nodes.size();i++){
                printVec(heapNode->nodes[i],lvl);
            }
        }
    }

    void printHeap(Node * heapNode){
        cout<<"Head: "<<heapNode->val<<endl;
        int lvl=1;
        while(heapNode!=NULL){
            printVec(heapNode,lvl);
            heapNode=heapNode->right;
        }
    }

}