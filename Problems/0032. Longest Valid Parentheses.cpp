class Solution {
public:
    int longestValidParentheses(string s) {
        // ==============================
        // Space - O(n)
        
        stack<int> st{};
        int res{0};
        
        // if 1st bracket is  ')'
        st.push(-1);
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                st.pop(); 
                // did not match
                if(st.empty()){
                    st.push(i); //for further calculation of len
                }
                // popped bracket matched
                else{
                    int len = i - st.top();
                    res = max(res, len);
                }
            }
        }
        return res;
        
        // =======================================
        // Space - O(1)
        
//         int open{0}, close{0};
//         int res{};
        
//         // 0...n-1
//         for(auto c:s){
//             (c=='(') ? open++ : close++;
            
//             if(open == close){
//                 int len = open + close;
//                 res = max(res, len); 
//             }else if(close > open){
//                 open = close = 0;
//             }
//         }
        
//         open = close = 0;
        
//         // n-1...0
//         for(int i=s.length()-1 ; i>=0; i--){
//             (s[i]=='(') ? open++ : close++;
            
//             if(open == close){
//                 int len = open + close;
//                 res = max(res, len);
//             }else if(open > close){
//                 open = close = 0;
//             }
//         }
//         return res;
    }
};
