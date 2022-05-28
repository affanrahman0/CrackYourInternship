#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        for(int i=0;i<n-2;i++)
        {
            if(i==0 || nums[i]!=nums[i-1])
            {
                int l = i+1,h=n-1,tar = - nums[i];
                while(h>l)
                {
                    if(nums[l]+nums[h]==tar)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[h]);
                        ans.push_back(temp);
                        
                        while(l<h  && nums[l]==nums[l+1]) l++;
                        while(l<h && nums[h]==nums[h-1]) h--;
                        l++;
                        h--;
                       
                    }
                    else if(tar>nums[l]+nums[h]) l++;
                    else h--;
                }
            }
            
        }
        return ans;
    }
};