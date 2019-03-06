#include<bits/stdc++.h>

#include "Avl.h"
#include "problem1.h"


using namespace avltree;

int main(int argc, char **argv) {

    Node* root1 = populateTree(NULL, 1);
    Node* root2 = populateTree(NULL, 2);

    std::cout<<"\nMerging trees."<<std::endl;

    Node *root = mergeTrees(root1, root2);

    std::cout<<"New merged tree: "<<std::endl;
    displayTree(root);

    return 0;
}













