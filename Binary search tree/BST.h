#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <iostream>
#include <queue>
using namespace std;

template<class T>
class BST{

struct node{
    T item;
    node *left;
    node *right;

    node():right(NULL),left(NULL),item(-1){}
};

node *root;
void inorder(node *newNode){//left root right
        if(newNode == NULL)return;
        inorder(newNode->left);
        cout<<newNode->item<<" " ;
        inorder(newNode->right);
    }
void preorder(node *newNode){//root left right
        if(newNode == NULL)return;
        cout<<newNode->item<<" ";
        preorder(newNode->left);
        preorder(newNode->right);
    }
void postorder(node *newNode){//left right root
        if(newNode==NULL)return;
        postorder(newNode->left);
        postorder(newNode->right);
        cout<<newNode->item<<" ";
    }
int nodeCntHelper(node *p){
        if(p == NULL)return 0;
        else return 1+nodeCntHelper(p->left)+nodeCntHelper(p->right);
    }
int leafCntHelper(node *p){
    if(p==NULL)return 0;
    if(p->right==NULL&&p->left==NULL)return 1;
    return leafCntHelper(p->left)+leafCntHelper(p->right);
}

node *MIN(node *newNode){
        if(newNode->left==NULL)return newNode;
        MIN(newNode->left);
    }

node *MAX(node *newNode){
    if(newNode->right==NULL)return newNode;
    return (newNode->right);
}
node *delHelper(node *newNode,T element){
        if(newNode == NULL)return NULL;
        else if(element < newNode->item) newNode->left = delHelper(newNode->left,element);
        else if(element > newNode->item) newNode->right = delHelper(newNode->right,element);

        else{// node founded
            if(newNode->left == NULL && newNode->right == NULL){//Zero child
                delete newNode;
                newNode = NULL;
            }
            if(newNode->left == NULL){//One child on right
                node *tmp = newNode;
                newNode = newNode->right;
                delete tmp;

            }
            else if(newNode->right == NULL){//One child on left
                node *tmp = newNode;
                newNode = newNode->left;
                delete tmp;

            }
            else{//two children
                node *tmp = MIN(newNode->right);//Max of the left or min of the right
                newNode->item = tmp->item;
                newNode->right = delHelper(newNode->right , tmp->item);
            }
        }
        return newNode;
}

public:
    BST(){root = NULL;}

    void push (T element){

        node *curr = root;
        node *newNode = new node;
        newNode->item = element;
        newNode->left = newNode->right = NULL;

        if(root == NULL){
            root = newNode;
        }
        else{

            while(curr != NULL){
                if(curr->item >= newNode->item){
                    if(curr->left != NULL)curr = curr->left;
                    else{
                        curr->left = newNode;
                        break;
                    }
                }
                else{
                    if(curr->right != NULL)curr = curr->right;
                    else{
                        curr->right = newNode;
                        break;
                    }
                }
            }
        }
    }

    void bfs_print(){
        if(root == NULL)return;
        else{
            queue<node*> q;
            q.push(root);
            while(!q.empty()){
                node *curr = q.front();
                q.pop();
                cout<<curr->item<<" ";
                if(curr->left != NULL)q.push(curr->left);
                if(curr->right != NULL)q.push(curr->right);
            }
        }
    }


    void dfs_inorder(){
        inorder(root);
    }

    void dfs_preorder(){
        preorder(root);
    }

    void dfs_postorder(){
        postorder(root);
    }

    bool search(T element){
        node *curr = root;
        while(curr){
            if(curr->item == element)return true;
            else if(curr->item > element)curr = curr->left;
            else curr = curr->right;
        }
        return false;
    }

    void del(T item){
        delHelper(root ,item);
    }

    void nodeCnt(){// or hight of the tree
        cout<<nodeCntHelper(root);
    }

    void leafCnt(){
        cout<<leafCntHelper(root);
    }

    void maxValue(){
        if(root == NULL){
            cout<<"Tree is empty\n";
            return;
        }
        cout<<MAX(root)->item;
    }

    void minValue(){
        if(root == NULL){
            cout<<"Tree is empty\n";
            return;
        }
        cout<<MIN(root)->item;
    }











};



#endif // BST_H_INCLUDED
