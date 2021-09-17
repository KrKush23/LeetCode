class Solution {
    int n;
    vector<vector<int>> res{};
    vector<bool> vis;
    
    void backtrack(vector<int> &nums, vector<int> &cur){
        if(cur.size() == n){
            res.push_back(cur);
            return;
        }
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                vis[i] = 1;
                cur.push_back(nums[i]);
                backtrack(nums, cur);
                cur.pop_back();
                vis[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        res.clear();
        vis.resize(n);
        vector<int> cur{};
        
        backtrack(nums, cur);
        return res;
    }
};
