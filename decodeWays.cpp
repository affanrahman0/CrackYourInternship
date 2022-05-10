#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func(string& s,int ind,vector<int>& dp)
    {
        if(ind == -1) return 1;
        if(ind< 0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int l =0;
        if(s[ind]!='0') l = func(s,ind-1,dp);
        int r = 0;
        if(ind-1 >=0 && (s[ind-1]=='1' || (s[ind-1]=='2' && s[ind]<='6')))
        {
            cout<<s[ind]<<" "<<s[ind-1]<<endl;
            r = func(s,ind-2,dp);
        }
            
        return dp[ind] = l + r;
    }
    int numDecodings(string s) {
        
        vector<int> dp(s.size(),-1);
        return func(s,s.size()-1,dp);
    }
};