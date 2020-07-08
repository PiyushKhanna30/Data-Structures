#include<bits/stdc++.h>
using namespace std;
class Deque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    vector<int>deque;
    int count;
    int front;
    int rear;
    int length;
    Deque(int k):deque(k,0)
    {
        count=0;
        front=0;
        rear=k-1;
        length=k;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(length==count)
            return false;
        deque[front]=value;
        front=(front+1)%length;
        count++;
        return true;
    }
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(length==count)
            return false;
        deque[rear]=value;
        rear=(rear-1+length)%length;
        count++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(count==0)
            return false;
        front=(front-1+length)%length;
        count--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(count==0)
            return false;
        rear=(rear+1)%length;
        count--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if(count==0)
            return -1;
        return deque[(front-1+length)%length];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if(count==0)
            return -1;
        return deque[(rear+1)%length];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return (count==0)?true:false;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (count==length)?true:false;
    }
};
int main()
{
    int n;
    cout<<"Enter size of deque : ";
    cin>>n;
    Deque obj(n);
    int x=1;
    while(x)
    {
        cout<<"\n* * * * * * * * * *";
        cout<<"\n* 1.Insert Front  *";
        cout<<"\n* 2.Insert Rear   *";
        cout<<"\n* 3.Delete Front  *";
        cout<<"\n* 4.Delete Rear   *";
        cout<<"\n* 5.Get Front     *";
        cout<<"\n* 6.Get Rear      *";
        cout<<"\n* 7.Is Empty      *";
        cout<<"\n* 8.Is Full       *";
        cout<<"\n* 0.Exit          *";
        cout<<"\n* * * * * * * * * *";
        cout<<"\n\nEnter choice : ";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int value;
                cout<<"\nEnter Value : ";
                cin>>value;
                if(obj.insertFront(value))
                {
                    cout<<"\nTrue";
                }
                else
                {
                    cout<<"\nFalse";
                }
                break;
            }
            case 2:
            {
                int value;
                cout<<"\nEnter Value : ";
                cin>>value;
                if(obj.insertLast(value))
                {
                    cout<<"\nTrue";
                }
                else
                {
                    cout<<"\nFalse";
                }
                break;
            }
            case 3:
            {
                if(obj.deleteFront())
                {
                    cout<<"\nTrue";
                }
                else
                {
                    cout<<"\nFalse";
                }
                break;
            }
            case 4:
            {
                if(obj.deleteLast())
                {
                    cout<<"\nTrue";
                }
                else
                {
                    cout<<"\nFalse";
                }
                break;
            }
            case 5:
            {
                int value;
                value=obj.getFront();
                if(value!=-1)
                {
                    cout<<"\n"<<value;
                }
                else
                {
                    cout<<"\nEmpty";
                }
                break;
            }
            case 6:
            {
                int value;
                value=obj.getRear();
                if(value!=-1)
                {
                    cout<<"\n"<<value;
                }
                else
                {
                    cout<<"\nEmpty";
                }
                break;
            }
            case 7:
            {
                if(obj.isEmpty())
                {
                    cout<<"\nTrue";
                }
                else
                {
                    cout<<"\nFalse";
                }
                break;
            }
            case 8:
            {
                if(obj.isFull())
                {
                    cout<<"\nTrue";
                }
                else
                {
                    cout<<"\nFalse";
                }
                break;
            }
            case 0:
            {
                x=0;
                break;
            }
            default:
            {
                cout<<"\nInvalid choice.";
            }
        }
    }
    return 0;
}
