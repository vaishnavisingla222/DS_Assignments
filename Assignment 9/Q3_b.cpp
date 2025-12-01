#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
class Edge 
{
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
void createGraph(vector<Edge> &graph)
{
    graph.push_back(Edge(0,1,2));
    graph.push_back(Edge(0,2,4));
    graph.push_back(Edge(1,2,1));
    graph.push_back(Edge(1,3,7));
    graph.push_back(Edge(2,4,3));
    graph.push_back(Edge(3,4,5));
}
void primAlgo(vector<Edge> &edges,int vertex)
{
    vector<vector<pair<int,int>>> adj(vertex);
    for (auto &e:edges)
    {
        adj[e.src].push_back({e.dest, e.weight});
        adj[e.dest].push_back({e.src, e.weight});
    }

    int start=0;
    vector<int> key(vertex,INT_MAX);
    vector<int> parent(vertex,-1);
    vector<bool> inMST(vertex,false); 

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    key[start]=0;
    pq.push({0,start});

    while (!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if (inMST[u])
        continue; 

        inMST[u]=true;
        for (auto &p:adj[u])
        {
            int v=p.first;
            int wt=p.second;
            if (!inMST[v] && wt<key[v])
            {
                key[v]=wt;
                parent[v]=u;
                pq.push({key[v], v});
            }
        }
    }
    cout<<"Prim's MST edges:\n";
    int totalWeight=0;
    for (int v=0;v<vertex;v++)
    {
        if (parent[v]!=-1)
        {
            cout<<parent[v]<<" to "<<v<<" -> weight="<<key[v]<<endl;
            totalWeight+=key[v];
        }
    }
    cout<<"Total weight of MST="<<totalWeight<<endl;
}
int main() 
{
    int vertex=5;
    vector<Edge> graph;
    createGraph(graph);
    primAlgo(graph,vertex);
    return 0;
}
