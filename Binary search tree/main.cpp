#include"BST.h"

int main(){
    BST<int> tree;
    tree.push(5);
    tree.push(10);
    tree.push(3);
    tree.push(4);
    tree.push(1);
    tree.push(11);

    cout<<"Print using BFS technique : ";
    tree.bfs_print();
    cout<<endl;
    cout<<"Print using inorder DFS technique : ";
    tree.dfs_inorder();
    cout<<endl;
    cout<<"Print using postorder DFS technique : ";
    tree.dfs_postorder();
    cout<<endl;
    cout<<"Print using preorder DFS technique : ";
    tree.dfs_preorder();
    cout<<endl;
    int number;
    cout<<"Search for item : ";
    cin>>number;
    if(tree.search(number)){
        cout<<"Number exist.\n";
    }
    else{
        cout<<"Number dose not exist.\n";
    }
    cout<<"Tree after deletion of 5 : ";tree.del(5);tree.bfs_print();
    cout<<"\nNode count  : ";tree.nodeCnt();
    cout<<"\nLeaf count : ";tree.leafCnt();
    cout<<"\nMax value : ";tree.maxValue();
    cout<<"\nMin value : ";tree.minValue();

    return 0;
}
