class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m{};
        m[0]=1;
        int sum{}, count{}, n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(m.find(sum-k)!=m.end())
                count += m[sum-k];
            m[sum]++;
        }
        return count;
    }
};
