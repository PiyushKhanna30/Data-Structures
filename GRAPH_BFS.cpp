#include<iostream>
#include<vector>
#include<list>
using namespace std;
class graph
{
    int vertex;
    vector <int> *adj;
public:
    graph(int v=4)
    {
        ///cout<<"\nEnter number of vertex : ";
        ///cin>>v;
        vertex=v;
        adj = new vector <int> [v];
    }
    void edge(int a,int b)
    {
        adj[a].push_back(b);
    }
    void bfs(int s)
    {
        cout<<"\n";
        bool *visited;
        visited=new bool [vertex];
        for(int i=0;i<=vertex-1;i++)
            visited[i]=false;

        list <int> que;
        que.push_back(s);
        visited[s]=true;
        while(!que.empty())
        {
            int node=que.front();
            cout<<node<<" ";
            que.pop_front();
            vector <int>::iterator it=adj[node].begin();
            while(it!=adj[node].end())
            {
                if(!visited[*it])
                {
                    visited[*it]=true;
                    que.push_back(*it);
                }
                it++;
            }
        }
    }
    void show()
    {
        cout<<"\nAdjacency list is : ";
        for(int i=0;i<=vertex-1;i++)
        {
            cout<<"\n "<<i;
            vector <int>::iterator it=adj[i].begin();
            while(it!=adj[i].end())
            {
                cout<<"->"<<*it;
                it++;
            }
        }
    }
};
int main()
{
    graph g;

    g.edge(0,1);
    g.edge(0,2);
    g.edge(1,2);
    g.edge(2,0);
    g.edge(2,3);
    g.show();
    g.bfs(2);

}
