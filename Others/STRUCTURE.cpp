#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class linkedList
{
    node *head,*tail;
    public:
    linkedList()
    {
        head=NULL;
        tail=NULL;
    }
    void createNode(int value)
    {
        node *temp =new node;
        temp->data=value;
        temp->next=NULL;
        if (head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    void display()
    {
        node *temp=new node;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }
};
int main()
{
    linkedList obj;
    obj.createNode(1);
    obj.createNode(2);
    obj.createNode(3);
    obj.display();
}
