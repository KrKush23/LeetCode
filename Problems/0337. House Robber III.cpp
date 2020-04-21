/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define F first
#define S second
class Solution {
public:
    pair<int, int> thief(TreeNode* root){
        if(!root)
            return {0, 0};  
        auto l = thief(root->left);
        auto r = thief(root->right);
        // if we rob this house
        int robbed = l.F + r.F + root->val;
        // if we do not rob this house
        int not_robbed = max(l.F, l.S) + max(r.F, r.S);
        return {not_robbed, robbed};
    }
    int rob(TreeNode* root) {
        auto res = thief(root);
        // first  -> if last house is not robbed
        // second -> if last house is robbed
        return max(res.F, res.S);     
    }
};
