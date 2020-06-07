#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
class avl
{
public:
    int max(int a,int b)
    {
        if (a>b)
            return(a);
        else
            return(b);
    }
    int height(node *avl)
    {
        int l_h,r_h,max_h;
        if (avl==NULL)
            return(0);
        l_h=height(avl->left);
        r_h=height(avl->right);
        max_h=max(l_h,r_h);
        return(max_h);
    }
    int diff(node *avl)
    {
        int l_h,r_h,dif;
        l_h=height(avl->left);
        r_h=height(avl->right);
        dif=l_h-r_h;
        return(dif);
    }
    node *ll(node *avl)
    {
        node *temp=new node;
        temp=avl->left;
        avl->left=temp->right;
        temp->right=avl;
        return(temp);
    }
    node *rr(node *avl)
    {
        node *temp=new node;
        temp=avl->right;
        avl->right=temp->left;
        temp->left=avl;
        return(temp);
    }
    node *lr(node *avl)
    {
        avl->left=rr(avl->left);
        return(ll(avl));
    }
    node *rl(node *avl)
    {
        avl->right=ll(avl->right);
        return(rr(avl));
    }

    node *verify(node *avl)
    {
        int dif=diff(avl);
        if (dif>1)
        {
            if (diff(avl->left)>0)
            {
                avl=ll(avl);
            }
            else
                avl=lr(avl);
        }
        else if(dif<=-1)
        {
            if (diff(avl->right) >0)
            {
                avl=rl(avl);
            }
            else
                avl=rr(avl);
        }
        return (avl);
    }
    node *insert(node *avl,int data)
    {
        if (avl==NULL)
        {
            node *avl=new node;
            avl->data=data;
            avl->left=NULL;
            avl->right=NULL;
            return(avl);
        }
        else if(data< avl->data)
        {
            avl->left=insert(avl->left,data);
            avl=verify(avl);
        }
        else if(data>= avl->data)
        {
            avl->right=insert(avl->right,data);
            avl=verify(avl);
        }
        return(avl);
    }
    int inorder(node *avl)
    {
        if (avl==NULL)
        {
            return(0);
        }
        inorder(avl->left);
        cout<<" "<<avl->data;
        inorder(avl->right);
    }
};
int main()
{
    avl tree;
    int x=1,ch,item;
    node *avl = new node;
    avl=NULL;
    while(x!=0)
    {
        cout<<"\n1.To insert \n2.Inorder \n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\nEnter number ";
            cin>>item;
            avl=tree.insert(avl,item);
            break;
        case 2:
            tree.inorder(avl);
            break;
        case 3:
            x=0;
            break;
        default:
            cout<<"\nError ";
        }
    }
}
