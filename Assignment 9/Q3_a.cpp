#include<iostream>
#include<vector>
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
void createGraph(vector<Edge> &graph)
{
    graph.push_back(Edge(0,1,2));
    graph.push_back(Edge(0,2,4));
    graph.push_back(Edge(1,2,1));
    graph.push_back(Edge(1,3,7));
    graph.push_back(Edge(2,4,3));
    graph.push_back(Edge(3,4,5));
}
void sortByWeight(vector<Edge> &edges)
{
    int len=edges.size();
    for (int i=0; i<len-1;i++)
    {
        for (int j=0;j<len-1-i;j++)
        {
            if (edges[j].weight>edges[j+1].weight)
            {
                Edge temp=edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=temp;
            }
        }
    }
}
int findParent(vector<int> &parent,int node)
{
    if (parent[node]==node)
        return node;

    return parent[node]=findParent(parent,parent[node]);
}
void unionSet(vector<int> &parent,vector<int> &rank,int u,int v)
{
    int parentU=findParent(parent,u);
    int parentV=findParent(parent,v);
    if (parentU==parentV)
        return;

    if (rank[parentU]<rank[parentV])
    parent[parentU]=parentV;

    else if (rank[parentU]>rank[parentV])
    parent[parentV]=parentU;
        
    else
    {
        parent[parentV]=parentU;
        rank[parentU]++;
    }
}
void kruskal(vector<Edge> &edges, int vertex)
{
    sortByWeight(edges);
    vector<int> parent(vertex);
    vector<int> rank(vertex, 0);
    for (int i=0;i<vertex;i++)
        parent[i]=i;

    vector<Edge> mst;
    int mstWeight=0;

    for (auto &edge:edges)
    {
        int u=edge.src;
        int v=edge.dest;
        int parentU=findParent(parent, u);
        int parentV=findParent(parent, v);
        if (parentU!=parentV)
        {
            mst.push_back(edge);
            mstWeight+=edge.weight;
            unionSet(parent,rank,parentU,parentV);
        }
    }
    cout<<"Kruskal's MST edges:\n";
    for (auto &e:mst)
    cout<<e.src<<" to "<<e.dest<<" -> weight="<< e.weight<<endl;

    cout<<"Total weight of MST="<<mstWeight<<endl;
}
int main() 
{
    int vertex=5;
    vector<Edge> graph;
    createGraph(graph);
    kruskal(graph,vertex);
    return 0;
}
