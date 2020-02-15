class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum{nums[0]},mx{sum};
        for(int i=1;i<nums.size();i++){
            sum = max(sum+nums[i],nums[i]);
            if(sum>mx)  mx=sum;
        }
        return mx;
    }
};
