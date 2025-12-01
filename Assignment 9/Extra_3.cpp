#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Edge 
{
public:
    int src;
    int dest;
    int weight;
    Edge(int s, int d, int w) 
    {
        src=s;
        dest=d;
        weight=w;
    }
};
int networkTime(vector<Edge> graph[],int nodes,int start) 
{
    vector<int> dist(nodes+1,INT_MAX);
    vector<bool> visited(nodes+1,false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[start]=0;
    pq.push({0,start});
    while (!pq.empty()) 
    {
        int curr=pq.top().second;
        int currDist=pq.top().first;
        pq.pop();

        if (visited[curr]) 
        continue;

        visited[curr]=true;

        for (auto &edge:graph[curr]) 
        {
            int v=edge.dest;
            int w=edge.weight;

            if (dist[curr]+w<dist[v]) 
            {
                dist[v]=dist[curr]+w;
                pq.push({dist[v],v});
            }
        }
    }

    int maxTime=0;
    for (int i=1;i<=nodes;i++) 
    {
        if (dist[i]==INT_MAX) 
        return -1;//unreachable node
    
        maxTime=max(maxTime,dist[i]);
    }
    return maxTime;
}

int main() 
{
    int nodes,edges,start;
    cout<<"Enter nubmer of nodes and edges: ";
    cin>>nodes>>edges;
    cout<<"Enter the start node: ";
    cin>>start;

    vector<Edge>graph[nodes+1];
    cout<<"Enter the nodes of edge and then its weight:\n";
    for (int i=0; i<edges;i++) 
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(Edge(u,v,w));
    }
    int ans=networkTime(graph,nodes,start);

    if(ans!=-1)
    cout<<"Total time: "<<ans<<endl;

    else
    cout<<"All nodes are not able to reach.\n";
    return 0;
}
