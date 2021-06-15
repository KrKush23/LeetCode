class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.length(), n=s2.length();
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        
        //LCS - modified to get sum of ASCII of LCS
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = (int)s1[i-1] + dp[i-1][j-1]; // adding ASCII value if char MATCHES
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        int sum1 = accumulate(s1.begin(), s1.end(), 0);
        int sum2 = accumulate(s2.begin(), s2.end(), 0);
        
        return sum1 + sum2 - 2 * dp[m][n]; //total ASCII of (s1+s2)  - ASCII of LCS
    }
};
