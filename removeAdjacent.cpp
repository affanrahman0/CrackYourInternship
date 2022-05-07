#include<bits/stdc++.h>
#include<string.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int,char>> k1;
        
        for(auto c: s)
        {
            if(k1.empty() || k1.top().second!=c)
                k1.push({1,c});
            else if(++k1.top().first==k) k1.pop();
        }
        string res = "";
        while(!k1.empty())
        {
            res.append(k1.top().first,k1.top().second);
            k1.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};