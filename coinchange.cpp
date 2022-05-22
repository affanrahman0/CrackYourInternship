class Solution {
public:
   int coinChange(vector<int>& coins, int amount) {
        if(amount == 0 ) return 0;
        int n = coins.size();
        //vector<vector<int>> dp(n,vector<int>(amount+1,1e8));
        vector<int> prev (amount+1,1e8),prev2(amount+1,1e8);
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0) prev[i] = i/coins[0]; 
            //else  dp[0][i] = 1e8;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                int not_take = prev[j];
                int take = 1e8 ;
                if(j>=coins[i]) take = 1 + prev2[j-coins[i]];
                prev2[j]=min(take,not_take);
            }
            prev= prev2;
        }
        if(prev[amount]>=1e8) return -1;
        else return prev[amount];
    }
};
