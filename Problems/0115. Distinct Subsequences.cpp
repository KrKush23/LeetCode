class Solution {
    string s,t;
    int n, m;
    int dfs(int i, int j, vector<vector<int>>& dp){
        if(j == m) //end of 't'
            return 1;
        if(i == n) // end of 's'
            return 0;
        if(dp[i][j] != -1) // lookup
            return dp[i][j];
        
        if(s[i] == t[j]) //if equal char
            dp[i][j] = dfs(i+1, j+1, dp) + dfs(i+1, j, dp);
        else            // if unequal char
            dp[i][j] = dfs(i+1, j, dp);
        return dp[i][j];
    }
public:
    int numDistinct(string s, string t) {
        // MEMOIZATION
        this->s = s;
        this->t = t;
        n = s.length();
        m = t.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return dfs(0, 0, dp);
        
    }
};
