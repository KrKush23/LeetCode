class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())    return 0;
        int n = nums.size();
        //======== LIS using BINARY SEARCH ==========
        
        // vector<int> tail{};
        // for(auto i:nums){
        //     auto it = lower_bound(tail.begin(),tail.end(),i);
        //     if(it == tail.end()){
        //         tail.push_back(i);
        //     }else{
        //         *it=i;
        //     }
        // }
        // return tail.size();
        
        // ==== shorter soln =======
        
        vector<int> dp(n+1, 1e9);
        for(auto i:nums)
            *lower_bound(dp.begin(),dp.end(),i) = i;
        return lower_bound(dp.begin(),dp.end(),1e9) - dp.begin();
        
        //======== BASIC LIS ================
        
        // vector<int> dp(n,1);
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[j]<nums[i] and dp[j]+1 > dp[i])
        //             dp[i] = dp[j] + 1;
        //     }
        // }
        // return *max_element(dp.begin(),dp.end());
    }
};
