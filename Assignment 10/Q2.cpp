#include <iostream>
#include <unordered_set>
using namespace std;

int main() 
{
    int size1,size2;
    cout<<"Enter size of first array: ";
    cin>>size1;
    int arr1[size1];

    cout<<"Enter elements of first array: ";
    for (int i=0;i<size1;i++)
    cin>>arr1[i];

    cout<<"Enter size of second array: ";
    cin>>size2;
    int arr2[size2];

    cout<<"Enter elements of second array: ";
    for (int i=0;i<size2;i++)
    cin>>arr2[i];

    unordered_set<int> s;
    for (int i=0;i<size1;i++)
    s.insert(arr1[i]);

    cout<<"Common elements: ";
    for (int i=0;i<size2;i++) 
    {
        if (s.find(arr2[i])!=s.end())
        cout<<arr2[i]<<" ";
    }

    cout<<endl;
    return 0;
}
