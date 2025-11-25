#include<iostream>
#include<unordered_set>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};
Node* insertEnd(Node* head,int data) 
{
    if (head==nullptr) 
    return (new Node(data));

    Node* temp=head;
    while(temp->next!=nullptr) 
    temp=temp->next;

    temp->next=new Node(data);
    return head;
}
Node *getUnion(Node *head1,Node *head2)
{
    unordered_set<int> s;
    Node *head=nullptr;
    Node *curr=head1;
    while(curr!=nullptr)
    {
        if(s.insert(curr->data).second==true)
        head=insertEnd(head,curr->data);

        curr=curr->next;
    }
    curr=head2;
    while(curr!=nullptr)
    {
        if(s.insert(curr->data).second==true)
        head=insertEnd(head,curr->data);

        curr=curr->next;
    }
    return head;
}
Node *getIntersection(Node *head1,Node *head2)
{
    unordered_set<int> s;
    Node *head=nullptr;
    Node *curr=head1;
    while(curr!=nullptr)
    {
        s.insert(curr->data);
        curr=curr->next;
    }
    curr=head2;
    while(curr!=nullptr)
    {
        if(s.count(curr->data))
        head=insertEnd(head,curr->data);

        curr=curr->next;
    }
    return head;
}
void printList(Node* head) 
{
    while (head) 
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
    int len1,len2;
    cout<<"Enter the length of first linked List: ";
    cin>>len1;
    cout<<"Enter the length of second linked List: ";
    cin>>len2;

    Node *head1=nullptr;
    Node *head2=nullptr;
    cout<<"Enter the elements of first LinkedList: ";
    for(int i=0;i<len1;i++)
    {
        int num;
        cin>>num;
        head1=insertEnd(head1,num);
    }
    cout<<"Enter the elements of second LinkedList: ";
    for(int i=0;i<len2;i++)
    {
        int num;
        cin>>num;
        head2=insertEnd(head2,num);
    }   
    Node *unionList=getUnion(head1,head2);
    Node *interList=getIntersection(head1,head2); 

    cout<<"Union List: ";
    printList(unionList);
    cout<<"Intersection List: ";
    printList(interList);
    return 0;
}
