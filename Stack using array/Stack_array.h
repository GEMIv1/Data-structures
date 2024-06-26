#ifndef STACK_ARRAY_H_INCLUDED
#define STACK_ARRAY_H_INCLUDED


#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int maxSize=100;

template<class T>
class Stack{
    int top;
    T arr[maxSize];
public:

    Stack():top(-1){}

    bool isEmpty(){
        return top<0;
    }

    void push(T value){
        if(top==maxSize)cout<<"Stack overflow\n";
        else {
            top++;
            arr[top]=value;
        }
    }

    void pop(){
        if(isEmpty())cout<<"Stack is empty\n";
        else{
            top--;
        }
    }

    T getTop(){
        return arr[top];
    }

};

int calculation(int op1, int op2, char ch) {
    if (ch == '+') return op1 + op2;
    else if (ch == '-') return op1 - op2;
    else if (ch == '*') return op1 * op2;
    else if (ch == '/') return op1 / op2;
    else return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool isOperand(char ch) {
    return isdigit(ch);
}

#endif // STACK_ARRAY_H_INCLUDED
