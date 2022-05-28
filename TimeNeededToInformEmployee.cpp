#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func(int node,vector<vector<int>>& g,vector<int>& time)
    {
        if(g[node].size()==0) return 0;
        int sum = -1;
        for(auto a: g[node])
        {
            sum = max(sum,time[node]+func(a,g,time));
        }
        return sum;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
       vector<vector<int>> g(n);
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
            {
                g[manager[i]].push_back(i);
            }
        }
        return func(headID,g,informTime);
    }
};