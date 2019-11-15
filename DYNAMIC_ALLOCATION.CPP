#include<iostream.h>
#include<conio.h>
void main()
{
 clrscr();
 int *p,n;
 cout<<endl<<"Enter numbers count : ";
 cin>>n;
 p=new int[n] ;
// p=new int;
// *p=n;

 cout<<endl<<"Enter numbers : ";
 for (int i=0;i<n;i++)
 {
  cin>>p[i];
 }
  cout<<endl<<"Output numbers : ";
 for (int j=0;j<n;j++)
 {
  cout<<p[j];
 }
 delete p;
 getch();
}