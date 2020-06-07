#include<iostream.h>
#include<conio.h>
class A
{
 int a,b,c;
 public:
  void abc()
 {
  a=10;
  b=20;
  c=30;
 }
 void abc2()
 {
  int a;
  a=100;
  this->a=a;
  cout<<"\n"<<this->a<<","<<b<<","<<c;
  cout<<"\n"<<a<<","<<b<<","<<c;
 }
 void dis()
 {
  cout<<"\n"<<a<<","<<b<<","<<c;
 }
};
void main()
{
 clrscr();
 A obj;
 obj.abc();
 obj.abc2();
 obj.dis();
 getch();
}