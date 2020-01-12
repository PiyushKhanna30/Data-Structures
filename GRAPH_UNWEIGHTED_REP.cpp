#include<iostream>
#include<vector>
using namespace std;
void edge(vector <int> adj[],int a,int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}
void show(vector <int> adj[],int V)
{
    for(int i=0;i<=V-1;i++)
    {
        cout<<"\n"<<i<<" -->";
        vector <int> ::iterator it=adj[i].begin();
        while (it!=adj[i].end())
        {
            cout<<" "<<*it;
            it++;
        }
    }
}
int main()
{
    int V=5;
    vector <int> adj[V];
    edge(adj,0,1);
    edge(adj,0,4);
    edge(adj,1,2);
    edge(adj,1,3);
    edge(adj,1,4);
    edge(adj,2,3);
    edge(adj,3,4);
    show(adj,V);

}
