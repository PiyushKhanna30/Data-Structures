#include<iostream>
using namespace std;
class Hash
{
    int capacity,arr[7],key;
    public:
    Hash()
    {
        capacity=7;
        for (int i=0;i<=capacity-1;i++)
        {
            arr[i]=-1;
        }
    }

    void ins(int value)
    {
        key=value%capacity;
        if (arr[key]!=-1)
        {
            cout<<"\nCollision Occurred.";
        }
        else
        {
            arr[key]=value;
            cout<<"\nItem inserted.";
        }
    }
    void del(int value)
    {
        key=value%capacity;
        if (arr[key]==value)
        {
            arr[key]=-1;
            cout<<"\nItem deleted.";
        }
        else
        {
            cout<<"\nItem not present.";
        }
    }
    void sear(int value)
    {
        key=value%capacity;
        if (arr[key]==value)
        {
            cout<<"\nItem found.";
        }
        else
        {
            cout<<"\nItem not found.";
        }
    }
    void show()
    {
        cout<<"\nElements are ";
        for(int i=0;i<=capacity-1;i++)
        {
            if (arr[i]!=-1)
            {
                cout<<"\n"<<arr[i]<<" - "<<i;
            }
        }
    }
};
int main()
{
    Hash h;
    h.show();
    h.ins(5);
    h.ins(1);
    h.ins(21);
    h.sear(1);
    h.show();
    h.del(1);
    h.show();
}
