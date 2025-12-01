#include <iostream>
#include <vector>
using namespace std;

class Edge 
{
public:
    int src;
    int dest;
    Edge(int s,int d) 
    {
        src=s;
        dest=d;
    }
};
void addEdge(vector<Edge> graph[],int u,int v) 
{
    graph[u].push_back(Edge(u,v));
    graph[v].push_back(Edge(v,u));
}

void dfs(vector<Edge> graph[], vector<bool> &visited, int curr) 
{
    visited[curr] = true;
    for (auto &edge : graph[curr]) 
    {
        int next=edge.dest;
        if (!visited[next])
        dfs(graph, visited, next);
    }
}

int countComponents(vector<Edge> graph[], int vertex) 
{
    vector<bool> visited(vertex,false);
    int count=0;

    for (int i=0;i<vertex;i++) 
    {
        if (!visited[i]) 
        {
            dfs(graph,visited,i);
            count++;
        }
    }
    return count;
}

int main() 
{
    int vertex,edge;
    cout<<"Enter numer of vertex and edges: ";
    cin>>vertex>>edge;

    vector<Edge> graph[vertex];
    cout<<"Enter the vertex values of edges:\n";
    for (int i=0;i<edge;i++) 
    {
        int u,v;
        cin>>u>>v;
        addEdge(graph,u,v);
    }
    int res=countComponents(graph,vertex);
    cout<<"Number of connected components: "<<res<<endl;
    return 0;
}
