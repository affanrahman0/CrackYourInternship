#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    pair<int,int> zero(string s)
    {
        pair<int,int> a;
        a.first = 0,a.second = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0') a.first++;
            else a.second++;
        }
        return a;
    }
    
    int recur(vector<string>& strs, int m, int n,int ind,vector< vector< vector<int> > >& dp)
    {
       
        if(m<0 || n<0) return -1;
        if(ind<0) return 0;
        if(dp[ind][n][m]!=-1) return dp[ind][n][m];
        int take = 1 + recur(strs,m-zero(strs[ind]).first,n-zero(strs[ind]).second,ind-1,dp);
        int not_take = recur(strs,m,n,ind-1,dp);
        return dp[ind][n][m]=max(take,not_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        //vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        vector< vector< vector<int> > > dp(k, vector< vector<int> >(n+1 , vector<int>(m+1,-1)));
        return recur(strs,m,n,k-1,dp);
        
    }
};