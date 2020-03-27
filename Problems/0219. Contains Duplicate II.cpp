class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m{};
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(m.find(nums[i]) == m.end())
                m[nums[i]] = i;
            else if( (i-m[nums[i]]) >k )
                m[nums[i]] = i;
            else // we have to find AT LEAST ONE TRUE CASE
                return 1;
        }
        return 0;
    }
};
