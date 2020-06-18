#include<bits/stdc++.h>
using namespace std;

int findMinIndex(int *distance,bool *visited,int n_vertices)
{
    int min_weight_index=-1;
    for(int i=0;i<n_vertices;i++)
    {
        if(visited[i]==false && (min_weight_index==-1||distance[min_weight_index] > distance[i]))
        {
            min_weight_index=i;
        }
    }
    return min_weight_index;
}
void dijkstra(int **Edges,int n_vertices)
{
    int *distance;
    bool *visited;
    distance=new int [n_vertices];
    visited=new bool [n_vertices];
    for(int i=0;i<n_vertices;i++)
    {
        distance[i]=INT_MAX;
        visited[i]=false;
    }
    ///Set distance from vertex 0 as 0 or marking as starting vertex
    distance[0]=0;
    for(int i=0;i<n_vertices;i++)
    {
        int min_weight_index=findMinIndex(distance,visited,n_vertices);
        visited[min_weight_index]=true;
        for(int j=0;j<n_vertices;j++)
        {
            if(visited[j]==false && Edges[min_weight_index][j]!=0 && distance[j]>distance[min_weight_index]+Edges[min_weight_index][j])
            {
                distance[j]=distance[min_weight_index]+Edges[min_weight_index][j];
            }
        }
    }

    ///Printing result
    for(int i=0;i<n_vertices;i++)
    {
        cout<<i<<"         "<<distance[i]<<endl;
    }
    delete []distance;
    delete []visited;
}
int main()
{
    int n_vertices,n_edges;
    cin>>n_vertices>>n_edges;
    int **Edges;
    Edges=new int *[n_vertices];
    for(int i=0;i<n_vertices;i++)
    {
        Edges[i]=new int[n_vertices];
        for(int j=0;j<n_vertices;j++)
        {
            ///setting initial values as 0
            Edges[i][j]=0;
        }
    }
    ///Taking input from user
    for(int i=0;i<n_edges;i++)
    {
        int a,b,weight;
        cin>>a>>b>>weight;
        Edges[a][b]=weight;
        Edges[b][a]=weight;
    }
    dijkstra(Edges,n_vertices);
    for(int i=0;i<n_vertices;i++)
    {
        delete []Edges[i];
    }
    delete [] Edges;
}
/**
Input
9   14
0   1   4
0   7   8
1   2   8
1   7   11
2   3   7
2   8   2
2   5   4
3   4   9
3   5   14
4   5   10
5   6   2
6   8   6
6   7   1
7   8   7

Output
0       0
1       4
2       12
3       19
4       21
5       11
6       9
7       8
8       14
*/
