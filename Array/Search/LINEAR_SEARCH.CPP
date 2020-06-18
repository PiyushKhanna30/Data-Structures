#include<iostream>
using namespace std;
int linearSeach(int arr[],int arr_size,int num)
{
    for(int i=0;i<arr_size-1;i++)
    {
        if(arr[i]==num)
            return i;
    }
    return -1;
}
int main()
{
    int arr[]={4,5,1,3,2};
    int arr_size=sizeof(arr)/sizeof(arr[0]);
    int index_of_5=linearSeach(arr,arr_size,5);
    int index_of_12=linearSeach(arr,arr_size,12);
    cout<<index_of_5<<"\n"<<index_of_12;
}

