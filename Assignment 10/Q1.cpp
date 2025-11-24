#include<iostream>
#include <unordered_set>
using namespace std;

bool contaisDuplicates(int arr[],int size)
{
    unordered_set<int> s;
    for(int i=0;i<size;i++)
    {
        if(s.find(arr[i])!=s.end())
        return true;

        s.insert(arr[i]);
    }
    return false;
}
int main()
{
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int nums[size];

    cout<<"Enter the ellements: ";
    for(int i=0;i<size;i++)
    cin>>nums[i];

    if(contaisDuplicates(nums,size))
    cout<<"Array contains duplicates\n";

    else
    cout<<"Array doesn't contain duplicates\n";
}
