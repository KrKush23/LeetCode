class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0)
            return 1;
        int s_ptr{0},t_ptr{0};
        while(t_ptr < t.length()){
            if(t[t_ptr] == s[s_ptr]){
                s_ptr++;
                if(s_ptr == s.length())
                    return 1;
            }
            t_ptr++;
        }
        return 0;
    }
};
