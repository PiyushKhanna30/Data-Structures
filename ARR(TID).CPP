#include<iostream.h>
#include<conio.h>
class Array
{ int arr[5];
  public:
  Array()
  {
   int a[5]={1,2,3,4,5};
   for (int i=0;i<=4;i++)
    {
     arr[i]=a[i];
    }
  }
  void traverse();
  void insertitem(int index,int num);
  void deleteitem(int index);
  void display();
};
void Array::traverse(){
 for (int i=0;i<=4;i++)
 {
  cout<<endl<<"Item at index "<<i<<" is : "<<arr[i];
 }
}
void Array::insertitem(int index,int num){
 for (int i=4-1;i>=index;i--)
 {
  arr[i+1]=arr[i];
 }
 arr[index]=num;
}
void Array::deleteitem(int index){
 for (int i=index;i<=4-1;i++)
 {
  arr[i]=arr[i+1];
 }
 arr[4]=0;
}
void Array::display(){
 for (int i=0;i<=4;i++)
 {
  cout<<" "<<arr[i];
 }
}
void main()
{
 int x,choice;
 clrscr();
 Array obj;
 while(x!=0)
 {
 cout<<endl<<"\nSelect from following options.";
 cout<<endl<<"1=To traverse an array.";
 cout<<endl<<"2=To insert item into array.";
 cout<<endl<<"3=To delete item from array.";
 cout<<endl<<"4=To display array.";
 cout<<endl<<"0=To exit.\n";
 cin>>choice;
 switch(choice)
 {
  case 1:
  {
   obj.traverse();
   break;
  }
  case 2:
  {
   int index,num;
   cout<<"\nEnter index and number.";
   cin>>index>>num;
   obj.insertitem(index,num);
   break;
  }
  case 3:
  {
   int index;
   cout<<"\nEnter index.";
   cin>>index;
   obj.deleteitem(index);
   break;
  }
  case 4:
  {
   obj.display();
   break;
  }
  case 0:
  {
   x=0;
   break;
  }
  default:
  {
   cout<<"\nERROR";
  }
 }
 }
 getch();
}