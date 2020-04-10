class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size(), anchor{}, ans{};
        for(int i=0;i<n;i++){
            if(i>0 and nums[i-1]>=nums[i])
                anchor=i;
            ans = max(ans,i-anchor+1);
        }
        return ans;
    }
};
