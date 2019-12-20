#include<iostream>
using namespace std;

class dynamicArray
{
    int *arr,initial_cap,capacity,top;
public:
    dynamicArray()
    {
        initial_cap=1;
        capacity=1;
        top=0;
        arr=new int[capacity];
    }

    void shrinkArray()
    {
        int *temp;
        capacity=capacity/2;
        temp=new int[capacity];
        for (int i=0;i<top;i++)
        {
            temp[i]=arr[i];
        }
        delete [] arr;
        arr=new int[capacity];
        arr=temp;
    }
    void doubleArray()
    {
        capacity=2*capacity;
        int *temp;
        temp=new int[capacity];
        for (int i=0;i<=top-1;i++)
        {
            temp[i]=arr[i];
        }
        delete [] arr;
        arr=new int[capacity];
        arr=temp;
    }
    void addItem(int item)
    {
        if (capacity==top)
        {
            doubleArray();
            cout<<"\n                     (doubling)               ";
        }
        arr[top]=item;
        top++;
    }
    void deleteItem()
    {
        if(top==0)
        {
            cout<<"\nArray Already Empty!!!";
        }
        else
        {
            arr[top-1]=0;
            top--;
            if(top==capacity/2 && capacity>initial_cap)
            {
                shrinkArray();
                cout<<"\n                     (shrinking)               ";
            }
        }
    }
    void show()
    {
        cout<<"\nArray is - ";
        for(int i=0;i<=top-1;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};

int main()
{
    int x,choice,item;
    dynamicArray obj;
    x=1;
    while(x!=0)
    {
    cout<<"\n";
    cout<<"\n* * * * * * *";
    cout<<"\n*  1.Insert *";
    cout<<"\n*  2.Delete *";
    cout<<"\n*  3.Show   *";
    cout<<"\n*  4.Exit   *";
    cout<<"\n* * * * * * *";
    cout<<"\nEnter choice number - ";
    cin>>choice;
    switch(choice)
    {
    case(1):
        {
            cout<<"\nEnter value - ";
            cin>>item;
            obj.addItem(item);
            break;
        }
    case(2):
        {
            obj.deleteItem();
            break;
        }
    case(3):
        {
            obj.show();
            break;
        }
    case(4):
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
