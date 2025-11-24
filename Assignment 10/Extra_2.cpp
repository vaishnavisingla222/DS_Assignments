#include<iostream>
#include<unordered_set>
using namespace std;

bool pairSum(int arr[],int size,int target)
{
    unordered_set<int> s;
    for(int i=0;i<size;i++)
    {
        int second=target-arr[i];
        if(s.find(second)!=s.end())
        {
            cout<<"Pair: "<<arr[i]<<" & "<<second<<endl;
            return true;
        }
        s.insert(arr[i]);
    }
    return false;
}
int main()
{
    int size,target;
    int maxFreq,maxNum;
    cout<<"Enter the size of the array: ";
    cin>>size;

    int nums[size];
    cout<<"Enter the ellements: ";
    for(int i=0;i<size;i++)
    cin>>nums[i];

    cout<<"Enter the targeted sum: ";
    cin>>target;

    if(!pairSum(nums,size,target))
    cout<<"No pair found\n";

    return 0;
}
