#include<bits/stdtr1c++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(st.empty() || temp[st.top()]>=temp[i]) st.push(i);
            else
            {
                while(!st.empty() && temp[st.top()]< temp[i])
                {
                    ans[st.top()] = i - st.top() ;
                    st.pop();
                }
                
                st.push(i);
            }
        }
        return ans;
        
    }
};