//Authored: ADWAIT , 2019

#include<bits/stdc++.h>
using namespace std;

namespace binaryheap {

    struct node {
        long int val;
        long int id;
    };

    typedef node Node;


int left(int i) {
    return 2 * i +1;
}

int right(int i) {
    return 2 * i + 2;
}

int parent(int i) {
    return (i - 1) / 2;
}

void bubbleUp(int i, vector<Node*>&A) {

    if(i == 0)
        return;
    
    int parent = (i-1)/2;

    if(A[parent]->val > A[i]->val) {
        Node* temp = A[parent];
        A[parent] = A[i];
        A[i] = temp;
        bubbleUp(parent, A);
    }
}

void bubbleDown(int i, vector<Node*>&A) {

    int len = A.size();
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // If 'i' is a leaf
    if(l >= len)
        return;

    int min = i;

    if(A[i]->val > A[l]->val)
        min = l;
    
    if(r < len && A[min]->val > A[r]->val)
        min = r;
    
    if(min != i) {
        Node* temp = A[i];
        A[i] = A[min];
        A[min] = temp;
        bubbleDown(min, A);
    }
}

void buildMinHeap(vector<Node*>&A) {
    int len = A.size();
    for(int i = len; i >= 0; i--)
        bubbleDown(i, A);
}


Node* getMin(vector<Node*>&A) {
    return A[0];
}

void extractMin(vector<Node*>&A) {

    if(A.size() == 0)
        return;

    A[0] = A[A.size()-1];
    A.pop_back();
    bubbleDown(0, A);
}


}   // namespace binaryheap end.