class Solution {
public:
    string removeDuplicates(string s) {
        string res{};
        for(auto c:s){
            if(res.length() == 0 or res.back() != c)
                res.push_back(c);
            else
                res.pop_back();
        }
        return res;
        
        // STACK
        /*
        stack<char> st;
        string res{};
        
        for(auto c:s){
            if(st.empty())          
                st.push(c);
            else if(c == st.top())  
                st.pop();
            else
                st.push(c);
        }
        
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        
        return res;
        */
        
        // RECURSIVE
        /*
        for(int i=1; i<s.length(); i++){
            if(s[i] == s[i-1])
                return removeDuplicates(s.substr(0, i-1) + s.substr(i+1, s.length()-i));
        }
        return s;
        */
    }
};
