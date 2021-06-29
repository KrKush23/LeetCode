class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int t1{INT_MAX}, t2{INT_MAX};
        for(auto i:nums){
            if(i <= t1)
                t1 = i;
            else if(i <= t2)
                t2 = i;
            else
                return true;
        }
        return false;
    }
};
