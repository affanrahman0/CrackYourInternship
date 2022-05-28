class Solution {
public:
    int cal(int st,int end,vector<int> &arr)
    {
        int maxi = arr[st];
       for(int i = st+1;i<=end;i++)
        {
            maxi = max(maxi,arr[i]);
        } 
        return maxi;
    }
    int func(int st,int end,vector<int> &arr,vector<vector<int>>& dp)
    {     
        if(st==end) return 0;
        if(end-st==1) return arr[st]*arr[end];
        if(dp[st][end]!=-1) return dp[st][end];
        int mini = 1e9;
        for(int i = st;i<end;i++)
        {
            int a = cal(st,i,arr);
            int b = cal(i+1,end,arr);
            
            int c = func(st,i,arr,dp) +func(i+1,end,arr,dp);
            mini = min(mini,(a*b) + c );
        }
        return dp[st][end] = mini;
    }   
    int mctFromLeafValues(vector<int>& arr) {
        
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return func(0,arr.size()-1,arr,dp);
    }
};