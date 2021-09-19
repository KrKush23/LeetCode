class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // SOLUTION 1 ====================
        stack<int> st;
        
        for(auto i:arr){
            int curMax = (st.empty()) ? i : max(st.top(), i);
            
            while(!st.empty() and st.top() > i)
                st.pop();
            
            st.push(curMax);
        }
        
        return st.size();
        
        // SOLUTION 2 =======================
        int res{};
        vector<int> sorted{arr};
        sort(begin(sorted), end(sorted));
        
        long sum1{}, sum2{};
        for(int i=0; i<arr.size(); i++){
            sum1 += arr[i];
            sum2 += sorted[i];
            if(sum1 == sum2)
                res++;
        }
        return res;
    }
};
