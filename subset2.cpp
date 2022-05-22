#include<bits/stdc++.h>
using namespace  std;
class Solution {
public:
    
    void func(vector<vector<int>> &ans, vector<int> &temp, int ind,vector<int> &nums)
    {
        
        
        if(ind < 0)
        {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[ind]);
        func(ans,temp,ind-1,nums);
        temp.pop_back();
        if(ind>0)
        {
            for(int i = ind-1;i>=0;i--)
             {
                if(nums[i]!=nums[ind]) 
                {
                    cout<<nums[i]<<" "<<nums[ind]<<endl;
                    // cout<<"hgkjhgkh"<<endl;
                    func(ans,temp,i,nums);
                    break;
                }
                if(i==0) func(ans,temp,i-1,nums);
             }
        }
        
        else
        {
             func(ans,temp,ind-1,nums);
        }
       
    }
    
    
void func(vector<vector<int>> &ans, vector<int> &temp, int ind,vector<int> &nums)
{
     ans.push_back(temp);
    for(int i = ind;i<nums.size();i++)
    {
        if(i!=ind && nums[i] == nums[i-1]) continue;
        
        temp.push_back(nums[i]);
        
        func(ans,temp,i+1,nums);
        
        temp.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        func(ans,temp,0,nums);
        return ans;
        
    }
};