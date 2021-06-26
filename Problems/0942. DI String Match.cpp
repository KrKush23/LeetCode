#define pb push_back
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        int l=0, r=n;
        vector<int> res{};
        
        for(auto c:s){
            if(c == 'I')
                res.pb(l++);
            else
                res.pb(r--);
        }
        res.pb(l);
        return res;
    }
};
