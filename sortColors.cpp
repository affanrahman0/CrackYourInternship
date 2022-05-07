#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int mid =0,low=0,n= nums.size();
        int high = n-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                mid++;
                low++; 
            }
            else if(nums[mid]==1)
            {
                //swap(nums[mid],nums[low]);
                mid++;
                //low++; 
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};