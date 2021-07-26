class Solution {
    vector<vector<int>> res;
    
    void backtrack(int i, vector<int>& nums, vector<int>& cur){
        res.push_back(cur); 
        
        for(int j=i; j<nums.size(); j++){
            cur.push_back(nums[j]);
            backtrack(j+1, nums, cur);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        
        // BACKTRACKING (recursive) ========================
        /*
        vector<int> cur{};
        backtrack(0, nums, cur);
        */
        
        // ITERATIVE =======================================
        res.push_back({}); // empty set
        
        for(auto num: nums){
            int n = res.size();
            for(int i=0; i<n; i++){ // push 'num' to all currently present sets
                res.push_back(res[i]);
                res.back().push_back(num);
            }
        }
        
        // BIT MANIPULATION ===============================
        /*
        int n = nums.size(), p = 1 << n;
        res.resize(p);
        
        for(int i=0; i<p; i++){
            for(int j=0; j<n; j++){
                if((i>>j) & 1)
                    res[i].push_back(nums[j]);
            }
        }
        */
        
        return res;
    }
};
