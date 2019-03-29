//Authored: Sumukha PK , 2019

#include<bits/stdc++.h>
#include"BinomialHeap.h"
using namespace binomialheap;

int main(){
    map<int,int> hashMap;

    Node* node= createNode(1,hashMap, 0);
    //Look into the problem of returning nodes

    srand(time(NULL));
    for(int i=1;i<12;i++){
        int j = i +1;
        heapUnion(&node,node,createNode(j,hashMap, i),hashMap);  
        
    }
// printHeap(node); 
    
    
    // heapUnion(&node,node,createNode(2,hashMap),hashMap);

    // heapUnion(&node,node,createNode(11,hashMap),hashMap);
    
    // heapUnion(&node,node,createNode(1,hashMap),hashMap);

    // heapUnion(&node,node,createNode(3,hashMap),hashMap);

    // heapUnion(&node,node,createNode(5,hashMap),hashMap);

    // heapUnion(&node,node,createNode(7,hashMap),hashMap);

    // heapUnion(&node,node,createNode(4,hashMap),hashMap);
    
    // heapUnion(&node,node,createNode(6,hashMap),hashMap);
    
    // heapUnion(&node,node,createNode(8,hashMap),hashMap);
    
    // heapUnion(&node,node,createNode(9,hashMap),hashMap);

    // heapUnion(&node,node,createNode(12,hashMap),hashMap);
    
    // heapUnion(&node,node,createNode(19,hashMap),hashMap);
    
    // heapUnion(&node,node,createNode(13,hashMap),hashMap);
    
    // heapUnion(&node,node,createNode(15,hashMap),hashMap);
    printHeap(node);
    
    // cout<<getMin(&node)->val<<endl;

    for(int i=0;i<11;i++){
        extractMin(&node,hashMap);
        printHeap(node);
    }


    // for(int i=0;i<100;i++){
    //     int j = rand() %1000 +1;
    //     heapUnion(&node,node,createNode(j,hashMap),hashMap);
        
    // }
    // cout<<node->right->nodes[3]->nodes[1]->val<<endl;

    // decreaseKey(node->right->nodes[3]->nodes[1],4);
    // cout<<node->l<<endl;
    printHeap(node);
    return 0;
}