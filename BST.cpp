#include <iostream>
#include "BST.h"
using namespace std;

BST::BST()
{
    mRoot = nullptr;
}
BST::~BST()
{
    clear();
}
BST::Node* BST::insertNode(Node* root, int val)
{
    if (root == nullptr)
    {
        root = new Node;
        root->value  = val;
        root->count = 1;
        root->left = nullptr;
        root->right = nullptr;
    }
    else if (val < root->value) root->left = insertNode(root->left, val);
    else if (val > root->value) root->right = insertNode(root->right, val);
    else root->count++;
    return root;
}
void BST::insert(int val)
{
    mRoot = insertNode(mRoot, val);
}
int BST::searchNode(Node* root, int val)
{
    if (root == nullptr) return 0;
    else if (val < root->value)
        return searchNode(root->left, val);
    else if (val > root->value)
        return searchNode(root->right, val);
    else return root->count;
}
int BST::search(int val)
{
    return searchNode(mRoot, val);
}
void BST::printNode(Node* root)
{
    if (root != nullptr)
    {
        printNode(root->left);
        for (int i = 0; i < root->count; i++)
        {
            cout << root->value << " ";
        }
        printNode(root->right);
    }
}
void BST::print()
{
    printNode(mRoot);
    cout << endl;
}
BST::Node* BST::delTree(Node* root)
{
    if (root == nullptr) return root;
    else
    {
        root->left = delTree(root->left);
        root->right = delTree(root->right);
        delete root;
    }
    return nullptr;
}
void BST::clear()
{
    delTree(mRoot);
}