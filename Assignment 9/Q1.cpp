#include <iostream>
#include <vector>
#include <queue>
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
    graph[0].push_back(Edge(0, 1));

    graph[1].push_back(Edge(1, 0));
    graph[1].push_back(Edge(1, 3));

    graph[2].push_back(Edge(2, 0));
    graph[2].push_back(Edge(2, 4));

    graph[3].push_back(Edge(3, 4));
    graph[3].push_back(Edge(3, 1));
    graph[3].push_back(Edge(3, 5));

    graph[4].push_back(Edge(4, 2));
    graph[4].push_back(Edge(4, 3));
    graph[4].push_back(Edge(4, 5));

    graph[5].push_back(Edge(5, 3));
    graph[5].push_back(Edge(5, 4));
    graph[5].push_back(Edge(5, 6));

    graph[6].push_back(Edge(6, 5));
}

void bfs(vector<Edge> graph[], int vertex, vector<bool> &visited, int start) 
{
    queue<int> q;
    q.push(start);

    while (!q.empty()) 
    {
        int curr=q.front();
        q.pop();
        if (!visited[curr])
        {
            cout<<curr<<" ";
            visited[curr]=true;
            for (auto &edge:graph[curr])
                q.push(edge.dest);
        }
    }
}

int main() 
{
    int vertex=7;
    vector<Edge> graph[vertex];

    createGraph(graph,vertex);

    cout<<"BFS Traversal: ";
    vector<bool>visited(vertex,false);

    for (int i=0;i<vertex;i++) 
    {
        if (!visited[i])
            bfs(graph, vertex, visited, i);
    }

    cout<<endl;
    return 0;
}
