#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int a: nums)
            pq.push(a);
        
        while(!pq.empty())
        {
           
            k--;
            if(k==0) return pq.top();
            pq.pop();
        }
        return 0;
    }
};