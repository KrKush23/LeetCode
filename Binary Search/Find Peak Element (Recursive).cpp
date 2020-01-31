class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return search(nums, 0, (int)nums.size()-1);
    }
    int search(vector<int> &nums, int l, int r){
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid]<nums[mid+1])
                return search(nums,mid+1,r);
            return search(nums,l,mid);
        }
        return l;
    }
};
