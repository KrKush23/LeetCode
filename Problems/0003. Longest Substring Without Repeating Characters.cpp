class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        
        int start = -1;
        int res{};
        
        for(int i=0; i<s.length(); i++){
            // to make jump instead of coming  1 step at a time
            start = max(start, dict[s[i]] + 1); 
            
            dict[s[i]] = i;
            res = max(res, i - start + 1);
        }
        
        return res;
    }
};
