class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans{};
        int n=nums.size();
        for(int i=0; i<n-3;i++){
            if(i==0 or (i>0 and nums[i] != nums[i-1])){ //cz we don't want duplicates
                for(int j=i+1; j<n-2;j++){
                    if(j==i+1 || (j>i+1 and nums[j] != nums[j-1])){ //cz we don't want duplicates
                        int l=j+1, r=n-1;
                        int sum = target - nums[i] - nums[j];
                    
                        while(l<r){
                            if(nums[l] + nums[r] == sum){
                                ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                                while(l < r and nums[l] == nums[l+1]) l++;  //cz we don't want duplicates
                                while(l < r and nums[r] == nums[r-1]) r--;  //cz we don't want duplicates
                                l++;
                                r--;
                            }else if(nums[l] + nums[r] >= sum){
                                r--;
                            }else{
                                l++;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
