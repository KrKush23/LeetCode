class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        
        int idx_2{1}, idx_3{1}, idx_5{1};
        int next2{2}, next3{3}, next5{5};
        
        for(int i=1; i<n; i++){
            dp[i] = min({next2, next3, next5});
            
            if (dp[i] == next2) next2 = dp[idx_2++] * 2;
            if (dp[i] == next3) next3 = dp[idx_3++] * 3;
            if (dp[i] == next5) next5 = dp[idx_5++] * 5;
        }
        
        return dp[n-1];
    }
};
