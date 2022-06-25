#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
         
        int n = matrix.size(),m = matrix[0].size(),pre = 0;
        //vector<vector<int>> dp(n,vector<int>(m,0));
        vector<int> cur(m,0);
        int res = 0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j =0;j<matrix[0].size();j++)
            {
                int temp = cur[j];
                if(matrix[i][j]!='0' && i && j)
                {
                    cur[j] = min(pre,min(cur[j],cur[j-1])) +1;
                }
                else
                {
                    cur[j] = matrix[i][j] - '0';
                }
                //cout<<dp[i][j]<<endl;
                pre = temp;
                res = max(res,cur[j]);
            }
        }
        return res*res;
    }
};