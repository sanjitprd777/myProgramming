// Queues are a type of container adaptors which operate in a first in first out (FIFO) type of arrangement.
// Elements are inserted at the back (end) and are deleted from the front.
#include <bits/stdc++.h>
#include <list>
using namespace std;
void showqueue(queue <int> t){
    while(!t.empty()){
        cout<<t.front()<<" ";  // in stack we use t.top();
        //after extracting an element we must pop that element to access next element
        t.pop();
    }
    cout<<endl;
}
int main(){
    queue <int> q;
    int i;
    for(i=0;i<10;++i)
        q.push(i);
    cout<<"ELEMENTS IN THE QUEUE ARE : "<<endl;
    showqueue(q);

    cout<<"Front element : "<<q.front()<<endl;
    cout<<"Last element : "<<q.back()<<endl;
    cout<<"Size  of queue : "<<q.size()<<endl;

    return 0;
}
