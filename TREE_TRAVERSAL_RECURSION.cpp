#include<iostream>
using namespace std;
struct node
{
    node *left;
    int data;
    node *right;
    node(int item)
    {
        data=item;
        right=left=NULL;
    }
};
class traversal
{
public:
    int preorder(node *temp)
    {
        if (temp==NULL)
        {
            return(0);
        }
        cout<<" "<<temp->data;
        preorder(temp->left);
        preorder(temp->right);
    }
    int inorder(node *temp)
    {
        if (temp==NULL)
        {
            return(0);
        }
        inorder(temp->left);
        cout<<" "<<temp->data;
        inorder(temp->right);
    }
    int postorder(node *temp)
    {
        if (temp==NULL)
        {
            return(0);
        }
        postorder(temp->left);
        postorder(temp->right);
        cout<<" "<<temp->data;
    }
};
int main()
{
    node *temp=new node(1);
    temp->left=new node(2);
    temp->left->left=new node(4);
    temp->left->left->right=new node(7);
    temp->left->left->right->right=new node(8);
    temp->left->right=new node(5);
    temp->right=new node(3);
    temp->right->left=new node(6);
    traversal obj;
    cout<<"\nPRE-ORDER : ";
    obj.preorder(temp);
    cout<<"\nIN-ORDER : ";
    obj.inorder(temp);
    cout<<"\nPOST-ORDER : ";
    obj.postorder(temp);
}
