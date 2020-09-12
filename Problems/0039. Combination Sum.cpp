class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res{};
        vector<int> path{};
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, res, path);
        return res;
    }
private:
    void dfs(const vector<int> &candidates, int target, int idx, vector<vector<int>>& res, vector<int>& path){
        // Target reached
        if(target==0){
            res.push_back(path);
            return;
        }
        for(int i=idx; i<candidates.size();i++){
            //Sum gets larger than target
            if(candidates[i] > target)
                return;
            //Possible solution
            path.push_back(candidates[i]);
            dfs(candidates, target-candidates[i],i,res,path);
            path.pop_back();
        }
    }
};
