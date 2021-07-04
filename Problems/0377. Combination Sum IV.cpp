class Solution {
    vector<int> dp;
public:
    // ITS  ACTUALLLY PERMUTATION SUM (IMPORTANT) ====================
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1, -1);
        dp[0] = 1;
        return helper(target, nums);//no. ways to get target
    }
    
    int helper(int target, vector<int>& nums){
        if(dp[target] != -1)
            return dp[target];
        
        int res{0};
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= target)
                res += helper(target - nums[i], nums); //no. of ways to get (target - nums[i])
        }
        
        return dp[target] = res;
    }
};
