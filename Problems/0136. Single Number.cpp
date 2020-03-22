class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x{};
        for(auto i:nums)
            x^=i;
        return x;
    }
};
