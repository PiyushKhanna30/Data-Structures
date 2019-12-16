#include<iostream>
using namespace std;

void dis(int h[],int n)
{
    cout<<"\n";
    for(int j=0;j<=n-2;j++)
    {
        cout<<h[j]<<" ";
    }
}
void del(int h[],int n)
{
    n=n-1;
    int last=h[n];
    n=n-1;
    int left=0,right=0,ptr;
    ptr=0;
    while (right<n)
    {
        left=2*ptr+1;
        right=2*ptr+2;
        if (last>=h[left] && last>=h[right])
        {
            h[ptr]=last;
            break;
        }
        else if(h[left]>h[right])
        {
            h[ptr]=h[left];
            h[left]=last;
            ptr=left;
        }
        else
        {
            h[ptr]=h[right];
            h[right]=last;
            ptr=right;
        }
        dis(h,n+2);
    }
}
int main()
{
   // int n=11;
   // int h[11]={95,85,70,55,33,30,65,15,20,15,22};
   int  n=20;
   int h[20]={97,88,95,66,55,95,48,66,35,48,55,62,77,25,38,18,40,30,26,24};
   dis(h,n+1);
   cout<<"\n";
   cout<<"\n";
    del(h,n);
    cout<<"\n";
    cout<<"\n";
    dis(h,n);

}
