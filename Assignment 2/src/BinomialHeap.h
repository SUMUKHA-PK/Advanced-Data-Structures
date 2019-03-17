#include<bits/stdc++.h>
using namespace std;

namespace binomialheap{
    
    typedef struct node{
        int l;//length of the vector
        vector<node*> nodes; // Contains all its children
        struct node*  parent = NULL;
        int val;
        int head;
        struct node* left = NULL;
        struct node* right = NULL;
    }Node;

/*
 *  createNode creates a node* pointer,
 *  checks whether a single node exists,
 *  and hashes that values in if necessary.
 */

    Node * createNode(int n,map<int,int> &hashMap){
        Node * node = new Node;
        node->val = n;
        node->l = 1;
        node->head=1;
        if(hashMap.find(1)!=hashMap.end()){
            hashMap.insert(pair<int,int>(1,1));
        }
        return node;
    }

    void printVec(Node * heapNode,int lvl){
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
        int lvl=1;
        while(heapNode!=NULL){
            cout<<"Head: "<<heapNode->val<<endl;
            printVec(heapNode,lvl);
            heapNode=heapNode->right;
        }
        cout<<endl;
    }

/*
 *  fixHeap : Used to make the structure of the heap bheap type.
 *  calledBy -> heapUnion.
 *  hashmap is used to hash the values and check whether there is a collision,
 *  and heap fixing is needed.
 */

    void fixHeap(Node** heapNode,map<int,int> &hashMap,int l){
        Node* temp = *heapNode;
        while(temp->l<l){
            temp=temp->right;
        }
        if(temp->l!=l) temp=temp->right;
        if(temp->val<temp->right->val){
            // if(temp==*heapNode){
            //     *heapNode = temp->right;
            // }
            temp->nodes.push_back(temp->right);
            temp->right->parent=temp;
            // temp->right->left=NULL;
            // temp->right->right=NULL;
            temp->right = temp->right->right;
            if(temp->right!=NULL){
                temp->right->left=temp;
            }
            hashMap.erase(temp->l);
            temp->l = temp->l + 1;
            if(hashMap.find(temp->l)==hashMap.end()){
                hashMap.insert(pair<int,int>(temp->l,1));
            }
            else{
                fixHeap(heapNode,hashMap,temp->l);
            }
        }
        else{
            temp->right->nodes.push_back(temp);
            temp->parent=temp->right;
            if(temp->left!=NULL){
                temp->left->right=temp->right;
                temp->right->left = temp->left;
            }
            else{
                temp->right->left=NULL;
            }
            hashMap.erase(temp->l);
            if(*heapNode==temp){
                *heapNode = temp->right;
            }
            temp=temp->right;
            temp->l = temp->l + 1;
            if(hashMap.find(temp->l)==hashMap.end()){
                hashMap.insert(pair<int,int>(temp->l,1));
            }
            else{
                fixHeap(heapNode,hashMap,temp->l);
            }
        }
    }

/*
 *  heapUnion: Merges 2 heaps.
 *  Adds node2 heap to node1 heap.
 *  Checks whether there is a collision and then calls fixHeap.
 */

    void heapUnion(Node** node,Node* node1, Node* node2, map<int,int> &hashMap){  
        //Iterate to find the right node in order to insert
        while(node1->right!=NULL && node1->l<node2->l){
            node1=node1->right;
        }
        // If the degrees of the nodes are same, compare the value and add based on that
        if(node1->l==node2->l){
            if(node1->val<node2->val){
                node1->nodes.push_back(node2);
                node2->parent=node1;
                node2->head=0;   
                hashMap.erase(node1->l);
                node1->l= node1->l+1;
               if(hashMap.find(node1->l)==hashMap.end()){
                    hashMap.insert(pair<int,int>(node1->l,1));
                }
                // If there is a collision in the 'l' values, fixheap.
                else{
                    fixHeap(node,hashMap,node1->l);
                }
            }
            else{
                node2->right=node1->right;
                node2->left=node1->left;
                node1->left=NULL;
                node1->right=NULL;
                node2->nodes.push_back(node1);
                node1->parent=node2;
                node1->head=0;
                node2->head=1;
                hashMap.erase(node1->l);
                node2->l= node2->l+1;
                node1=node2;
                *node = node1;
                if(hashMap.find(node1->l)==hashMap.end()){
                    hashMap.insert(pair<int,int>(node1->l,1));
                }
                else{
                    fixHeap(node,hashMap,node1->l);
                }
            }
        }
        // If the degree is not same, insert checking whether its the first node to be added or in the middle.
        else{
            if(node1->left==NULL){
                node2->right=node1;
                node1->left=node2;
                node1=node2;
                *node = node1;
            }
            else{
                node2->right=node1->right->right;
                node2->right->left = node2;
                node1->right=node2;
                node2->left=node1;
                *node=node2;
            }
        }
    }


/*
 *  getMin : Returns the node with the least value in the heap 
 */
    Node * getMin(Node **heapNode){

        Node * temp = *heapNode;

        int min = temp->val;
        temp = temp->right;
        while(temp->right!=NULL){
            if(temp->val<min){
                min = temp->val;
            }
            temp=temp->right;
        }
        return temp;
    }


    void extractMin(Node ** heapNode) {
        
        Node * minNode = getMin(heapNode);

    }

} //namespace BHeap
