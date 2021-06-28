class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res{0};
        for(int i=1; i<nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                int to_add = nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1]+1;
                res += to_add;
            }
        }
        return res;
    }
};
