#include<bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int source;
    int destination;
    int weight;
};
bool compare(Edge a,Edge b)
{
    return a.weight<b.weight;
}
int findParent(int v,int *parent)
{
    if(parent[v]==v)
        return v;
    return findParent(parent[v],parent);
}
void kruskal(Edge *input,int v,int e)
{
    ///sort according to weights
    sort(input,input+e,compare);

    Edge *output=new Edge[v-1];
    int cou=0;
    int i=0;
    int *parent=new int[v];
    for(int i=0;i<v;i++)
        parent[i]=i;
    while(cou!=v-1)
    {
        Edge current_edge=input[i];
        ///check if forming loop?
        int sourceParent=findParent(current_edge.source,parent);
        int destParent=findParent(current_edge.destination,parent);
        if(sourceParent!=destParent)
        {
            output[cou]=current_edge;
            cou++;
            parent[sourceParent]=destParent;
        }
        i++;
    }

    ///Printing
    cout<<"Kruskal"<<endl;
    for(int i=0;i<v-1;i++)
    {
        if(output[i].source<output[i].destination)
            cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
        else
            cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
    }
}
int main()
{
    int v,e;
    cin>>v>>e;
    Edge *input=new Edge[e];
    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].destination=d;
        input[i].weight=w;
    }
    kruskal(input,v,e);
}
