#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int newc,int s)
    {
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size()) return;
        if(image[i][j]!=s) return;
        //cout<<i<<" "<<j<<endl;
        image[i][j] = newc;
        
        dfs(image,i+1,j,newc,s);
        dfs(image,i-1,j,newc,s);
        dfs(image,i,j+1,newc,s);
        dfs(image,i,j-1,newc,s);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int n) {
        
        if(n!=image[sr][sc]) dfs(image,sr,sc,n,image[sr][sc]);
        return image;
    }
};