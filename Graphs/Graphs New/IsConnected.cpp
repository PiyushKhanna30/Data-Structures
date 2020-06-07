#include<bits/stdc++.h>
using namespace std;

bool isConnected(int **adj,int v,int sv)
{
    bool *visited=new bool[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    visited[sv]=true;
    queue<int>q;
    q.push(sv);
    while(q.empty()==false)
    {
        int cur=q.front();
        q.pop();
        for(int i=0;i<v;i++)
        {
            if(cur==i)
                continue;
            if(adj[cur][i]==1 && visited[i]==false)
            {
                visited[i]=true;
                q.push(i);
            }
        }
    }
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
            return false;
    }
    return true;
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
    int sv=0;
    cout<<isConnected(adj,v,sv);
}
