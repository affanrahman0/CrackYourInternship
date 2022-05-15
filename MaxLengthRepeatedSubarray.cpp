#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m  = nums2.size();
        
      // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        vector<int> prev(m+1,0);
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            vector<int> cur(m+1,0);
            for(int j=1;j<=m;j++)
            {
               //cout<<cur[j]<<"<-"<<prev[j-1]<<"    ";
                if(nums1[i-1]==nums2[j-1])
                {
                    //cout<<nums1[i-1]<<" "<<nums2[j-1]<<endl;
                    cur[j] = prev[j-1]+1;
                }
                    
               
                ans = max(ans,cur[j]);
                
            }
            cout<<endl;
            prev = cur;
        }
        return ans;
    }
};