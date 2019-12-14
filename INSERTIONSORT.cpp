#include<iostream>
using namespace std;
void show(int arr[],int low,int high)
{
    cout<<"\n";
    for (int i=low;i<=high;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
void insertionSort(int arr[],int low,int high)
{
    int val,j,i;
    for (i=low+1;i<=high;i++)
    {
        val=arr[i];
        j=i-1;
        while(j>=low && val<arr[j])
        {
            arr[j+1]=arr[j];
            //arr[j]=val;
            //cout<<"\n"<<arr[i]<<"\t"<<arr[j];
            j--;
        }
        arr[j+1]=val;
    }
}
int main()
{
    int arr[6]={5,2,4,7,3,1} ;
    int l=0;
    int h=5;
    show(arr,l,h);
    insertionSort(arr,l,h);
    show(arr,l,h);
}
