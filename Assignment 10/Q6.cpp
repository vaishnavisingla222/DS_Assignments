#include<iostream>
#include<unordered_set>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node *right;
    Node(int data)
    {
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};
bool duplicateTree(Node *root,unordered_set<int> &visited)
{
    if(root==nullptr)
    return false;

    if(visited.find(root->data)!=visited.end())
    return true;

    visited.insert(root->data);
    return (duplicateTree(root->left,visited) || duplicateTree(root->right,visited) );
}
int main()
{
    Node* n1=new Node(1);
    Node* n2=new Node(2);
    Node* n3=new Node(3);
    Node* n4=new Node(4);
    Node* n5=new Node(3);
    Node* n6=new Node(6);

    n1->left=n2;
    n1->right=n3;
    n2->left=n4;
    n2->right=n5;
    n3->left=n6;

    unordered_set<int>visited;
    if(duplicateTree(n1,visited))
    cout<<"Duplicate exist\n";

    else
    cout<<"Duplicate not exist\n";

    return 0;
}
