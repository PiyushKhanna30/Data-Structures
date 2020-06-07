#include<bits/stdc++.h>
using namespace std;

int findVertex(int *weight,bool* visited,int n)
{
    int minVertex=-1;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false && (minVertex==-1||weight[i-1]<weight[minVertex]))
        {
            minVertex=i;
        }
    }
    return minVertex;
}
void prims(int **adj,int n)
{
    int *weight=new int[n];
    int *parent=new int[n];
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        weight[i]=INT_MAX;
        visited[i]=false;
    }
    weight[0]=0;
    parent[0]=-1;

    for(int i=0;i<n-1;i++)
    {
        int minVertex=findVertex(weight,visited,n);
        visited[minVertex]=true;
        for(int j=0;j<n;j++)
        {
            if(adj[minVertex][j]!=0 && visited[j]!=true)
            {
                if(weight[j]>adj[minVertex][j])
                {
                    weight[j]=adj[minVertex][j];
                    parent[j]=minVertex;
                }

            }
        }
    }
    for(int i = 1; i < n; i++){
		if(parent[i] < i){
			cout << parent[i]<<" "<< i << " " << weight[i] << endl;
		}else{
			cout << i << " " << parent[i] << " " << weight[i] << endl;
		}
	}
}
int main()
{
    int n,e;
    cin>>n>>e;
    int **adj=new int*[n];
    for(int i=0;i<n;i++)
        adj[i]=new int [n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            adj[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int a,b,weight;
        cin>>a>>b>>weight;
        adj[a][b]=weight;
        adj[b][a]=weight;
    }
    prims(adj,n);
}
