class Solution {
public:
    string removeKdigits(string num, int k) {
        string res{};
        for(auto c:num){
            while(res.length() and k and res.back() > c){
                res.pop_back();
                k--;
            }
            if(res.size() or c != '0')  // if c == 0 check for char before it
                res.push_back(c);       //to prevent LEADING ZEROES
        }
        
        while(res.size() and k--){      // if 'k' > 0..MUST DELETE MORE
            res.pop_back();
        }
        
        return (res =="") ? "0" : res;
        
    }
};
