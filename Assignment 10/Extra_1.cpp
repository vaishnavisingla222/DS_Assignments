#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<int,int>freq;
    int size;
    int maxFreq,maxNum;
    cout<<"Enter the size of the array: ";
    cin>>size;

    int nums[size];
    cout<<"Enter the ellements: ";
    for(int i=0;i<size;i++)
    cin>>nums[i];

    for(int i=0;i<size;i++)
    freq[nums[i]]++;

    maxFreq=freq[nums[0]];
    maxNum=nums[0];
    for(int i=0;i<size;i++)
    {
        if(freq[nums[i]]>maxFreq)
        {
            maxFreq=freq[nums[i]];
            maxNum=nums[i];
        }
        else if(freq[nums[i]]==maxFreq)
        {
            if(nums[i]>maxNum)
            {
                maxFreq=freq[nums[i]];
                maxNum=nums[i];
            }
        }
    }
    cout<<"The number which appears most frequently: "<<maxNum<<endl;
    return 0;
}
