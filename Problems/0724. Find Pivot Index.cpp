class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> presum(n+1,0);
        for(int i=1;i<=n;i++)
            presum[i] = presum[i-1] + nums[i-1];
        for(int i=0;i<n;i++){
            if(presum[i] == presum[n] - presum[i+1])
                return i;
        }
        return -1;
    }
};
