#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // if(n==0) return 
        unordered_map<char,int> mp;
        
        int count = 0;
        
        
        for(auto &a : tasks) 
        {
            mp[a]++;
            count = max(count,mp[a]);
        }
        
        int ans = 0;
        
        ans = (count-1)*(n+1);
        
        for(auto a: mp) 
        {
            if(a.second==count)
            {
                ans++;
            }
        }
        
        return max((int)tasks.size(),ans);
        
        
        
    }
};