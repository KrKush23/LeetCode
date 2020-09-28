class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;
        
        int ans{}, left{}, product{1};
        
        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right];
            
            while (product >= k)
                product /= nums[left++];
            
            ans += right - left + 1; //main code 
        }
        
        return ans;
    }
};
