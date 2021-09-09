class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001; // given
        vector<int> val(n);
        
        for(auto i:nums)
            val[i] += i;
        
        int take{}, skip{};
        
        for(int i=0; i<n; i++){
            int takei = skip + val[i];  // taking this
            int skipi = max(skip, take);// not taking this
            
            take = takei;
            skip = skipi;
        }
        
        return max(take, skip);
    }
};
