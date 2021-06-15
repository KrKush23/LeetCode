class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        //ODD SUM can't be divided into 2 parts
        if(sum & 1) return false;
        
        sum /= 2;
        
        //NOW JUST DO SUBSET SUM FOR GIVEN SUM
        bool dp[n+1][sum+1];
        memset(dp, 0, sizeof(dp));
        
        //ZERO sum is always possible
        for(int i=0; i<=n; i++)
            dp[i][0] = 1;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                dp[i][j] = dp[i-1][j];
                if(nums[i-1] <=j)
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
            }
        }
        
        return dp[n][sum];
    }
};
