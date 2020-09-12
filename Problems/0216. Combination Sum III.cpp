class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> res{};
        vector<int> path{};
        backtrack(target, 1,k, res, path);
        return res;
    }
private:
    void backtrack(int target, int val, int k, vector<vector<int>>& res, vector<int>& path){
        if(k==0){
            if(target==0)
                res.push_back(path);
            return;
        }
        for(int i=val; i<=9; i++){
            if(i>target)
                return;
            path.push_back(i);
            backtrack(target-i, i+1, k-1, res, path);
            path.pop_back();
        }
    }
};
