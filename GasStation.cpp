#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot_surplus = 0;
        int surplus = 0;
        int start = 0;
        int n = gas.size();
        for(int i=0;i<n;i++)
        {
            tot_surplus += gas[i] - cost[i];
            surplus += gas[i] - cost[i] ;
            if(surplus<0)
            {
                surplus = 0;
                start = i+1;
            }
        }
        if(tot_surplus>=0) return start;
        else return -1;
    }
};