#define MOD (int)(1e9 + 7)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        stack<int> st,st1;
        vector<int> next(n,n),prev(n,0);
        
        for(int i  = n-1;i>=0;i--)
        {
           while(!st.empty() && arr[st.top()]>=arr[i])
            {
                
                st.pop();
            }
            next[i] = st.empty()? n-i :  st.top() - i;
            st.push(i);
        }
        //for(auto a: next) cout<<a<<" ";
        //cout<<endl;
        
        for(int i  = 0;i<n;i++)
        {
            while(!st1.empty() && arr[st1.top()]>arr[i])
            {
                
                st1.pop();
            }
            prev[i] = st1.empty()? i+1 : i - st1.top();
            st1.push(i);
        }
        
        int sum =0;
        for(int i  = 0;i<n;i++)
        {
           long long prod = (prev[i]*next[i])%MOD;
            prod = (prod*arr[i])%MOD;
            sum = (sum + prod)%MOD;
            
        }
        return sum;
    }
};