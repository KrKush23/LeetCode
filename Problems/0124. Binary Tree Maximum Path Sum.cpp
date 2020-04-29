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
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* root, int &res){
        if(root){
            int l = max(helper(root->left, res),0);
            int r = max(helper(root->right, res),0);
            res = max({res, root->val+l+r});
            return max(l,r) + root->val;
        }
        return 0;
    }
};
