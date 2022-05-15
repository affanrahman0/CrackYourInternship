#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void update(int i,int j,vector<vector<int>>& grid,int &found)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid.size() || grid[i][j]!=1) return;
        
        grid[i][j] = 2;
        found = 1;
        update(i+1,j,grid,found);
        update(i-1,j,grid,found);
        update(i,j+1,grid,found);
        update(i,j-1,grid,found);
    }
    
    bool expand(int i,int j,vector<vector<int>>& grid,int c)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid.size()) return false;
        grid[i][j] = grid[i][j] == 0 ? c + 1 : grid[i][j];
        return grid[i][j] == 1;
        
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
      for(int i =0,found =0 ; !found && i<grid.size();i++)
      {
          for(int j=0; !found && j<grid.size(); j++)
          {
              update(i,j,grid,found);
          }
      }
      for(int c = 2;;++c)
      {
          for(int i= 0;i<grid.size();i++)
          {
              for(int j = 0;j<grid.size();j++)
              {
                  if(grid[i][j]==c && (expand(i+1,j,grid,c) || expand(i,j+1,grid,c) || expand(i-1,j,grid,c) || expand(i,j-1,grid,c))) return c-2;
              }
          }
      }
      return 0;  
    }
};