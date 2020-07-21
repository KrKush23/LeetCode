class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans{};
        for(int i=0; i<n-2;i++){
            if(i==0 || (i>0 and nums[i]!=nums[i-1])){ //cz we don't want duplicates
                int l= i+1, r = n-1;
                int sum = 0 - nums[i];
                while(l < r){
                    if(nums[l] + nums[r] == sum){
                        ans.push_back({nums[i], nums[l], nums[r]});
                        while(l < r and nums[l] == nums[l+1]) l++;  //cz we don't want duplicates
                        while(l < r and nums[r] == nums[r-1]) r--;  //cz we don't want duplicates
                        l++;
                        r--;
                    } else if(nums[l] + nums[r] > sum){
                        r--;
                    }else{
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};
