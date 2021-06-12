class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        // 1D MATRIX APPROACH ==========================
        vector<int> dp(amount+1, amount+1);
        dp[0]=0; //0 ways to make 0 amount
        
        for(int i=1; i<=amount; i++){
            for(int j=0; j<n; j++){
                if(coins[j] <= i) //if coins is applicable
                    // min of exclusion and inclusion
                    dp[i] = min(dp[i], 1+ dp[i - coins[j]]);
            }
        }
        return dp[amount] > amount ? -1:dp[amount];
        
        
        
        // 2D MATRIX APPROACH ==========================
//         vector<vector<int>> dp(n+1, vector<int>(amount+1,amount+1));
        
//         // i=0  -> coin = 0 already initialised with amount+1
//         for(int i=1; i<=n; i++){
//             for(int j=0; j<=amount; j++){
//                 if(j==0)    //amount = 0
//                     dp[i][j] = 0;
//                 else if(coins[i-1] > j) //coin val > amount
//                     dp[i][j] = dp[i-1][j]; //copy last coin's dp
//                 else 
//                     //min of inclusion and exclusion
//                     dp[i][j] = min(1+ dp[i][j-coins[i-1]], dp[i-1][j]);
//             }
//         }
//         return dp[n][amount] > amount ? -1:dp[n][amount];
    }
};
