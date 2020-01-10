#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector <int> v1;
    vector <int> v2={1,2,3};

    cout<<"\nCurrent capacity and size of v1 : "<<v1.capacity()<<","<<v1.size();
    v1.push_back(15);
    v1.push_back(11);
    v1.push_back(19);
    v1.push_back(49);
    v1.push_back(429);
    cout<<"\nCurrent capacity and size of v1 : "<<v1.capacity()<<","<<v1.size();
    v1.pop_back();

    cout<<"\nElemens of v1 using [] "<<v1[0]<<" "<<v1[1];

    cout<<"\nAt location 2 : "<<v1.at(2);

    cout<<"\nNow insertion at index 2 value 100 using iterators.";
    vector<int>::iterator i=v1.begin();
    v1.insert(i+2,100);

    cout<<"\nFront : "<<v1.front()<<"\nBack : "<<v1.back();

    vector <int> ::iterator it=v1.begin();
    cout<<"\nElements of v1 are : ";
    while (it!=v1.end())
    {
        cout<<" "<<*it;
        it++;
    }

    vector <int> ::iterator it2=v2.begin();
    cout<<"\nElements of v2 are : ";
    while (it2!=v2.end())
    {
        cout<<" "<<*it2;
        it2++;
    }
    v2.clear();                                                             ///Clear all the v2 dynamic array.
}
