class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size(), n2 = nums2.size();
		if (n1 > n2)
			return findMedianSortedArrays(nums2, nums1);

		int lo{0}, hi{n1}, cut1{}, cut2{};
        
        //BINARY SEARCH for correct partition =========================
		while (lo <= hi) {
            // cut1 + cut2 = (n1 + n2 + 1)/2
			cut1 = lo + (hi - lo) / 2;       // partition of 1st array
			cut2 = (n1 + n2 + 1) / 2 - cut1; // partition of 2nd array accordingly
            
			int left1{}, right1{}, left2{}, right2{};
			left1  = (cut1 == 0)  ? INT_MIN : nums1[cut1 - 1];
			right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
			left2  = (cut2 == 0)  ? INT_MIN : nums2[cut2 - 1];
			right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            // if valid partition
			if (left1 <= right2 and left2 <= right1) {
				if ((n1 + n2) & 1) // odd length
					return (double)max(left1, left2);
				else               // even length
					return ((double)max(left1, left2) + min(right1, right2)) / 2;
			}
			else if (left1 > right2) // go towards correct partition
				hi = cut1 - 1;
			else                     // go towards correct partition
				lo = cut1 + 1;
		}
		return -1;
	}
};
