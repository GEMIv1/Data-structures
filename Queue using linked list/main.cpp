#include "QUEUE.h"

int main(){

    Queue<int> q;
    q.Insert(1);
    q.Insert(2);
    q.Insert(3);
    q.Insert(4);
    q.Insert(5);
    q.Insert(6);
    q.display();
    cout<<endl;
    q.pop();
    q.display();
    cout<<endl;
    cout<<"Size after pop(): ";cout<<q.getSize()<<endl;
    cout<<"Front element: "<<q.getFront()<<endl;
    cout<<"Back element: "<<q.getBack()<<endl;

    q.Clear();
    q.pop();
    cout<<"Size after clearing the queue: "<<q.getSize();



    return 0;
}
