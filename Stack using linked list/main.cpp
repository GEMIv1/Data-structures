#include "Stack_linkedList.h"

int main(){


    Stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.display();
    stk.pop();
    stk.display();
    cout<<stk.top();



}

