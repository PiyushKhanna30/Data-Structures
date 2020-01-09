#include<iostream>
#include<string>
#include<tuple>
using namespace std;
int main()
{
    tuple <int,string,string> t1;
    t1=make_tuple(1,"India","Delhi");
    cout<<"\n"<<get<0>(t1)<<" "<<get<1>(t1)<<" "<<get<2>(t1);
}
