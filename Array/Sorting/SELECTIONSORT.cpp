#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int t = *a;
    *a=*b;
    *b=t;
}
void show(int arr[],int low,int high)
{
    for (int i=low;i<=high;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
void selctionSort(int arr[],int low,int high)
{
    int min_index,j,i;
    for (i=low;i<=high;i++)
    {
        min_index=i;
        for ( j=i+1;j<=high;j++)
        {
            if (arr[min_index]>arr[j])
            {
                min_index=j;
            }
        }
        swap(&arr[min_index],&arr[i]);
        show(arr,low,high);
    }
}

int main()
{
    int arr[6]={5,2,4,7,3,1} ;
    int l=0;
    int h=5;
    show(arr,l,h);
    selctionSort(arr,l,h);
    show(arr,l,h);
}
