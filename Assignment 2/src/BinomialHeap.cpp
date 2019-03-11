#include<bits/stdc++.h>
#include"BinomialHeap.h"
using namespace binomialheap;

int main(){
    map<int,int> hashMap;

    Node* node= createNode(10,hashMap);
    //Look into the problem of returning nodes

    heapUnion(&node,node,createNode(20,hashMap),hashMap);
    printHeap(node);

    heapUnion(&node,node,createNode(2,hashMap),hashMap);
    printHeap(node);

    heapUnion(&node,node,createNode(11,hashMap),hashMap);
    printHeap(node);
    
    heapUnion(&node,node,createNode(1,hashMap),hashMap);
    printHeap(node);

    heapUnion(&node,node,createNode(3,hashMap),hashMap);
    printHeap(node);

    heapUnion(&node,node,createNode(5,hashMap),hashMap);
    printHeap(node);

    heapUnion(&node,node,createNode(7,hashMap),hashMap);
    printHeap(node);

    heapUnion(&node,node,createNode(4,hashMap),hashMap);
    printHeap(node);
    
    heapUnion(&node,node,createNode(6,hashMap),hashMap);
    printHeap(node);
    
    heapUnion(&node,node,createNode(8,hashMap),hashMap);
    printHeap(node);
    
    heapUnion(&node,node,createNode(9,hashMap),hashMap);
    printHeap(node);

    heapUnion(&node,node,createNode(12,hashMap),hashMap);
    printHeap(node);
    
    heapUnion(&node,node,createNode(19,hashMap),hashMap);
    printHeap(node);
    
    heapUnion(&node,node,createNode(13,hashMap),hashMap);
    printHeap(node);
    
    heapUnion(&node,node,createNode(15,hashMap),hashMap);
    printHeap(node);
    
    
    return 0;
}