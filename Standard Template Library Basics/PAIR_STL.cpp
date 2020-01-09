#include<iostream>
#include<string>
using namespace std;
class student
{
    string name;
    int roll_no;
public:
    void setStudent(string na,int rno)
    {
        name=na;
        roll_no=rno;
    }
    void out()
    {
        cout<<"\nRoll No - "<<roll_no<<"\nName - "<<name;
    }
};
int main()
{
    pair <string,int> p1;
    p1=make_pair("Piyush",21);
    cout<<"\nPair p1 string is "<<p1.first<<" and integer is "<<p1.second;

    pair <int,student> p2;
    student s;
    s.setStudent("Piyush Khanna",1149);
    p2=make_pair(1,s);
    cout<<"\nPair p2 string is "<<p2.first;
    student s1 = p2.second;
    s1.out();
}
