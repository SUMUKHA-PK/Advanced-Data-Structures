 #include<bits/stdc++.h>

#include "Avl.h"
#include "problem1.h"


using namespace avltree;

int main(int argc, char **argv) {

    Node* root1 = populateTree(NULL, 1);
    Node* root2 = populateTree(NULL, 2);

    std::cout<<"Tree-1: "<<std::endl;
    displayTree(root1);
    std::cout<<"\n"<<std::endl;

    std::cout<<"Tree-2: "<<std::endl;
    displayTree(root2);
    std::cout<<"\n"<<std::endl;

    std::cout<<"Merging trees...."<<std::endl;

    Node *root = mergeTrees(root1, root2);

    std::cout<<"Final merged tree: "<<std::endl;
    displayTree(root);
    std::cout<<"\n"<<std::endl;
    std::cout<<"Inorder: "<<std::endl;
    inorder(root);

    return 0;
}













