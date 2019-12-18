#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void heapify(int h[],int n,int nln)
{
    int par,left_ch,right_ch;
    par=nln;
    left_ch=2*par+1;
    right_ch=2*par+2;
    if(left_ch<n && h[left_ch]>h[par])
    {
        par=left_ch;
    }
    if(right_ch<n && h[right_ch]>h[par])
    {
        par=right_ch;
    }
    if (nln!=par)
    {
        swap(&h[nln],&h[par]);
        nln=par;
        heapify(h,n,nln);
    }
}
void heapsort(int h[],int n)
{
    int nln=((n-1)-1)/2;
    for(int k=nln;k>=0;k--)
    {
        heapify(h,n,k);
    }
    for (int last_element=n-1;last_element>=0;last_element--)
    {
        swap(&h[last_element],&h[0]);
        heapify(h,last_element,0);

        ///-----OR------

       /*for (int m=(last_element-2)/2;m>=0;m--)
        {
            heapify(h,last_element,m);
        }*/
    }
}
void show(int h[],int n)
{
    cout<<"\nResult is - ";
    for(int i=0;i<=n-1;i++)
    {
        cout<<h[i]<<" ";
    }
}
int main()
{
    //int h[100],n;
    int  n=20;
    int h[20]={97,88,95,66,55,95,48,66,35,48,55,62,77,25,38,18,40,30,26,24};
    show(h,n);
    /*cout<<"\nEnter total numbers in array - ";
    cin>>n;
    for (int j=0;j<=n-1;j++)
    {
        cint>>h[n];
    }*/
    //----------------------------------------
    heapsort(h,n);
    show(h,n);
}
