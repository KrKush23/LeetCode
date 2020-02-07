class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        auto k = find(nums.begin(), nums.end(), target);
        if(k == nums.end())
            return ans;
        auto t1 = lower_bound(nums.begin(),nums.end(), target);
        auto t2 = upper_bound(nums.begin(),nums.end(), target);
        ans[0]=t1 - nums.begin();
        ans[1]=t2 - nums.begin()-1;
        return ans;
    }
};
