#ifndef DOUBLE_LINKED_LIST_H_INCLUDED
#define DOUBLE_LINKED_LIST_H_INCLUDED

#include <iostream>
using namespace std;

template<class T>
class DLL{
    struct node{
            T item;
            node *next , *prev;
    };
    node *first,*last;
    int sz;
public:
    DLL():first(NULL),last(NULL),sz(0){}

    void addFirst(T value) {
        node* newNode = new node;
        newNode->item = value;
        if (sz == 0) {
            first = last = newNode;
            newNode->next = NULL;
            newNode->prev = NULL;
        }
        else {
            newNode->next = first;
            newNode->prev = NULL;
            first->prev = newNode;
            first = newNode;
        }
        sz++;
    }

    void addLast(T value){
        node *newNode = new node;
        newNode->item = value;
        if(sz==0){
            first=last=newNode;
            newNode->next = NULL;
            newNode->prev = NULL;
        }
        else{
            newNode->next = NULL;
            newNode->prev = last;
            last->next = newNode;
            last = newNode;
        }
        sz++;
    }

    void Insert(T value,int pos){
        if(pos<0||pos>sz){
            cout<<"Out of range !!\n";
            return;
        }
        else{
            node *newNode = new node;
            newNode->item = value;
            if(pos==0){
                addFirst(value);
            }
            else if(pos==sz){
                addLast(value);
            }
            else{
                node *curr = first;
                for(int i = 1;i < pos;i++){
                    curr = curr->next;
                }
                newNode->next = curr->next;
                newNode->prev = curr;
                curr->next->prev = newNode;
                curr->next = newNode;
                sz++;
            }
        }
    }

    void removeFirst(){
        if(sz == 0){
            cout<<"Already empty !!\n";
            return;
        }
        else if(sz == 1){
            delete first;
            last=first=NULL;
        }
        else{
            node *curr = first;
            first = first->next;
            delete curr;
            first->prev = NULL;
            sz--;
        }
    }

    void removeLast(){
        if(sz == 0){
            cout<<"Already empty !!\n";
            return;
        }
        else if(sz == 1){
            delete last;
            first=last=NULL;
            return;
        }
        else{
            node *curr = last;
            last = last->prev;
            delete curr;
            last->next = NULL;
            sz--;
        }
    }

    void removeItem(T value){
        node *curr = first;
        if(sz == 0){
            cout<<"Already empty !!\n";
            return;
        }
        else if(sz == 1&&first->item == value){
            delete first;
            last=first=NULL;
            return;
        }
        while(curr->next != NULL&&curr->item != value)curr = curr->next;
        if(curr==NULL)cout<<"Item not found !!\n";
        else if(curr->next == NULL){
            removeLast();
            return;
        }
        else{
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            sz--;
        }
    }

    void removeByPos(int pos){
        if(pos<0||pos>sz){
            cout<<"Out of range !!\n";
            return;
        }
        if(pos == 0){
            removeFirst();
            return;
        }
        else if(pos == sz){
            removeLast();
            return;
        }
        else{
            node *curr = first;
            for(int i = 0; i < pos-1; ++i){
                curr = curr->next;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            sz--;
        }
    }

    void display(){
        node *curr = first;
        while(curr!=NULL){
            cout<<curr->item<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }

    void revDisplay(){
        node *curr = last;
        while(curr!=NULL){
            cout<<curr->item<<" ";
            curr = curr->prev;
        }
        cout<<endl;
    }

    int getSize(){
        return sz;
    }

    ~DLL() {
        node* current = first;
        while (current != nullptr) {
            node* next = current->next;
            delete current;
            current = next;
        }
        first = last = nullptr;
        sz = 0;
    }



};


#endif // DOUBLE_LINKED_LIST_H_INCLUDED
