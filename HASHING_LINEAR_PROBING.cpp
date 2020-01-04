#include<iostream>
using namespace std;
class Hash
{
    int arr[7],cap,key;
public:
    Hash()
    {
        cap=7;
        for (int i=0;i<=cap-1;i++)
        {
            arr[i]=-1;
        }
    }

    void ins(int value)
    {
        int c=0;
        key=value%cap;
        while(arr[key]!=-1)
        {
            c++;
            key=(key+1)%cap;
            if (c==cap)
            {
                break;
            }
        }
        if (c==cap)
        {
            cout<<"\nNo space";
        }
        else
        {
            arr[key]=value;
            cout<<"\nAdded value.";
        }
    }
    void sear(int value)
    {
        int c=0;
        key=value%cap;
        while(arr[key]!=value)
        {
            c++;
            key=(key+1)%cap;
            if (c==cap)
            {
                break;
            }
        }
        if(arr[key]==value)
        {
            cout<<"\nFound at key "<<key;
        }
        else
        {
            cout<<"\nNot Found";
        }
    }
    void del(int value)
    {
        int c=0;
        key=value%cap;
        while(arr[key]!=value)
        {
            c++;
            key=(key+1)%cap;
            if (c==cap)
            {
                break;
            }
        }
        if(arr[key]==value)
        {
            arr[key]=-1;
            cout<<"\nDeleted";
        }
        else
        {
            cout<<"\nCould not deleted";
        }
    }
    void show()
    {
        cout<<"\nElements are ";
        for(int i=0;i<=cap-1;i++)
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
    h.ins(21);
    h.ins(22);
    h.ins(23);
    h.ins(24);
    h.ins(25);
    h.ins(26);
    h.ins(35);
    h.ins(27);
    h.show();
    h.sear(23);
    h.sear(35);
    h.del(35);
    h.ins(101);
    h.show();
}
