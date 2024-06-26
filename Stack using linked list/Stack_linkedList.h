#ifndef STACK_LINKEDLIST_H_INCLUDED
#define STACK_LINKEDLIST_H_INCLUDED

#include <iostream>
using namespace std;


template<class T>
class Stack{
    struct node{
    T data;
    node *next;};
    node *Top;
public:

    Stack():Top(NULL){}

    void push(T value){
        node *newNode = new node;
        newNode->data = value;
        newNode->next = Top;
        Top = newNode;

    }

    bool isEmpty(){
        return Top==NULL;
    }

    void pop(){
        if(isEmpty())cout<<"Stack is already empty\n";
        else{
            node *newNode = Top;
            Top = Top->next;
            newNode->next = NULL;
            delete newNode;
        }
    }

    T top(){
        return Top->data;
    }

    void display(){
        node *newNode = Top;
        while(newNode!=NULL){
            cout<<newNode->data<<" ";
            newNode = newNode->next;
        }
        cout<<endl;
    }


};



#endif // STACK_LINKEDLIST_H_INCLUDED
