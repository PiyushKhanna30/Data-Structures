#include<bits/stdc++.h>
using namespace std;

vector<int>* getPathDFS_help(int **adj,int v,int a,int b,bool *visited)
{
    if(a==b)
    {
        vector<int>*ans=new vector<int>;
        ans->push_back(a);
        return ans;
    }
    visited[a]=true;
    for(int i=0;i<v;i++)
    {
        if(i==a)
            continue;
        if(adj[a][i]==1 && visited[i]==false)
        {
            visited[i]=true;
            vector<int>* small_ans=getPathDFS_help(adj,v,i,b,visited);
            if(small_ans)
            {
                small_ans->push_back(a);
                return small_ans;
            }
        }
    }
    return NULL;
}
vector<int>* getPathDFS(int **adj,int v,int a,int b)
{
    bool *visited=new bool[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    return getPathDFS_help(adj,v,a,b,visited);
}
vector<int>* getPathBFS(int **adj,int v,int a,int b)
{
    bool *visited=new bool[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    unordered_map<int,int>m;
    queue<int>q;
    q.push(a);
    visited[a]=true;
    m[a]=-1;
    while(q.empty()==false && m.find(b)==m.end())
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
                m.insert({i,cur});
                if(i==b)
                    break;
            }
        }
    }
    vector<int>*ans=new vector<int>;
    if(m.find(b)==m.end())
    {
        return ans;
    }
    else
    {
        ans->push_back(b);
        int temp=b;
        while(!m.empty() && m[temp]!=-1)
        {
            ans->push_back(m[temp]);
            temp=m[temp];
        }
    }
    return ans;
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
    int a,b;
    cin>>a>>b;
    vector<int>*out=getPathBFS(adj,v,a,b);
    for(auto i:*out)
    {
        cout<<i<<endl;
    }
}
