class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m{};
        for(auto i:s)
            m[i]++;
        int ans{};
        bool check{0};
        for(auto i:m){
            ans += (i.second/2)*2;
            if(i.second &1)
                check=1;
        }
        return ans + check;
    }
};
