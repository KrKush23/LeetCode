class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans{},cnt{};
        for(auto i:nums){
            if(i){
                cnt++;
                ans = max(ans,cnt);
            }
            else
                cnt=0;
        }
        return ans;
    }
};
