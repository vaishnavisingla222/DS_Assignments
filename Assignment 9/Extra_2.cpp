#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
class Node 
{
public:
    int row;
    int col;
    int cost;
    Node(int r,int c,int w) 
    {
        row=r;
        col=c;
        cost=w;
    }
};
struct Compare 
{
    bool operator()(const Node &a,const Node &b) 
    {
        return a.cost>b.cost;//smaller cost=higher priority
    }
};
int dijkstraGrid(vector<vector<int>> &grid) 
{
    int row=grid.size();
    int col=grid[0].size();

    vector<vector<int>> dist(row,vector<int>(col,INT_MAX));

    priority_queue<Node,vector<Node>,Compare> pq;

    dist[0][0]=grid[0][0];
    pq.push(Node(0,0,grid[0][0]));

    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};

    while (!pq.empty()) 
    {
        Node curr=pq.top();
        pq.pop();

        int r=curr.row;
        int c=curr.col;
        int currCost=curr.cost;

        if (currCost>dist[r][c])
        continue;

        if (r==row-1 && c==col-1)
        return currCost;

        for (int k=0;k<4;k++) 
        {
            int nr=r+dr[k];
            int nc=c+dc[k];

            if (nr>=0 && nr<row && nc>=0 && nc<col) 
            {
                int newCost=currCost+grid[nr][nc];
                if (newCost<dist[nr][nc])
                {
                    dist[nr][nc]=newCost;
                    pq.push(Node(nr,nc,newCost));
                }
            }
        }
    }
    return dist[row-1][col-1];
}
int main() 
{
    int r,c;
    cout<<"Enter the size of the matrix: ";
    cin>>r>>c;
    vector<vector<int>> grid(r,vector<int>(c));
    cout<<"Enter the matrix value:\n";
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        cin>>grid[i][j];
    }
    int ans=dijkstraGrid(grid);
    cout<<"Minimum cost: "<<ans<<endl;
    return 0;
}
