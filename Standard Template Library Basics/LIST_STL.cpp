#include<iostream>
#include<list>
using namespace std;
int main()
{
    list <int> l1={22,33,22,11,44,55};
    cout<<"\nSize of list l1 - "<<l1.size();
    l1.push_back(77);
    l1.push_back(88);
    l1.push_front(0);
    l1.push_front(11);
    cout<<"\nElements in list l1 : ";
    list<int>::iterator i=l1.begin();
    while(i!=l1.end())
    {
        cout<<*i<<" ";
        i++;
    }
    l1.pop_back();
    l1.pop_front();
    l1.sort();

    cout<<"\nElements in list l1 : ";
    list<int>::iterator i1=l1.begin();
    while(i1!=l1.end())
    {
        cout<<*i1<<" ";
        i1++;
    }

    l1.remove(22);
    l1.reverse();
    cout<<"\nElements in list l1 : ";
    list<int>::iterator i2=l1.begin();
    while(i2!=l1.end())
    {
        cout<<*i2<<" ";
        i2++;
    }

    l1.clear();

}
