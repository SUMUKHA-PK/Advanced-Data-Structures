#include<bits/stdc++.h>
#include<stdlib.h>
#include<time.h>

#include "BinomialHeap.h"
#include "BinaryHeap.h"
#include "FibHeap1.h"
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
        if(i == SOURCE) {
            node = binomialheap::createNode(0, hashMap, i);
            pointerVector.push_back(node);
            binomialheap::heapUnion(&root, root, pointerVector[i], hashMap);
        }

        else {
            node = binomialheap::createNode(INT_MAX, hashMap, i);
            pointerVector.push_back(node);
            binomialheap::heapUnion(&root, root, pointerVector[i], hashMap);
        }
    }

    // Add 1 extra node to manage.
    binomialheap::heapUnion(&root, root, binomialheap::createNode(INT_MAX, hashMap, -1), hashMap);
    binomialheap::heapUnion(&root, root, binomialheap::createNode(INT_MAX, hashMap, -2), hashMap);


    set<int> S;
    S.clear();

    cout<<"No problems till here"<<endl;

    // Till there is only 1 node.
    while(S.size() <= TotalNodeCount) {

        binomialheap::Node *U = binomialheap::getMin(&root);
        binomialheap::printHeap(root);
        cout<<endl;
        cout<<"Minimum = "<<U->val<<endl;
        // binomialheap::printHeap(root);
        binomialheap::extractMin(&root, hashMap);
        cout<<"Extracted that minimum"<<endl;
        S.insert(U->id);

        int u = U->id;

        for(int z = X[u]; z < X[u+1]; z++) {
            cout<<"\n\n\nz = "<<z<<endl;
            int  v = Y[z];
            cout<<"Neighbour v = "<<v;
            cout<<"\nNeighbour check = "<<pointerVector[v]->id<<endl;
            int w_u_v = W[z];
            cout<<", Weight = "<<w_u_v<<endl;

            if(pointerVector[v]->val > pointerVector[u]->val + w_u_v) {
                cout<<"pointer to "<<pointerVector[v]->id<<endl;
                binomialheap::decreaseKey(&root,pointerVector[v], pointerVector[u]->val + w_u_v);
                cout<<"pointer to "<<pointerVector[v]->id<<endl;

                for(int i = 0; i < TotalNodeCount; i++) {
                   cout<<"NodeId = "<<pointerVector[i]->id<<", Distance = "<<pointerVector[i]->val<<endl;
                }
            
            }
        }
    }

    cout<<"Shortest paths from source to all other nodes: "<<endl;
    for(int i = 0; i < TotalNodeCount; i++) {
        cout<<"NodeId = "<<pointerVector[i]->id<<", Distance = "<<pointerVector[i]->val<<endl;
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

void UseFibHeap(vector<int> &X, vector<int> &Y, vector<int> &W) {

    map<int, int> hashMap;
    int TotalNodeCount = X.size() - 1;

    // Array of pointers needed for fast updation of value.
    vector<fibheap1::Node*> pointerVector;
    pointerVector.reserve(TotalNodeCount);

    fibheap1::Node *root = fibheap1::createNode(INT_MAX, hashMap, -1);
    fibheap1::Node *node;

    // Creating and initializing the binomial heap
    for(int i = 0; i < TotalNodeCount; i++) {
        if(i == SOURCE) {
            node = fibheap1::createNode(0, hashMap, i);
            pointerVector.push_back(node);
            fibheap1::heapUnion(&root, root, pointerVector[i], hashMap);
        }

        else {
            node = fibheap1::createNode(INT_MAX, hashMap, i);
            pointerVector.push_back(node);
            fibheap1::heapUnion(&root, root, pointerVector[i], hashMap);
        }
    }

    // Add 1 extra node to manage.
    fibheap1::heapUnion(&root, root, fibheap1::createNode(INT_MAX, hashMap, -1), hashMap);

    set<int> S;
    S.clear();

    cout<<"No problems till here"<<endl;

    // Till there is only 1 node.
    while(S.size() <= TotalNodeCount) {

        fibheap1::Node *U = fibheap1::getMin(&root);
        fibheap1::printHeap(root);
        cout<<endl;
        cout<<"Minimum = "<<U->val<<endl;
        fibheap1::extractMin(&root, hashMap);
        cout<<"Extracted that minimum"<<endl;
        S.insert(U->id);

        int u = U->id;

        for(int z = X[u]; z < X[u+1]; z++) {
            cout<<"\n\n\nz = "<<z<<endl;
            int  v = Y[z];
            cout<<"Neighbour v = "<<v;
            cout<<"\nNeighbour check = "<<pointerVector[v]->id<<endl;
            int w_u_v = W[z];
            cout<<", Weight = "<<w_u_v<<endl;

            if(pointerVector[v]->val > pointerVector[u]->val + w_u_v) {
                cout<<"pointer to "<<pointerVector[v]->id<<endl;
                fibheap1::decreaseKey(pointerVector[v], pointerVector[u]->val + w_u_v);
                cout<<"pointer to "<<pointerVector[v]->id<<endl;

                for(int i = 0; i < TotalNodeCount; i++) {
                   cout<<"NodeId = "<<pointerVector[i]->id<<", Distance = "<<pointerVector[i]->val<<endl;
                }
            
            }
        }
    }

    cout<<"Shortest paths from source to all other nodes: "<<endl;
    for(int i = 0; i < TotalNodeCount; i++) {
        cout<<"NodeId = "<<pointerVector[i]->id<<", Distance = "<<pointerVector[i]->val<<endl;
    }
   
}


int main(int argc, char **argv) {

    if(argc != 3) {
        cout<<"Usage: $ "<<argv[0]<<" <HeapType> <InputType>"<<endl;
        cout<<"--> Types of heap available: "<<endl;
        cout<<"1. binary"<<endl;
        cout<<"2. binomial"<<endl;
        cout<<"3. fibonacci"<<endl;
        cout<<"--> Input Size: "<<endl;
        cout<<"1. small"<<endl;
        cout<<"2. large"<<endl;

        return -1;
    }

    string HeapType(argv[1]);
    cout<<HeapType<<endl;

    if (HeapType != "binary" && HeapType != "binomial" && HeapType != "fibonacci") {
        cout<<"Error: Invalid Heap type"<<endl;
        return -1;
    }

    string InputSize(argv[2]);
    if(InputSize != "small" && InputSize != "large") {
        cout<<"Invalid Input Type<<"<<endl;
        return -1;
    }


    // For now, I will be using adjacency matrix. 
    // Later, will shift to CSR - for huge number of nodes.

    unsigned long TotalNodeCount;
    cout<<"Enter total number of nodes: "<<endl;
    cin>>TotalNodeCount;

   int Graph[TotalNodeCount][TotalNodeCount];

    // If small, ask for user input
    if(InputSize == "small") {

        for(unsigned i = 0; i < TotalNodeCount; i++) {
            for(unsigned j = i + 1; j < TotalNodeCount; j++) {
                Graph[i][j] = 0;

                cout<<"Weight of edge ("<<i<<", "<<j<<") : ";
                cin>>Graph[i][j];
                if(Graph[i][j] < 0) {
                    cout<<"Non-negative weights only"<<endl;
                    return -1;
                }
                Graph[j][i] = Graph[i][j];
            }

            // No self-loops
            Graph[i][i] = 0;
        }
    }
    // If large, generate the graph
    else if(InputSize == "large") {
        srand(time(NULL));
        
        for(unsigned i = 0; i < TotalNodeCount; i++) {
            for(unsigned j = i + 1; j < TotalNodeCount; j++) {
                unsigned w = (unsigned)(rand() % 10);
                Graph[i][j] = w;
                Graph[j][i] = Graph[i][j];
            }
            
        // No self-loops
        Graph[i][i] = 0;  
        
        }
    }
    
    // Convert Adjacency Matrix to CSR Form
    // Dijkstra works on CSR

    // CSR Form
    vector<int> X;      
    vector<int> Y;  
    vector<int> W;
    unsigned EdgeCount = 0;

    // Initialization
    X.push_back(0);

    for(unsigned i = 0; i < TotalNodeCount; i++) {

        for(unsigned j = 0; j < TotalNodeCount; j++) {
            if(Graph[i][j] != 0) {
                EdgeCount++;
                Y.push_back(j);
                W.push_back(Graph[i][j]);
            }
        }
        X.push_back(EdgeCount);
    }

    cout<<"X: ";
    for(unsigned i = 0; i < X.size(); i++) {
        cout<<X[i]<<" ";
    }
    cout<<endl;
    
    cout<<"Y: ";
    for(unsigned i = 0; i < Y.size(); i++) {
        cout<<Y[i]<<" ";
    }
    cout<<endl;

    cout<<"W: ";
    for(unsigned i = 0; i < W.size(); i++) {
        cout<<W[i]<<" ";
    }
    cout<<endl;


    if(HeapType == "binomial")
        UseBinomialHeap(X, Y, W);
    
    else if(HeapType == "binary")
        UseBinaryHeap(X, Y, W);
    
    else if(HeapType == "fibonacci")    
        UseFibHeap(X, Y, W);

    // UseBinomialHeap(w, TotalNodeCount);

   


    // Initialize distance from source (1) to all other vertices.


    return 0;
}

