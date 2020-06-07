#include<iostream>
using namespace std;
int TOH(int n,char pegA,char pegB,char pegC)
{
    ///If only 1 plate,move from pegA to pegC.
    if (n==1)
    {
        cout<<"\n"<<pegA<<"---->"<<pegC;
        return(0);
    }
    ///Move n-1 plates from pegA to pegB
    TOH(n-1,pegA,pegC,pegB);
    ///Move last plate from pegA to pegC
    cout<<"\n"<<pegA<<"---->"<<pegC;
    ///Move n-1 plates from pegB to pegC
    TOH(n-1,pegB,pegA,pegC);
}
int main()
{
    char pegA='A',pegB='B',pegC='C';
    int n;
    cout<<"\n  |   \t   |   \t   |     ";
    cout<<"\n  |   \t   |   \t   |     ";
    cout<<"\n  |   \t   |   \t   |     ";
    cout<<"\n----- \t ----- \t -----   ";
    cout<<"\n  A   \t   B   \t   C     ";

    cout<<"\n\nEnter number of plates - ";
    cin>>n;
    TOH(n,pegA,pegB,pegC);

}
