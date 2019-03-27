#include<bits/stdc++.h>
#include "BinaryHeap.h"
using namespace binaryheap;

int main() {

    std::vector<Node*> heap;
    heap.reserve(100);
    
    int TotalNodeCount;
    cin>>TotalNodeCount;

    for(int i = 0; i < TotalNodeCount; i++) {
        Node* temp = new Node;
        temp->id = i;
        heap.push_back(temp);
    }

    std::cout<<"sizeof heap = "<<heap.size()<<std::endl;

    // Input the nodes in any order
    for(int i = 0; i < TotalNodeCount; i++)
        std::cin>>heap[i]->val;
    
    for(int i =0; i < TotalNodeCount; i++)
        std::cout<<heap[i]->val<<" ";

    std::cout<<"Before buildMinHeap"<<std::endl;
    buildMinHeap(heap);
    std::cout<<"After buildMinHeap"<<std::endl;

    std::cout<<std::endl;

    for(int i = 0; i < TotalNodeCount; i++)
        std::cout<<heap[i]->val<<" ";

    std::cout<<"min = "<<getMin(heap)->val<<std::endl;

    extractMin(heap);

    for(int i = 0; i < heap.size(); i++)
        std::cout<<heap[i]->val<<" ";


    return 0;
}