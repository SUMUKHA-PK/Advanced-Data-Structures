#include<bits/stdc++.h>
#include"FibHeap.h"

using namespace fibheap;

int main() {

    H = InitializeHeap();
    
    int TotalNodeCount = 100;
    for(int i = 0; i < TotalNodeCount; i++) {
        node *temp = Create_node(i, i);
        H = Insert(H, temp);
        Display(H);
    }

    return 0;
}