class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        
        sort(nums.begin(), nums.end());
        
        int i=n-3, j=n-2, k=n-1;
        while(i>=0){
            if(nums[i] + nums[j] > nums[k]) // SORTED -> only need to check this condition
                return nums[i] + nums[j] + nums[k];
            i--;
            j--;
            k--;
        }
        return 0;
    }
};
