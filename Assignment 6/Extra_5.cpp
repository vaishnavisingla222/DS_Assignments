#include<iostream>
#include<vector>
using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;
    Node(int val)
    {
        data=val;
        prev=nullptr;
        next=nullptr;
        up=nullptr;
        down=nullptr;
    }
};
Node* constructGrid(vector<vector<int>>& matrix)
{
    int row=(int)matrix.size();
    if(row==0)
    return nullptr;

    int col=(int)matrix[0].size();
    if (col==0)
    return nullptr;

    vector<vector<Node*>> nodes(row, vector<Node*>(col, nullptr)); 
    for (int i=0;i<row;i++) 
    {
        for (int j=0;j<col;j++) 
        {
            nodes[i][j]=new Node(matrix[i][j]);
            
            if (j>0)//link to left
            {
                nodes[i][j]->prev=nodes[i][j-1];
                nodes[i][j-1]->next=nodes[i][j];
            }
            if (i>0)//link to top
            {
                nodes[i][j]->up=nodes[i-1][j];
                nodes[i-1][j]->down=nodes[i][j];
            }
        }
    }
    return nodes[0][0];
}
int main()
{
    int row,col;
    cout<<"Enter the number of rows and columns: ";
    cin>>row>>col;
    
    vector<vector<int>> matrix(row, vector<int>(col));
    cout<<"Enter the values of matrix:\n";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        cin>>matrix[i][j];
    }
    Node* head=constructGrid(matrix);
    
    Node* rPtr;//pointer to move right
    Node* dPtr=head;// pointer to move down

    cout<<"Grid of doubly linked list: \n";
    while (dPtr!=nullptr) 
    {
        rPtr=dPtr;
        while (rPtr->next!=nullptr) 
        {
            cout<<rPtr->data<<" <-> ";
            rPtr=rPtr->next;
        }
        cout<<rPtr->data<<" -> NULL\n";
        dPtr=dPtr->down;
    }
    return 0;
}
