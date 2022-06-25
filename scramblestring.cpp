#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
   
    bool func(string s1, string s2,unordered_map<string,bool> dp) {
        
        int len;
        
        len = s1.size();
        if(len==1) return s1==s2;
        else if(len==0) return true;
        else
        {
            if(dp.count(s1+s2)) return dp[s1+s2];
            for(int i=1;i<len;i++)
            {
                if(s1==s2) return dp[s1+s2] = true;
                else if(( func(s1.substr(0,i),s2.substr(0,i),dp) && func(s1.substr(i,len-i),s2.substr(i,len-i),dp)) )
                {
                    
                    return  dp[s1+s2] =true;  
                }
                else if(func(s1.substr(0,i),s2.substr(len-i,i),dp) && func(s1.substr(i,len-i),s2.substr(0,len-i),dp)) 
                {
                    
                   return   dp[s1+s2] =true;  
                }
                    
                
            }
        }
        return dp[s1+s2] = false;
        
        
    }
    bool isScramble(string s1, string s2) {
        unordered_map<string,bool> dp;
        return func(s1,s2,dp);
    }
};