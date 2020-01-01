#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
class Find
{
    node *par,*loc,*ptr,*save;
public:
    node *findloc(node *root,int item)
    {
        if (root==NULL)
        {
            loc=NULL;
            par=NULL;
            cout<<"\n1\n";
            return(loc);
        }
        else if(root->data==item)
        {
            loc=root;
            par=NULL;
            cout<<"2\n";
            return(loc);
        }
        else
        {
            if ((root->data)>item)
            {
                par=root;
                root=root->left;
            }
            else
            {
                par=root;
                root=root->right;
            }
            while(root!=NULL)
            {
                if (item==(root->data))
                {
                    loc=root;
                    cout<<"\n3\n";
                    return(loc);
                }
                else if(item<(root->data))
                {
                    par=root;
                    root=root->left;
                }
                else
                {
                    par=root;
                    root=root->right;
                }
            }
        }
        loc=NULL;
        cout<<"\n4\n";
        return(loc);
    }
    void insloc(node *root,int item)
    {
        node *temp=new node(item);
        findloc(root,item);
        if (loc!=NULL)
        {
            cout<<"\nAlready present.";
        }
        else
        {
            if (par==NULL)
            {
                root=temp;
            }
            else if(par->data>item)
            {
                par->left=temp;
                cout<<"\nAdded in left of "<<par->data;
            }
            else
            {
                par->right=temp;
                cout<<"\nAdded in right of "<<par->data;
            }
        }
    }
    int preorder(node *root)
    {
        if (root==NULL)
        {
            return(0);
        }
        cout<<" "<<root->data;
        preorder(root->left);
        preorder(root->right);
    }
};
int main()
{
    node *temp=new node(38);
    temp->left=new node(14);
    temp->left->left=new node(8);
    temp->left->right=new node(23);
    temp->left->right->left=new node(18);
    temp->right=new node(56);
    temp->right->left=new node(45);
    temp->right->right=new node(82);
    temp->right->right->left=new node(70);
    Find f;
    ///cout<<f.fxn(temp,14);
    f.insloc(temp,20);
    cout<<"\n";
    f.preorder(temp);
}
