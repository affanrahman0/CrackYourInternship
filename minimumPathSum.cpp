#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func(int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(n<0 || m<0) return 1e9;
        if(n==0 && m == 0) return grid[0][0];
        if(dp[n][m]!=-1) return dp[n][m];
       // int up = INT_MAX;
        int up = grid[n][m]+func(n-1,m,grid,dp);
        
        //int left = INT_MAX;
        int left = grid[n][m] + func(n,m-1,grid,dp);
        return dp[n][m]=min(up,left);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return func(n-1,m-1,grid,dp);
        // for(int i=1;i<n;i++)
        // {
        //     grid[i][0] += grid[i-1][0]; 
        // }
        // for(int i=1;i<m;i++)
        // {
        //     grid[0][i] += grid[0][i-1]; 
        // }
        // for(int i=1;i<n;i++)
        // {
        //     for(int j=1;j<m;j++)
        //     {
        //         grid[i][j] += min(grid[i-1][j],grid[i][j-1]); 
        //     }
        // }
        // return grid[n-1][m-1];
    }
};