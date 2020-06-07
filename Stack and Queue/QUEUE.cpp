#include<iostream>
using namespace std;
class queue{
private:
    int q[5],head,tail;
public:
    queue(){
    head=-1;
    tail=-1;}
    void enqueue(int n){
        if(tail==-1&&head==-1){
            tail=0;
            head=0;
            q[tail]=n;}
        else if(tail==4){cout<<"\nQueue Full.";
        }
        else{
                tail++;
                q[tail]=n;}}
    void dequeue(){
        if (head==tail)
            {head=-1;
             tail=-1;
        }
        else{head++;}}
    void display(){
    cout<<"\nQueue is - ";
    if(head!=-1&&tail!=-1){
    for(int i=head;i<=tail;i++){
        cout<<","<<q[i];
    }}}
};
int main()
{   int x,n;
    queue obj;
    cout<<"\nPress 1 for Dequeue";
    cout<<"\nPress 2 for Enqueue";
    cout<<"\nPress 3 for Display";
    cout<<"\nPress 4 for Exit";
    while (x!=4){
    cout<<"\nEnter your choice - ";
    cin>>x;
    switch (x)
    {
    case 1:
        obj.dequeue();
        break;
    case 2:
        cout<<"\nEnter integer value - ";
        cin>>n;
        obj.enqueue(n);
        break;
    case 3:
        obj.display();
        break;
    case 4:
        break;
    default:
        cout<<"\nInvalid input";
    }
    }
}
