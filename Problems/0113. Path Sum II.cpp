/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<vector<int>> res{};
    vector<int> cur{};
    
    void helper(TreeNode* root, int sum){
        if(!root)
            return;
        
        cur.push_back(root->val);
        if(!root->left and !root->right and sum==root->val){
            res.push_back(cur);
            cur.pop_back();
            return;
        }
        
        helper(root->left, sum-root->val);
        helper(root->right, sum-root->val);
        
        cur.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        res.clear();
        cur.clear();
        
        if(!root)
            return res;
        
        helper(root, sum);
        return res;
    }
};
