class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // SOLUTION 1 =============================
        stack<int> st;
        
        for(auto i:arr){
            int curMax = (st.empty()) ? i : max(i, st.top());
            
            while(!st.empty() and st.top() > i)
                st.pop();
            
            st.push(curMax);
        }
        return st.size();
        
        // SOLUTION 2 =============================
        int cnt{0}, curMax{-1};
        
        for(int i=0; i<arr.size(); i++){
            curMax = max(curMax, arr[i]);
            if(curMax == i)
                cnt++;
        }
        return cnt;
    }
};
