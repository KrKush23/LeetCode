class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //====== SINGLE SCAN - O(n) ============
        
        int min1{INT_MAX}, min2{min1};
        int max1{INT_MIN}, max2{max1}, max3{max1};
        for(auto i:nums){
            if(i <= min1){
                min2=min1;
                min1=i;
            }
            else if(i < min2)
                min2=i;
            if(i>=max1){
                max3=max2;
                max2=max1;
                max1=i;
            }
            else if(i>=max2){
                max3=max2;
                max2=i;
            }
            else if(i>max3)
                max3=i;
        }
        return max1 * max(max2*max3, min1*min2);
        
        //=========== USING SORTING - O(nlogn) ===========
        
        // sort(nums.begin(),nums.end(),greater<int>());
        // int n=nums.size();
        // return nums[0] * max(nums[1]*nums[2] , nums[n-1]*nums[n-2]);
    }
};
