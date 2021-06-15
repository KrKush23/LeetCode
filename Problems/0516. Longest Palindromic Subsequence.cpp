class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int l = s.length();
        string t{s};
        reverse(t.begin(), t.end());
        int dp[l+1][l+1];
        memset(dp, 0, sizeof(dp));
        
        // JUST apply LCS on (s, reverse(s))
        for(int i=1; i<=l; i++){
            for(int j=1; j<=l; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[l][l];
    }
};
