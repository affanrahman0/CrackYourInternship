#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& g,int node,set<int>& vis)
    {
        vis.insert(node);
        for(auto a: g[node]) 
        {
            if(vis.find(a)==vis.end()) dfs(g,a,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& con) {
        if(con.size() >= n-1)
        {
            vector<vector<int>> g(n);
            for(int i=0;i<con.size();i++)
            {
                g[con[i][0]].push_back(con[i][1]);
                g[con[i][1]].push_back(con[i][0]);
            }
            
            set<int> vis;
            int components = 0;
            for(int i=0;i<g.size();i++)
            {
                if(vis.find(i)==vis.end())
                {
                     dfs(g,i,vis);
                    components++;
                }
                   
                
            }
            return components-1;
        }
        else
        {
            return -1;
        }
    }
};