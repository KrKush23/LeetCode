class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        if(l1>l2)
            return findMedianSortedArrays(nums2, nums1);
        int l{0},r{l1},partX{},partY{};
        while(l<=r){
            partX = l + (r-l)/2;
            partY = (l1+l2+1)/2 - partX;
            
            int maxLeftX{}, minRightX{}, maxLeftY{}, minRightY{};
            maxLeftX = (partX == 0) ? INT_MIN : nums1[partX-1];
            minRightX = (partX == l1) ? INT_MAX : nums1[partX];
            maxLeftY = (partY == 0) ? INT_MIN : nums2[partY-1];
            minRightY = (partY == l2) ? INT_MAX : nums2[partY];
                    
            if(maxLeftX <= minRightY and maxLeftY <= minRightX){
                if((l1+l2)&1)
                    return (double)max(maxLeftX,maxLeftY);
                else
                    return ((double)max(maxLeftX,maxLeftY) + min(minRightX, minRightY))/2;
            }
            else if(maxLeftX > minRightY)
                r = partX - 1;
            else
                l = partX + 1;
        }
        return -1;
    }
};
