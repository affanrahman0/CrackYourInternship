#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> &a,
         pair<int, int> &b)
{
    return a.second > b.second;
}
void sort(map<int, int> &M, vector<int> &ans, int k)
{
    vector<pair<int, int>> A;

    for (auto &it : M)
    {
        A.push_back(it);
    }
    sort(A.begin(), A.end(), cmp);

    for (auto &it : A)
    {
        if (k <= 0)
            break;
        ans.push_back(it.first);

        k--;
    }
}

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> m;
        for (auto a : nums)
        {
            m[a]++;
        }
        vector<int> ans;
        sort(m, ans, k);

        return ans;
    }
};