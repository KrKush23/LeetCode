class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        set<char> seen{};
        int ans{},i{},j{};
        // sliding window
        // i -> left end of window
        // j -> right end of window
        while(i<n and j<n){
            if(seen.find(s[j])==seen.end()){
                seen.insert(s[j++]);
                ans = max(ans, j-i);
                // j-i -> size of window
            }
            else
                seen.erase(s[i++]);
        }
        return ans;
    }
};
