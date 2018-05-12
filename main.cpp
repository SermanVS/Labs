#include <iostream>
#include "BST.h"
using namespace std;

int main()
{
    BST bst;
    bst.insert(5);
    bst.insert(6);
    bst.insert(3);
    bst.insert(3);
    bst.insert(11);
    bst.insert(1);
    cout << bst.search(3) << endl;
    system("pause");
    return 0;
}