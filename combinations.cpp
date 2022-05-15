class Solution {
public:
    void recur(vector<vector<int>>& dp,vector<int>& temp,int k,int ind)
    {
        if(ind==0)
        {
            if(temp.size()==k) dp.push_back(temp);
            return;
        }
        
        temp.push_back(ind);
        recur(dp,temp,k,ind-1);
        temp.pop_back();
        recur(dp,temp,k,ind-1);
        
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> dp;
        vector<int> temp;
        recur(dp,temp,k,n);
        return dp;
        
        
        
    }
};