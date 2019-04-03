//Authored: Sumukha PK , 2019

#include<bits/stdc++.h>
#include"BinomialHeap.h"
using namespace binomialheap;

int main(){
    map<int,int> hashMap;

    Node* node= createNode(1,hashMap, 0);
    //Look into the problem of returning nodes

    srand(time(NULL));
    // for(int i=1;i<10;i++){
    //     int j = rand()%10000 +1;
    //     heapUnion(&node,node,createNode(j,hashMap, i),hashMap);  
        
    // }
// printHeap(node); 
    
    
    heapUnion(&node,node,createNode(2,hashMap,0),hashMap);

    heapUnion(&node,node,createNode(11,hashMap,0),hashMap);
    
    heapUnion(&node,node,createNode(1,hashMap,0),hashMap);

    heapUnion(&node,node,createNode(3,hashMap,0),hashMap);

    heapUnion(&node,node,createNode(5,hashMap,0),hashMap);

    heapUnion(&node,node,createNode(7,hashMap,0),hashMap);

    heapUnion(&node,node,createNode(4,hashMap,0),hashMap);
    
    heapUnion(&node,node,createNode(6,hashMap,0),hashMap);
    
    heapUnion(&node,node,createNode(8,hashMap,0),hashMap);
    
    heapUnion(&node,node,createNode(9,hashMap,0),hashMap);

    heapUnion(&node,node,createNode(12,hashMap,0),hashMap);
    
    heapUnion(&node,node,createNode(19,hashMap,0),hashMap);
    
    heapUnion(&node,node,createNode(13,hashMap,0),hashMap);
    
    heapUnion(&node,node,createNode(15,hashMap,0),hashMap);
    printHeap(node);
    
    // cout<<getMin(&node)->val<<endl;

    // for(int i=0;i<99999;i++){
    //     extractMin(&node,hashMap);
    //     // printHeap(node);
    // }


    // for(int i=0;i<100;i++){
    //     int j = rand() %1000 +1;
    //     heapUnion(&node,node,createNode(j,hashMap,0),hashMap);
        
    // }
    // cout<<node->right->nodes[3]->nodes[1]->val<<endl;

    // decreaseKey(node->right->right->right->nodes[2],0);
    // printHeap(node);
    heapUnion(&node,node,createNode(115,hashMap,0),hashMap);
    // heapUnion(&node,node,createNode(125,hashMap,0),hashMap);
    // heapUnion(&node,node,createNode(915,hashMap,0),hashMap);
    printHeap(node);
    
    // cout<<node->right->nodes[2]->nodes[1]->nodes[0]->val<<endl;
    // decreaseKey(node->right->nodes[2]->nodes[1]->nodes[0],0);
    // decreaseKey(node->right->nodes[3]->nodes[0],0);
    decreaseKey(&node,node->nodes[0],0);
    printHeap(node);
    return 0;
}