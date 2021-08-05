class Solution {
    int n;
    
    int helper(int i, vector<int>& s, vector<int>& dp){
        //BASE CASE
        if(i >= n)  return 0;
        
        // LOOK UP
        if(dp[i] != -1)  return dp[i];
        
        // RECURSIVE
        int res = INT_MIN;
        
        res = max(res, s[i] - helper(i+1, s, dp));
        if(i+1 < n) res = max(res, s[i] + s[i+1] - helper(i+2, s, dp));
        if(i+2 < n) res = max(res, s[i] + s[i+1] + s[i+2] - helper(i+3, s, dp));
        
        return dp[i] = res;
    }
public:
    string stoneGameIII(vector<int>& s) {
        n = s.size();
        
        // MEMOIZATION ========================
        vector<int> dp(n, -1);
        int res = helper(0, s, dp);
        
        // TABULAR ============================
        vector<int> dp(n+1, 0);
        
        for(int i=n-1; i>=0; i--){
            int res = INT_MIN;
        
            res = max(res, s[i] - dp[i+1]);
            if(i+1 < n) res = max(res, s[i] + s[i+1] - dp[i+2]);
            if(i+2 < n) res = max(res, s[i] + s[i+1] + s[i+2] - dp[i+3]);
            
            dp[i] = res;
        }
        int res = dp[0];
        
        // TABULAR with O(1) space -> just 4 variables required =============
        int i_1=0, i_2=0, i_3=0; 
        
        for(int i=n-1; i>=0; i--){
            int res = INT_MIN;
        
            res = max(res, s[i] - i_1);
            if(i+1 < n) res = max(res, s[i] + s[i+1] - i_2);
            if(i+2 < n) res = max(res, s[i] + s[i+1] + s[i+2] - i_3);
            
            i_3 = i_2;
            i_2 = i_1;
            i_1 = res;
        }
        int res = i_1;
       
        // Common Part ============================ 
        if(res > 0) return "Alice";
        if(res < 0) return "Bob";
        return "Tie";
    }
};
