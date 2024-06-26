#include "Queue.h"

int main(){

    Queue<int> q;
    q.Insert(10);
    q.Insert(20);
    q.Insert(30);
    q.Insert(40);
    q.Insert(50);
    q.Insert(60);
    q.dispay();
    cout<<endl;
    q.pop();
    q.dispay();
    cout<<endl<<q.getFront()<<endl;
    cout<<q.getBack();


}
