class Solution {
public: 
    // STRAIGHT means no rotation is present
    int search(vector<int>& nums, int target) {
        int l{0},r{(int)nums.size()-1},mid{};
        while(l<=r){
            mid = l + (r-l)/2;
            // if mid matches, end
            if(nums[mid]==target)
                return mid;
            // find straight part of array
            // left of mid is straight
            if(nums[mid] >= nums[l]){
                if(nums[mid] > target and nums[l]<=target)
                    // inside straight part, continue search here
                    r=mid-1;
                else
                    // not inside straight part, continue search here
                    l=mid+1;
            }
            else{
                // right of mid is straight
                if(nums[mid] < target and nums[r]>=target)
                    // inside straigth part
                    l=mid+1;
                else
                    // inside rotated part
                    r=mid-1;
            }
        }
        return -1;
    }
};
