// We use 'mid = l + (r-l)/2'
// to keep value of 'mid' within limits of its data type
// Eg: INT_MAX + INT_MAX-1
// Though size of array won't be that large, 
// it may create unwanted problems in other implementations
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l{0},r{nums.size()-1},mid{};
        while(l<=r){
            mid = l + (r-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                l=mid+1;
            else 
                r=mid-1;
        }
        return -1;
    }
};
