#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
#include <cassert>
using namespace std;

template<class T>
class Queue{

    int Front;
    int Back;
    int sz;
    int len;
    T *arr;

public:

    Queue(){
        len = 0;
        sz = 1000;
        Front = 0;
        Back = sz - 1;
        arr = new T [sz];
    }
    Queue(int sizee){
        if(sizee<=0){
            sz=1000;
            len = 0;
            Front = 0;
            Back = sz - 1;
            arr = new T [sz];
        }
        else{
            sz=sizee;
            Front = 0;
            Back = sz - 1;
            arr = new T [sz];
        }
    }

    bool isFull(){
        return len == sz;
    }

    bool isEmpty(){
        return len==0;
    }

    void Insert(T element){
        if(isFull()){
            cout<<"The Queue is already full ";
        }
        else{
            Back = (Back+1)%sz;
            arr[Back] = element;
            len++;
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"The Queue is already empty ";
        }
        else{
            Front = (Front+1)%sz;
            len--;
        }
    }

    void dispay(){
        for(int i=Front;i!=Back+1;i=(1+i)%sz){
            cout<<arr[i]<<" ";
        }
    }

    T getFront(){
        assert(!isEmpty());
        return arr[Front];
    }

    T getBack(){
        assert(!isEmpty());
        return arr[Back];
    }

    ~Queue(){
        delete []arr;
    }

};


#endif // QUEUE_H_INCLUDED
