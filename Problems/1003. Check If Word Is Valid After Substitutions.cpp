class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(auto c:s){
            // 'a'
            if(c=='a'){
                st.push(c);
            }
            // 'b'
            else if(c=='b'){
                if(st.empty() or st.top() != 'a')  
                    return false;
                else
                    st.push(c);
            }
            // 'c'
            else{
                if(st.empty() or st.top() != 'b')
                    return false;
                else{
                    st.pop(); // pop 'b'
                    st.pop(); // pop 'a'
                }
            }
        }
        
        return st.empty();
    }
};
