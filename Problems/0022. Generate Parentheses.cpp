class Solution {
    vector<string> res{};
public:
    vector<string> generateParenthesis(int n) {
        backtrack("", n, n);
        return res;
    }
    void backtrack(string cur, int left, int right){
        if(left==0 and right==0){
            res.push_back(cur);
            return;
        }
        if(left!=0)
            backtrack(cur+"(", left-1, right);
        if(left<right)
            backtrack(cur+")", left, right-1);
    }
};
