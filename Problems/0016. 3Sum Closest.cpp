class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int min_diff{INT_MAX}, ans{};
        for(int i=0; i<n-2;i++){
            int l= i+1, r = n-1;
            int sum = target - nums[i];
            while(l < r){
                if(min_diff > abs(sum - nums[l] - nums[r])){
                    ans = nums[i] + nums[l] + nums[r];
                    min_diff = abs(target - ans);
                }
                if(nums[l] + nums[r] == sum){
                    return target;
                } else if(nums[l] + nums[r] > sum){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ans;
    }   
};
