#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        vector<int> counts(26,0);
        int n = s.size();
        int result = 0;
        int maxcount = 0;
        
        for(int end = 0;end<n;end++)
        {
            counts[s[end]-'A']++;
            maxcount = max(maxcount,counts[s[end]-'A']);
            
            
            while(end - start - maxcount + 1> k)
            {
                counts[s[start++]-'A']--;
            }
            result = max(result,end - start+1);
        }
        return result;
    }
};