class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums{1};
        int idx_2{}, idx_3{}, idx_5{};
        int next2{}, next3{}, next5{};
        while(nums.size()<n){
            next2 = nums[idx_2] * 2;
            next3 = nums[idx_3] * 3;
            next5 = nums[idx_5] * 5;
            int next = min({next2, next3, next5});
            nums.push_back(next);
            if(next == next2)
                idx_2++;
            if(next == next3)
                idx_3++;
            if(next == next5)
                idx_5++;
        }
        return nums.back();
    }
};
