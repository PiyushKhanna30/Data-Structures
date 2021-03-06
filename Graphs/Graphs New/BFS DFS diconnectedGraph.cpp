#include<bits/stdc++.h>
using namespace std;

void printDFS_help(int **adj,int v,int sv,bool* visited)
{
    visited[sv]=true;
    cout<<sv<<endl;
    for(int i=0;i<v;i++)
    {
        if(i==sv)
            continue;
        if(adj[sv][i]==1 && visited[i]==false)
        {
            visited[i]=true;
            printDFS_help(adj,v,i,visited);
        }
    }
}
void printDFS(int **adj,int v,int sv)
{
    bool *visited=new bool[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    cout<<"DFS"<<endl;
    printDFS_help(adj,v,sv,visited);
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
            printDFS_help(adj,v,i,visited);
    }
}
void printBFS_help(int **adj,int v,int sv,bool *visited)
{
    visited[sv]=true;
    queue<int>q;
    q.push(sv);
    while(q.empty()==false)
    {
        int cur=q.front();
        cout<<cur<<endl;
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
}
void printBFS(int **adj,int v,int sv)
{
    bool *visited=new bool[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    cout<<"BFS"<<endl;
    printBFS_help(adj,v,sv,visited);
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
            printBFS_help(adj,v,i,visited);
    }

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
    printDFS(adj,v,0);
    printBFS(adj,v,0);
}
