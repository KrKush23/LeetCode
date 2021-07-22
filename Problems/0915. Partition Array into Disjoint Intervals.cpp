class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int cur = nums[0], maxTillNow = nums[0];
        int res = 1;
        
        for(int i=1; i<nums.size(); i++){
            // element less than CUR, update RES and CUR
            if(nums[i] < cur){
                res = i+1;
                cur = maxTillNow;
            }else{
                // track of maximum element till here
                maxTillNow = max(maxTillNow, nums[i]);
            }
        }
        return res;
    }
};
