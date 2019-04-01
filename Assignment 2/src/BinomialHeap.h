//Authored: Sumukha PK , 2019

#include<bits/stdc++.h>
using namespace std;

namespace binomialheap{
    
    typedef struct node{
        int l;//length of the vector
        vector<node*> nodes; // Contains all its children
        struct node*  parent = NULL;
        int val;
        int head;
        int id;
        struct node* left = NULL;
        struct node* right = NULL;
    }Node;

/*
 *  createNode creates a node* pointer,
 *  checks whether a single node exists,
 *  and hashes that values in if necessary.
 */

    Node * createNode(int n,map<int,int> &hashMap, int id){
        Node * node = new Node;
        node->val = n;
        node->l = 1;
        node->head=1;
        node->id = id;
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
            temp->nodes.push_back(temp->right);
            temp->right->parent=temp;
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
                if(node1->left!=NULL&&node1->right!=NULL){
                    node2->right=node1->right;
                    node2->right->left=node2;
                    node2->left=node1->left;
                    node2->left->right=node2;
                    node1->right=NULL;
                    node1->left=NULL;
                }
                else if(node1->left!=NULL){
                    node2->left=node1->left;
                    node2->left->right=node2;
                    node2->right=NULL;
                    node1->right=NULL;
                    node1->left=NULL;
                }
                else if(node1->right!=NULL){
                    node2->right=node1->right;
                    node2->right->left=node2;
                    *node=node2;
                    node2->left=NULL;
                    node1->right=NULL;
                    node1->left=NULL;
                }
                if(*node==node1) *node = node2;
                node2->nodes.push_back(node1);
                node1->parent=node2;
                node1->head=0;
                node2->head=1;
                hashMap.erase(node1->l);
                node2->l= node2->l+1;
                if(hashMap.find(node2->l)==hashMap.end()){
                    hashMap.insert(pair<int,int>(node2->l,1));
                }
                else{
                    fixHeap(node,hashMap,node2->l);
                }
            }
        }
        // If the degree is not same, insert checking whether its the first node to be added or in the middle.
        else{
            if(node1->l>node2->l){
                if(node1->left==NULL){
                    node2->right=node1;
                    node1->left=node2;
                    node2->left=NULL;
                    *node = node2;
                }
                else{
                    node2->left=node1->left;
                    node1->left->right=node2;
                    node1->left=node2;
                    node2->right=node1;
                }
            }
            else{
                if(node1->right==NULL){
                    node1->right = node2;
                    node2->left = node1;
                    node2->right=NULL;
                }   
                else{
                    node1->right->left=node2;
                    node2->right=node1->right;
                    node1->right=node2;
                    node2->left=node1;
                }
            }
        }
    }


/*
 *  getMin : Returns the node with the least value in the heap 
 */
    Node * getMin(Node **heapNode){

        Node * temp = *heapNode;
        Node * minNode = temp;
        int min = temp->val;
        temp = temp->right;
        while(temp!=NULL){
            if(temp->val<min){
                min = temp->val;
                minNode = temp;
            }
            temp=temp->right;
        }
        return minNode;
    }


    void extractMin(Node ** heapNode,map<int,int>&hashMap) {
        
        Node * minNode = getMin(heapNode);
        Node * temp = *heapNode;
        int start = 0;
        if(*heapNode==minNode){
            if(minNode->right!=NULL){
                *heapNode = minNode->right;
                minNode->right->left=NULL;
                minNode->right=NULL;
            }
            else{
                if(temp->nodes[0]!=NULL){
                    *heapNode = temp->nodes[0];
                    start=1;
                }
                else{
                    printf("Heap empty!\n");
                    return;
                }
            }
        }
        else{
            if(minNode->right!=NULL&&minNode->left!=NULL){
                minNode->left->right = minNode->right;
                minNode->right->left = minNode->left;
                minNode->right=NULL;
                minNode->left=NULL;
            }
            else if(minNode->left!=NULL){
                minNode->left->right = NULL;
                minNode->left=NULL;
            }
        }
        hashMap.erase(minNode->l);
        for(int i=start;i<minNode->nodes.size();i++){
            if(hashMap.find(minNode->nodes[i]->l)!=hashMap.end()) hashMap.insert(pair<int,int>(minNode->nodes[i]->l,1));  
            Node * temp = *heapNode;
            heapUnion(heapNode,*heapNode,minNode->nodes[i],hashMap);
        }
        delete(minNode);
        
    }

    void decreaseKey(Node * node, int key){
        if(node->val==key){
            return;
        }
        node->val=key;
        while(node->parent!=NULL&&node->parent->val>node->val){
            int temp = node->val;
            node->val = node->parent->val;
            node->parent->val = temp;
            node=node->parent;
        }
    }

// n2 is parent!!!
void ChildCopy(Node *n1, Node *n2) {

    vector<Node*> temp;

    

    for(int i = 0; i < n1->nodes.size(); i++) {
        temp.push_back(n1->nodes[i]);
    }

    n1->nodes.clear();

    for(int i = 0; i < n2->nodes.size(); i++) {
        
        if(n2->nodes[i] != n1)
            n1->nodes.push_back(n2->nodes[i]);
    }

    n2->nodes.clear();

    for(int i = 0; i < temp.size(); i++)
        n2->nodes.push_back(temp[i]);
}



void decreaseKey(Node * node, int key){
    
    cout<<"In decrease key!!!, nodeid = "<<node->id<<endl;

    if(node->val==key){
        return;
    }
    node->val=key;
    while(node->parent!=NULL&&node->parent->val>node->val){
        
        Node *parent = node->parent;
        if(parent->left != NULL && parent->right != NULL) {
            node->left = parent->left;
            node->right = parent->right;
            parent->left->right = node;
            parent->right->left = node;
        }

        else if(parent->left == NULL) {
            
            node->right = parent->right;
            parent->right->left = node;
        }

        else if(parent->right == NULL) {
            node->left = parent->left;
            parent->left->right = node;
        }
        parent->parent = node;
            
        ChildCopy(node, parent);
        node->nodes.push_back(parent);

        node->parent = NULL;
        parent->left = NULL;
        parent->right = NULL;



    }
}

} //namespace BHeap
