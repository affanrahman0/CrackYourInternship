#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int temp(int n , int s)
    {
        if (s>n)
            return 0;
        else if (s==n)
            return 1;
        return temp(n,s+1)+temp(n,s+2);
    }
    int climbStairs(int n) {
        return temp(n,0);
    }


};