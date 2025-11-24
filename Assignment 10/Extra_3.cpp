#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<int,int> freq1,freq2;
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    int nums1[size],nums2[size];
    cout<<"Enter the ellements of first array: ";
    for(int i=0;i<size;i++)
    cin>>nums1[i];
    cout<<"Enter the ellements of second array: ";
    for(int i=0;i<size;i++)
    cin>>nums2[i];

    for(int i=0;i<size;i++)
    {
        freq1[nums1[i]]++;
        freq2[nums2[i]]++;
    }
    if(freq1==freq2)
    cout<<"They are equal\n";
    else
    cout<<"They are not equal\n";

    return 0;
}
