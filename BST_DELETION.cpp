#include<iostream>
using namespace std;

struct node
{
    node *left;
    int data;
    node *right;
    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
class del
{
    node *loc,*par;
public:
    node *findloc(node *root,int item)
    {
        if (root==NULL)
        {
            loc=NULL;
            par=NULL;
            return(loc);
        }
        else if(root->data==item)
        {
            loc=root;
            par=NULL;
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
                if ((root->data)==item)
                {
                    loc=root;
                    return(loc);
                }
                else if((root->data)>item)
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
        return(loc);
    }
    void deleteloc(node *root,int item)
    {
        loc=findloc(root,item);
        if (par==NULL && loc==NULL)
        {
            cout<<"\nEmpty.";
        }
        else if(par==NULL && loc!=NULL)
        {
            root=NULL;
            cout<<"\nRoot element removed.";
        }
        else if(par!=NULL && loc==NULL)
        {
            cout<<"\nNot found.";
        }
        else if(loc->left==NULL && loc->right==NULL)
        {
            loc=NULL;
            par->left=par->right=NULL;
            cout<<"\nRemoved from end.";
        }
        else if(loc->left==NULL)
        {
            if (par->left==loc)
            {
                par->left=loc->right;
            }
            else
            {
                par->right=loc->right;
            }

        }
        else if(loc->right==NULL)
        {
            if (par->left==loc)
            {
                par->left=loc->right;
            }
            else
            {
                par->right=loc->right;
            }
        }
        else
        {
           node *suc;
           node *parsuc;
           suc=loc->right;                  ///s50 p50 s33
           cout<<"\n\n"<<suc->data;
           while(suc->left!=NULL)
           {
               parsuc=suc;
               suc=suc->left;
               cout<<"\n"<<suc->data<<" "<<parsuc->data;
           }
           loc->data=suc->data;
           parsuc->left=suc->right;

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
    node *temp=new node(60);
    temp->left=new node(25);
    temp->left->left=new node(15);
    temp->left->right=new node(50);
    temp->left->right->left=new node(33);
    temp->left->right->left->right=new node(44);
    temp->right=new node(75);
    temp->right->left=new node(66);
    del d;
    cout<<"\n ";
    d.preorder(temp);
    //cout<<"\n answere - "<<d.findloc(temp,70);
    d.deleteloc(temp,25);
    cout<<"\n ";
    d.preorder(temp);
}


/**
                    60
        25                      75
   15        50             66
           33
             44

 */
