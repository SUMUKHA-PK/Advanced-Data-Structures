#include<bits/stdc++.h>
#include<stdlib.h>

#include "BinomialHeap.h"
#include "BinaryHeap.h"
// #include "FibHeap.h"
using namespace std;

// source node
const unsigned SOURCE = 0;

void UseBinomialHeap(vector<int> X, vector<int> Y, vector<int> W) {
    
    map<int, int> hashMap;
    int TotalNodeCount = X.size() - 1;

    // Array of pointers needed for fast updation of value.
    vector<binomialheap::Node*> pointerVector;
    pointerVector.reserve(TotalNodeCount);

    binomialheap::Node *root = binomialheap::createNode(INT_MAX, hashMap, -1);
    binomialheap::Node *node;

    // Creating and initializing the binomial heap
    for(int i = 0; i < TotalNodeCount; i++) {
        pointerVector[i] = binomialheap::createNode(0, hashMap, i);
        if(i == SOURCE) 
            binomialheap::heapUnion(&root, root, pointerVector[i], hashMap);
    
        else    
            binomialheap::heapUnion(&root, root, pointerVector[i], hashMap);
    }
}

void UseBinaryHeap(vector<int> &X, vector<int> &Y, vector<int> &W) {

    vector<binaryheap::Node*> heap;
    vector<binaryheap::Node*> ptrVector;
    int TotalNodeCount = X.size()-1;

    for(int i = 0; i < TotalNodeCount; i++) {
        binaryheap::Node* temp = new binaryheap::Node;
        temp->id = i;
        if(i == SOURCE)
            temp->val = 0;
        else
            temp->val = std::numeric_limits<int>::max();
        
        heap.push_back(temp);
        ptrVector.push_back(temp);
    }

    binaryheap::buildMinHeap(heap);

    set<int> S;
    S.clear();

    while(heap.size() != 0) {
        binaryheap::Node *U = binaryheap::getMin(heap);
        binaryheap::extractMin(heap);
        S.insert(U->id);
        
        int u = U->id;
        
        for(int z = X[u]; z < X[u+1]; z++) {

            cout<<z<<" ";
            int v = Y[z];
            int w_u_v = W[z];

            if(ptrVector[v]->val > ptrVector[u]->val + w_u_v) {
                
                // Make changes in the required node
                ptrVector[v]->val = ptrVector[u]->val + w_u_v;
                

                // Heap property might be violated because of the above change. 
                // build heap again!
                binaryheap::buildMinHeap(heap);
            }
        }

        cout<<endl;
    }

    cout<<"Shortest paths from source to all other nodes: "<<endl;
    for(int i = 0; i < TotalNodeCount; i++) {
        cout<<"NodeId = "<<ptrVector[i]->id<<", Distance = "<<ptrVector[i]->val<<endl;
    }

}


int main(int argc, char **argv) {

    if(argc != 2) {
        cout<<"Usage: $ "<<argv[0]<<" <HeapType> "<<endl;
        cout<<"Types of heap available: "<<endl;
        cout<<"1. binary"<<endl;
        cout<<"2. binomial"<<endl;
        cout<<"3. fibonacci"<<endl;
        
        return -1;
    }

    string HeapType(argv[1]);
    cout<<HeapType<<endl;

    if (HeapType != "binary" && HeapType != "binomial" && HeapType != "fibonacci") {
        cout<<"Error: Invalid Heap type"<<endl;
        return -1;
    }

    

    // For now, I will be using adjacency matrix. 
    // Later, will shift to CSR - for huge number of nodes.

    unsigned long TotalNodeCount;
    cout<<"Enter total number of nodes: "<<endl;
    cin>>TotalNodeCount;

    // CSR Form
    vector<int> X;      
    vector<int> Y;  
    vector<int> W;
    int temp;
    vector<int>::iterator iter;

    // If there are n nodes, X has (n+1) elements
    for(int i = 0; i <= TotalNodeCount; i++) {
        cin>>temp;
        X.push_back(temp);
    }

    while(scanf("%d", &temp) == 1) {
        Y.push_back(temp);
    }

    int Ylen = Y.size();
    vector<int> tempv;

    for(int i = 0; i < Ylen/2; i++) {
        temp = Y[Y.size() - 1];
        Y.pop_back();
        tempv.push_back(temp);
    }

    for(int i = 1; i < Ylen/2; i++) {
        temp = tempv[tempv.size() - 1];
        tempv.pop_back();
        W.push_back(temp);
    }


    if(HeapType == "binomial")
        UseBinomialHeap(X, Y, W);
    
    else if(HeapType == "binary")
        UseBinaryHeap(X, Y, W);
    
    // else if(HeapType == "fibonacci")    
    //     UseBinomialHeap(w, TotalNodeCount);

    // UseBinomialHeap(w, TotalNodeCount);

   


    // Initialize distance from source (1) to all other vertices.


    return 0;
}

