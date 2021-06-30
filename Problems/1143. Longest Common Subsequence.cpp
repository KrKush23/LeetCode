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
        /*
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
        */
        
        // TOP-DOWN APPROACH ===================
        // space optimized ====================
        vector<vector<int>> dp(2, vector<int> (m+1, 0));
        bool bi{0};
        
        for(int i=1; i<=n; i++){
            bi = i&1; // even&1 = 0, odd&1 = 1
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1])
                    dp[bi][j] = 1 + dp[1-bi][j-1]; // 1-bi instead of i-1...for keeping index +ve
                else
                    dp[bi][j] = max(dp[1-bi][j], dp[bi][j-1]);
            }
        }
        
        return dp[bi][m];
        
    }
};
