#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Edge {
public:
    int src;
    int dest;
    int weight;
    Edge(int s,int d,int w) 
    {
        src=s;
        dest=d;
        weight=w;
    }
};

void createGraph(vector<Edge> graph[]) 
{
    graph[0].push_back(Edge(0,1,2));
    graph[0].push_back(Edge(0,2,4));

    graph[1].push_back(Edge(1,0,2));
    graph[1].push_back(Edge(1,3,7));
    graph[1].push_back(Edge(1,2,1));

    graph[2].push_back(Edge(2,0,4));
    graph[2].push_back(Edge(2,1,1));
    graph[2].push_back(Edge(2,4,3));

    graph[3].push_back(Edge(3,1,7));
    graph[3].push_back(Edge(3,4,5));

    graph[4].push_back(Edge(4,2,3));
    graph[4].push_back(Edge(4,3,5));
}

void dijkstra(vector<Edge> graph[], int vertex, int src) 
{
    vector<int> dist(vertex, INT_MAX);
    dist[src]=0;

    //Min Heap(distance,node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) 
    {
        int curr=pq.top().second;
        int currDist=pq.top().first;
        pq.pop();

        if(currDist>dist[curr])
            continue;

        
        for (int i=0;i<graph[curr].size();i++) 
        {
            Edge &edge=graph[curr][i];
            int u=edge.src;
            int v=edge.dest;
            int w=edge.weight;

            if (dist[u]+w<dist[v]) 
            {
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    cout << "Shortest distances:"<<endl;
    for (int i=0;i<vertex;i++)
        cout<<src<<" to "<<i<<" -> "<<dist[i]<<endl;
}

int main() 
{
    int vertex=5;
    int source;
    vector<Edge> graph[vertex];
    cout<<"Enter source node: ";
    cin>>source;
    
    createGraph(graph);
    dijkstra(graph,vertex,source);
    return 0;
}
