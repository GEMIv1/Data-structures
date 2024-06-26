#include "AVL_TREES.h"

int main(){

    AVL_TREE<int> tree;

    tree.push(12);
    tree.push(8);
    tree.push(18);
    tree.push(11);
    tree.push(17);
    tree.push(5);
    tree.push(4);
    tree.push(7);
    tree.push(2);
    cout<<"Balanced tree : ";tree.print();cout<<"\n";
    cout<<"Balanced tree after deleting 2: ";tree.pop(2);tree.print();

    return 0;
}