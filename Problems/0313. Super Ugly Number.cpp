class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> nums{1};
        vector<int> idx(m,0);
        while(nums.size()<n){
            int next{INT_MAX};
            vector<int> min_idx{};
            for(int i=0;i<m;i++){
                int val = nums[idx[i]] * primes[i];
                if(val < next){
                    next = val;
                    min_idx = {i};
                }
                else if(val == next)
                    min_idx.push_back(i);
            }
            for(auto i:min_idx)
                idx[i]++;
            nums.push_back(next);
        }
        return nums.back();
    }
};
