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
    void doubleArray()
    {
        int *temp;
        capacity=2*capacity;
        temp=new int[capacity];
        for (int i=0;i<=top-1;i++)
        {
            temp[i]=arr[i];
        }
        delete [] arr;
        arr=temp;
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
        arr=temp;
        //delete temp;
    }
    void addItem(int item)
    {
        if (capacity==top)
        {
            doubleArray();
            cout<<"\n                     (doubling)               ";
            addItem(item);
        }
        else
        {
            arr[top]=item;
            top++;
        }
        /*
        if (capacity==top)
        {
            doubleArray();
            cout<<"\n                     (doubling)               ";
        }
        arr[top]=item;
        top++;
        */
    }
    void addItemAtPosition(int index,int item)
    {
        index--;
        if (index<0 || index>top)
        {
            cout<<"\nIllegal Index!!!";
        }
        else
        {///1(0) 2(1) 2(2)  3(3)top=3   1
            if (capacity==top)
            {
                doubleArray();
                cout<<"\n                     (doubling2)               ";
            }
            for (int i=top;i>=index+1;i--)
            {
                arr[i]=arr[i-1];
            }
            arr[index]=item;
            top++;
        }
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
    void deleteItemAtPosition(int index)
    {
        index--;
        if (top==0 || index<0 || index>=top)
        {
            cout<<"\nIllegal Index!!!";
        }
        else
        {
            for (int i=index;i<=top-1-1;i++)
            {
                arr[i]=arr[i+1];
            }
            arr[top-1]=0;
            top--;
            if(top==capacity/2 && capacity>initial_cap)
            {
                shrinkArray();
                cout<<"\n                     (shrinking2)                ";
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
    void details()
    {
        cout<<"\nCapacity of dynamic array currently is "<<capacity<<" with "<<top<<" elements.";
    }
};
int main()
{
    int x,choice,item,index;
    dynamicArray obj;
    x=1;
    while(x!=0)
    {
    cout<<"\n-----------------------";
    cout<<"\n* * * * * * * * * * * *";
    cout<<"\n*  1.Insert           *";
    cout<<"\n*  2.Insert Position  *";
    cout<<"\n*  3.Delete           *";
    cout<<"\n*  4.Delete Position  *";
    cout<<"\n*  5.Show             *";
    cout<<"\n*  6.Details          *";
    cout<<"\n*  0.Exit             *";
    cout<<"\n* * * * * * * * * * * *";
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
            cout<<"\nEnter position - ";
            cin>>index;
            cout<<"\nEnter value - ";
            cin>>item;
            obj.addItemAtPosition(index,item);
            break;
        }
    case(3):
        {
            obj.deleteItem();
            break;
        }
    case(4):
        {
            cout<<"\nEnter position - ";
            cin>>index;
            obj.deleteItemAtPosition(index);
            break;
        }
    case(5):
        {
            obj.show();
            break;
        }
    case(6):
        {
            obj.details();
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
