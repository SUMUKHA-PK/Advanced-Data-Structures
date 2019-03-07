#include<bits/stdc++.h>

#include "Avl.h"
#include "problem1.h"


using namespace avltree;

int main(int argc, char **argv) {

    Node* root1 = populateTree(NULL, 1);
    Node* root2 = populateTree(NULL, 2);

    std::cout<<"\n\nTree-1: \n"<<std::endl;
    displayTree(root1);

    std::cout<<"\n\nTree-2: \n"<<std::endl;
    displayTree(root2);

    std::cout<<"\n\nMerging trees...."<<std::endl;

    Node *root = mergeTrees(root1, root2);

    std::cout<<"\n\nNew merged tree: \n"<<std::endl;
    displayTree(root);

    std::cout<<"\n\n"<<std::endl;

    return 0;
}













