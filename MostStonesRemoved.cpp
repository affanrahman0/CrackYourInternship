#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void func(int node,vector<int>& vis,vector<vector<int>>& g)
    {
        if(vis[node]==2)
        {
            vis[node] = 1;
            for(auto a: g[node])
            {
                func(a,vis,g);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        
        int m = stones.size();
        int island = 0;
        vector<vector<int>> g(20002);
        vector<int> vis(20002,0);
        for(auto a: stones)
        {
            g[a[0]].push_back(10001+a[1]);
            g[10001+a[1]].push_back(a[0]);
            
            vis[a[0]] = 2;
            vis[10001+a[1]] = 2;
        }
        for(int i = 0;i<20002;i++)
        {
             if(vis[i]==2)
           {
               func(i,vis,g);
               island++;
           }
        }
        
        return m-island;
    }
};