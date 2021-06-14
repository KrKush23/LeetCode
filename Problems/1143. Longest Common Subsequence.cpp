class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        // RECURSIVE APPROACH (TLE) =============
        // ======================================
        /*
        // BASE CASE
        if(n==0 or m==0)
            return 0;
        // RECUSRIVE CASE
        if(text1[n-1] == text2[m-1])
            return 1 + helper(n-1, m-1, s1, s2);
        else
            return max(helper(n-1, m, s1, s2), helper(n, m-1, s1, s2));
        */
        
        // TOP-DOWN APPROACH ===================
        // =====================================
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][m];
        
    }
};
