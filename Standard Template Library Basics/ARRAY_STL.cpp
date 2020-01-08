#include<iostream>
#include<array>
using namespace std;
int main()
{
    int i;
    array <int,10> ar1;                            ///array <data_type,capacity> object;
    array <int,10> ar2={11,22,33,44,55};

    cout<<"\nSize of arr2 is : "<<ar2.size();

    cout<<"\nArr2 elements are : ";
    for(i=0;i<ar2.size();i++)
        cout<<ar2[i]<<" ";

    cout<<"\nFront element ar2 : "<<ar2.front();
    cout<<"\nLast element ar2 : "<<ar2.back();     /// if array capacity 5 and items are 3 then other two are 0.

    ar1.fill(10);
    cout<<"\nFill ar1 with 10 in each block : ";
    for(i=0;i<ar1.size();i++)
        cout<<ar1[i]<<" ";

    ar1.swap(ar2);
    cout<<"\nSwapping both arrays of same size and data type";
    cout<<"\nAr1 : ";
    for(i=0;i<ar1.size();i++)
        cout<<ar1[i]<<" ";
    cout<<"\nAr2 : ";
    for(i=0;i<ar2.size();i++)
        cout<<ar2[i]<<" ";

    ///ar1.begin() Pointer to first index
    ///ar1.end()   Pointer to last index

}
