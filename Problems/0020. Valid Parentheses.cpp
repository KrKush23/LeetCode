class Solution {
public:
    bool isValid(string s) {
        stack<char> st{};
        for(auto ch:s){
            switch (ch){
                case  '(':
                case  '{':
                case  '[':
                    st.push(ch);
                    break;
                case '}':
                    if (st.empty() || (st.top() != '{'))
                        return 0;;
                    st.pop();
                    break;
                case ')':
                    if (st.empty() || (st.top() != '('))
                        return 0;
                    st.pop();
                    break;
                case ']':
                    if (st.empty() || (st.top() != '['))
                        return 0;
                    st.pop();
                    break;    
            }   
        }
        return st.empty();
    }
};
