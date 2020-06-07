#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class Stack
{
    node *head,*tail;
public:
    Stack()
    {
        head=NULL;
        tail=NULL;
    }
    void push(int item)
    {
        node *temp = new node;
        temp->data=item;
        temp->next=NULL;
        if (head==NULL)
        {
            head=temp;
            tail=temp;
            //delete temp;
        }
        else
        {
            temp->next=head;
            head=temp;
            //delete temp;
        }
    }
    void pop()
    {
        int item;
        if (head==NULL)
        {
            cout<<"\nUnderflow!!!";
        }
        else
        {
            item=head->data;
            head=head->next;
            cout<<"\nPopped out item "<<item;
        }
    }
    void display()
    {
        node *temp = new node;
        temp=head;
        cout<<"\nElements are -";
        while(temp!=NULL)
        {
            cout<<" "<<temp->data;
            temp=temp->next;
        }
        //delete temp;
    }
};
int main()
{
    int x,choice,item;
    Stack s;
    x=1;
    while(x)
    {
        cout<<"\n* * * * * * * * * * * * *";
        cout<<"\n*                       *";
        cout<<"\n*   1.Push Element      *";
        cout<<"\n*   2.Pop  Element      *";
        cout<<"\n*   3.Show Elements     *";
        cout<<"\n*   0.To Exit           *";
        cout<<"\n*                       *";
        cout<<"\n* * * * * * * * * * * * *";
        cout<<"\nEnter choice - ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
                cout<<"\nEnter item - ";
                cin>>item;
                s.push(item);
                break;
            }
        case 2:
            {
                s.pop();
                break;
            }
        case 3:
            {
                s.display();
                break;
            }
        case 4:
            {
                x=0;
                break;
            }
        default:
            {
                cout<<"\nInvalid Choice!!!";
            }
        }
    }
}
