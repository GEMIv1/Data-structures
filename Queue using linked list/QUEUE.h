#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include<iostream>
#include<cassert>
using namespace std;

template<class T>
class Queue{
private:

    struct node{
        T value;
        node *next;

    };
    int length=0;
    node *Front,*Back;

public:

    Queue():Front(NULL),Back(NULL),length(0){}
    Queue(int l):Front(NULL),Back(NULL),length(l){}

    void Insert(T element){

        node *newNode = new node;
        newNode->value=element;
        newNode->next = NULL;
        if(length==0){
            Front=Back=newNode;
        }
        Back->next = newNode;
        Back = newNode;
        length++;
    }

    bool isEmpty(){return Front==NULL;}// or length==0


    void pop(){
        if(isEmpty())cout<<"Queue is already empty \n";
        else if(length==1){
            delete Front;
            Back = NULL;
            length--;
        }
        node *newNode = Front;
        Front=Front->next;
        delete newNode;
        length--;

    }

    void display(){

        node *newNode = Front;

        while(newNode!=Back){
            cout<<newNode->value<<" ";
            newNode = newNode->next;
        }
        cout<<newNode->value;
        cout<<endl;

    }

    T getFront(){
        return Front->value;
    }

    T getBack(){
        return Back->value;
    }

    void Clear(){

        node *newNode = new node;

        while(Front!=NULL){
            newNode = Front;
            Front = Front->next;
            delete newNode;
        }
        Back = NULL;
        length = 0;
    }

    int getSize(){
        return length;
    }

};


#endif // QUEUE_H_INCLUDED
