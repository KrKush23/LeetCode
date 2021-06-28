#define F first
#define S second
class Solution {
public:
    string removeDuplicates(string s, int k) {
        // USING VECTOR INSTEAD OF STACK
        vector<pair<char, int>> st{};
        string res{};
        
        for(auto c:s){
            if(st.empty() or st.back().F != c)
                st.push_back({c, 1});
            else if(++st.back().S == k) //pre increment
                st.pop_back();
        }
        
        for(auto t:st){
            res.append(t.S, t.F); // no. of times, character
        }
        return res;
        
        // STACK ============
        /*
        stack<pair<char,int>> st;
        string res{};
        
        for(auto c:s){
            if(st.empty() or st.top().F != c)
                st.push({c, 1});
            else{
                if(st.top().S + 1 == k)
                    st.pop();
                else{
                    int cnt = st.top().S+1;
                    st.pop();
                    st.push({c, cnt});
                }
            }
        }
        
        while(!st.empty()){
            auto [c, n] = st.top();
            st.pop();
            for(int i=0; i<n; i++)
                res += c;
        }
        reverse(res.begin(), res.end());
        return res;
        */
    }
};
