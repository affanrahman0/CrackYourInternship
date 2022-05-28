class StockSpanner {
public:
    
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int i = 1 ;
        while(!st.empty() && st.top().first<=price)
        {
            i += st.top().second;
            st.pop();
        }
        st.push({price,i});
        return i;
    }
};