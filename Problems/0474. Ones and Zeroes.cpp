class Solution {
    int dp[601][101][101];
    
    int helper(int i, vector<string>& strs, int m, int n){
        //BASE CASES
        if(i == strs.size())
            return 0;
        if(m == 0 and n==0)
            return 0;
        
        // LOOK UP
        if(dp[i][m][n] != -1)
            return dp[i][m][n];
        
        // COUNT '0' and '1' in strs[i]
        int zeroes = count(strs[i].begin(), strs[i].end(), '0');
        int ones   = count(strs[i].begin(), strs[i].end(), '1');
        
        int res=0;
        
        if(m-zeroes >= 0 and n-ones >=0) // if possible take this strs[i]
            res = 1 + helper(i+1, strs, m-zeroes, n-ones);
        
        res = max(res, helper(i+1, strs, m, n)); // try not taking it
            
        return dp[i][m][n] = res;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        // MEMOIZATION
        return helper(0, strs, m, n);
    }
};
