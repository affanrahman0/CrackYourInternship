#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void recur(vector<int>& can, int tar, vector<int> temp,vector<vector<int>>& ans,int ind)
    {
        if(tar==0) 
        {
            ans.push_back(temp);
            return;
        }
        if(ind<0 || tar<0) return;
                
        temp.push_back(can[ind]);
        
        recur(can,tar-can[ind],temp,ans,ind-1);
        temp.pop_back();
        
        for(int i =ind-1;i>=0;i--)
        {
            if(can[ind]!=can[i])
            {
               recur(can,tar,temp,ans,i);
                break;
            }
        }
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int tar) {
        sort(can.begin(),can.end());
        vector<int> temp;
        vector<vector<int>> ans;
        recur(can,tar,temp,ans,can.size()-1);
        return ans;
    }
};