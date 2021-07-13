class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // SOLUTION 1...only local inversions should be present
        // => max(nums[i]) < nums[i+2]
        // MORE INTUITIVE
        int curMax = 0;
        for(int i=0; i<n-2; i++){
            curMax = max(curMax, nums[i]);
            if(curMax > nums[i+2])
                return false;
        }
        return true;
        
        // SOLUTION 2...'i' can only be placed at
        // nums[i-1] or nums[i] or  nums[i+1]
        // need to create an example to know it
        for(int i=0; i<n; i++){
            if(abs(nums[i] - i) > 1)
                return false;
        }
        return true;
    }
};
