#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<int,int>freq;
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    int nums[size];
    cout<<"Enter the ellements: ";
    for(int i=0;i<size;i++)
    cin>>nums[i];

    for(int i=0;i<size;i++)
    freq[nums[i]]++;

    cout<<"Freqencies: \n";
    for(auto &p: freq)
    cout<<p.first<<" -> "<<p.second<<endl;

    return 0;
}
