#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited,int r,int c,int row,int col)
{
    if (r<0 || r>=row || c<0 || c>=col)
    return;

    if (visited[r][c] || grid[r][c]==0)
    return;

    visited[r][c]=true;

    dfs(grid,visited,r-1,c,row,col);//up
    dfs(grid,visited,r+1,c,row,col);//down
    dfs(grid,visited,r,c-1,row,col);//left
    dfs(grid,visited,r,c+1,row,col);//right
}

int countIslands(vector<vector<int>> &grid)
{
    int row=grid.size();
    if (row==0) 
    return 0;

    int col=grid[0].size();

    vector<vector<bool>> visited(row,vector<bool>(col,false));
    int count=0;

    for (int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
            if (grid[i][j]==1 && !visited[i][j])
            {
                dfs(grid,visited,i,j,row,col);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    cout<<"Enter the number of rows and columns: ";
    int row,col;
    cin>>row>>col;
    vector<vector<int>>grid(row, vector<int>(col));

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        cin>>grid[i][j];
    }
    int result=countIslands(grid);
    cout<<"Total islands: "<<result<<endl;

    return 0;
}
