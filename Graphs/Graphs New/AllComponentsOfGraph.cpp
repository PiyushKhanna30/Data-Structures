#include<bits/stdc++.h>
using namespace std;
void allComponents_help(int **adj,int v,int sv,bool* visited)
{
    visited[sv]=true;
    cout<<sv;
    for(int i=0;i<v;i++)
    {
        if(i==sv)
            continue;
        if(adj[sv][i]==1 && visited[i]==false)
        {
            visited[i]=true;
            cout<<",";
            allComponents_help(adj,v,i,visited);
        }
    }
}
void allComponents(int **adj,int v)
{
    bool *visited=new bool[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    cout<<"Components are : "<<endl;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            cout<<"< ";
            allComponents_help(adj,v,i,visited);
            cout<<" >";
        }
    }
    delete []visited;
}
int main()
{
    int **adj;
    int v,e;
    cin>>v>>e;
    adj=new int*[v];
    for(int i=0;i<v;i++)
    {
        adj[i]=new int [v];
    }
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
            adj[i][j]=0;
    }

    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a][b]=1;
        adj[b][a]=1;
    }
    allComponents(adj,v);
}
