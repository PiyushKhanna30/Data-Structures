#include<iostream>
using namespace std;
int findMaxSum(int arr[],int size)
{
    int sum=arr[0],ans=arr[0];
    for(int i=1;i<size-1;i++)
    {
        sum+=arr[i];
        sum=max(sum,arr[i]);
        ans=max(ans,sum);
    }
    return ans;
}
int main()
{
    int arr[]={1, 2, 3, -2, 5};
    cout<<"Max continuous sum in array is "<<findMaxSum(arr,5)<<endl;
    int arr2[]={-1 ,-2, -3, -4};
    cout<<"Max continuous sum in array is "<<findMaxSum(arr2,4)<<endl;
}
