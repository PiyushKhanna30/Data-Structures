#include<iostream>
using namespace std;

class heap
{
    int n,h[100];
public:
    heap()
    {
        n=0;
    }
    void swap(int *a,int *b)
    {
        int t=*a;
        *a=*b;
        *b=t;
    }
    void insertVerify(int value_index)
    {
        int parent_index=(value_index-1)/2;
        if (parent_index>=0)
        {
            if (h[parent_index]<h[value_index])
            {
                swap(&h[value_index],&h[parent_index]);
                insertVerify(parent_index);
            }
        }
    }
    void insert(int value)
    {
        n++;
        h[n-1]=value;
        insertVerify(n-1);
    }
    void deleteVerify(int index)
    {
        int left_ch,right_ch,par;
        par=index;
        left_ch=(2*par)+1;
        right_ch=(2*par)+2;
        if (h[left_ch]>h[par] && left_ch<=(n-1) )
        {
            par=left_ch;
        }
        if (h[right_ch]>h[par] && right_ch<=(n-1))
        {
            par=right_ch;
        }
        if (index!=par)
        {
            swap(&h[index],&h[par]);
            index=par;
            deleteVerify(index);
        }
    }
    void delet()
    {
        h[0]=h[n-1];
        n--;
        deleteVerify(0);
    }
    void show()
    {
        cout<<"\nResult is - ";
        for(int i=0;i<=n-1;i++)
        {
            cout<<h[i]<<" ";
        }
    }
};
int main()
{
    heap obj;
    int x=1;
    int item,choice;
    while(x!=0)
    {
    cout<<"\n\n---------------";
    cout<<"\n* * * * * * * * *";
    cout<<"\n*  1.Insert     *";
    cout<<"\n*  2.Delete     *";
    cout<<"\n*  3.Show       *";
    cout<<"\n*  0.Exit       *";
    cout<<"\n* * * * * * * * *";
    cout<<"\n\nEnter choice number - ";
    cin>>choice;
    switch(choice)
    {
    case(1):
        {
            cout<<"\nEnter value - ";
            cin>>item;
            obj.insert(item);
            break;
        }
    case(2):
        {
            obj.delet();
            break;
        }
    case(3):
        {
            obj.show();
            break;
        }
    case(0):
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
