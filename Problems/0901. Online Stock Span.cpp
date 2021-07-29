#define F first
#define S second
class StockSpanner {
    stack< pair<int,int> > st; // {price, stock_span}
public:    
    int next(int price) {
        int res = 1;
        
        // PREVIOUS GREATER ELEMENT LIKE
        while(!st.empty() and st.top().F <= price){
            res += st.top().S;
            st.pop();
        }
        
        st.push({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
