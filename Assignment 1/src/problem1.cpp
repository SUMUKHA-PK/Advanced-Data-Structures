#include<bits/stdc++.h>

#include "Avl.h"
#include "problem1.h"


using namespace avltree;

int main(int argc, char **argv) {

    Node* root1 = new Node;
    Node* root2 = new Node;

    populateTree(root1, 1);
    populateTree(root2, 2);

    std::cout<<"Tree-1: "<<std::endl;
    displayTree(root1);

    std::cout<<"Tree-2: "<<std::endl;
    displayTree(root2);

    std::cout<<"\nMerging trees."<<std::endl;

    Node *root = mergeTrees(root1, root2);

    std::cout<<"New merged tree: "<<std::endl;
    displayTree(root);

    return 0;
}













