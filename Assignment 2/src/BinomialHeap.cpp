#include<bits/stdc++.h>
#include"BinomialHeap.h"
using namespace binomialheap;

int main(){
    Node* node= createNode(10);

    Node* node1 = createNode(1);
    node->nodes.push_back(node1);
    node1->parent=node;

    Node* node11 = createNode(11);
    node1->nodes.push_back(node11);
    node11->parent = node1;

    Node* node12 = createNode(12);
    node1->nodes.push_back(node12);
    node12->parent = node1;

    Node* node13 = createNode(13);
    node1->nodes.push_back(node13);
    node13->parent = node1;

    Node* node2 = createNode(2);
    node->nodes.push_back(node2);
    node2->parent=node;

    Node* node21 = createNode(21);
    node2->nodes.push_back(node21);
    node21->parent=node2;

    Node* node211 = createNode(211);
    node21->nodes.push_back(node211);
    node211->parent=node21;

    Node* node212 = createNode(212);
    node21->nodes.push_back(node212);
    node212->parent=node21;

    Node* node213 = createNode(213);
    node21->nodes.push_back(node213);
    node213->parent=node21;

    Node* node22 = createNode(22);
    node2->nodes.push_back(node22);
    node22->parent=node2;

    Node* node23 = createNode(23);
    node2->nodes.push_back(node23);
    node23->parent=node2;

    Node* node3 = createNode(3);
    node->nodes.push_back(node3);
    node3->parent=node;

    Node* node31 = createNode(31);
    node3->nodes.push_back(node31);
    node31->parent=node3;

    Node* node32 = createNode(32);
    node3->nodes.push_back(node32);
    node32->parent=node3;

    Node* node33 = createNode(33);
    node3->nodes.push_back(node33);
    node33->parent=node3;

    Node* node4 = createNode(4);
    node->nodes.push_back(node4);
    node4->parent=node;

    Node* node5 = createNode(5);
    node->nodes.push_back(node5);
    node5->parent=node;

    printHeap(node);
    return 0;
}