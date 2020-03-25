class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length();
        int ans{0};
        for(char ch: s){
            ans += pow(26,n-1) * (ch-'A'+1);
            n--;
        }
        return ans;
    }
};
