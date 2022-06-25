
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func(vector<int>& nums,int in,vector<int>& dp)
    {
        int index = in;
       if(index >= nums.size()) return 0;
       if(dp[in]!=-1) return dp[in]; 
        int cur = nums[index];
        
        int ans = nums[index];
        index++;
        for(int i=index;i<nums.size() && (ans == nums[index]) ;i++)
        {
            cur+= nums[index];
            index++;
        }
        for(int i=index;i<nums.size() && ((ans+1) == nums[index]) ;i++)
        {
            //cur+= nums[index];
            index++;
        }
        cout<<cur<<endl;
        return dp[in]=max(cur+func(nums,index,dp),func(nums,in+1,dp));
        
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),-1);
        return func(nums,0,dp);
    }
};