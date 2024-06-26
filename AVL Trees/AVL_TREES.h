#ifndef AVL_TREES_H_INCLUDED
#define AVL_TREES_H_INCLUDED
#include<iostream>
#include <queue>
using namespace std;

template<class T>
class AVL_TREE{
    struct node{
        T value;
        node *left;
        node *right;
    };
    node *root;

int height(node *ptr){
    if(ptr==NULL)return 0;
    int leftPart = height((ptr->left));
    int rightPart = height((ptr->right));
    return 1+max(leftPart,rightPart);
}
int balance_factor(node *ptr){
        return height(ptr->left)-height(ptr->right);
}
node *rightRotation(node *ptr){//30
    node *ptr2 = ptr->left;//20
    node *ptr3 = ptr2->right;//if there is any node on the right of the node the will become the parent

    ptr2->right = ptr;
    ptr->left = ptr3;

    return  ptr2;
}

node *leftRotation(node *ptr){//10
    node *ptr2 = ptr->left;
    node *ptr3 = ptr2->left;

    ptr2->right = ptr;
    ptr->right = ptr3;

    return ptr2;
}

node *pushHelper(node *ptr, node* curr){
    if(ptr==NULL){
        ptr = curr;
        return ptr;
    }
    if(curr->value > ptr->value)ptr->right = pushHelper(ptr->right , curr);
    else if(curr->value < ptr->value)ptr->left = pushHelper(ptr->left , curr);
    int bf = balance_factor(ptr);
    if(bf>1 && curr->value < ptr->left->value){// left imbalance ---> RR rotation
       return rightRotation(ptr);
    }
    else if(bf<-1 && curr->value > ptr->right->value){// right imbalance ---> LL rotation
        return leftRotation(ptr);
    }
    else if(bf>1 && curr->value > ptr->left->value){// LR rotation
        ptr->left = leftRotation(ptr->left);
        return rightRotation(ptr);
    }
    else if(bf<-1 && curr->value < ptr->right->value){ //RL rotation
        ptr->right = rightRotation(ptr->right);
        return leftRotation(ptr);
    }
    return ptr;

}
node *minValue(node* curr){
    //if(curr==NULL)return  NULL;
    if(curr->left==NULL)return curr;
    minValue(curr->left);
}
node* popHelper(node* curr, T item){
    if(curr==NULL)return NULL;
    if(curr->value > item)curr->left = popHelper(curr->left,item);
    else if(curr->value < item)curr->right = popHelper(curr->right,item);
    else{
        if(curr->left == NULL && curr->right == NULL){//child
            node *tmp = curr;
            delete curr;
            return NULL;
        }
        else if(curr->left == NULL || curr->right == NULL){//one child on the left or the right
            node *tmp = (curr->left == NULL) ? curr->right : curr->left;
            delete curr;
            return tmp;
        }
        else{//Two children
            node *tmp = minValue(curr->right);
            curr->value = tmp->value;
            curr->right = popHelper(curr->right,tmp->value);
        }
    }
    int bf = balance_factor(curr);
    if(bf>1 && curr->value < curr->left->value){// left imbalance ---> RR rotation
        return rightRotation(curr);
    }
    else if(bf<-1 && curr->value > curr->right->value){// right imbalance ---> LL rotation
        return leftRotation(curr);
    }
    else if(bf>1 && curr->value > curr->left->value){// LR rotation
        curr->left = leftRotation(curr->left);
        return rightRotation(curr);
    }
    else if(bf<-1 && curr->value < curr->right->value){ //RL rotation
        curr->right = rightRotation(curr->right);
        return leftRotation(curr);
    }
    return curr;
}
public:
    AVL_TREE():root(NULL){}
    void push(T element){
        node *newNode = new node;
        newNode->value = element;
        newNode->left = newNode->right = NULL;
        if(root==NULL){
            root = newNode;
        }
        else{
            root = pushHelper(root,newNode);
        }
    }

    bool search(T element)
    {
        node* curr = root;
        while (curr!=NULL)
        {
            if(curr->value==element)return true;
            if(curr->value > element)curr=curr->left;
            if(curr->value < element)curr=curr->right;
        }
        return false;

    }

    void pop(T item){
        if(root == NULL){
            cout<<"Tree is already empty!!\n";
            return;
        }
        else{
            if(search(item))root = popHelper(root,item);
            else
            {
                cout<<"Item not found!!\n";
            }

        }
    }


    void print(){ // BFS printing
        if(root == NULL)
        {
            cout<<"Empty tree!\n";
            return;
        }
        else
        {
            queue<node*> q;
            q.push(root);
            while(!q.empty())
            {
                node *curr = q.front();
                q.pop();
                cout<<curr->value<<" ";
                if(curr->left != NULL)q.push(curr->left);
                if(curr->right != NULL)q.push(curr->right);
            }

        }

    }


};


#endif // AVL_TREES_H_INCLUDED
