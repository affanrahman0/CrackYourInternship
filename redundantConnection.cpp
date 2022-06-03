#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int par(int node,vector<int> &parent,vector<int>& rank)
    {
        if(node==parent[node]) return node;
        
        return parent[node] = par(parent[node],parent,rank); 
    }
    
    void union2(int u, int v,vector<int> &parent,vector<int>& rank)
    {
        if(rank[u]<rank[v])
        {
            parent[u] = v;
        }
        else if(rank[u]>rank[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      
        vector<int> parent(1001),rank(1001,0);
        for(int i=0;i<1001;i++) parent[i] = i;
        vector<int> ans;
        for(auto a: edges)
        {
            int x = par(a[0],parent,rank),y = par(a[1],parent,rank);
            if(x!=y)
            {
                union2(x,y,parent,rank);
            }
            else
            {
                ans.push_back(a[0]);
                ans.push_back(a[1]);
                
                return ans;
            }
            
        }
        return ans;
    }
};