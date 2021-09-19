#define F first
#define S second
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int cnt{}, maxLen{};
        vector<pair<int, int>> dp(n, {1, 1}); // {len, count}
        
        for(int i=0; i<n; i++){
            for(int j=0;j<i; j++){
                if(nums[j] < nums[i]){
                    if(dp[i].F < dp[j].F + 1) 
                        dp[i] = {dp[j].F + 1, dp[j].S}; // {len[j]+1, count[j]}
                    else if(dp[i].F == dp[j].F + 1)
                        dp[i].S += dp[j].S; // count += count[j]
                }
            }
            if(maxLen == dp[i].F)
                cnt += dp[i].S;
            
            if(maxLen < dp[i].F){
                maxLen = dp[i].F;
                cnt = dp[i].S;
            }
        }
        return cnt;
    }
};
