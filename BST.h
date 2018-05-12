#ifndef BST_BST_H
#define BST_BST_H

#endif //BST_BST_H
#include <iostream>
using namespace std;

class BST
{
    struct Node
    {
        int value;
        int count;
        Node* left;
        Node* right;
    };
    Node* mRoot;
    Node* insertNode(Node*, int);
    int searchNode(Node*, int);
    void printNode(Node*);
    Node* delTree(Node*);
public:
    BST();
    ~BST();
    void insert(int);
    int search(int);
    void print();
    void clear();
};