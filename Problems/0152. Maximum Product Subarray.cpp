class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res{INT_MIN};
        int curMin{1}, curMax{1};
        
        for(auto i:nums){
            int temp = curMin;
            
            curMin = min({i, curMin * i, curMax * i});
            curMax = max({i, curMax * i, temp * i});
            
            res = max(res, curMax);
        }
        
        return res;
    }
};
