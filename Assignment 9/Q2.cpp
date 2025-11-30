#include <iostream>
#include <vector>
using namespace std;

class Edge 
{
    public:
    int src;
    int dest;

    Edge(int s, int d) 
    {
        src=s;
        dest=d;
    }
};

void createGraph(vector<Edge> graph[], int vertex) 
{
    graph[0].push_back(Edge(0, 2));

    graph[1].push_back(Edge(1, 2));
    graph[1].push_back(Edge(1, 3));

    graph[2].push_back(Edge(2, 0));
    graph[2].push_back(Edge(2, 1));
    graph[2].push_back(Edge(2, 3));

    graph[3].push_back(Edge(3, 1));
    graph[3].push_back(Edge(3, 2));
}

void dfs(vector<Edge> graph[], vector<bool> &visited, int curr) 
{
    cout<<curr<<" ";
    visited[curr]=true;

    for (auto &edge : graph[curr]) 
    {
        if (!visited[edge.dest])
            dfs(graph, visited, edge.dest);
    }
}

int main() 
{
    int vertex=4;
    vector<Edge> graph[vertex];

    createGraph(graph, vertex);

    cout<<"DFS Traversal: ";
    vector<bool> visited(vertex, false);
    dfs(graph,visited,0);

    // For broken graph use this instead:
    /*
    for (int i=0;i<vertex;i++) 
    {
        if (!visited[i])
            dfs(graph, visited, i);
    }
    */
    cout<<endl;
    return 0;
}
