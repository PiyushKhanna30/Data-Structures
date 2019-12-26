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
    void push(char item)
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
        char item;
        if (head==NULL)
        {
            //cout<<"\nUnderflow!!!";
        }
        else
        {
            item=head->data;
            head=head->next;
            //cout<<"\nPopped out item "<<item;
        }
    }
    char top()
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
        //delete temp;
    }
}obj;

int prec(char a)
{
    if (a=='^')
        return(3);
    else if (a=='*'||a=='/')
        return(2);
    else if (a=='-'||a=='+')
        return(1);
    else
        return(0);
}
void i_to_p(string s)
{
    string res;
    obj.push('(');
    s=s+")";
    int len = s.length();
    for (int i=0;i<=len-1;i++)
    {
        if ((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
        {
            res=res+s[i];
            cout<<"\n"<<res;
        }
        else if(s[i]=='(')
        {
            obj.push(s[i]);
            cout<<"\n"<<res;
        }
        else if(s[i]==')')
        {
            while(obj.top()!='(')
            {
                res=res+obj.top();
                obj.pop();
            }
            obj.pop();
            cout<<"\n"<<res;
        }
        else
        {
            while(obj.top()!=')' && prec(s[i])<prec(obj.top()))
            {
                res=res+obj.top();
                obj.pop();
                ///cout<<"hjdfj";
            }
            obj.push(s[i]);
            cout<<"\n"<<res;
        }
    }
    cout<<"\n\n\n"<<res;
}
int main()
{
    string exp = "a+(b*c-(d/e^f)*g)*h";
    i_to_p(exp);
}
