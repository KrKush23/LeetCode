class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax {0}, curMin{0};
        int maxSum {nums[0]}, minSum{nums[0]};
        int total{0};
        
        for(auto i:nums){
            curMax = max(curMax + i, i);
            maxSum = max(maxSum, curMax);
            
            curMin = min(curMin + i, i);
            minSum = min(minSum, curMin);
            
            total += i;
        }
        
        return (maxSum > 0) ? max(maxSum, total - minSum) : maxSum;
    }
};
