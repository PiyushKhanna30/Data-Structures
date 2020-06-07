#include<iostream>
#include<string.h>
#include <ctype.h>
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
        }
        else
        {
            temp->next=head;
            head=temp;
        }
    }
    int pop()
    {
        int item;
        if (head==NULL)
        {
            return (0);
        }
        else
        {
            item=head->data;
            head=head->next;
            return(item);
        }
    }
    int top()
    {
        return(head->data);
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
    }
}s;
void evaluation(char exp[])
{
    int len;
    s.push(')');
    s.display();
    len=strlen(exp);
    for (int i=0;i<=len-1;i++)
    {
        if (isdigit(exp[i]))
        {
            int v=exp[i]-'0';
            s.push(v);
            s.display();
        }
        else if(s.top()==')')
        {
            break;
        }
        else
        {
            int v1,v2;
            v1=s.pop();
            v2=s.pop();
            if (exp[i]=='+')
                s.push(v2+v1);
            else if(exp[i]=='-')
                s.push(v2-v1);
            else if(exp[i]=='*')
                s.push(v2*v1);
            else if(exp[i]=='/')
                s.push(v2/v1);
            s.display();
        }
    }
    cout<<"\n"<<s.pop();
}
int main()
{
    char exp[50]="562+*24/-";
    evaluation(exp);
}
