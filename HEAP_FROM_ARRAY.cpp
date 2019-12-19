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
    int left_ch,right_ch,par;
    par=nln;
    left_ch=par*2+1;
    right_ch=par*2+2;
    if (left_ch<n && h[left_ch]>h[par])
    {
        par=left_ch;
    }
    if (right_ch<n && h[right_ch]>h[par])
    {
        par=right_ch;
    }
    if (nln!=par)
    {
        swap(&h[par],&h[nln]);
        nln=par;
        heapify(h,n,nln);
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
    int b[5]={4, 10, 3, 5, 1};
    int n=5;
    int nln= ((n-1)-1)/2;           //non_leaf_nodes
    for (int i=nln;i>=0;i--)
    {
        heapify(b,n,i);
    }
    show(b,n);
}
