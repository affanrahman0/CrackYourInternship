#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSafe(int row,int col,vector<string> &b)
    {
        for(int i = row;i>=0;i--)
        {
            if(b[i][col]=='Q') return false;
        }
        for(int i = row,j=col;i>=0 && j>=0;i--,j--)
        {
            if(b[i][j]=='Q') return false;
        }
         for(int i = row,j=col;i>=0 && j<b.size() ;i--,j++)
        {
            if(b[i][j]=='Q') return false;
        }
        
        return true;
    }
    void recur(int row,vector<vector<string>> &b,vector<string> &temp,int n)
    {
        if(row==n) 
        {
            b.push_back(temp);
            return;
        }
        for(int c = 0;c<n;c++)
        {
            if(isSafe(row,c,temp))
            {
                temp[row][c] = 'Q';
                recur(row+1,b,temp,n);
                temp[row][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        vector<string> a(n,string(n,'.'));
        recur(0,ans,a,n);
        
        return ans;
        
    }
};