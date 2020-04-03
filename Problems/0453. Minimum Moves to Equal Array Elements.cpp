class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = *min_element(nums.begin(),nums.end());
        int cnt{};
        for(auto i:nums)
            cnt += i - min;
        return cnt;
    }
};
