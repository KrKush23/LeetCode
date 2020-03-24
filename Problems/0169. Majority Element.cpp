class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans{nums[0]},cnt{1},n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==ans)
                cnt++;
            else
                cnt--;
            if(cnt==0){
                ans=nums[i];
                cnt=1;
            }
        }
        return ans;
    }
};
