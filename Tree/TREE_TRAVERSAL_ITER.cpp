#include<iostream>
using namespace std;

struct bst
{
    bst *left;
    int item;
    bst *right;
    bst(int item)
    {
        this->item=item;
        left=NULL;
        right=NULL;
    }
};
struct node
{
    struct bst *data;
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
    void push(bst *tmp)
    {
        node *temp = new node;
        temp->data=tmp;
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
    void pop()
    {
        if (head!=NULL)
        {
            head=head->next;
        }
    }
    bst *top()
    {
        if (head!=NULL)
        {
            return(head->data);
        }
    }
    int isempty()
    {
        if (head==NULL)
        {
            return(0);
        }
        else
        {
            return(1);
        }
    }
}s;
class traversal
{
    public:
    void preorder(bst *temp)
    {
        while (temp!=NULL || s.isempty()!=0 )
        {
            while(temp!=NULL)
            {
                cout<<" "<<temp->item;
                s.push(temp->right);
                temp=temp->left;
            }
            temp=s.top();
            s.pop();
        }
    }
    void inorder(bst *temp)
    {
        while(temp!=NULL || s.isempty()!=0)
        {
            while (temp!=NULL)
            {
                s.push(temp);
                temp=temp->left;
            }
            temp=s.top();
            cout<<" "<<temp->item;
            s.pop();
            temp=temp->right;
        }
    }
    void postorder(bst *temp)
    {
        while (temp!=NULL||s.isempty()!=0)
        {
            while(temp!=NULL)
            {
                if (temp->right!=NULL)
                {
                    s.push(temp->right);
                }
                s.push(temp);
                temp=temp->left;
            }
            temp=s.top();
            s.pop();
            if (temp->right==s.top())
            {
                s.pop();
                s.push(temp);
                temp=temp->right;
            }
            else
            {
                cout<<" "<<temp->item;
                temp=NULL;
            }
        }
    }
};
int main()
{
    bst *temp=new bst(1);
    temp->left=new bst(2);
    temp->left->left=new bst(4);
    temp->left->left->right=new bst(7);
    temp->left->left->right->right=new bst(8);
    temp->left->right=new bst(5);
    temp->right=new bst(3);
    temp->right->left=new bst(6);
    traversal t;
    cout<<"\nPRE-ORDER : ";
    t.preorder(temp);
    cout<<"\nIN-ORDER : ";
    t.inorder(temp);
    cout<<"\nPOST-ORDER : ";
    t.postorder(temp);
}
/**
            1
        2        3
    4      5    6
      7
        8*/
