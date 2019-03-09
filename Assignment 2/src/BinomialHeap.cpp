#include<bits/stdc++.h>
#include"BinomialHeap.h"
using namespace binomialheap;

int main(){
    map<int,int> hashMap;

    Node* node= createNode(10,hashMap);
    //Look into the problem of returning nodes

    node = heapUnion(&node,node,createNode(20,hashMap),hashMap);
    printHeap(node);

    node = heapUnion(&node,node,createNode(2,hashMap),hashMap);
    printHeap(node);

    node = heapUnion(&node,node,createNode(11,hashMap),hashMap);
    printHeap(node);
    
    node = heapUnion(&node,node,createNode(1,hashMap),hashMap);
    printHeap(node);

    node = heapUnion(&node,node,createNode(3,hashMap),hashMap);
    printHeap(node);

    node = heapUnion(&node,node,createNode(5,hashMap),hashMap);
    printHeap(node);

    node = heapUnion(&node,node,createNode(7,hashMap),hashMap);
    printHeap(node);

    return 0;
}