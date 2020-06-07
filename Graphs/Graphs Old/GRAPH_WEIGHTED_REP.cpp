#include<iostream>
#include<vector>
using namespace std;

class graph
{
    int vertex;
    vector <pair<int,int>> *adj;
public:
    graph(int vertex=5)
    {
        //2int vertex;
        //cout<<"\nEnter number of vertex : ";
        //cin>>vertex;
        this->vertex=vertex;
        adj=new vector<pair<int,int>> [vertex];
    }
    void edge(int v1,int v2,int wt)
    {
        adj[v1].push_back(make_pair(v2,wt));
        adj[v2].push_back(make_pair(v1,wt));
    }
    void show()
    {
        cout<<"\nAdjacency list is : \n";
        for(int i=0;i<=vertex-1;i++)
        {
            cout<<"\n"<<i;
            vector <pair<int,int>> :: iterator it=adj[i].begin();
            while(it!=adj[i].end())
            {
                int v=it->first;
                int w=it->second;
                cout<<"-> "<<v<<"("<<w<<")";
                it++;
            }
        }
    }
};
int main()
{
    graph g;
    g.edge(0, 1, 10);
    g.edge(0, 4, 20);
    g.edge(1, 2, 30);
    g.edge(1, 3, 40);
    g.edge(1, 4, 50);
    g.edge(2, 3, 60);
    g.edge(3, 4, 70);
    g.show();
}

