#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0,ans = 0;
        int rem ;
        unordered_map<int,int> um;
        um[0]= 1;
        for(auto i: nums)
        {
            sum+= i;
            rem = sum%k;
            if(rem<0) rem+= k;
            um[rem]++;
            cout<<rem<<" "<<um[rem]<<endl;
            if(um[rem]>1) ans += um[rem] - 1 ;
        }
        return ans;
    }
};