#include<iostream>
using namespace std;

int main()
{
    int a[8]={9,13,19,20,21,56,82,100};
    int b[5]={2,4,18,30,45};
    int sa=sizeof(a)/sizeof(a[0]);
    int sb=sizeof(b)/sizeof(b[0]);
    sa--;
    sb--;
    int last;
    ///------------------
    cout<<"\n";
    for (int i=0;i<=sa;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<"\n";
    for (int i=0;i<=sb;i++)
    {
        cout<<b[i]<<"\t";
    }
    ///-------------------

    for (int j=sb;j>=0;j--)
    {
        if(a[sa]>b[j])
        {
            last=b[j];
            b[j]=a[sa];

            ///-----
            int jk=sa-1;
            while(jk>=0 && a[jk]>last)
            {
                a[jk+1]=a[jk];
                jk--;
            }
            a[jk+1]=last;
            ///-----
        }
    }
    ///---------------------
    cout<<"\n";
    for (int i=0;i<=sa;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<"\n";
    for (int i=0;i<=sb;i++)
    {
        cout<<b[i]<<"\t";
    }
}
