class Solution {
public:
    int findMin(vector<int>& nums) {
        int l{0},r{(int)nums.size()-1},mid{};
        while(l<=r){
            if(nums[l]<=nums[r])
                return nums[l];
            mid = l + (r-l)/2;
            if(nums[mid] > nums[r])
                l=mid+1;
            else
                r=mid;
        }
        return -1;
    }
};
