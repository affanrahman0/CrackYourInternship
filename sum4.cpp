#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
       int n = nums.size();
        
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int l = j+1,h = n-1,tar = target - (nums[i] + nums[j]);
                
                while(l<h)
                {
                    if(tar == nums[l] + nums[h])
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[h]);
                        
                        ans.push_back(temp);
                        
                        while(l<h && nums[l] == nums[l+1]) l++;
                        while(l<h && nums[h]==nums[h-1]) h--;
                        
                        l++;
                        h--;
                        
                    }
                    else if(tar > nums[l] + nums[h]) l++;
                    else h--;
                }
                
                while(j<n-3 && nums[j]==nums[j+1]) j++;
            }
            
            while(i < n-4 && nums[i]==nums[i+1]) i++;
        }
        
        return ans;
    }
};