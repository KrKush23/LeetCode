class Solution {
    vector<vector<int>> res;
    
    void backtrack(int idx, vector<int>& nums, vector<int>& cur){
        // Add the subset formed so far to the subsets list.
        res.push_back(cur);
        
        for(int i=idx; i<nums.size(); i++){
            // If the current element is a duplicate, ignore.
            if(i!=idx and nums[i] == nums[i-1]) // IMPT -> i != idx
                continue;
            
            cur.push_back(nums[i]);
            backtrack(i+1, nums, cur);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        sort(nums.begin(), nums.end()); // SORT..to have duplicates together
        
        // BACKTRACKING =======================================
        vector<int> cur{};
        backtrack(0, nums, cur);
        
        // ITERATIVE ==========================================
        /*
        res.push_back({}); // empty set
        int sizeBeforeLastRound{};
        
        for(int i=0; i<nums.size(); i++){
            // if DUPLICATE FOUND
            // add it to subsets formed ONLY IN THE PREVIOUS ROUND
            int j = (i>0 and nums[i] == nums[i-1]) ? sizeBeforeLastRound : 0;
            
            sizeBeforeLastRound = res.size();
            
            for(; j<sizeBeforeLastRound; j++){
                auto cur = res[j];
                cur.push_back(nums[i]);
                res.push_back(cur);
            }
        }
        */
        // ====================================================
        return res;
    }
};
