class Solution {
    int dp[201][201];
public:
    int getMoneyAmount(int n) {
        memset(dp, -1, sizeof(dp));
        
        return helper(1, n);
    }
    
    int helper(int start, int end){
        if(dp[start][end] != -1)
            return dp[start][end];
        // BASE CASES
        if(start == end)
            return dp[start][end] = 0;
        if(end - start == 1)
            return dp[start][end] = start;
        if(end - start == 2)
            return dp[start][end] = start + 1;
        
        
        int res {INT_MAX};
        for(int i=start+1; i<end; i++){
            int cur = i + max(helper(i+1, end), helper(start, i-1));
            res = min(res, cur);
        }
        return dp[start][end] = res;
    }
};
