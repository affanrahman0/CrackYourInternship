#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) continue;
                
                grid[i][j] = 201;
                if(i>0) grid[i][j] = min(grid[i][j],grid[i-1][j] +1);
                if(j>0) grid[i][j] = min(grid[i][j],grid[i][j-1] +1);

            }
        }
        
        int maxi = 0;
        for(int i = n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(grid[i][j]==1) continue;
                
                //grid[i][j] = 2001;
                if(i<n-1) grid[i][j] = min(grid[i][j],grid[i+1][j] +1);
                if(j<n-1) grid[i][j] = min(grid[i][j],grid[i][j+1] +1);
                
                maxi = max(maxi,grid[i][j]);

            }
        }
        return maxi==201? - 1 :maxi-1;
    }
};