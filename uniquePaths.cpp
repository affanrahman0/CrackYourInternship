#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func(int n,int m,int i,int j,vector<vector<int>>& dp)
    {
        if(n==i && m==j) return 1;
        if(n<i || m<j) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        int  a = func(n,m,i+1,j,dp)+func(n,m,i,j+1,dp);
        return dp[i][j]=a;
    }
    int uniquePaths(int m, int n) {
        vector<int> prev(m,1);
        for(int i=1;i<n;i++)
        {
            vector<int> prev2(m,0);
            for(int j=0;j<m;j++)
            {
               
                
                    prev2[j]+=prev[j];
                    if(j>0) prev2[j]+=prev2[j-1];
                
            }
            prev = prev2;
        }
        return prev[m-1];
    }
};