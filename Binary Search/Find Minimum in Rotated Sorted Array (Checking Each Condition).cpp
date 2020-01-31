class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int l{0},r{(int)nums.size()-1},mid{};
        if(nums[l]< nums[r])
            return nums[0];
        
        while(l<=r){
            mid = l + (r-l)/2;
            if(nums[mid ]> nums[mid+1])
                return nums[mid+1];
            if(nums[mid-1]>nums[mid])
                return nums[mid];
            if(nums[mid] > nums[0])
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
};
