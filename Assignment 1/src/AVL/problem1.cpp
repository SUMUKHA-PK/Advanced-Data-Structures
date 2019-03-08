 #include<bits/stdc++.h>

#include "Avl.h"
#include "problem1.h"


using namespace avltree;

int main(int argc, char **argv) {

    Node* root1 = NULL;
    root1 = populateTree(NULL, 1);

    Node* root2 = NULL;
    root2 = populateTree(NULL, 2);

    std::cout<<"Tree-1: "<<std::endl;
    if(root1 != NULL)
        displayTree(root1);
    else
        std::cout<<"No T1 exists"<<std::endl;

    std::cout<<"\n"<<std::endl;

    std::cout<<"Tree-2: "<<std::endl;
    if(root2 != NULL)
        displayTree(root2);
    else
        std::cout<<"No T2 exists"<<std::endl;
    
    std::cout<<"\n"<<std::endl;

    std::cout<<"Merging trees...."<<std::endl;

    Node *root = mergeTrees(root1, root2);

    std::cout<<"Final merged tree: "<<std::endl;
    if(root != NULL)
        displayTree(root);
    else {
        std::cout<<"No tree exists because there were no T1 and T2"<<std::endl;
        return 0;
    }

    
    std::cout<<"\n"<<std::endl;
    std::cout<<"Inorder: "<<std::endl;
    inorder(root);

    return 0;
}













