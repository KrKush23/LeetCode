class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<1)     return 0;
        if(n==1)    return nums[0];
        if(n==2)    return max(nums[0],nums[1]);
        //calculate it for (1st to 2ns last) and (2nd to last)
        return max(helper(nums,0,n-2), helper(nums,1,n-1));
    }
    int helper(vector<int>& nums, int i, int j){
        int n=nums.size();
        vector<int> dp(n);
        dp[i] = nums[i];
        dp[i+1] = max(dp[i], nums[i+1]);
        for(int k=i+2; k<=j; k++)
            dp[k] = max(dp[k-1], dp[k-2]+nums[k]);
        return dp[j];
    }
};
