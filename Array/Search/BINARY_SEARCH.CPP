#include<iostream>
using namespace std;
int binarySeach(int arr[],int arr_size,int num)
{
    int beg=0;
    int end=arr_size-1;
    while(beg<=end)
    {
        int mid=(beg+end)/2;   ///or (end-beg)/2 + beg
        if(arr[mid]==num)
            return mid;
        else if(arr[mid]>num)
            end=mid-1;
        else
            beg=mid+1;
    }
    return -1;
}
int main()
{
    int arr[]={1,2,3,4,5};
    int arr_size=sizeof(arr)/sizeof(arr[0]);
    int index_of_2=binarySeach(arr,arr_size,4);
    int index_of_12=binarySeach(arr,arr_size,12);
    cout<<index_of_2<<"\n"<<index_of_12;
}
