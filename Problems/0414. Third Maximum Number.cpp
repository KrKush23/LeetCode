class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long max1{LONG_MIN}, max2{LONG_MIN}, max3{LONG_MIN};
        for(auto i:nums){
            if(i == max1 or i==max2 or i==max3)
                continue;
            if(i>max1){
                max3=max2;
                max2=max1;
                max1=i;
            }
            else if(i>max2 and i<max1 ){
                max3=max2;
                max2=i;
            }
            else if(i>max3 and i<max2)
                max3=i;
        }
        return (max3==LONG_MIN)?max1:max3;
    }
};
