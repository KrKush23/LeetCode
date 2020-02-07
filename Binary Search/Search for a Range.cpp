class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        int Li = helper(nums, target, true);
        // sent true to show that we need LEFT END of the target
        if(Li == nums.size() || nums[Li] != target)
            return ans;
        ans[0]= Li;
        ans[1]= helper(nums, target, false) - 1;
        // sent false to show that we need RIGHT END of the target
        // '-1' to get correct answer
        return ans;
    }
    
    int helper(vector<int> &nums, int target, bool left){
        int l{0}, r{nums.size()}, mid{};
        while(l<r){
            mid = l + (r-l)/2;
            if(nums[mid]> target || (left && nums[mid]==target))
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};
