class Solution {
public:
    unordered_set <int> cycle,visited,safe;
    bool dfs(int i,vector<vector<int>> &g )
    {
        if(safe.find(i)!=safe.end()) return true;
        if(cycle.find(i)!=cycle.end()) return false;
        
        if(visited.find(i)!=visited.end()) 
        {
            cycle.insert(i);
            return false;
        }
        
        visited.insert(i);
        for(auto a: g[i])
        {
            if(!dfs(a,g)) 
            {
                cycle.insert(i);
                return false;
            }
        }
        
        safe.insert(i);
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            vector<int> ans;
            
            for(int i=0;i<graph.size();i++)
            {
                if(dfs(i,graph)) ans.push_back(i);
            }
        return ans;
    }
};