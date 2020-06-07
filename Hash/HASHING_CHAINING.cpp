#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
class Hash
{
    node *arr[7];
    int cap,key;
public:
    Hash()
    {
        cap=7;
        for (int i=0;i<=cap-1;i++)
        {
            arr[i]=NULL;
        }
    }
    void ins(int value)
    {
         key=value%cap;
         node *valnode=new node(value);
         if(arr[key]==NULL)
         {
             arr[key]= valnode;
         }
         else
         {
             node *temp;
             temp=arr[key];
             while(temp->next!=NULL)
             {
                 temp=temp->next;
             }
             temp->next=valnode;
         }
    }
    void sear(int value)
    {
        int x=0;
        node *temp;
        key=value%cap;
        if (arr[key]!=NULL)
        {
            temp=arr[key];
            while(temp!=NULL)
            {
                if (temp->data== value)
                {
                    cout<<"\nFound "<<value<<" at key "<<key;
                    x=1;
                    break;
                }
                temp=temp->next;
                x=0;
            }
        }
        if(x==0)
        {
            cout<<"\nNot Found "<<value;
        }
    }
    int del(int value)
    {
        int x=0;
        node *temp,*par;
        key=value%cap;
        if (arr[key]!=NULL)
        {
            temp=arr[key];
            if (temp->data==value)
            {
                arr[key]=NULL;
                cout<<"\nDeleted "<<value;
                return(1);
            }
            while(temp->next!=NULL)
            {
                par=temp;
                temp=temp->next;
                if (temp->data==value)
                {
                    par->next=temp->next;
                    cout<<"\nDeleted "<<value;
                    x=1;
                    break;
                }
                else
                {
                    x=0;
                }
            }
        }
        if(x==0)
        {
            cout<<"\nCould Not Found "<<value;
        }
    }
    void show()
    {
        node *temp;
        for (int i=0;i<=cap-1;i++)
        {
            if (arr[i]!=NULL)
            {
                cout<<"\nKey "<<i<<" values -";
                temp=arr[i];
                while(temp!=NULL)
                {
                    cout<<" "<<temp->data;
                    temp=temp->next;
                }
            }
        }
    }
};
int main()
{
    Hash h;
    h.ins(0);
    h.ins(21);
    h.ins(27);
    h.ins(35);
    h.ins(22);
    h.ins(30);
    h.show();

    h.del(22);
    h.del(21);
    h.del(2);
    h.show();

}
