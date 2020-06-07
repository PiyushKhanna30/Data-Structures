#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void dis(int h[],int n)
{
    cout<<"\n";
    for(int j=0;j<=n-1;j++)
    {
        cout<<h[j]<<" ";
    }
    cout<<"\n";
}
void ins(int h[],int n,int value)
{
    n++;
    h[n-1]=value;
    dis(h,n);
    int par,child;
    child=n-1;
    par=(child-1)/2;
    while(par!=child)
    {
        if (h[par]>value)
        {
            break;
        }
        else if(h[par]<value)
        {
            swap(&h[par],&h[child]);
            child=par;
            par=(child-1)/2;
        }
    }
    dis(h,n);
}
int main()
{
   int n=20;
   int h[20]={97,88,95,66,55,95,48,66,35,48,55,62,77,25,38,18,40,30,26,24};
   dis(h,n);
   ins(h,n,70);
}
