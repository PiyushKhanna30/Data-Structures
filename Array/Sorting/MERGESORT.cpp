#include<iostream>
using namespace std;
void display(int arr[],int low,int high)
{
    cout<<"\n\n\nSorted array is : ";
    for (int i=low;i<=high;i++)
        cout<<arr[i]<<" ";
}
void merge(int arr[],int low,int middle,int high)
{
    int i,j,k,n1,n2;
    n1=middle-low+1;
    n2=high-middle;
    int A1[n1],A2[n2];
    for (i=0;i<n1;i++)
    {
        A1[i]=arr[low+i];
    }
    for (j=0;j<n1;j++)
    {
        A2[j]=arr[middle+1+j];
    }
    i=0;
    j=0;
    k=low;
    while(i<n1 && j<n2)
    {
        if (A1[i]<A2[j])
        {
            arr[k]=A1[i];
            i++;
        }
        else
        {
            arr[k]=A2[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k]=A1[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=A2[j];
        k++;
        j++;
    }
}
void mergeSort(int arr[],int low,int high)
{
    if (low<high)
    {
        int middle=(high+low)/2;
        mergeSort(arr,low,middle);
        mergeSort(arr,middle+1,high);
        merge(arr,low,middle,high);
    }
}
int main()
{
    int arr[10]={4,6,5,3,10};
    int low=0;
    int high=4;
    mergeSort(arr,low,high);
    display(arr,low,high);
    return 0;
}
