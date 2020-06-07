#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class graph
{
    int vertex;
    vector <int> *adj;
public:
    graph(int vertex=4)
    {
        this->vertex=vertex;
        adj=new vector<int> [vertex];
    }
    void edge(int a,int b)
    {
        adj[a].push_back(b);
        //adj[b].push_back(a);
    }
    void dfs(int node)
    {
        bool *visited;
        visited=new bool [vertex];
        for (int i=0;i<=vertex-1;i++)
            visited[i]=false;
        stack <int> stk;
        stk.push(node);
        visited[node]=true;
        while(!stk.empty())
        {
            int top=stk.top();
            cout<<top<<" ";
            stk.pop();
            vector <int> :: iterator it=adj[top].begin();
            while(it!=adj[top].end())
            {
                if (!visited[*it])
                    stk.push(*it);
                    visited[*it]=true;
                it++;
            }
        }
    }
    void show()
    {
        for(int i=0;i<=vertex-1;i++)
        {
            cout<<"\n"<<i<<" ";
            vector<int> :: iterator it=adj[i].begin();
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
    g.edge(3,3);
    g.dfs(0);
    g.show();
}
