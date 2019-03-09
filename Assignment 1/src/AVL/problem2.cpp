#include<bits/stdc++.h>

#include "Avl.h"
#include "problem2.h"
#include "problem1.h"

using namespace avltree;

int main(int argc, char **argv) {

    Node *root = populateTree(NULL, 1);
    int k;

    std::cout<<"\n\nThis is the tree: \n"<<std::endl;
    displayTree(root);

    Node *root1, *root2;

    std::cout<<"\n\nEnter the value of k: "<<std::endl;
    std::cin>>k;
    std::cout<<"k = "<<k<<std::endl;

    // root and k are the actual arguments. 
    // root1 and root2 are roots of the 2 new trees
    bool value;
    split(root, k, &root1, &value, &root2);

    std::cout<<"\n\nTree1: \n"<<std::endl;
    displayTree(root1);

    std::cout<<"\n\nTree2: \n"<<std::endl;
    displayTree(root2);
    
    return 0;
}