class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // ============ Sliding Window -- O(n) =============
        
        int n= nums.size(), ans{INT_MAX}, sum{}, left{0};
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=s){
                ans = min(ans,i-left+1);
                sum-=nums[left++];
            }
        }
        return (ans != INT_MAX)? ans:0 ;
        
        // =========== Binary Search -- O(nlogn) ==========
        // int n = nums.size(), ans{INT_MAX};
        // if(n==0)
        //     return 0;
        // vector<int> sum(n+1,0);
        // for(int i=1;i<=n;i++)
        //     sum[i] = sum[i-1] + nums[i-1];
        // for (int i = 1; i <= n; i++) {
        //     int to_find = s + sum[i - 1];
        //     auto bound = lower_bound(sum.begin(), sum.end(), to_find);
        //     if (bound != sum.end())
        //         ans = min(ans, static_cast<int>(bound - (sum.begin() + i - 1)));
        // }
        // return (ans!=INT_MAX)? ans:0;
        
    }
};
